#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "blemanager.h"
#include "bleinterface.h"
#include "linkmanager.h"
#include "receiverscan.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <Qt>
#include <jni.h>
#include "linkmanager.h"
#include "receiverscan.h"
#include <QAndroidJniObject>
#include <QDebug>

#ifdef __cplusplus
extern "C" {
#endif
receiverScan m_receiverScan;
JNIEXPORT void JNICALL
    Java_org_qtproject_lamp_MyJavaNatives_sendAdvertiseData(JNIEnv */*env*/, jobject /*obj*/, jstring name,jstring address )
    {
        QAndroidJniObject m_name = name;
        QAndroidJniObject m_address = address;
        m_receiverScan.receiver_data(m_name.toString(), m_address.toString());
    }

#ifdef __cplusplus
}
#endif
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    BLEmanager m_bleManager;
    BLEInterface m_bleInterface;
    QQmlApplicationEngine engine;
    linkManager m_linkmanager;

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    engine.rootContext()->setContextProperty("_bleManager",&m_bleManager);
    engine.rootContext()->setContextProperty("_bleInterface",&m_bleInterface);

    m_linkmanager.linkConnect(&m_receiverScan,&m_bleManager);

    return app.exec();
}
