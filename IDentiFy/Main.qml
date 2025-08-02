import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
ApplicationWindow {
    id:root
    width: 960
    height: 720
    visible: true
    title: "证件智能识别软件"
    color:"#1e2a38"

    //添加一个Connections元素来监听C++信号
    Connections{
        target:backend  //main.cpp中注册的对象

        //对应信号scanProgressChanged
        function onScanProgressChanged(step,message){
            statusLabel.text=message;
            //采集完成
            if(step>=7)
            {
                processButton.enabled=true;
            }
        }

        //对应信号newImageCaptured
        function onNewImageCaptured(imagePath,frameIndex)
        {
            switch(frameIndex) {
            case 0: frameFrontWhite.imageSource = imagePath; break;
            case 1: frameFrontIR.imageSource = imagePath; break;
            case 2: frameFrontUV.imageSource = imagePath; break;
            case 3: frameBackWhite.imageSource = imagePath; break;
            case 4: frameBackIR.imageSource = imagePath; break;
            case 5: frameBackUV.imageSource = imagePath; break;
            }
        }

        //对应识别完成信号
        function onRecognitionComplete(results)
        {
            // 将QVariantMap直接当做JS对象使用
            nameLabel.text = results.name
            genderLabel.text = results.gender
            birthDateLabel.text = results.birthDate
            idNumberLabel.text = results.idNumber
            nationalityLabel.text = results.nationality
            validUntilLabel.text = results.validUntil
            confidenceLabel.text = results.confidence

            // 显示结果区域
            resultsFrame.visible = true
        }
    }

    //脚注标识
    footer:Frame{
        height:40
        background: Rectangle{color:"#2c3e50"}
        Label{
            id:statusLabel
            text:"准备就绪"
            anchors.centerIn: parent
            color:"white"
        }

        Button {
            id: settingsButton
            ToolTip.text: "图像参数设置"
            icon.source: "qrc:/icons/settings.svg" // 需要一个settings.svg图标
            icon.color: "white"
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
            anchors.rightMargin: 10
            flat: true
            onClicked: settingsDrawer.open()
        }
    }

    //设置抽屉
    Drawer{
       id:settingsDrawer
       width:250
       height:parent.height/2
       edge:Qt.RightEdge //从右侧滑出
       background: Rectangle{color:"#1c3e50"}
       ColumnLayout{
           anchors.fill: parent
           anchors.margins: 10
           spacing: 10

           Label{
               text:"图像调节"
               font.bold: true
               color:"#ecf0f1"
               Layout.alignment: Qt.AlignHCenter
           }

           //对比度
           Label { text: "对比度: " + contrastSlider.value.toFixed(2); color: "white" }
           Slider {
               id: contrastSlider
               from: 1.0
               to: 3.0
               value: 1.0 // 默认值
               Layout.fillWidth: true
               // 当滑块值变化时，实时调用C++槽函数
               onValueChanged: backend.setContrast(value)
           }

           // 亮度
           Label { text: "亮度: " + brightnessSlider.value; color: "white" }
           Slider {
               id: brightnessSlider
               from: -100
               to: 100
               value: 0 // 默认值
               Layout.fillWidth: true
               onValueChanged: backend.setBrightness(value)
           }
       }
    }

    ColumnLayout{
        anchors.fill: parent
        anchors.margins: 10
        spacing: 10
        //图像显示区
        GridLayout{
            id:photoGrid
            Layout.fillWidth: true
            Layout.fillHeight: true
            columns: 3
            columnSpacing: 15
            rowSpacing: 15
            Layout.alignment: Qt.AlignHCenter

            PhotoFrame{
                id:frameFrontWhite
                title:"正面-白光"
                Layout.fillHeight:true
                Layout.fillWidth: true
            }
            PhotoFrame{
                id:frameFrontIR
                title:"正面-红外"
                Layout.fillHeight:true
                Layout.fillWidth: true
            }
            PhotoFrame{
                id:frameFrontUV
                title:"正面-紫外"
                Layout.fillHeight:true
                Layout.fillWidth: true
            }
            PhotoFrame{
                id:frameBackWhite
                title:"反面-白光"
                Layout.fillHeight:true
                Layout.fillWidth: true
            }
            PhotoFrame{
                id:frameBackIR
                title:"反面-红外"
                Layout.fillHeight:true
                Layout.fillWidth: true
            }
            PhotoFrame{
                id:frameBackUV
                title:"反面-紫外"
                Layout.fillHeight:true
                Layout.fillWidth: true
            }
        }
        //识别结果展示区
        Frame {
            id: resultsFrame
            Layout.fillWidth: true
            Layout.topMargin: 20
            visible: false // 默认隐藏
            background: Rectangle { color: "#2c3e50" }

            GridLayout {
                anchors.fill: parent
                anchors.margins: 10
                columns: 2
                columnSpacing: 20
                rowSpacing: 5

                // 左侧标签
                Label { text: "姓名:"; color:"#bdc3c7"; font.bold: true }
                Label { id: nameLabel; color: "white" }

                Label { text: "性别:"; color:"#bdc3c7"; font.bold: true }
                Label { id: genderLabel; color: "white" }

                Label { text: "出生日期:"; color:"#bdc3c7"; font.bold: true }
                Label { id: birthDateLabel; color: "white" }

                Label { text: "证件号码:"; color:"#bdc3c7"; font.bold: true }
                Label { id: idNumberLabel; color: "white" }

                // 右侧标签
                Label { text: "国籍:"; color:"#bdc3c7"; font.bold: true }
                Label { id: nationalityLabel; color: "white" }

                Label { text: "有效期至:"; color:"#bdc3c7"; font.bold: true }
                Label { id: validUntilLabel; color: "white" }

                Label { text: "置信度:"; color:"#bdc3c7"; font.bold: true }
                Label { id: confidenceLabel; color: "white"; font.pixelSize: 16 }
            }
        }
        //操作区
        RowLayout{
            Layout.alignment: Qt.AlignHCenter
            spacing:50

            Button{
                id:scanButton
                Layout.preferredWidth: 120
                Layout.preferredHeight: 50
                text:" 开始采集"
                icon.source: "/icons/camera.svg"
                onClicked:{
                    //采集逻辑
                    processButton.enabled = false
                    // 清空所有图片
                    frameFrontWhite.imageSource = ""
                    frameFrontIR.imageSource = ""
                    frameFrontUV.imageSource = ""
                    frameBackWhite.imageSource = ""
                    frameBackIR.imageSource = ""
                    frameBackUV.imageSource = ""

                    // 调用C++后端的采集函数
                    backend.startScan()

                    resultsFrame.visible=false
                }
                background: Rectangle{
                    color:parent.down?"#16a085":"#1abc9c"
                    radius:5
                }
            }

            Button{
                id:processButton
                Layout.preferredWidth: 120
                Layout.preferredHeight: 50
                text:" 处理并识别"
                enabled:false //采集完后才能用
                icon.source: "/icons/zap.svg"
                onClicked:{
                    //处理逻辑
                    backend.processAndRecognize()
                }
                background: Rectangle{
                    color:parent.down?"#16a085":"#1abc9c"
                    radius:5
                }
            }
        }
    }
}
