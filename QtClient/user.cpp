#include <QDebug>
#include "user.h"

// 将Flag枚举转换为字符串
const char* flagToString(Flag flag) {
    switch (flag) {
        case UP: return "UP";
        case MASTER: return "MASTER";
        default: return "UNKNOWN_FLAG";
    }
}

// 将type枚举转换为字符串
const char* typeToString(type msgType) {
    switch (msgType) {
        case REG: return "REG";
        case LOGIN: return "LOGIN";
        case ONLINE: return "ONLINE";
        case EXIT: return "EXIT";
        case ROOMNAME: return "ROOMNAME";
        case PORTID: return "PORTID";
        case CHATNAME: return "CHATNAME";
        case ROOMLIST: return "ROOMLIST";
        case CHATLIST: return "CHATLIST";
        case QUIT: return "QUIT";
        case TEXT: return "TEXT";
        case AUDIO: return "AUDIO";
        case UNAUDIO: return "UNAUDIO";
        case VIDEO: return "VIDEO";
        case UNVIDEO: return "UNVIDEO";
        default: return "UNKNOWN_TYPE";
    }
}

void showUser_t(const user_t& user) {
    qDebug() << "##########################";
    qDebug() << "用户信息:";
    qDebug() << "类型:" << typeToString(static_cast<type>(user.type));
    qDebug() << "状态标志位:" << flagToString(static_cast<Flag>(user.flag));
    qDebug() << "Port偏移量:" <<QString::number(user.portId);
    qDebug() << "用户名:" << user.username;
    qDebug() << "密码:" << user.userpasswd;
    qDebug() << "聊天室名称:" << user.roomName;
    qDebug() << "聊天对象:" << user.chatname;
    qDebug() << "数据:" << user.data;
    qDebug() << "##########################";
}
