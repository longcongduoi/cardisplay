import QtQuick 2.0

Item {
    id: root
    property bool connect_status: false
    property bool search_status: false
    Rectangle{
        id: title
        width: parent.width
        height: 60*size_height
        color: "#2196F3"
        VTextStyle{
            text: "Search"
            anchors.centerIn: title
            font.pixelSize: 25*size_scale
            color: "white"
        }
    }
    VListDevice{
        id: listble
        width: parent.width
        height: parent.height*2/3
        anchors.top: title.bottom;
    }
    Rectangle{
        id: line
        color: "#FFA726"
        width: parent.width
        height: 2 *size_height
        anchors.top: listble.bottom
    }

    Row{
        id: connectbt
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: line.bottom; anchors.topMargin: 20 *size_height
        spacing: 20 *size_width
        FlatButton{
            id: searchbt
            radius_button: 8 *size_scale
            text: "Search"
            text_size: 25 *size_scale
            width: 200*size_width
            onClicked: {
                searchbt.text = "Searching"
                search_status = true
                if(search_status) listble.blemodel.clear()

//                _bleManager.scan_device()
//                timersearch.running =  true
                timerstop.running = false
                timerstop.running = true
                _bleManager.scanBLE(search_status)

            }
        }
        FlatButton{
            id: connectbt1
            text: connect_status? "Disconnect":"Connect"
            text_size: 25 *size_scale
            radius_button: 8 *size_scale
            width: 200*size_width
            onClicked: {
                if(!connect_status){
                    if(search_status){
                        timerstop.running = false
                        search_status = false
                        _bleManager.scanBLE(search_status)
                        searchbt.text = "Search"
                    }
                    _bleManager.connect_to_device(listble.ble_address)
                }
                else _bleManager.disconnectDevice()
//                _bleInterface.connectCurrentDevice(listble.ble_address)
            }
        }

    }
    Timer{
        id: timerstop
        running: false
        interval: 10000
        repeat: false
        onTriggered: {
            search_status = false
            _bleManager.scanBLE(search_status)
            searchbt.text = "Search"
        }
    }

    Timer{
        id: timersearch
        running: false
        interval: 500
        repeat: true
        triggeredOnStart: true
        onTriggered: {
            searchbt.text = searchbt.text + " .";
            if(searchbt.text == "Searching . . . .") searchbt.text = "Searching"
        }
    }

    Connections{
        target: _bleManager
        onClear_list_device:{
            listble.blemodel.clear();
        }

        onBle_name:{
            var count = 0;
            for(var i = 0; i < listble.blemodel.count; i++){
                if(listble.blemodel.get(i).address === _add){
                    count ++;
                }
            }
            if(count == 0) listble.blemodel.append({"name":_name ,"address": _add})

        }
        onDevice_connect:{
            connect_status = _status


        }
    }
    Connections{
        target: _bleInterface
        onScanblefinnish:{
            timersearch.running = false
            searchbt.text = "Search"
        }
    }
    Component.onCompleted: {
//        listble.blemodel.clear()
//        _bleManager.scan_device()
//        timersearch.running =  true
//        timerstop.running = true
    }


}
