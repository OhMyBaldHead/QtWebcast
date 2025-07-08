/****************************************************************************
** Meta object code from reading C++ file 'chatroom.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../chatroom.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chatroom.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN8ChatRoomE_t {};
} // unnamed namespace

template <> constexpr inline auto ChatRoom::qt_create_metaobjectdata<qt_meta_tag_ZN8ChatRoomE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ChatRoom",
        "onsigPortId",
        "",
        "user_t",
        "user",
        "onsigChatName",
        "onsigChatList",
        "on_chatlist_btn_clicked",
        "onsigMasterExit",
        "on_send_clicked",
        "onsigChatText",
        "on_video_clicked",
        "onsigVideo",
        "onsigunVideo",
        "UdpReadRead",
        "onvideoChanged",
        "QVideoFrame",
        "on_audio_clicked",
        "onsigAudio",
        "onsigunAudio",
        "ReadyReadAudio",
        "onaudioChanged"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'onsigPortId'
        QtMocHelpers::SlotData<void(user_t)>(1, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'onsigChatName'
        QtMocHelpers::SlotData<void(user_t)>(5, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'onsigChatList'
        QtMocHelpers::SlotData<void(user_t)>(6, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'on_chatlist_btn_clicked'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onsigMasterExit'
        QtMocHelpers::SlotData<void(user_t)>(8, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'on_send_clicked'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onsigChatText'
        QtMocHelpers::SlotData<void(user_t)>(10, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'on_video_clicked'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onsigVideo'
        QtMocHelpers::SlotData<void(user_t)>(12, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'onsigunVideo'
        QtMocHelpers::SlotData<void(user_t)>(13, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'UdpReadRead'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onvideoChanged'
        QtMocHelpers::SlotData<void(QVideoFrame)>(15, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 16, 2 },
        }}),
        // Slot 'on_audio_clicked'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onsigAudio'
        QtMocHelpers::SlotData<void(user_t)>(18, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'onsigunAudio'
        QtMocHelpers::SlotData<void(user_t)>(19, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'ReadyReadAudio'
        QtMocHelpers::SlotData<void()>(20, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onaudioChanged'
        QtMocHelpers::SlotData<void()>(21, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ChatRoom, qt_meta_tag_ZN8ChatRoomE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject ChatRoom::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8ChatRoomE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8ChatRoomE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN8ChatRoomE_t>.metaTypes,
    nullptr
} };

void ChatRoom::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ChatRoom *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->onsigPortId((*reinterpret_cast< std::add_pointer_t<user_t>>(_a[1]))); break;
        case 1: _t->onsigChatName((*reinterpret_cast< std::add_pointer_t<user_t>>(_a[1]))); break;
        case 2: _t->onsigChatList((*reinterpret_cast< std::add_pointer_t<user_t>>(_a[1]))); break;
        case 3: _t->on_chatlist_btn_clicked(); break;
        case 4: _t->onsigMasterExit((*reinterpret_cast< std::add_pointer_t<user_t>>(_a[1]))); break;
        case 5: _t->on_send_clicked(); break;
        case 6: _t->onsigChatText((*reinterpret_cast< std::add_pointer_t<user_t>>(_a[1]))); break;
        case 7: _t->on_video_clicked(); break;
        case 8: _t->onsigVideo((*reinterpret_cast< std::add_pointer_t<user_t>>(_a[1]))); break;
        case 9: _t->onsigunVideo((*reinterpret_cast< std::add_pointer_t<user_t>>(_a[1]))); break;
        case 10: _t->UdpReadRead(); break;
        case 11: _t->onvideoChanged((*reinterpret_cast< std::add_pointer_t<QVideoFrame>>(_a[1]))); break;
        case 12: _t->on_audio_clicked(); break;
        case 13: _t->onsigAudio((*reinterpret_cast< std::add_pointer_t<user_t>>(_a[1]))); break;
        case 14: _t->onsigunAudio((*reinterpret_cast< std::add_pointer_t<user_t>>(_a[1]))); break;
        case 15: _t->ReadyReadAudio(); break;
        case 16: _t->onaudioChanged(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QVideoFrame >(); break;
            }
            break;
        }
    }
}

const QMetaObject *ChatRoom::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChatRoom::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8ChatRoomE_t>.strings))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ChatRoom::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
