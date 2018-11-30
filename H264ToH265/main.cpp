#include <QCoreApplication>
#include "Link.h"
#include "Worker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Link::init();


    Worker w1;
    w1.start("rtsp://admin:admin@192.168.1.21/cam/realmonitor?channel=1&subtype=0","stream1");
    Worker w2;
    w2.start("rtsp://admin:admin@192.168.1.22/cam/realmonitor?channel=1&subtype=0","stream2");
    Worker w3;
    w3.start("rtsp://admin:admin@192.168.1.23/cam/realmonitor?channel=1&subtype=0","stream3");
    Worker w4;
    w4.start("rtsp://admin:admin@192.168.1.24/cam/realmonitor?channel=1&subtype=0","stream4");


    return a.exec();
}

