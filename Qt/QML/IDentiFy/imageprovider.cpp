#include "imageprovider.h"

ImageProvider::ImageProvider():QQuickImageProvider(QQuickImageProvider::Image)
{

}

QImage ImageProvider::requestImage(const QString &id, QSize *size, const QSize &requestedSize)
{
    if(m_images.contains(id))
    {
        QImage img=m_images.value(id);
        if(size)
        {
            *size=img.size();
        }
        return img;
    }
    return QImage();
}

void ImageProvider::updateImage(const QString &id, const QImage &image)
{
    m_images.insert(id,image);
}
