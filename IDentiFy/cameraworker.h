#ifndef CAMERAWORKER_H
#define CAMERAWORKER_H

#include <QObject>
#include <QCamera>
#include <QMediaCaptureSession>
#include <QImageCapture>
#include <QTimer>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
class CameraWorker : public QObject
{
    Q_OBJECT
public:
    explicit CameraWorker(QObject *parent = nullptr);
    ~CameraWorker();
signals:
    //通知UI更新
    void progressUpdated(int step,const QString& message);
    //一张图片捕获完毕
    void imageCaptured(const QImage& image,int frameIndex);
    //全部采集完毕
    void captureFinished();
    //错误
    void errorOccurred(const QString& errorMessage);

public slots:
    //从backend接收开始采集的指令
    void startCapture();
    //接收调节参数的槽
    void setContrast(double contrast);
    void setBrightness(int brightness);

private slots:
    //当QImageCapture 捕获到 一帧图像被调用
    void processCapturedImage(int requestId,const QImage& img);
    //用于触发下一次拍照的定时器
    void triggerNextCapture();
private:
    QCamera* m_camera=nullptr;
    QMediaCaptureSession* m_captureSession=nullptr;
    QImageCapture* m_imageCapture=nullptr;

    int m_captureStep;
    const int m_totalSteps=6;
    double m_contrast=1.0;
    int m_brightness=0;
};

#endif // CAMERAWORKER_H
