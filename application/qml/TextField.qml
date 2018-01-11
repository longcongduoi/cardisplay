import QtQuick 2.0
import "."

Item {
    id: control
//    implicitWidth: input.contentWidth
//    implicitHeight: Math.max(input.contentHeight + 32, 48)
    width: 350 *size_width
    height: 50 *size_height

    property color focusColor: "#E91E63"

    property alias text: input.text
    property alias hint: placeholder.text
    property alias length: input.length
    property alias maxLength: input.maximumLength

    property alias echoMode: input.echoMode
    property alias color: input.color
    property alias font: input.font

    Text {
        id: placeholder
        anchors.fill: input
        visible: !input.length && !input.inputMethodComposing
        color: "#a0a0a0"
        font.family: "qrc:/images/images/Lato-Medium.ttf"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 25 *size_scale
        font.italic: true

    }

    TextInput {
        id: input
        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
            bottom: divider.top
            topMargin: 16 *size_height
        }
        color: "#de000000"
        selectionColor: "#91a7ff"
        selectedTextColor: color
        font.family: "qrc:/images/images/Lato-Medium.ttf"
        font.pixelSize: 25 *size_scale
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        cursorVisible: true
        maximumLength: 30
        onTextChanged: {
            input.text = text
        }

        Keys.onEnterPressed: {
            //...
            Qt.inputMethod.hide();
        }
        Keys.onReturnPressed: {
            //...
            Qt.inputMethod.hide();
        }
    }

    Rectangle {
        id: divider
        anchors {
            left: parent.left
            right: parent.right
            bottom: parent.bottom
            bottomMargin: 8 *size_height
        }
        height: input.focus ? 2  : 2
        color: input.focus ? control.focusColor : "#9E9E9E"

        Behavior on color {
            ColorAnimation { duration: 200 }
        }
    }
}
