import QtQuick 2.0

Image {
    id: taskBar

    property alias controlModel: controlView.model
    property alias currentIndex: controlView.currentIndex
    property int index
    signal indexChaged(int _index)

    height: 70 *size_height; width: 480 *size_width
    Component {
        id: highlight
        Item {
            width: taskBar.width / 3; height: 50 *size_height
//            Image {
//                id: highlightRect
//                 width: taskBar.width / 3; height: 80
//                 source: "qrc:/images/images/hover_general_button.png"
//            }
            Rectangle {
                id: highlightRect
                 width: taskBar.width / 3; height: 70 *size_height
                 color: "#2962FF"
            }
        }
    }
    Component {
        id: taskDelegate
        Item
        {
            id: delegate
            width: taskBar.width / 3; height: 70 *size_height
            Rectangle {
                id: borderIamge
                color: "#64425f80"
//                source:""//"qrc:/images/images/normal_general_button.png"
                width: taskBar.width / 3; height: 70 *size_height
//                border.left: 0; border.top: 0
//                border.right: 0; border.bottom: 0
//                asynchronous: true
                Image {
                    width: 45*size_scale ;  height: 45 *size_scale
                    asynchronous: true
                    anchors.centerIn: parent
                    source: delegate.ListView.isCurrentItem? pixmapfocus:pixmap
                }
            }
            VTextStyle {
                text: name
                color: "blue"
                verticalAlignment: Text.AlignBottom; horizontalAlignment: Text.AlignHCenter
                anchors.top: borderIamge.bottom; anchors.topMargin: 5 *size_height
                anchors.horizontalCenter: borderIamge.horizontalCenter
            }
            MouseArea {
                anchors.fill: parent;
                onClicked: {
                    delegate.ListView.view.currentIndex = index;
//                    control_selected_index = index
                    delegate.ListView.view.clicked(stateId) }
            }
        }
    }


    ListView {
        id: controlView
        signal clicked( string stateId )
        width: parent.width
        height: parent.height; anchors.horizontalCenter: parent.horizontalCenter;
        anchors.verticalCenter: parent.verticalCenter;
        spacing: 0
        orientation: ListView.Horizontal
        delegate: taskDelegate
        highlight: highlight
        highlightMoveDuration: 200
        highlightFollowsCurrentItem: true
        focus: true
        clip: true
        onClicked: {
            indexChaged(currentIndex)
            index = currentIndex
        }
    }


}

