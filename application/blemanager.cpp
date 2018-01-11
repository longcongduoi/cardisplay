#include "blemanager.h"

BLEmanager::BLEmanager(QObject *parent) : QObject(parent), localDevice(new QBluetoothLocalDevice)
{
    m_timer = new QTimer(this);
    power_enable();
    m_bleInterface = new BLEInterface(this);
    m_database_manager.database_init();
    m_database_manager.open_database();
//    m_bleInterface->scanDevices();
    connect(m_bleInterface, &BLEInterface::dataReceived,
            this, &BLEmanager::dataReceived);
//    connect(m_bleInterface, &BLEInterface::devicesNamesChanged,
//            [this] (QStringList devices){
//        emit clear_list_device();
//        for(int i=0; i<devices.length();i++){
//            qDebug()<< devices[i];
//            emit ble_name(devices[i]);
//        }
//    });
    connect(m_bleInterface, &BLEInterface::device_found,
            [this] (QStringList devices, QStringList add ){
        emit clear_list_device();
        for(int i=0; i<devices.length();i++){
            qDebug()<< devices[i];
            emit ble_name(devices[i], add[i]);
        }
    });
    connect(m_bleInterface, &BLEInterface::servicesChanged,
            [this] (QStringList services){
//        ui->servicesComboBox->clear();
//        ui->servicesComboBox->addItems(services);
        emit device_connect(true);
        for(int i=0; i<services.length();i++){
            qDebug()<<"server thinh"<< services[i];
        }
    });
    connect(m_bleInterface, &BLEInterface::devivedisconnect,
            [this]{
        emit device_connect(false);
    });
//    connect(m_bleInterface, &BLEInterface::statusInfoChanged,
//            [this](QString info, bool){
////        emit device_connect(bool);
//        qDebug()<<"server thinh xff fdf dfbdfsgdfbdf fgdfgdbdfb";
//    });
    connect(m_timer,SIGNAL(timeout()),this,SLOT(timer_set_service()));
}

void BLEmanager::scan_device()
{
    qDebug() << "scan";
    m_bleInterface->scanDevices();
}

void BLEmanager::disconnectDevice()
{
    m_bleInterface->disconnectDevice();
}

void BLEmanager::connect_to_device(QString _address)
{
//    m_bleInterface->set_currentDevice(_index);
    m_bleInterface->connectCurrentDevice(_address);
//    m_timer->start(1000);
//    m_bleInterface->setCurrentService(2);//service
}

void BLEmanager::send_command_direct_to_device(unsigned char _value)
{
    unsigned char datapass[] = {_value};
    int size = sizeof(datapass);
    m_bleInterface->write(QByteArray((char*)datapass,size));
}

void BLEmanager::send_command_speed_to_device(unsigned char _value)
{
    unsigned char datapass[] = {_value};
    int size = sizeof(datapass);
    m_bleInterface->write(QByteArray((char*)datapass,size));
}

void BLEmanager::vietlott(QString _status)
{

    QByteArray data;
    data = QByteArray(_status.toLatin1());
    m_bleInterface->write(data);
}

void BLEmanager::setmsg(QString _msg)
{
    QString message;
    for(int i = 0; i< _msg.length(); i++){
        QString trans;
        if(_msg[i] == "á") trans = "a1";
        else if(_msg[i] == "à") trans = "a2";
        else if(_msg[i] == "ả") trans = "a3";
        else if(_msg[i] == "ã") trans = "a4";
        else if(_msg[i] == "ạ") trans = "a5";
        else if(_msg[i] == "ă") trans = "a8";
        else if(_msg[i] == "ắ") trans = "a81";
        else if(_msg[i] == "ằ") trans = "a82";
        else if(_msg[i] == "ẳ") trans = "a83";
        else if(_msg[i] == "ẵ") trans = "a84";
        else if(_msg[i] == "ặ") trans = "a85";
        else if(_msg[i] == "â") trans = "a6";
        else if(_msg[i] == "ấ") trans = "a61";
        else if(_msg[i] == "ầ") trans = "a62";
        else if(_msg[i] == "ẩ") trans = "a63";
        else if(_msg[i] == "ẫ") trans = "a64";
        else if(_msg[i] == "ậ") trans = "a65";

        else if(_msg[i] == "Á") trans = "A1";
        else if(_msg[i] == "À") trans = "A2";
        else if(_msg[i] == "Ả") trans = "A3";
        else if(_msg[i] == "Ã") trans = "A4";
        else if(_msg[i] == "Ạ") trans = "A5";
        else if(_msg[i] == "Ă") trans = "A8";
        else if(_msg[i] == "Ắ") trans = "A81";
        else if(_msg[i] == "Ằ") trans = "A82";
        else if(_msg[i] == "Ẳ") trans = "A83";
        else if(_msg[i] == "Ẵ") trans = "A84";
        else if(_msg[i] == "Ặ") trans = "A85";
        else if(_msg[i] == "Â") trans = "A6";
        else if(_msg[i] == "Ấ") trans = "A61";
        else if(_msg[i] == "Ầ") trans = "A62";
        else if(_msg[i] == "Ẩ") trans = "A63";
        else if(_msg[i] == "Ẫ") trans = "A64";
        else if(_msg[i] == "Ậ") trans = "A65";

        else if(_msg[i] == "đ") trans = "d9";
        else if(_msg[i] == "Đ") trans = "D9";

        else if(_msg[i] == "é") trans = "e1";
        else if(_msg[i] == "è") trans = "e2";
        else if(_msg[i] == "ẻ") trans = "e3";
        else if(_msg[i] == "ẽ") trans = "e4";
        else if(_msg[i] == "ẹ") trans = "e5";
        else if(_msg[i] == "É") trans = "E1";
        else if(_msg[i] == "È") trans = "E2";
        else if(_msg[i] == "Ẻ") trans = "E3";
        else if(_msg[i] == "Ẽ") trans = "E4";
        else if(_msg[i] == "Ẹ") trans = "E5";

        else if(_msg[i] == "ê") trans = "e6";
        else if(_msg[i] == "ế") trans = "e61";
        else if(_msg[i] == "ề") trans = "e62";
        else if(_msg[i] == "ể") trans = "e63";
        else if(_msg[i] == "ễ") trans = "e64";
        else if(_msg[i] == "ệ") trans = "e65";
        else if(_msg[i] == "Ê") trans = "E6";
        else if(_msg[i] == "Ế") trans = "E61";
        else if(_msg[i] == "Ề") trans = "E62";
        else if(_msg[i] == "Ể") trans = "E63";
        else if(_msg[i] == "Ễ") trans = "E64";
        else if(_msg[i] == "Ệ") trans = "E65";

        else if(_msg[i] == "í") trans = "i1";
        else if(_msg[i] == "ì") trans = "i2";
        else if(_msg[i] == "ỉ") trans = "i3";
        else if(_msg[i] == "ĩ") trans = "i4";
        else if(_msg[i] == "ị") trans = "i5";
        else if(_msg[i] == "Í") trans = "I1";
        else if(_msg[i] == "Ì") trans = "I2";
        else if(_msg[i] == "Ỉ") trans = "I3";
        else if(_msg[i] == "Ĩ") trans = "I4";
        else if(_msg[i] == "Ị") trans = "I5";

        else if(_msg[i] == "ó") trans = "o1";
        else if(_msg[i] == "ò") trans = "o2";
        else if(_msg[i] == "ỏ") trans = "o3";
        else if(_msg[i] == "õ") trans = "o4";
        else if(_msg[i] == "ọ") trans = "o5";
        else if(_msg[i] == "Ó") trans = "O1";
        else if(_msg[i] == "Ò") trans = "O2";
        else if(_msg[i] == "Ỏ") trans = "O3";
        else if(_msg[i] == "Õ") trans = "O4";
        else if(_msg[i] == "Ọ") trans = "O5";

        else if(_msg[i] == "ô") trans = "o6";
        else if(_msg[i] == "ố") trans = "o61";
        else if(_msg[i] == "ồ") trans = "o62";
        else if(_msg[i] == "ổ") trans = "o63";
        else if(_msg[i] == "ỗ") trans = "o64";
        else if(_msg[i] == "ộ") trans = "o65";
        else if(_msg[i] == "Ô") trans = "O6";
        else if(_msg[i] == "Ố") trans = "O61";
        else if(_msg[i] == "Ồ") trans = "O62";
        else if(_msg[i] == "Ổ") trans = "O63";
        else if(_msg[i] == "Ỗ") trans = "O64";
        else if(_msg[i] == "Ộ") trans = "O65";

        else if(_msg[i] == "ơ") trans = "o7";
        else if(_msg[i] == "ớ") trans = "o71";
        else if(_msg[i] == "ờ") trans = "o72";
        else if(_msg[i] == "ở") trans = "o73";
        else if(_msg[i] == "ỡ") trans = "o74";
        else if(_msg[i] == "ợ") trans = "o75";
        else if(_msg[i] == "Ơ") trans = "O7";
        else if(_msg[i] == "Ớ") trans = "O71";
        else if(_msg[i] == "Ờ") trans = "O72";
        else if(_msg[i] == "Ở") trans = "O73";
        else if(_msg[i] == "Ỡ") trans = "O74";
        else if(_msg[i] == "Ợ") trans = "O75";

        else if(_msg[i] == "ú") trans = "u1";
        else if(_msg[i] == "ù") trans = "u2";
        else if(_msg[i] == "ủ") trans = "u3";
        else if(_msg[i] == "ũ") trans = "u4";
        else if(_msg[i] == "ụ") trans = "u5";
        else if(_msg[i] == "Ú") trans = "U1";
        else if(_msg[i] == "Ủ") trans = "U2";
        else if(_msg[i] == "Ủ") trans = "iU3";
        else if(_msg[i] == "Ũ") trans = "U4";
        else if(_msg[i] == "Ụ") trans = "U5";

        else if(_msg[i] == "ư") trans = "u7";
        else if(_msg[i] == "ứ") trans = "u71";
        else if(_msg[i] == "ừ") trans = "u72";
        else if(_msg[i] == "ử") trans = "u73";
        else if(_msg[i] == "ữ") trans = "u74";
        else if(_msg[i] == "ự") trans = "u75";
        else if(_msg[i] == "Ư") trans = "U7";
        else if(_msg[i] == "Ứ") trans = "U71";
        else if(_msg[i] == "Ừ") trans = "U72";
        else if(_msg[i] == "Ử") trans = "U73";
        else if(_msg[i] == "Ữ") trans = "U74";
        else if(_msg[i] == "Ự") trans = "U75";

        else trans = _msg[i];
//        qDebug() << "transt " << trans;

        message.append(trans);
    }
    QByteArray data;
    data = QByteArray(message.toLatin1());
    m_bleInterface->write(data);
}

void BLEmanager::scanBLE(bool _status)
{
    if(_status){
        QAndroidJniObject::callStaticMethod<void>("org/qtproject/lamp/MainActivity",
                                              "scanNewAdvertise");
    }
    else QAndroidJniObject::callStaticMethod<void>("org/qtproject/lamp/MainActivity",
                                                   "stopScanNewAdvertise");
}

void BLEmanager::save_database(QStringList listsave)
{
    qDebug() << "list save" << listsave.length();
    m_profile_selected_name = "listMsg";
    if(m_database_manager.params_table_init(m_profile_selected_name)){
        m_database_manager.save_one_parameter(0,"",listsave.length());
    }
    int parameter_id = 1;
    for(int i = 0; i < listsave.length(); i++){
        m_database_manager.save_one_parameter(parameter_id, listsave[i],0);
        parameter_id++;
    }
}

void BLEmanager::load_database()
{
    qDebug() << "load database";
    m_profile_selected_name = "listMsg";
    if(m_database_manager.params_table_init(m_profile_selected_name)){
        int counter_group = m_database_manager.get_type_parameter(0);
        for (int k = 1; k < counter_group + 1; k++){
            get_msg(m_database_manager.get_name_parameter(k));
        }
    }
}

void BLEmanager::power_enable()
{
    localDevice->powerOn();
}

int BLEmanager::get_lengh(QString _msg)
{
    QString message;
    for(int i = 0; i< _msg.length(); i++){
        QString trans;
        if(_msg[i] == "á") trans = "a1";
        else if(_msg[i] == "à") trans = "a2";
        else if(_msg[i] == "ả") trans = "a3";
        else if(_msg[i] == "ã") trans = "a4";
        else if(_msg[i] == "ạ") trans = "a5";
        else if(_msg[i] == "ă") trans = "a8";
        else if(_msg[i] == "ắ") trans = "a81";
        else if(_msg[i] == "ằ") trans = "a82";
        else if(_msg[i] == "ẳ") trans = "a83";
        else if(_msg[i] == "ẵ") trans = "a84";
        else if(_msg[i] == "ặ") trans = "a85";
        else if(_msg[i] == "â") trans = "a6";
        else if(_msg[i] == "ấ") trans = "a61";
        else if(_msg[i] == "ầ") trans = "a62";
        else if(_msg[i] == "ẩ") trans = "a63";
        else if(_msg[i] == "ẫ") trans = "a64";
        else if(_msg[i] == "ậ") trans = "a65";

        else if(_msg[i] == "Á") trans = "A1";
        else if(_msg[i] == "À") trans = "A2";
        else if(_msg[i] == "Ả") trans = "A3";
        else if(_msg[i] == "Ã") trans = "A4";
        else if(_msg[i] == "Ạ") trans = "A5";
        else if(_msg[i] == "Ă") trans = "A8";
        else if(_msg[i] == "Ắ") trans = "A81";
        else if(_msg[i] == "Ằ") trans = "A82";
        else if(_msg[i] == "Ẳ") trans = "A83";
        else if(_msg[i] == "Ẵ") trans = "A84";
        else if(_msg[i] == "Ặ") trans = "A85";
        else if(_msg[i] == "Â") trans = "A6";
        else if(_msg[i] == "Ấ") trans = "A61";
        else if(_msg[i] == "Ầ") trans = "A62";
        else if(_msg[i] == "Ẩ") trans = "A63";
        else if(_msg[i] == "Ẫ") trans = "A64";
        else if(_msg[i] == "Ậ") trans = "A65";

        else if(_msg[i] == "đ") trans = "d9";
        else if(_msg[i] == "Đ") trans = "D9";

        else if(_msg[i] == "é") trans = "e1";
        else if(_msg[i] == "è") trans = "e2";
        else if(_msg[i] == "ẻ") trans = "e3";
        else if(_msg[i] == "ẽ") trans = "e4";
        else if(_msg[i] == "ẹ") trans = "e5";
        else if(_msg[i] == "É") trans = "E1";
        else if(_msg[i] == "È") trans = "E2";
        else if(_msg[i] == "Ẻ") trans = "E3";
        else if(_msg[i] == "Ẽ") trans = "E4";
        else if(_msg[i] == "Ẹ") trans = "E5";

        else if(_msg[i] == "ê") trans = "e6";
        else if(_msg[i] == "ế") trans = "e61";
        else if(_msg[i] == "ề") trans = "e62";
        else if(_msg[i] == "ể") trans = "e63";
        else if(_msg[i] == "ễ") trans = "e64";
        else if(_msg[i] == "ệ") trans = "e65";
        else if(_msg[i] == "Ê") trans = "E6";
        else if(_msg[i] == "Ế") trans = "E61";
        else if(_msg[i] == "Ề") trans = "E62";
        else if(_msg[i] == "Ể") trans = "E63";
        else if(_msg[i] == "Ễ") trans = "E64";
        else if(_msg[i] == "Ệ") trans = "E65";

        else if(_msg[i] == "í") trans = "i1";
        else if(_msg[i] == "ì") trans = "i2";
        else if(_msg[i] == "ỉ") trans = "i3";
        else if(_msg[i] == "ĩ") trans = "i4";
        else if(_msg[i] == "ị") trans = "i5";
        else if(_msg[i] == "Í") trans = "I1";
        else if(_msg[i] == "Ì") trans = "I2";
        else if(_msg[i] == "Ỉ") trans = "I3";
        else if(_msg[i] == "Ĩ") trans = "I4";
        else if(_msg[i] == "Ị") trans = "I5";

        else if(_msg[i] == "ó") trans = "o1";
        else if(_msg[i] == "ò") trans = "o2";
        else if(_msg[i] == "ỏ") trans = "o3";
        else if(_msg[i] == "õ") trans = "o4";
        else if(_msg[i] == "ọ") trans = "o5";
        else if(_msg[i] == "Ó") trans = "O1";
        else if(_msg[i] == "Ò") trans = "O2";
        else if(_msg[i] == "Ỏ") trans = "O3";
        else if(_msg[i] == "Õ") trans = "O4";
        else if(_msg[i] == "Ọ") trans = "O5";

        else if(_msg[i] == "ô") trans = "o6";
        else if(_msg[i] == "ố") trans = "o61";
        else if(_msg[i] == "ồ") trans = "o62";
        else if(_msg[i] == "ổ") trans = "o63";
        else if(_msg[i] == "ỗ") trans = "o64";
        else if(_msg[i] == "ộ") trans = "o65";
        else if(_msg[i] == "Ô") trans = "O6";
        else if(_msg[i] == "Ố") trans = "O61";
        else if(_msg[i] == "Ồ") trans = "O62";
        else if(_msg[i] == "Ổ") trans = "O63";
        else if(_msg[i] == "Ỗ") trans = "O64";
        else if(_msg[i] == "Ộ") trans = "O65";

        else if(_msg[i] == "ơ") trans = "o7";
        else if(_msg[i] == "ớ") trans = "o71";
        else if(_msg[i] == "ờ") trans = "o72";
        else if(_msg[i] == "ở") trans = "o73";
        else if(_msg[i] == "ỡ") trans = "o74";
        else if(_msg[i] == "ợ") trans = "o75";
        else if(_msg[i] == "Ơ") trans = "O7";
        else if(_msg[i] == "Ớ") trans = "O71";
        else if(_msg[i] == "Ờ") trans = "O72";
        else if(_msg[i] == "Ở") trans = "O73";
        else if(_msg[i] == "Ỡ") trans = "O74";
        else if(_msg[i] == "Ợ") trans = "O75";

        else if(_msg[i] == "ú") trans = "u1";
        else if(_msg[i] == "ù") trans = "u2";
        else if(_msg[i] == "ủ") trans = "u3";
        else if(_msg[i] == "ũ") trans = "u4";
        else if(_msg[i] == "ụ") trans = "u5";
        else if(_msg[i] == "Ú") trans = "U1";
        else if(_msg[i] == "Ủ") trans = "U2";
        else if(_msg[i] == "Ủ") trans = "iU3";
        else if(_msg[i] == "Ũ") trans = "U4";
        else if(_msg[i] == "Ụ") trans = "U5";

        else if(_msg[i] == "ư") trans = "u7";
        else if(_msg[i] == "ứ") trans = "u71";
        else if(_msg[i] == "ừ") trans = "u72";
        else if(_msg[i] == "ử") trans = "u73";
        else if(_msg[i] == "ữ") trans = "u74";
        else if(_msg[i] == "ự") trans = "u75";
        else if(_msg[i] == "Ư") trans = "U7";
        else if(_msg[i] == "Ứ") trans = "U71";
        else if(_msg[i] == "Ừ") trans = "U72";
        else if(_msg[i] == "Ử") trans = "U73";
        else if(_msg[i] == "Ữ") trans = "U74";
        else if(_msg[i] == "Ự") trans = "U75";

        else trans = _msg[i];
//        qDebug() << "transt " << trans;

        message.append(trans);
    }
    return message.length();
}

void BLEmanager::call_frome_java(QString _name, QString _add)
{
//    qDebug() << "device get" << _data;
    emit ble_name(_name,_add);
}

void BLEmanager::timer_set_service()
{
//    m_bleInterface->setCurrentService(2);
//    m_timer->stop();
}

void BLEmanager::dataReceived(QByteArray data)
{
    qDebug() << "Data receiver: " << data;
    if(data.length() == 5){
        int light_data = data.mid(2,3).toInt();
        emit value_light(light_data);
        qDebug() << "value receiver: " << light_data;
    }
}

