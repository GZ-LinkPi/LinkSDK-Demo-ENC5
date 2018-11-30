#include <QCoreApplication>
#include "Link.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Link::init();

    qDebug()<<"demo 2";

    LinkObject *mix=Link::create("MixV");
    QVariantMap dataMix;
    QVariantList srcs;
    QVariantList layouts;

    for(int i=0;i<9;i++)
    {
        QVariantMap lay;
        lay["x"]=1.0*(i%3)/3;

        lay["y"]=1.0*(i/3)/3;
        lay["w"]=1.0/3;
        lay["h"]=1.0/3;
        lay["a"]=1;
        lay["index"]=i;
        layouts<<lay;
    }



    LinkObject *vo=Link::create("OutputVo");
    QVariantMap dataVo;
    dataVo["type"]="hdmi";
    dataVo["mode"]=12;
    dataVo["ui"]=true;
    vo->start(dataVo);


    QList<LinkObject *> inputList;
    char aa='A';
    for(int i=0;i<5;i++)
    {
        char c=aa+i;
        QString iface="HDMI-"+QString(c);
        LinkObject *vi=Link::create("InputVi");
        QVariantMap data;
        data["interface"]=iface;
        vi->start(data);
        inputList<<vi;
    }
    for(int i=0;i<inputList.count();i++)
    {
        srcs<<inputList[i]->name();
        inputList[i]->linkV(mix);
    }

    dataMix["src"]=srcs;
    dataMix["layout"]=layouts;
    mix->start(dataMix);

    mix->linkV(vo);

    return a.exec();
}

