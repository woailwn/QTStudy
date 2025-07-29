#ifndef GETALBUMING_H
#define GETALBUMING_H

#include <QObject>
#include <QQmlEngine>
#include <QMediaPlayer>
#include <QFile>
#include <QDir>
#include <QImage>
#include <QAudioOutput>
#include <QMediaMetaData>
#include <QStandardPaths>
#include <QCoreApplication>
#include <QGuiApplication>
#include <QTimer>
class GetAlbuming : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit GetAlbuming(QObject *parent = nullptr);
    Q_INVOKABLE QString getAlbumArt()
    {
        // qDebug()<<"返回专辑封面地址！！！"<<albumArtUrl;
        return albumArtUrl;
    }

    Q_INVOKABLE void loadMedia(QString filePath)
    {
        qDebug()<<"打开专辑！！！"<<filePath;

        player->setSource(filePath);
    }

private slots:
    void onMediaStatusChanged(QMediaPlayer::MediaStatus status) {
        qDebug() << status;
        if (status == QMediaPlayer::LoadedMedia) {
            qDebug() << "媒体已加载，准备读取封面";
            QTimer::singleShot(300, this, [this]() {
                auto metaData = player->metaData();
                qDebug() << "MetaData keys:" << metaData.keys();
                albumArt = metaData.value(QMediaMetaData::CoverArtImage).value<QImage>();

                if (!albumArt.isNull()) {
                    QString tempDir = QStandardPaths::writableLocation(QStandardPaths::TempLocation);
                    QString filePath = QDir(tempDir).filePath("album_art.png");
                    albumArt.save(filePath);
                    albumArtUrl = QUrl::fromLocalFile(filePath).toString();
                } else {
                    albumArtUrl = "";
                }
                qDebug() << "封面图读取完成：" << albumArtUrl;
            });
        }
    }

signals:

private:
    QMediaPlayer* player;
    QImage albumArt;
    QAudioOutput* audioOutput;
    QString albumArtUrl;
};

#endif // GETALBUMING_H
