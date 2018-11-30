#include "Worker.h"
LinkObject *Worker::rtspSvr=NULL;
Worker::Worker(QObject *parent) : QObject(parent)
{
    if(rtspSvr==NULL)
    {
        rtspSvr=Link::create("Rtsp");
        rtspSvr->start();
    }
    net=Link::create("InputNet");
    dec=Link::create("DecodeV");
    enc=Link::create("EncodeV");
    mux=Link::create("Mux");
}

void Worker::start(QString url, QString name)
{
    QVariantMap netData;
    netData["path"]=url;
    net->start(netData);

    dec->start();

    QVariantMap encData;
    encData["width"]=1920;
    encData["height"]=1080;
    encData["bitrate"]=4000;
    encData["codec"]="h265";
    encData["split"]=true;//for rtsp
    enc->start(encData);

    QVariantMap muxData;
    muxData["path"]="mem://"+name;
    muxData["format"]="rtsp";
    muxData["mute"]=true;
    mux->start(muxData);

    net->linkV(dec)->linkV(enc)->linkV(mux)->linkV(rtspSvr);
}

void Worker::stop()
{
    net->stop();
}

