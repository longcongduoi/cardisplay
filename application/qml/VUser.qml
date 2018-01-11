
import QtQuick 2.7
import QtQuick.Controls 2.0
Rectangle{
    color: "white"
    Rectangle{
        id: title
        width: parent.width
        height: 60*size_height
        color: "#2196F3"
        VTextStyle{
            text: "User"
            anchors.centerIn: title
            font.pixelSize: 25*size_scale
            color: "white"
        }
    }

    VListMessage{
        id: listmsg
        width: parent.width
        height: parent.height * 2/3
        anchors.top: title.bottom;
    }
    Rectangle{
        id: line
        color: "#FFA726"
        width: parent.width
        height: 2 *size_height
        anchors.top: listmsg.bottom
    }

//    FlatButton{
//        id: connectbt1
//        anchors.horizontalCenter: parent.horizontalCenter
//        anchors.top: line.bottom; anchors.topMargin: 20 *size_height
//        text: "Remove"
//        radius_button: 8 *size_scale
//        text_size: 25 *size_scale
//        width: 200*size_width
//        onClicked: {
//            listmsg.msgmodel.remove(listmsg.port_index)
//            var list = []
//            for(var i = 0; i< listmsg.msgmodel.count; i++){
//                list[i] = listmsg.msgmodel.get(i).msg;
//            }

//            _bleManager.save_database(list)
//        }
//    }
    Row{
        id: controlbt
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: line.bottom; anchors.topMargin: 20 *size_height
        spacing: 20 *size_width
        FlatButton{
            id: searchbt
            text: "Clear LCD"
            radius_button: 8 *size_scale
            text_size: 25 *size_scale
            width: 200*size_width
            onClicked: {
                _bleManager.setmsg("")
            }
        }
        FlatButton{
            id: connectbt1
            text: "Remove"
            radius_button: 8 *size_scale
            text_size: 25 *size_scale
            width: 200*size_width
            onClicked: {
                listmsg.msgmodel.remove(listmsg.port_index)
                var list = []
                for(var i = 0; i< listmsg.msgmodel.count; i++){
                    list[i] = listmsg.msgmodel.get(i).msg;
                }

                _bleManager.save_database(list)
            }
        }

    }

    Connections{
        target: mainwindows
        onAdd_msg_to_list:{
            listmsg.msgmodel.append({"msg": _msg});
            var list = []
            for(var i = 0; i< listmsg.msgmodel.count; i++){
                list[i] = listmsg.msgmodel.get(i).msg;
            }

            _bleManager.save_database(list)
        }
    }
    Connections{
        target: _bleManager
        onGet_msg:{
            listmsg.msgmodel.append({"msg": msg});
        }
    }


    Timer{
        id: loaddatabase
        interval: 1000
        running: true
        repeat: false
        onTriggered: {
            _bleManager.load_database()
//            _bleManager.power_enable()
        }
    }

}
