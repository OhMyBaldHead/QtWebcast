#include "mainwindow.h"
#include "ui_mainwindow.h"

QMutex MainWindow::mutex;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    server = new QTcpServer(this);


    connect(server, SIGNAL(newConnection()),
                     this, SLOT(onNewConnection()));
    connect(ui->exitButton,&QPushButton::clicked,this,&MainWindow::on_exitButtonclicked);
    connect(ui->startButton,&QPushButton::clicked,this,&MainWindow::on_startButton_clicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onNewConnection()
{
    ui->textEdit->append("有客户端连接上服务器");
    QTcpSocket *client = server->nextPendingConnection();

    QHostAddress address = client->peerAddress();
    QString addressStr = address.toString();
    QString peerPortStr = QString::number(client->peerPort());
    ui->textEdit->append("客户端ip:"+addressStr);
    ui->textEdit->append("客户端port:"+peerPortStr);

    ClientSocket *cs = new ClientSocket(client);

    QThread *th = new QThread(this);
    QObject::connect(client, SIGNAL(disconnected()),
                     cs, SLOT(deleteLater()));
    QObject::connect(client, SIGNAL(disconnected()),
                     th, SLOT(quit()));
    qRegisterMetaType<user_t>("user_t");    //完成结构体注册
    QObject::connect(cs, SIGNAL(sigWrite(QTcpSocket*,user_t,int)),
                     this, SLOT(onSigWrite(QTcpSocket*,user_t,int)));
    cs->moveToThread(th);
    th->start();

    SocketManager *sockets = SocketManager::getInstance ();
    sockets->insertSocket (cs);
}

void MainWindow::on_startButton_clicked()
{
    if(server->isListening()){
        ui->textEdit->append("已经在监听");
        return;
    }
    //第二步：启动监听
    bool ret = server->listen(QHostAddress::Any, 8888);
    if(ret == true){
        ui->textEdit->append("监听成功");
    }
    else{
        ui->textEdit->append("监听失败");
    }
}

void MainWindow::on_exitButtonclicked(){

    OnlineDao *od = new OnlineDaoImp();
    vector<QString> v_name = od->selectOnline ();
    vector<QString>::iterator it;
    for(it = v_name.begin (); it != v_name.end (); ++it){
        QString q_name = *it;
        mutex.lock();
        od->delOnline(q_name);
        mutex.lock();
    }
    delete od;
    this->close();
}


void MainWindow::onSigWrite(QTcpSocket *socket, user_t user, int len)
{
    socket->write((char *)&user, len);
}


