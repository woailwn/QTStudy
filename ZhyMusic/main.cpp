#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDir>
#include "getalbuming.h"
#include "readdata.h"
#include <QtQml>
#include <QUrl>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    // QDir dir(":/");
    // qDebug() << "资源中内容:";
    // for (auto const& s : dir.entryList()) {
    //     qDebug() << s;
    // }

    ReadData readData;
    GetAlbuming getAlbum;
    //两种方法注册这个类
    qmlRegisterSingletonInstance<ReadData> ("SendData",1,0,"ReadData",ReadData::getInstance());
    qmlRegisterType<ReadData>("SendData",1,0,"ReadData");

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.rootContext()->setContextProperty("SendData",&readData);
    engine.rootContext()->setContextProperty("mediaPlayer_first",&getAlbum);

    engine.load(QUrl(QStringLiteral("qrc:/Main.qml")));
    return app.exec();
}
