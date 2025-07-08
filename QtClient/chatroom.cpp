#include "chatroom.h"
#include "ui_chatroom.h"
#include<QDateTime>
#include<QMessageBox>
#include"roommanager.h"
#include<QPoint>
#include<QMovie>

/*
函数功能：构造函数
参数：ClientSocket *cs, QTcpSocket *socket, QString curRoom,user_t user, QWidget *parent
返回值：无
*/
ChatRoom::ChatRoom(ClientSocket *cs, QTcpSocket *socket, QString curRoom,
                   user_t user, QWidget *parent) :
    QDialog(parent),cs(cs),socket(socket),curRoom(curRoom),user(user),
    ui(new Ui::ChatRoom)
{
    ui->setupUi(this);

    ui->textEdit->installEventFilter(this); //安装监听

    uiDesign(); //界面布局
    sendPortId();  //获取portID
    showChatList();//聊天用户列表

    QObject::connect (cs, SIGNAL(sigPortId(user_t)),
                     this, SLOT(onsigPortId(user_t)));
    QObject::connect (cs, SIGNAL(sigChatName(user_t)),
                      this, SLOT(onsigChatName(user_t)));
    QObject::connect (cs, SIGNAL(sigChatList(user_t)),
                      this, SLOT(onsigChatList(user_t)));
    QObject::connect (cs, SIGNAL(sigChatText(user_t)),
                      this, SLOT(onsigChatText(user_t)));
    QObject::connect(cs, SIGNAL(sigMasterExit(user_t)),
                     this, SLOT(onsigMasterExit(user_t)));
    QObject::connect (cs, SIGNAL(sigVideo(user_t)),
                      this, SLOT(onsigVideo(user_t)));
    QObject::connect (cs, SIGNAL(sigunVideo(user_t)),
                      this, SLOT(onsigunVideo(user_t)));
    QObject::connect (cs, SIGNAL(sigAudio(user_t)),
                     this, SLOT(onsigAudio(user_t)));
    QObject::connect (cs, SIGNAL(sigunAudio(user_t)),
                     this, SLOT(onsigunAudio(user_t)));
}

/*
函数功能：析构函数
参数：无
返回值：无
*/
ChatRoom::~ChatRoom()
{
    delete ui;
}


/*
函数功能：按enter发送信息
参数：QObject *obj, QEvent *ev
返回值：bool
*/
bool ChatRoom::eventFilter(QObject *obj, QEvent *ev)
{
    if(obj == ui->textEdit){
            //是否是键盘事件
            if(ev->type() == QEvent::KeyPress){
                //将QEvent*类型转化为QKeyEvent*
                QKeyEvent *keyEvent = dynamic_cast<QKeyEvent*>(ev);
                //判定是否是大键盘上的enter
                if(keyEvent->key() == Qt::Key_Return){
                    ChatRoom::on_send_clicked();    //执行发送按钮事件
                    return true;
                }else{
                    //继续转发
                    return false;
                }
            }else{
                return false;
            }
    }else{
        return ChatRoom::eventFilter(obj, ev);
    }
}


/*
函数功能：界面布局
参数：无
返回值：无
*/
void ChatRoom::uiDesign()
{
    //设置窗口背景图片
    this->setStyleSheet ("background-image:url(:/image/image/pic33.jpg)");
    ui->listWidget->setStyleSheet ("background-image:url(:/image/image/skin.jpg)");
    ui->textBrowser->setStyleSheet(R"(
        QTextBrowser {
            background-color: transparent; /* 透明背景 */
            border: none; /* 无边框 */
            color: white; /* 弹幕文本颜色，可根据需要调整 */
            font-size: 7pt; /* 弹幕字体大小 */
            text-align: left; /* 水平方向靠左 */
            vertical-align: bottom; /* 垂直方向靠下 */
        }
        QTextBrowser QScrollBar:vertical {
            width: 0px; /* 隐藏垂直滚动条 */
        }
        QTextBrowser QScrollBar:horizontal {
            height: 0px; /* 隐藏水平滚动条 */
        }
    )");

    // 设置属性使其可以透明叠加
    ui->textBrowser->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->textBrowser->setFrameShape(QFrame::NoFrame); // 确保无框架
    ui->textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // 关闭垂直滚动条
    ui->textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // 关闭水平滚动条

    ui->textEdit->setStyleSheet ("background-image:url(:/image/image/skin.jpg)");

   //设置按钮图片和无边框
    ui->send->setStyleSheet("QPushButton{background-color:blue;"
                            "color: black;"
                            "border-radius: 10px;"
                            "border: 2px groove gray;"
                            "border-style: outset;}"
                            "QPushButton:pressed{background-color:rgb(85, 170, 255);"
                            "border-style: inset; }"
                             );
    QPixmap video(":/image/image/icon/video.png");
    QPixmap audio(":/image/image/icon/audio.png");
    QPixmap flash(":/image/image/icon/flash.jpg");
    ui->send->setFlat (true);
    ui->video->setIcon (video);
    ui->video->setIconSize (QSize(35,35));
    ui->video->setFlat (true);
    ui->audio->setIcon (audio);
    ui->audio->setIconSize (QSize(35,35));
    ui->audio->setFlat (true);
    ui->chatlist_btn->setIcon (flash);
    ui->chatlist_btn->setIconSize (QSize(20,20));
    ui->chatlist_btn->setFlat (true);

    //显示当前用户
    QString label = "当前用户：";
    label += QString::fromLocal8Bit (user.username);
    ui->cur_user->setStyleSheet ("color:red;");
    ui->cur_user->setText (label);

    QPixmap pixmap(":/image/image/vpic.png");
    pixmap = pixmap.scaled(ui->videosurface->size());
    ui->videosurface->setPixmap(pixmap);
}

/*
函数功能：刚进入聊天室时向服务器请求房间port
参数：无
返回值：无
*/
void ChatRoom::sendPortId()
{
    user.type = PORTID;
    socket->write ((char*)&user, sizeof(user_t));
}

/*
函数功能：获取房间portid后，才能初始化ReadSocket和ReadSocketAudio的port
参数：user_t
返回值：无
*/
void ChatRoom::onsigPortId(user_t user)
{
    qDebug()<< __FUNCTION__ <<"\t\tin";
    showUser_t(user);

    this->user.portId = user.portId;
    this->portid = user.portId;
    udpVideo();
    udpAudio();

    qDebug()<< __FUNCTION__ <<"\t\tout";
}


/*
函数功能：udp视频传输协议
参数：无
返回值：无
*/
void ChatRoom::udpVideo()
{
    qDebug()<< __FUNCTION__ <<"\t\tin";
    qDebug()<< QString::number(user.portId);

    QMediaCaptureSession* captureSession = new QMediaCaptureSession(this);
    const QCameraDevice cameraDevice = QMediaDevices::defaultVideoInput();
    QVideoSink* videoSink = new QVideoSink(this);
    if (cameraDevice.isNull()) {
        qDebug() << "未找到可用摄像头设备";
    }
    camera = new QCamera(cameraDevice, this);
    captureSession->setCamera(camera);
    captureSession->setVideoSink(videoSink);
    connect(videoSink, &QVideoSink::videoFrameChanged,
            this, &ChatRoom::onvideoChanged);

    //建立udp网络连接
    socketWrite = new QUdpSocket(this);
    socketRead = new QUdpSocket(this);
    //groupAddress.setAddress ("224.0.1.200");
    // groupAddress.setAddress ("239.88.88.88");   //组播地址
    socketWrite->setSocketOption (QAbstractSocket::MulticastTtlOption,1);//设置套接字属性
    socketRead->bind (QHostAddress::AnyIPv4, (8000+portid), QUdpSocket::ReuseAddressHint|QUdpSocket::ShareAddress); //绑定广播地址端口
    //socketRead->joinMulticastGroup (groupAddress);  //添加到组播，绑定到读套接字上

    //udp读写
    connect(socketRead, SIGNAL(readyRead()),
             this, SLOT(UdpReadRead()));
    qDebug()<< __FUNCTION__ <<"\t\tout";
}


/*
函数功能：udp音频传输协议
参数：无
返回值：无
*/
void ChatRoom::udpAudio()
{
    // 音频输入设备设置
    const QAudioDevice audioInputDevice = QMediaDevices::defaultAudioInput();
    if (audioInputDevice.isNull()) {
        qDebug() << "未找到可用音频输入设备";
        return;
    }
    QAudioFormat format = audioInputDevice.preferredFormat();


    if (!audioInputDevice.isFormatSupported(format)) {
        qDebug() << "默认音频格式不支持";
    }

    // 音频输入
    audioInput = new QAudioSource(audioInputDevice, format, this);

    // 音频输出设备设置
    const QAudioDevice audioOutputDevice = QMediaDevices::defaultAudioOutput();
    if (audioOutputDevice.isNull()) {
        qDebug() << "未找到可用音频输出设备";
        return;
    }

    // 音频输出
    audioOutput = new QAudioSink(audioOutputDevice, format, this);
    audioOutputIODevice = audioOutput->start();

    socketWdaudio = new QUdpSocket(this);
    socketRdaudio = new QUdpSocket(this);

    // 绑定接收端口
    socketWdaudio->setSocketOption(QAbstractSocket::MulticastTtlOption,1);//设置套接字属性
    socketRdaudio->bind(QHostAddress::AnyIPv4, (8500 + portid),
                          QUdpSocket::ReuseAddressHint | QUdpSocket::ShareAddress);
    // 连接网络接收信号到音频播放
    connect(socketRdaudio, &QUdpSocket::readyRead, this, &ChatRoom::ReadyReadAudio);
}


/*
函数功能：刚进入聊天室时告诉服务器
参数：无
返回值：无
*/
void ChatRoom::showChatList()
{
    user.type = CHATNAME;
    socket->write ((char*)&user, sizeof(user_t));
}


/*
函数功能：刚进入聊天室时加入用户列表
参数：user_t user
返回值：无
*/
void ChatRoom::onsigChatName (user_t user)
{
    qDebug()<< __FUNCTION__ <<"\t\tin";
    showUser_t(user);

    QString chatName = QString::fromLocal8Bit (user.username);
    if(chatName == curRoom){
        chatName += "(房主)";
    }
    QListWidgetItem *item = new QListWidgetItem(QIcon(":/image/image/user/room2.jpg"), chatName, ui->listWidget);
    ui->listWidget->setIconSize(QSize(36,36));
    ui->listWidget->addItem (item);
    QString sysInfo = "[系统消息：]";
    sysInfo += chatName;
    sysInfo += "已加入聊天室";
    ui->textBrowser->setTextColor (QColor::fromRgb (255,0,0));
    ui->textBrowser->append (sysInfo);
    ui->textBrowser->setTextColor (QColor::fromRgb (0,128,255));

    qDebug()<< __FUNCTION__ <<"\t\tout";
}


/*
函数功能：刷新按钮
参数：无
返回值：无
*/
void ChatRoom::on_chatlist_btn_clicked()
{
    ui->listWidget->clear ();
    user.type = CHATLIST;
    socket->write((char*)&user, sizeof(user));
}


/*
函数功能：显示聊天列表
参数：user_t user
返回值：无
*/
void ChatRoom::onsigChatList (user_t user)
{
    qDebug()<< __FUNCTION__ <<"\t\tin";
    showUser_t(user);

    QString chatName = QString::fromLocal8Bit (user.chatname);
    if(chatName == curRoom){
        chatName += "(房主)";
    }
    QListWidgetItem *item = new QListWidgetItem(QIcon(":/image/image/user/room2.jpg"), chatName, ui->listWidget);
    ui->listWidget->setIconSize(QSize(36,36));
    ui->listWidget->addItem (item);
    qDebug()<< __FUNCTION__ <<"\t\tout";
}

/*
函数功能：发送消息按钮
参数：无
返回值：无
*/
void ChatRoom::on_send_clicked()    //文字聊天
{
    QString text = ui->textEdit->toPlainText ();
    if(text.isEmpty ()){
        QMessageBox::warning (this, "提示","内容不可为空");
        return;
    }
    QByteArray ba_text = text.toLocal8Bit ();
    char* c_text = ba_text.data ();
    strncpy(user.data, c_text, sizeof(user.data));
    user.type = TEXT;
    ui->textEdit->clear ();
    socket->write((char*)&user, sizeof(user));
}


/*
函数功能：返回文字消息处理
参数：user_t user
返回值：无
*/
void ChatRoom::onsigChatText(user_t user)
{
    qDebug()<< __FUNCTION__ <<"\t\tin";
    showUser_t(user);

    QString room = QString::fromLocal8Bit (user.roomName);
    QDateTime dt = QDateTime::currentDateTime ();
    QString str_head = QString::fromLocal8Bit (user.username);
    str_head += " ";
    str_head += dt.toString ("yyyy/MM/dd hh:mm:ss");
    QString str_body = "  ";
    str_body += QString::fromLocal8Bit (user.data);
    static int flag = -1;
    if(flag == -1){
        ui->textBrowser->setTextColor (QColor::fromRgb (50,205,50));
        flag *= -1;
    }
    else if(flag == 1){
        ui->textBrowser->setTextColor (QColor::fromRgb (255,128,64));
        flag *= -1;
    }
    ui->textBrowser->append (str_head);
    ui->textBrowser->setTextColor (QColor::fromRgb (0,128,255));
    ui->textBrowser->append (str_body);
    qDebug()<< __FUNCTION__ <<"\t\tout";
}


/*
函数功能：关闭聊天室
参数：QCloseEvent *
返回值：无
*/
void ChatRoom::closeEvent (QCloseEvent *)
{
    RoomManager *rm = RoomManager::getInstance ();
    QString room = QString::fromLocal8Bit (user.roomName);
    rm->eraseRoom (room);

    user.type = QUIT;
    socket->write((char*)&user, sizeof(user));
}


/*
函数功能：房主退出客户端通知其他人退出房间
参数：user_t user
返回值：无
*/
void ChatRoom::onsigMasterExit(user_t user)
{
    qDebug()<< __FUNCTION__ <<"\t\tin";
    showUser_t(user);

    QMessageBox::warning(this, "警告", "房主已经下线，房间将暂时关闭，谢谢配合");
    this->close();
    qDebug()<< __FUNCTION__ <<"\t\tout";
}

/*
函数功能：直播按钮
参数：无
返回值：无
*/
void ChatRoom::on_video_clicked()
{
    if(user.flag != MASTER){
        QMessageBox::warning (this, "警告", "只有房主可以开启直播");
        return;
    }
    static int fv = -1;
    if(fv == -1){
        user.type = VIDEO;      //开启视频
        QPixmap video(":/image/image/icon/video1.png");
        ui->video->setIcon (video);
        ui->video->setIconSize (QSize(35,35));
        socket->write((char*)&user, sizeof(user));
        fv *= -1;
    }
    else if(fv == 1){        //关闭视频
        user.type = UNVIDEO;
        QPixmap video(":/image/image/icon/video.png");
        ui->video->setIcon (video);
        ui->video->setIconSize (QSize(35,35));
        socket->write((char*)&user, sizeof(user));
        fv *= -1;
    }
}


/*
函数功能：开启直播
参数：user_t user
返回值：无
*/
void ChatRoom::onsigVideo (user_t user)
{
    qDebug()<< __FUNCTION__ <<"\t\tin";
    showUser_t(user);

    if(user.flag == UP){
        QMessageBox::information (this, "提示", "房主正在发起直播！");
    }
    else if(user.flag == MASTER){
        QMessageBox::information (this, "提示", "你正在发起直播！");
        camera->start ();
    }
    qDebug()<< __FUNCTION__ <<"\t\tout";
}


/*
函数功能：关闭直播
参数：user_t user
返回值：无
*/
void ChatRoom::onsigunVideo (user_t user)
{
    qDebug()<< __FUNCTION__ <<"\t\tin";
    showUser_t(user);

    if(user.flag == UP){
        QMessageBox::information (this, "提示", "房主已经关闭直播！");
    }
    else if(user.flag == MASTER){
        QMessageBox::information (this, "提示", "你已经关闭直播！");
        camera->stop ();
        //ui->videosurface->hide ();
        // QPixmap video(":/image/image/icon/video.png");
        // ui->video->setIcon (video);
        // ui->video->setIconSize (QSize(35,35));
    }
    QPixmap pixmap(":/image/image/vpic.png");
    pixmap = pixmap.scaled(ui->videosurface->size());
    ui->videosurface->setPixmap(pixmap);
    qDebug()<< __FUNCTION__ <<"\t\tout";
}


/*
函数功能：udp接收图片并显示
参数：无
返回值：无
*/
void ChatRoom::UdpReadRead()
{
    qDebug()<< __FUNCTION__ <<"\t\tin";
    static QByteArray receivedData;
    static int expectedSize = 0;
    static int totalReceived = 0;
    static int packetCount = 0;
    static QDateTime lastReceiveTime = QDateTime::currentDateTime();

    // 超时处理（1000ms未收到新包视为传输中断）
    if (lastReceiveTime.msecsTo(QDateTime::currentDateTime()) > 1000) {
        receivedData.clear();
        expectedSize = 0;
        totalReceived = 0;
        packetCount = 0;
    }

    while(socketRead->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(socketRead->pendingDatagramSize());

        QHostAddress sender;
        quint16 senderPort;

        socketRead->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);

        // 更新接收时间
        lastReceiveTime = QDateTime::currentDateTime();

        // 解析数据包头部
        QDataStream in(&datagram, QIODevice::ReadOnly);
        in.setVersion(QDataStream::Qt_5_15);

        int packetId;
        int totalPackets;
        int packetSize;

        in >> packetId >> totalPackets >> packetSize;

        // 初始化传输
        if (packetId == 0) {
            in >> expectedSize;
            receivedData.resize(expectedSize);
            totalReceived = 0;
            packetCount = 0;
            continue;
        }

        // 复制数据到缓冲区
        if (packetId > 0 && packetId <= totalPackets &&
            totalReceived + packetSize <= expectedSize) {
            memcpy(receivedData.data() + totalReceived, datagram.data() + sizeof(int) * 3, packetSize);
            totalReceived += packetSize;
            packetCount++;
        }
    }

    // 检查是否接收完成
    if (expectedSize > 0 && totalReceived >= expectedSize && packetCount > 0) {
        QImage image;
        if (image.loadFromData(receivedData, "JPG")) {
            // 调整图像大小以适应显示区域
            QPixmap map = QPixmap::fromImage(image);
            map = map.scaled(ui->videosurface->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
            ui->videosurface->setPixmap(map);
        } else {
            qDebug() << "Failed to load image from received data";
        }

        // 重置状态
        receivedData.clear();
        expectedSize = 0;
        totalReceived = 0;
        packetCount = 0;
    }
    qDebug()<< __FUNCTION__ <<"\t\tout";
}

/*
函数功能：获取视频采集的图片并通过udp发送出去
参数：QVideoFrame curFrame
返回值：无
*/
void ChatRoom::onvideoChanged(QVideoFrame curFrame)
{
    // 每三帧处理一次，降低带宽需求（1200×600分辨率需要更多带宽）
    static int frameCounter = 0;
    //if ((frameCounter++) % 3 != 0) return;

    // 将视频帧转换为可处理的格式
    QVideoFrame cloneFrame(curFrame);
    if (!cloneFrame.map(QVideoFrame::ReadOnly)) {
        qDebug() << "无法映射视频帧";
        return;
    }

    QImage image = cloneFrame.toImage();

    // 镜像和缩放图像为1200×600
    QTransform transform;
    transform.scale(-1, 1);  // 水平翻转
    image = image.transformed(transform).scaled(1200, 600, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);

    // 如果之前进行了映射，现在取消映射
    if (cloneFrame.isMapped()) {
        cloneFrame.unmap();
    }

    // 居中裁剪到1200×600
    if (image.width() > 1200 || image.height() > 600) {
        int x = (image.width() - 1200) / 2;
        int y = (image.height() - 600) / 2;
        image = image.copy(x, y, 1200, 600);
    }

    // 压缩图像为JPEG格式 - 调整质量参数以平衡画质和带宽
    QByteArray compressedData;
    QBuffer buffer(&compressedData);
    buffer.open(QIODevice::WriteOnly);

    // 尝试不同的质量设置，找到最佳平衡点
    const int quality = 75; // 可调整范围：0(最低质量)到100(最高质量)
    image.save(&buffer, "JPG", quality);
    buffer.close();

    // 准备发送数据包
    const int maxPacketSize = 1400 - sizeof(int) * 3;  // 增加包大小以减少数据包数量
    const int totalSize = compressedData.size();
    const int numPackets = (totalSize + maxPacketSize - 1) / maxPacketSize;

    // 发送头部数据包
    QByteArray headerPacket;
    QDataStream headerStream(&headerPacket, QIODevice::WriteOnly);
    headerStream.setVersion(QDataStream::Qt_5_15);

    headerStream << 0 << numPackets << 0 << totalSize;  // 头部包ID为0

    socketWrite->writeDatagram(headerPacket, QHostAddress::Broadcast, (8000 + portid));

    // 发送数据数据包
    for (int i = 0; i < numPackets; ++i) {
        const int offset = i * maxPacketSize;
        const int currentPacketSize = qMin(maxPacketSize, totalSize - offset);

        QByteArray dataPacket;
        QDataStream dataStream(&dataPacket, QIODevice::WriteOnly);
        dataStream.setVersion(QDataStream::Qt_5_15);

        dataStream << (i + 1) << numPackets << currentPacketSize;  // 数据包ID从1开始
        dataPacket.append(compressedData.mid(offset, currentPacketSize));

        socketWrite->writeDatagram(dataPacket, QHostAddress::Broadcast, (8000 + portid));
    }
}


/*
函数功能：音频按钮
参数：无
返回值：无
*/
void ChatRoom::on_audio_clicked()
{
    static int af = -1;
    if(af < 0){
        QPixmap audio(":/image/image/icon/audio1.png");
        ui->audio->setIcon (audio);
        ui->audio->setIconSize (QSize(35,35));
        user.type = AUDIO;
        socket->write((char*)&user, sizeof(user));
    }
    else if(af > 0){
        QPixmap audio(":/image/image/icon/audio.png");
        ui->audio->setIcon (audio);
        ui->audio->setIconSize (QSize(35,35));
        user.type = UNAUDIO;
        socket->write((char*)&user, sizeof(user));
    }
    af *= -1;
}

/*
函数功能：开启音频
参数：user_t user
返回值：无
*/
void ChatRoom::onsigAudio(user_t user){

    qDebug()<< __FUNCTION__ <<"\t\tin";
    showUser_t(user);

    if(user.flag != MASTER){
        QMessageBox::information (this, "提示", "房主正在语音！");
    }
    else if(user.flag == MASTER){
        QMessageBox::information (this, "提示", "你正在语音！");
        audioInputIODevice = audioInput->start();
        connect(audioInputIODevice, &QIODevice::readyRead, this, &ChatRoom::onaudioChanged);
    }

    qDebug()<< __FUNCTION__ <<"\t\tout";

}


/*
函数功能：关闭音频
参数：user_t user
返回值：无
*/
void ChatRoom::onsigunAudio(user_t user){
    qDebug()<< __FUNCTION__ <<"\t\tin";
    showUser_t(user);

    if(user.flag != MASTER){
        QMessageBox::information(this, "提示", "房主已经关闭音频！");
    }
    else if(user.flag == MASTER){
        QMessageBox::information(this, "提示", "你已经关闭音频！");
        disconnect(audioInputIODevice, &QIODevice::readyRead, this, &ChatRoom::onaudioChanged);
        audioInput->stop();
        audioInputIODevice = nullptr;
    }
    qDebug()<< __FUNCTION__ <<"\t\tout";
}



/*
函数功能：udp接收音频文件
参数：无
返回值：无
*/
void ChatRoom::ReadyReadAudio()
{
//    qDebug()<< __FUNCTION__ <<"\t\tin";
    if (!socketRdaudio || !audioOutputIODevice) return;

    while (socketRdaudio->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(socketRdaudio->pendingDatagramSize());

        QHostAddress sender;
        quint16 senderPort;

        // 读取数据报
        socketRdaudio->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);

        // 输出到音频设备
        if (audioOutputIODevice && audioOutputIODevice->isWritable()) {
            const qint64 bytesWritten = audioOutputIODevice->write(datagram);
            if (bytesWritten != datagram.size()) {
                qDebug() << "音频数据写入不完整，写入:" << bytesWritten << "数据大小:" << datagram.size();
            }
        }
    }
//    qDebug()<< __FUNCTION__ <<"\t\tout";
}

/*
函数功能：获取麦克风采集的数据并通过udp发送出去
参数：QVideoFrame curFrame
返回值：无
*/
void ChatRoom::onaudioChanged()
{
//    qDebug()<< __FUNCTION__ <<"\t\tin";
    if (!audioInputIODevice) return;

    // 直接从IODevice读取可用字节数
    const qint64 bytesAvailable = audioInputIODevice->bytesAvailable();

    if (bytesAvailable > 0) {
        QByteArray audioData(bytesAvailable, 0);
        const qint64 bytesRead = audioInputIODevice->read(audioData.data(), bytesAvailable);

        if (bytesRead > 0) {
            const quint16 broadcastPort = 8500 + portid;

            qint64 bytesWritten = socketWdaudio->writeDatagram(audioData, QHostAddress::Broadcast, (8500 + portid));
            if (bytesWritten != bytesRead) {
                qDebug() << "音频数据发送不完整，写入:" << bytesWritten << "读取:" << bytesRead;
            }
            else{
                qDebug() << "音频数据发送:" << bytesWritten << "字节";
            }

        }
    }
//    qDebug()<< __FUNCTION__ <<"\t\tout";
}



