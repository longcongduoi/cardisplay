import QtQuick 2.0

Item {
    id: button
    width: 26 *size_height
    height: 26 *size_height

    property alias rippleColor: ripple.color
    property alias iconSource: icon.source
    property int size_image: 16 *size_height

    signal clicked

    PaperRipple {
        id: ripple
        anchors {
            fill: undefined
            centerIn: parent
        }
        width: parent.width
        height: parent.height
        radius: width / 2
        mouseArea: mouseArea
    }

    Image {
        id: icon
        anchors.centerIn: parent
        width: size_image
        height: size_image
        sourceSize.width: size_image
        sourceSize.height: size_image
        opacity: button.enabled ? 1 : 0.62

        Behavior on opacity {
            NumberAnimation {
                duration: 200
                easing.type: Easing.Bezier; easing.bezierCurve: [0.4, 0, 0.2, 1, 1, 1]
            }
        }
    }

    MouseArea {
        id: mouseArea
        anchors.fill: ripple
        enabled: button.enabled
        onClicked: button.clicked()
    }
}
