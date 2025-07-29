import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Dialogs
import QtMultimedia
import SendData
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("ZhyMusic")

    //主界面
    Rectangle
    {
        id:play_area
        anchors.fill: parent
        anchors.topMargin: 420
        color:"lightgray"
        radius:8
        gradient:Gradient{
            stops:[
                GradientStop {position:0.0 ;color:"lightgray"},
                GradientStop {position:1.0 ;color:"black"}
            ]
        }

        //内部矩形，上面操作是为了实现边框的渐变
        Rectangle{
            anchors.fill: parent
            color:"white"
            radius:8
            anchors.topMargin: 2
            anchors.rightMargin: 2
            anchors.leftMargin: 2
            anchors.bottomMargin: 2
        }

        //音量调节
        Item{
            visible:true
            width:30
            height:30
            z:2
            anchors.right: parent.right
            anchors.rightMargin: 50
            anchors.verticalCenter: parent.verticalCenter


            Rectangle{
                anchors.fill: parent
                radius:5
                color:"white"
                border.color:"lightgray"
                border.width: 2

                Image{
                    id:ico

                    source:"qrc:/voice.png"
                    width:25
                    height:25
                    anchors.centerIn: parent
                    fillMode:Image.PreserveAspectFit
                }

                // property bool sliderVisble: false

                MouseArea{
                    anchors.fill: parent
                    hoverEnabled: true
                    onEntered: {
                        voice_rect.visible=true
                        // voice_rect.sliderVisble=true

                    }
                    onExited: {
                        timeout.start()
                    }
                }

                Timer{
                    id:timeout
                    interval: 500
                    repeat:false
                    onTriggered: {
                        if(!volume_slider.containMouse){
                            voice_rect.visible=false
                        }
                    }
                }

                Rectangle{
                    id:voice_rect
                    visible:false
                    width:100
                    height:25
                    color:"white"
                    border.color:"lightgray"
                    border.width:2
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.bottom: parent.top
                    anchors.bottomMargin: 5
                    radius:5

                    Slider{
                        id:volume_slider
                        value:0.1
                        anchors.centerIn: parent
                        property bool containMouse: false

                        // orientation: Qt.Vertical

                        MouseArea{
                            anchors.fill: parent
                            hoverEnabled: true
                            drag.target: parent
                            propagateComposedEvents: true //鼠标事件传给底层节点

                            onEntered: {
                                voice_rect.visible=true //鼠标进入滑动条区域时保持外部矩形框可见
                                timeout.stop();
                            }
                            onExited: {
                                timeout.start();
                            }
                            onPressed: (mouse)=>{
                                           mouse.accepted=false; //鼠标按住才穿透
                                       }
                        }

                        background: Rectangle{
                            x:volume_slider.leftPadding
                            y:volume_slider.topPadding + volume_slider.availableHeight/2-height/2
                            height:4
                            radius:2
                            color: "#bdbebf"
                            width:volume_slider.width
                            Rectangle {
                                width: volume_slider.visualPosition * parent.width
                                height: parent.height
                                color: "#21be2b"
                                radius: 2
                            }
                        }

                        handle:Rectangle{
                            x:volume_slider.leftPadding+volume_slider.visualPosition*(volume_slider.availableWidth-width)
                            y:volume_slider.topPadding + volume_slider.availableHeight/2-height/2
                            implicitHeight: 10
                            implicitWidth: 10
                            radius:5
                            color: volume_slider.pressed ? "#f0f0f0" : "#f6f6f6"
                            border.color: "#bdbebf"
                        }

                        onValueChanged: {
                            SendData.setVolume_value(value);
                            mediaplay.sound_volume=value;
                        }
                    }
                }
            }
        }


        //中心按钮区域
        Rectangle{
            id:play_Center_area
            anchors.fill: parent
            anchors.leftMargin: 250
            anchors.rightMargin: 250
            anchors.topMargin: 5
            anchors.bottomMargin:5
            color:"white"
            //播放按钮
            Rectangle{
                id:play_button
                width:40
                height:40
                radius:20
                color:"#39CCCC"
                anchors.centerIn: parent
                border.width: 2
                border.color:"lightgray"
                ColorAnimation on color{
                    id:play_button_color
                    duration:200
                }

                MouseArea{
                    anchors.fill:parent
                    hoverEnabled: true
                    onEntered:{
                        play_button_color.stop()
                        play_button_color.to="#0074D9"
                        play_button_color.start()
                    }
                    onExited:{
                        play_button_color.stop()
                        play_button_color.to="#39CCCC"
                        play_button_color.start()
                    }
                    onClicked:{
                        if(iconItem.isPlaying){
                            mediaplay.pause();
                            iconItem.isPlaying=!iconItem.isPlaying
                        }else{
                            mediaplay.play();
                            iconItem.isPlaying=!iconItem.isPlaying
                        }
                    }
                }
                //播放图形
                Item{
                    id:iconItem
                    anchors.fill:parent
                    property bool isPlaying: false
                    //anchors.centerIn:parent
                    Canvas{
                        visible:!parent.isPlaying
                        width:20
                        height:20
                        anchors.centerIn:parent
                        onPaint:{
                            var ctx=getContext("2d");
                            ctx.beginPath();
                            ctx.moveTo(5,0);
                            ctx.lineTo(20, 10);
                            ctx.lineTo(5, 20);
                            ctx.closePath();
                            ctx.fillStyle = "white";
                            ctx.fill();
                        }

                    }

                }
                //暂停图形
                Item {
                    id: pauseIcon
                    visible: iconItem.isPlaying
                    width: 18; height: 18
                    anchors.centerIn: parent

                    Rectangle {
                        width: 4
                        height: 18
                        color: "white"
                        anchors.left: parent.left
                        anchors.verticalCenter: parent.verticalCenter
                    }

                    Rectangle {
                        width: 4
                        height: 18
                        color: "white"
                        anchors.right: parent.right
                        anchors.verticalCenter: parent.verticalCenter
                    }
                }
            }

            //上一首
            Rectangle{
                id:last_button
                width:40
                height:40
                radius:20
                color:"white"
                border.width:2
                border.color:"lightgray"
                //anchors.centerIn:parent
                anchors.verticalCenter:parent.verticalCenter
                anchors.rightMargin:8
                anchors.right:play_button.left
                ColorAnimation on color{
                    id:last_button_color
                    duration:200
                }
                MouseArea{
                    anchors.fill:parent
                    hoverEnabled: true
                    onEntered:{
                        //console.log("1")
                        last_button_color.stop()
                        last_button_color.to="#A9A9A9"
                        last_button_color.start()
                    }
                    onExited:{
                        //console.log("0")
                        last_button_color.stop()
                        last_button_color.to="white"
                        last_button_color.start()
                    }
                }
                //上一首图形
                Item{
                    scale:-1
                    id:iconItem3
                    anchors.fill:parent
                    property bool isPlaying: false
                    //anchors.centerIn:parent
                    Canvas{

                        width:20
                        height:20
                        anchors.verticalCenter:parent.verticalCenter
                        anchors.horizontalCenter:parent.horizontalCenter
                        anchors.horizontalCenterOffset:-2
                        onPaint:{
                            var ctx=getContext("2d");
                            ctx.beginPath();
                            ctx.moveTo(5,0);
                            ctx.lineTo(20, 10);
                            ctx.lineTo(5, 20);
                            ctx.closePath();
                            ctx.fillStyle = "lightgray";
                            ctx.fill();

                        }

                    }
                    Rectangle{
                        height:18
                        width:4
                        color:"lightgray"
                        anchors.horizontalCenter:parent.horizontalCenter
                        anchors.horizontalCenterOffset:6
                        anchors.verticalCenter:parent.verticalCenter
                    }

                }
            }
            //下一首
            Rectangle{
                id:next_button
                width:40
                height:40
                radius:20
                color:"white"
                border.width:2
                border.color:"lightgray"
                //anchors.centerIn:parent
                anchors.verticalCenter:parent.verticalCenter
                anchors.leftMargin:8
                anchors.left:play_button.right
                ColorAnimation on color{
                    id:next_button_color
                    duration:200
                }
                MouseArea{
                    anchors.fill:parent
                    hoverEnabled: true
                    onEntered:{
                        //console.log("1")
                        next_button_color.stop()
                        next_button_color.to="#A9A9A9"
                        next_button_color.start()
                    }
                    onExited:{
                        //console.log("0")
                        next_button_color.stop()
                        next_button_color.to="white"
                        next_button_color.start()
                    }

                }
                //下一首图形
                Item{
                    id:iconItem2
                    anchors.fill:parent
                    property bool isPlaying: false
                    //anchors.centerIn:parent
                    Canvas{

                        width:20
                        height:20
                        anchors.verticalCenter:parent.verticalCenter
                        anchors.horizontalCenter:parent.horizontalCenter
                        anchors.horizontalCenterOffset:-2
                        onPaint:{
                            var ctx=getContext("2d");
                            ctx.beginPath();
                            ctx.moveTo(5,0);
                            ctx.lineTo(20, 10);
                            ctx.lineTo(5, 20);
                            ctx.closePath();
                            ctx.fillStyle = "lightgray";
                            ctx.fill();

                        }

                    }
                    Rectangle{
                        height:18
                        width:4
                        color:"lightgray"
                        anchors.horizontalCenter:parent.horizontalCenter
                        anchors.horizontalCenterOffset:6
                        anchors.verticalCenter:parent.verticalCenter
                    }
                }
            }
        }


        //进度条的实现
        Rectangle{
            width:parent.width-12
            height:4
            radius:2
            color:"green"
            z:1
            anchors.horizontalCenter:parent.horizontalCenter
            anchors.top:parent.top
            Slider{
                anchors.centerIn:parent
                width:parent.width
                height:4
                id:duration_slider
                property bool isIn: false
                value:0
                background:Rectangle{
                    id:duration_slider_b
                    anchors.centerIn:parent
                    width:parent.width
                    height:6
                    radius:2
                    color:"gray"
                    Rectangle{
                        width:duration_slider.visualPosition*parent.width
                        height:parent.height
                        color:"red"
                        radius:2
                    }
                }
                handle:Rectangle{

                }
                onPressedChanged:{
                    isIn=!isIn
                }



                MouseArea{
                    id:durition_slider_c
                    anchors.fill:parent
                    hoverEnabled:true
                    onEntered:{
                        duration_slider_b.height=6
                    }
                    onExited:{
                        duration_slider_b.height=2
                    }

                    onPressed:(mouse)=>{
                                  mouse.accepted=false
                              }
                    onReleased:(mouse)=>{
                               }
                }
                onValueChanged:{
                    if(isIn){
                        mediaplay.position=value*mediaplay._duration
                    }
                }
            }
        }
    }

    Connections{
        target: ReadData
        function onvolume_valueChanged()
        {
            console.log("音量改变")
        }
    }

    Item{
        Timer{
            interval: 100
            running:true
            repeat:true
            onTriggered: {
                if(mediaplay.mediaStatus==mediaplay.playing)
                {
                    duration_slider.value=mediaplay.position/mediaplay.last_duration
                }
                if(albumart.source!=mediaPlayer_first.getAlbumArt()){
                    albumart.source=mediaPlayer_first.getAlbumArt()
                    console.log("专辑图片已经改变")
                }/*else{
                    console.log("专辑图片没有改变")
                }*/
            }
        }

        Rectangle{
            MediaPlayer{
                id:mediaplay
                property double sound_volume: 0.1;
                property int _duration: value;

                audioOutput: AudioOutput{
                    volume:mediaplay.sound_volume;
                }

                onMediaStatusChanged: {
                    console.log("Media Status:",mediaplay.mediaStatus);
                    if(mediaplay.mediaStatus==4)
                    {
                        _duration=mediaplay.duration
                    }
                }
            }


            FileDialog{
                id:filedialog
                property string filePath: "null"
                onAccepted:{
                    filePath=selectedFile
                    SendData.filePath=filePath
                    mediaplay.source=filePath
                    albumart.source=""
                    console.log("专辑图片已清空")

                    mediaPlayer_first.loadMedia(filedialog.filePath) //加载音频保存图片
                    console.log(filedialog.filePath)
                }
            }

            Button{
                width:40
                height:20
                text:"打开"
                onClicked:{
                    SendData.bisPlaying=1
                    filedialog.open()
                }
            }
        }
    }

    Rectangle{
        width:200
        height:200
        color:"gray"
        anchors.horizontalCenter:parent.horizontalCenter
        y:110
        Image{
            id:albumart
            width:200
            height:200
            source:mediaPlayer_first.getAlbumArt()
        }
    }

}
