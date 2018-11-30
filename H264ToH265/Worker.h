#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include "Link.h"

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = 0);
    void start(QString url, QString name);
    void stop();
private:
    static LinkObject *rtspSvr;
    LinkObject *net;
    LinkObject *dec;
    LinkObject *enc;
    LinkObject *mux;
signals:

public slots:
};

#endif // WORKER_H
