/********************************************************************************
** Form generated from reading UI file 'chatroom.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATROOM_H
#define UI_CHATROOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_ChatRoom
{
public:
    QTextEdit *textEdit;
    QPushButton *send;
    QLabel *label;
    QPushButton *chatlist_btn;
    QTextBrowser *textBrowser;
    QPushButton *video;
    QPushButton *audio;
    QListWidget *listWidget;
    QLabel *cur_user;
    QLabel *videosurface;

    void setupUi(QDialog *ChatRoom)
    {
        if (ChatRoom->objectName().isEmpty())
            ChatRoom->setObjectName("ChatRoom");
        ChatRoom->resize(747, 435);
        textEdit = new QTextEdit(ChatRoom);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(20, 320, 491, 61));
        send = new QPushButton(ChatRoom);
        send->setObjectName("send");
        send->setGeometry(QRect(420, 390, 81, 31));
        label = new QLabel(ChatRoom);
        label->setObjectName("label");
        label->setGeometry(QRect(530, 40, 71, 16));
        chatlist_btn = new QPushButton(ChatRoom);
        chatlist_btn->setObjectName("chatlist_btn");
        chatlist_btn->setGeometry(QRect(670, 30, 51, 41));
        textBrowser = new QTextBrowser(ChatRoom);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(26, 136, 481, 115));
        video = new QPushButton(ChatRoom);
        video->setObjectName("video");
        video->setGeometry(QRect(40, 270, 71, 41));
        audio = new QPushButton(ChatRoom);
        audio->setObjectName("audio");
        audio->setGeometry(QRect(140, 270, 71, 41));
        listWidget = new QListWidget(ChatRoom);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(530, 70, 201, 351));
        cur_user = new QLabel(ChatRoom);
        cur_user->setObjectName("cur_user");
        cur_user->setGeometry(QRect(540, 0, 151, 21));
        videosurface = new QLabel(ChatRoom);
        videosurface->setObjectName("videosurface");
        videosurface->setGeometry(QRect(26, 10, 481, 241));
        textEdit->raise();
        send->raise();
        label->raise();
        chatlist_btn->raise();
        video->raise();
        audio->raise();
        listWidget->raise();
        cur_user->raise();
        videosurface->raise();
        textBrowser->raise();

        retranslateUi(ChatRoom);

        QMetaObject::connectSlotsByName(ChatRoom);
    } // setupUi

    void retranslateUi(QDialog *ChatRoom)
    {
        ChatRoom->setWindowTitle(QCoreApplication::translate("ChatRoom", "Dialog", nullptr));
        send->setText(QCoreApplication::translate("ChatRoom", "\345\217\221\351\200\201", nullptr));
        label->setText(QCoreApplication::translate("ChatRoom", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600; color:#aa0000;\">\347\224\250\346\210\267\345\210\227\350\241\250&gt;&gt;&gt;</span></p></body></html>", nullptr));
        chatlist_btn->setText(QString());
        video->setText(QCoreApplication::translate("ChatRoom", "\347\233\264\346\222\255", nullptr));
        audio->setText(QCoreApplication::translate("ChatRoom", "\350\257\255\351\237\263", nullptr));
        cur_user->setText(QCoreApplication::translate("ChatRoom", "TextLabel", nullptr));
        videosurface->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChatRoom: public Ui_ChatRoom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATROOM_H
