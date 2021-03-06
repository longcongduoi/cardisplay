import QtQuick 2.0

Rectangle {
    id: root
    width: 120 *size_width
    height: 170 *size_height
    color: "transparent"//"#2962FF"
    property string ble_address: ""
    property int port_index: 0
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
//        highlightMoveDuration: 0
        highlightFollowsCurrentItem: false
        focus: true
//        snapMode: ListView.SnapToItem
        model: blename
        delegate: Rectangle {
            height: 80 *size_height
            width: parent.width
            color: "transparent"
            MouseArea {
                anchors.fill: parent;
                onClicked: {
                    view.currentIndex = index;
                    ble_address = address
                    port_index = index

                }
            }

            VTextStyle {
                id: stockNameText
                width: parent.width
                height: 35 *size_height
                color: "#2196F3"
                font.family: "Open Sans"
                font.pixelSize: 20 *size_scale
                font.bold: false
                elide: Text.ElideRight
                maximumLineCount: 1
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.top: parent.top; anchors.topMargin: 5*size_height
                text: name
            }
            VTextStyle {
                id: stockAddressText
                anchors.top: stockNameText.bottom
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
                text: address
            }
            Rectangle {
                id: endingLine
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                height: 1.5 *size_height
                width: parent.width
                color: "#757575"
            }
        }

        highlight:  Rectangle {
                width: view.currentItem.width; height: view.currentItem.height
                color: "#FFA726"; radius: 5
                y: view.currentItem.y
                Behavior on y {
                    SpringAnimation {
                        spring: 2
                        damping: 0.2
                    }
                }
            }
    }

    Behavior on height{
        NumberAnimation { duration: 200 }
    }


}

