#include <QCoreApplication>
#include "Link.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Link::init();

    LinkObject *vo=Link::create("OutputVo");
    QVariantMap dataVo;
    dataVo["type"]="hdmi";
    dataVo["mode"]=12;
    dataVo["ui"]=true;
    vo->start(dataVo);

    LinkObject *vi=Link::create("InputVi");
    QVariantMap viData;
    viData["interface"]="HDMI-A";
    vi->start(viData);

    LinkObject *encV=Link::create("EncodeV");
    QVariantMap encData;
    encData["width"]=1920;
    encData["height"]=1080;
    encData["bitrate"]=8000;
    encData["codec"]="h265";
    encData["split"]=true;
    encV->start(encData);

    LinkObject *ai=Link::create("InputAi");
    QVariantMap aiData;
    aiData["interface"]="HDMI-A";
    ai->start(aiData);

    LinkObject *encA=Link::create("EncodeA");
    encA->start();

    LinkObject *mux=Link::create("Mux");
    QVariantMap dataMux;
    dataMux["path"]="mem://test";
    dataMux["format"]="rtsp";
    mux->start(dataMux);

    LinkObject *rtsp=Link::create("Rtsp");
    rtsp->start();

    ai->linkA(encA)->linkA(mux)->linkA(rtsp);
    vi->linkV(encV)->linkV(mux)->linkV(rtsp);
    vi->linkV(vo);

    return a.exec();
}

