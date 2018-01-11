#ifndef BLEMANAGER_H
#define BLEMANAGER_H

#include <QObject>
#include "bleinterface.h"
#include <QDebug>
#include <QTimer>
#include <QString>
#include <QAndroidJniObject>
#include "gDataBase.h"
#include <QStringList>
#include <QBluetoothLocalDevice>

class BLEmanager : public QObject
{
    Q_OBJECT
public:
    explicit BLEmanager(QObject *parent = 0);
    Q_INVOKABLE void scan_device();
    Q_INVOKABLE void disconnectDevice();
    Q_INVOKABLE void connect_to_device(QString _address);
    Q_INVOKABLE void send_command_direct_to_device(unsigned char _value);
    Q_INVOKABLE void send_command_speed_to_device(unsigned char _value);
    Q_INVOKABLE void vietlott(QString _status);
    Q_INVOKABLE void setmsg(QString _msg);
    Q_INVOKABLE void scanBLE(bool _status);
    Q_INVOKABLE void save_database(QStringList listsave);
    Q_INVOKABLE void load_database();
    Q_INVOKABLE void power_enable();
    Q_INVOKABLE int get_lengh(QString _msg);

signals:
    void ble_name(QString _name, QString _add);
    void clear_list_device();
    void device_connect(bool _status);
    void value_light(int _value);
    void get_msg(QString msg);
public slots:
    void call_frome_java(QString _name, QString _add);
private slots:
    void timer_set_service();
private:
    BLEInterface *m_bleInterface;
    void dataReceived(QByteArray data);
    QTimer *m_timer;
    gDataBase m_database_manager;
    QString m_profile_selected_name;
    QBluetoothLocalDevice *localDevice;

};

#endif // BLEMANAGER_H
