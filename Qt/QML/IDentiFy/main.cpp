#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QIcon>
#include <QQmlContext>
#include "backend.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    ImageProvider* imageProvider=new ImageProvider();
    Backend backend(imageProvider);
    app.setWindowIcon(QIcon(":/icons/appicon.png"));
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("backend",&backend);
    engine.rootContext()->setContextProperty("livefeed",imageProvider);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    engine.load(QUrl(QStringLiteral("qrc:/Main.qml")));

    return app.exec();
}
