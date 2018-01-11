import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Window 2.2
import "qml"

ApplicationWindow {
    id: mainwindows
    visible: true
    width: 480
    height: 720
    title: qsTr("Matrix")
    property int total_ticket: 0
//    property double size_width  : 1
//    property double size_height  : 1
//    property double size_scale: 1
    property double size_width  : Screen.desktopAvailableWidth/480
    property double size_height  : Screen.desktopAvailableHeight/720
    property double size_scale: (size_width + size_height) / 2

    signal add_msg_to_list(string _msg)
    TabBarPage{
        anchors.fill: parent
    }
    Connections{
        target: _bleManager
        onValue_light:{
            total_ticket = _value
        }
    }
}
