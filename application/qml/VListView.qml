import QtQuick 2.0

Rectangle {
    id: root
    width: 120 *size_width
    height: 170 *size_height
    color: "#96E040FB"//"#2962FF"
    property string ble_name: "ALL"
    property int vng_index: 0
    property alias blemodel: view.model

    MouseArea{
        anchors.fill: parent

    }
    ListModel {
        id: blename
    }
    ListView {
        id: view
        width: parent.width
        height: parent.height
        clip: true
        keyNavigationWraps: true
        highlightMoveDuration: 0
        focus: true
        snapMode: ListView.SnapToItem
        model: blename
        delegate: Rectangle {
            height: 40 *size_height
            width: parent.width
            color: "transparent"
            MouseArea {
                anchors.fill: parent;
                onClicked: {
                    view.currentIndex = index;
                    ble_name = name
                    vng_index = index
                }
            }

            VTextStyle {
                id: stockNameText
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                width: parent.width
                height: 40 *size_height
                color: "#2196F3"
                font.family: "Open Sans"
                font.pixelSize: 20 *size_scale
                font.bold: false
                elide: Text.ElideRight
                maximumLineCount: 1
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                text: name
            }
            Rectangle {
                id: endingLine
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                height: 1 *size_height
                width: parent.width
                color: "#d7d7d7"
            }
        }

        highlight: Rectangle {
//            width: parent.width
            color: "#F06292"
        }
    }

    Behavior on height{
        NumberAnimation { duration: 200 }
    }


}

