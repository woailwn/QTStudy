#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QQmlEngine>
#include <QTimer>
#include <QDebug>
#include <QThread>
#include "cameraworker.h"
#include "imageprovider.h"
class Backend : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit Backend(ImageProvider* provider,QObject *parent = nullptr);
    ~Backend();
    Q_INVOKABLE void startScan(); //可以在QML被调用
    Q_INVOKABLE void processAndRecognize();
    Q_INVOKABLE void setContrast(double contrast);
    Q_INVOKABLE void setBrightness(int brightness);
signals:
    //扫描进度改变 (当前步骤，提示信息)
    void scanProgressChanged(int step,const QString & message);
    //信号已经被采集 (图像资源路径，相框索引)
    void newImageCaptured(const QString& imagePath,int frameIndex);
    //识别完成 携带结果
    void recognitionComplete(const QVariant& results);

    //安全地启动工作线程的任务
    void startCaptureRequestd();
    //图像参数调整信号
    void contrastChanged(double contrast);
    void brightnessChanged(int brightness);
private:
    //从worker接收捕获的图像
    void handleCapturedImage(const QImage& image,int frameIndex);

private:
    QThread* m_cameraThread;
    CameraWorker* m_cameraWorker;
    ImageProvider* m_imageProvider;
};

#endif // BACKEND_H
