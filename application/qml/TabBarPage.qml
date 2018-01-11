import QtQuick 2.6
import QtQuick.Controls 2.0

Page {
    id: page

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: taskBar.index
        onCurrentIndexChanged: {
            taskBar.currentIndex = currentIndex
        }


        VSearchDevice{
            id: searchble
        }
        VUser{
            id: user
        }
        VSetting{
            id: setting
        }

    }

//    footer: TabBar {
//        id: tabBar
//        height: 300
//        currentIndex: swipeView.currentIndex

//        TabButton {
//            text: "Setting"
//        }
//        TabButton {
//            text: "User"
//        }
//    }
    ListModel{
        id: controls
        ListElement{
            name: "Home"
            pixmap:  "qrc:/images/images/search.png"
            pixmapfocus:  "qrc:/images/images/search.png"
            stateId: "Home"
        }
        ListElement{
            name: "RGB Control"
            pixmap:  "qrc:/images/images/user.png"
            pixmapfocus:  "qrc:/images/images/user.png"
            stateId: "RGB Control"
        }
        ListElement{
            name: "RGB Control"
            pixmap:  "qrc:/images/images/setting.png"
            pixmapfocus:  "qrc:/images/images/setting.png"
            stateId: "RGB Control"
        }

    }
    ETaskBar{
        id: taskBar
        anchors.bottom: parent.bottom;
        z: 100
        controlModel: controls
        currentIndex: swipeView.currentIndex
        onIndexChaged:{
            swipeView.currentIndex = _index
        }
    }

}
