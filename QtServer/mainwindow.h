#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QThread>
#include <QMetaType>
#include <QHostAddress>
#include "ui_mainwindow.h"
#include "clientsocket.h"
#include "socketmanager.h"
#include "user.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onNewConnection();
    void on_startButton_clicked();
    void onSigWrite(QTcpSocket *socket, user_t user, int len);
    void on_exitButtonclicked();


private:
    static QMutex mutex;
    Ui::MainWindow *ui;
    QTcpServer *server;
};
#endif // MAINWINDOW_H
