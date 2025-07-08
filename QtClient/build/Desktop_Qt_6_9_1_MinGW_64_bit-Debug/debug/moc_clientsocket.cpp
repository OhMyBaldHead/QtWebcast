/****************************************************************************
** Meta object code from reading C++ file 'clientsocket.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../clientsocket.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clientsocket.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN12ClientSocketE_t {};
} // unnamed namespace

template <> constexpr inline auto ClientSocket::qt_create_metaobjectdata<qt_meta_tag_ZN12ClientSocketE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ClientSocket",
        "sigReg",
        "",
        "user_t",
        "user",
        "sigLogin",
        "sigRoomName",
        "sigRoomList",
        "sigPortId",
        "sigChatName",
        "sigChatList",
        "sigMasterExit",
        "sigChatText",
        "sigVideo",
        "sigunVideo",
        "sigAudio",
        "sigunAudio",
        "onReadyRead"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'sigReg'
        QtMocHelpers::SignalData<void(user_t)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'sigLogin'
        QtMocHelpers::SignalData<void(user_t)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'sigRoomName'
        QtMocHelpers::SignalData<void(user_t)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'sigRoomList'
        QtMocHelpers::SignalData<void(user_t)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'sigPortId'
        QtMocHelpers::SignalData<void(user_t)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'sigChatName'
        QtMocHelpers::SignalData<void(user_t)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'sigChatList'
        QtMocHelpers::SignalData<void(user_t)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'sigMasterExit'
        QtMocHelpers::SignalData<void(user_t)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'sigChatText'
        QtMocHelpers::SignalData<void(user_t)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'sigVideo'
        QtMocHelpers::SignalData<void(user_t)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'sigunVideo'
        QtMocHelpers::SignalData<void(user_t)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'sigAudio'
        QtMocHelpers::SignalData<void(user_t)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'sigunAudio'
        QtMocHelpers::SignalData<void(user_t)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'onReadyRead'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ClientSocket, qt_meta_tag_ZN12ClientSocketE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject ClientSocket::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12ClientSocketE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12ClientSocketE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12ClientSocketE_t>.metaTypes,
    nullptr
} };

void ClientSocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ClientSocket *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->sigReg((*reinterpret_cast< std::add_pointer_t<user_t>>(_a[1]))); break;
        case 1: _t->sigLogin((*reinterpret_cast< std::add_pointer_t<user_t>>(_a[1]))); break;
        case 2: _t->sigRoomName((*reinterpret_cast< std::add_pointer_t<user_t>>(_a[1]))); break;
        case 3: _t->sigRoomList((*reinterpret_cast< std::add_pointer_t<user_t>>(_a[1]))); break;
        case 4: _t->sigPortId((*reinterpret_cast< std::add_pointer_t<user_t>>(_a[1]))); break;
        case 5: _t->sigChatName((*reinterpret_cast< std::add_pointer_t<user_t>>(_a[1]))); break;
        case 6: _t->sigChatList((*reinterpret_cast< std::add_pointer_t<user_t>>(_a[1]))); break;
        case 7: _t->sigMasterExit((*reinterpret_cast< std::add_pointer_t<user_t>>(_a[1]))); break;
        case 8: _t->sigChatText((*reinterpret_cast< std::add_pointer_t<user_t>>(_a[1]))); break;
        case 9: _t->sigVideo((*reinterpret_cast< std::add_pointer_t<user_t>>(_a[1]))); break;
        case 10: _t->sigunVideo((*reinterpret_cast< std::add_pointer_t<user_t>>(_a[1]))); break;
        case 11: _t->sigAudio((*reinterpret_cast< std::add_pointer_t<user_t>>(_a[1]))); break;
        case 12: _t->sigunAudio((*reinterpret_cast< std::add_pointer_t<user_t>>(_a[1]))); break;
        case 13: _t->onReadyRead(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ClientSocket::*)(user_t )>(_a, &ClientSocket::sigReg, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClientSocket::*)(user_t )>(_a, &ClientSocket::sigLogin, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClientSocket::*)(user_t )>(_a, &ClientSocket::sigRoomName, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClientSocket::*)(user_t )>(_a, &ClientSocket::sigRoomList, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClientSocket::*)(user_t )>(_a, &ClientSocket::sigPortId, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClientSocket::*)(user_t )>(_a, &ClientSocket::sigChatName, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClientSocket::*)(user_t )>(_a, &ClientSocket::sigChatList, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClientSocket::*)(user_t )>(_a, &ClientSocket::sigMasterExit, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClientSocket::*)(user_t )>(_a, &ClientSocket::sigChatText, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClientSocket::*)(user_t )>(_a, &ClientSocket::sigVideo, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClientSocket::*)(user_t )>(_a, &ClientSocket::sigunVideo, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClientSocket::*)(user_t )>(_a, &ClientSocket::sigAudio, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClientSocket::*)(user_t )>(_a, &ClientSocket::sigunAudio, 12))
            return;
    }
}

const QMetaObject *ClientSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClientSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12ClientSocketE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ClientSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void ClientSocket::sigReg(user_t _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void ClientSocket::sigLogin(user_t _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void ClientSocket::sigRoomName(user_t _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void ClientSocket::sigRoomList(user_t _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void ClientSocket::sigPortId(user_t _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void ClientSocket::sigChatName(user_t _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void ClientSocket::sigChatList(user_t _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1);
}

// SIGNAL 7
void ClientSocket::sigMasterExit(user_t _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1);
}

// SIGNAL 8
void ClientSocket::sigChatText(user_t _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 8, nullptr, _t1);
}

// SIGNAL 9
void ClientSocket::sigVideo(user_t _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 9, nullptr, _t1);
}

// SIGNAL 10
void ClientSocket::sigunVideo(user_t _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 10, nullptr, _t1);
}

// SIGNAL 11
void ClientSocket::sigAudio(user_t _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 11, nullptr, _t1);
}

// SIGNAL 12
void ClientSocket::sigunAudio(user_t _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 12, nullptr, _t1);
}
QT_WARNING_POP
