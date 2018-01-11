import QtQuick 2.0
import "."

Item {
    id: button
    width: 170*size_width // 130
    height: 60 *size_height //50

    property bool inline: false
    property alias text: label.text
    property alias textColor: label.color
    property alias backgroundColor: background.color
    property int text_size: 20 *size_scale
    property bool text_anchor: false
    property string font_text: "qrc:/images/images/Lato-Medium.ttf"
    property int radius_button: 0

    signal clicked
    signal released
    signal pressed

    Rectangle {
        id: background
        anchors.fill: parent
        radius: radius_button//parent.width/2
        color: "#2196F3"//button.enabled ? "#00999999" : "#1a999999"
    }


    Text {
        id: label
//        anchors.left: parent.left;
        font.family: "Arial"
        font.pixelSize: text_size
        horizontalAlignment:text_anchor? Text.AlignLeft: Text.AlignHCenter
        width: parent.width
        color:  "white"//button.enabled ? "#de000000": "#8a000000"
        opacity: button.enabled ? 1 : 0.62
        verticalAlignment: Text.AlignVCenter
        anchors.verticalCenter: parent.verticalCenter
        Behavior on opacity {
            NumberAnimation {
                duration: 200
                easing.type: Easing.Bezier; easing.bezierCurve: [0.4, 0, 0.2, 1, 1, 1]
            }
        }
    }

    PaperRipple {
        id: ripple
        radius: radius_button//parent.width/2
        mouseArea: mouseArea
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        enabled: button.enabled
        onClicked: button.clicked()
//        onPressed: button.pressed()
//        onReleased: button.released()
    }
}
