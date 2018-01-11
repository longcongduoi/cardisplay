#ifndef LINKMANAGER_H
#define LINKMANAGER_H

#include <QObject>
#include "blemanager.h"
#include "receiverscan.h"


class linkManager : public QObject
{
    Q_OBJECT
public:
    explicit linkManager(QObject *parent = 0);

signals:

public slots:
    void linkConnect(receiverScan *m_receiver, BLEmanager *m_blemanager);

};

#endif // LINKMANAGER_H
