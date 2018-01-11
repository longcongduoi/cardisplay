import QtQuick 2.0
//import QtQuick.Controls 2.0
Rectangle{
//    anchors.fill: parent
    color: "white"
    property int ticket: 1
    Rectangle{
        id: title
        width: parent.width
        height: 60*size_height
        color: "#2196F3"
        VTextStyle{
            text: "Setting"
            anchors.centerIn: title
            font.pixelSize: 25*size_scale
            color: "white"
        }
    }
    TextField{
        id: textinput
//        hint: "input message"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset:  - 80 *size_height
        
       
    }
    Row{
        id: connectbt
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: textinput.bottom; anchors.topMargin: 40 *size_height
        spacing: 20 *size_width
        FlatButton{
            id: searchbt
            text: "Add to list"
            radius_button: 8 *size_scale
            text_size: 25 *size_scale
            width: 200*size_width
            onClicked: {
                add_msg_to_list(textinput.text)
            }
        }
        FlatButton{
            id: connectbt1
            text: "Set Message"
            radius_button: 8 *size_scale
            text_size: 25 *size_scale
            width: 200*size_width
            onClicked: {
                _bleManager.setmsg(textinput.text)
            }
        }

    }


}
