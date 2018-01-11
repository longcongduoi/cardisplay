TEMPLATE = app

QT += quick qml core sql xml bluetooth quickcontrols2 gui charts widgets androidextras multimedia multimediawidgets network
CONFIG += c++11

SOURCES += main.cpp \
    bleinterface.cpp \
    blemanager.cpp \
    linkmanager.cpp \
    receiverscan.cpp \
    gDataBase.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    bleinterface.h \
    lib-qt-qml-tricks/src/qqmlhelpers.h \
    blemanager.h \
    linkmanager.h \
    receiverscan.h \
    gDataBase.h

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat \
    android/src/org/qtproject/lamp/AdvertiserService.java \
    android/src/org/qtproject/lamp/BluetoothLeService.java \
    android/src/org/qtproject/lamp/BroadcastReceive.java \
    android/src/org/qtproject/lamp/BroadcastSend.java \
    android/src/org/qtproject/lamp/Common.java \
    android/src/org/qtproject/lamp/DeviceScanActivity.java \
    android/src/org/qtproject/lamp/MainActivity.java \
    android/src/org/qtproject/lamp/NotificationClient.java \
    android/src/org/qtproject/lamp/ScanAdvertiser.java \
    android/src/org/qtproject/lamp/User.java

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
