#include "backend.h"
Backend::Backend(ImageProvider* provider,QObject *parent)
    : QObject{parent}
{
    m_cameraThread=new QThread(this);
    m_cameraWorker=new CameraWorker();
    m_cameraWorker->moveToThread(m_cameraThread);

    //backend请求->Worker执行
    connect(this,&Backend::startCaptureRequestd,m_cameraWorker,&CameraWorker::startCapture);

    //worker->backend槽->backend信号->QML
    connect(m_cameraWorker,&CameraWorker::progressUpdated,this,&Backend::scanProgressChanged);
    connect(m_cameraWorker,&CameraWorker::imageCaptured,this,&Backend::handleCapturedImage);
    connect(m_cameraWorker,&CameraWorker::captureFinished,[this](){

    });
    connect(m_cameraWorker,&CameraWorker::errorOccurred,this,[this](const QString& msg)
    {
        emit scanProgressChanged(0,msg); //错误显示
    });

    //线程退出，删除worker
    connect(m_cameraThread,&QThread::finished,m_cameraWorker,&QObject::deleteLater);

    //图像参数设置连接
    connect(this, &Backend::contrastChanged, m_cameraWorker, &CameraWorker::setContrast);
    connect(this, &Backend::brightnessChanged, m_cameraWorker, &CameraWorker::setBrightness);
    m_cameraThread->start();
}

Backend::~Backend()
{
    m_cameraThread->quit();
    m_cameraThread->wait();
}

void Backend::startScan()
{
    emit startCaptureRequestd();
}

void Backend::processAndRecognize()
{
    emit scanProgressChanged(8,"正在处理和识别图像...");

    QTimer::singleShot(2000,this,[this]()
    {
        //模拟网络处理，创建模拟的识别结果
        QVariantMap results;
        results["name"] = "张三 (ZHANG, SAN)";
        results["gender"] = "男 / M";
        results["birthDate"] = "1990.01.01";
        results["idNumber"] = "G12345678";
        results["nationality"] = "中国 / CHN";
        results["validUntil"] = "2030.01.01";
        results["confidence"] = "98.7%";

        emit recognitionComplete(results);
        emit scanProgressChanged(9,"识别完成");
    });
}

void Backend::handleCapturedImage(const QImage &image, int frameIndex)
{
    QString imageId=QString("capture_%1").arg(frameIndex);
    m_imageProvider->updateImage(imageId,image);
    QString imageUrl=QString("image://livefeed/%1").arg(imageId);
    emit newImageCaptured(imageUrl,frameIndex);
}

//对比对设置函数
void Backend::setContrast(double contrast)
{
    emit contrastChanged(contrast);
}

//亮度设置函数
void Backend::setBrightness(int brightness)
{
    emit brightnessChanged(brightness);
}
