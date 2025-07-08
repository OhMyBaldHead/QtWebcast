#ifndef CHATROOM_H
#define CHATROOM_H

#include <QDialog>
#include "user.h"
#include <QTcpSocket>
#include "clientsocket.h"
#include <QCloseEvent>
#include <QListWidgetItem>
#include <QUdpSocket>
#include <QTcpSocket>
#include <QCamera>
#include <QMediaCaptureSession>
#include <QCameraDevice>
#include <QMediaDevices>
#include <QVideoSink>
#include <QHostAddress>
#include <QTimer>
#include <QLabel>
#include <QTransform>
#include <QKeyEvent>
#include <QFile>
#include <QAudioFormat>
#include <QBuffer>
#include <QAudioSource>
#include <QAudioSink>


const qint64 TIME_TRANSFORM = 1000 * 1000;              // 微秒转秒;

//解析wav音频文件用到的结构体
struct WAVFILEHEADER
{
    // RIFF 头
    char RiffName[4];
    unsigned long nRiffLength;

    // 数据类型标识符
    char WavName[4];

    // 格式块中的块头
    char FmtName[4];
    unsigned long nFmtLength;

    // 格式块中的块数据
    unsigned short nAudioFormat;
    unsigned short nChannleNumber;
    unsigned long nSampleRate;
    unsigned long nBytesPerSecond;
    unsigned short nBytesPerSample;
    unsigned short nBitsPerSample;

    // 数据块中的块头
    char    DATANAME[4];
    unsigned long   nDataLength;
};

namespace Ui {
class ChatRoom;
}

class ChatRoom : public QDialog
{
    Q_OBJECT

public:
    explicit ChatRoom(ClientSocket *cs, QTcpSocket *socket, QString curRoom,
                      user_t user, QWidget *parent = 0);
    ~ChatRoom();
    void uiDesign();    //界面设计
    void udpVideo();    //udp视频协议
    void udpAudio();    //udp音频协议
    void showChatList();        //刚进聊天室自动添加到用户列表
    void sendPortId();
    virtual bool eventFilter(QObject *obj, QEvent *ev); //按enter发送消息
    void sendMsg(QString audioname);        //通过udp发送音频信息

protected:
    virtual void closeEvent (QCloseEvent *);//关闭事件

private slots:
    void onsigPortId(user_t user);//获取房间的portID
    void onsigChatName(user_t user);//添加用户名到列表
    void onsigChatList(user_t user);//刷新列表
    void on_chatlist_btn_clicked();//刷新按钮
    void onsigMasterExit(user_t user);//房主退出
    void on_send_clicked();//发送信息
    void onsigChatText(user_t user);//文字聊天信息处理

    void on_video_clicked();//视频
    void onsigVideo(user_t user);//视频处理
    void onsigunVideo(user_t user);//关闭视频
    void UdpReadRead();//udp处理槽函数
    void onvideoChanged(QVideoFrame);//视频采集成图片

    void on_audio_clicked();//音频按钮
    void onsigAudio(user_t user);//视频处理
    void onsigunAudio(user_t user);//关闭视频
    void ReadyReadAudio();//音频udp处理槽函数
    void onaudioChanged();//麦克风采集数据并udp发送

private:
    Ui::ChatRoom *ui;
    user_t user;
    int portid;
    QString curRoom;//保存当前房间名
    QTcpSocket *socket;
    ClientSocket *cs;

    QUdpSocket *socketWrite;
    QUdpSocket *socketRead;
    QUdpSocket *socketWdaudio;
    QUdpSocket *socketRdaudio;

    // QHostAddress groupAddress;
    // QHostAddress groupAddress1;
    QCamera *camera;
    QLabel *label;

    QAudioSource* audioInput;
    QAudioSink* audioOutput;
    QIODevice* audioInputIODevice;
    QIODevice* audioOutputIODevice;

};

#endif // CHATROOM_H


