#ifndef IMAGEPROVIDER_H
#define IMAGEPROVIDER_H

#include <QObject>
#include <QImage>
#include <QHash>
#include <QQuickImageProvider>

//这个类的作用:根据url提供QImage数据给 QML
class ImageProvider : public QQuickImageProvider
{
public:
    explicit ImageProvider();

    //给QML 请求用的
    QImage requestImage(const QString& id,QSize* size,const QSize& requestedSize) override;

    //从C++端更新图片
    void updateImage(const QString& id,const QImage& image);

private:
    //ID-图片
    QHash<QString,QImage> m_images;
};

#endif // IMAGEPROVIDER_H
