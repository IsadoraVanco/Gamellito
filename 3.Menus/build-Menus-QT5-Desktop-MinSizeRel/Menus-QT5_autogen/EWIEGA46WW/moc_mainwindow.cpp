/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Menus-QT5/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[14];
    char stringdata0[365];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 25), // "on_pushButton_som_clicked"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 29), // "on_pushButton_iniciar_clicked"
QT_MOC_LITERAL(4, 68, 32), // "on_pushButton_configurar_clicked"
QT_MOC_LITERAL(5, 101, 27), // "on_pushButton_sobre_clicked"
QT_MOC_LITERAL(6, 129, 31), // "on_pushButton_versao_qt_clicked"
QT_MOC_LITERAL(7, 161, 34), // "on_pushButton_voltar_sobre_cl..."
QT_MOC_LITERAL(8, 196, 39), // "on_pushButton_voltar_configur..."
QT_MOC_LITERAL(9, 236, 36), // "on_pushButton_voltar_iniciar_..."
QT_MOC_LITERAL(10, 273, 34), // "on_pushButton_voltar_video_cl..."
QT_MOC_LITERAL(11, 308, 21), // "inicializaSomAmbiente"
QT_MOC_LITERAL(12, 330, 15), // "ligaSomAmbiente"
QT_MOC_LITERAL(13, 346, 18) // "desligaSomAmbiente"

    },
    "MainWindow\0on_pushButton_som_clicked\0"
    "\0on_pushButton_iniciar_clicked\0"
    "on_pushButton_configurar_clicked\0"
    "on_pushButton_sobre_clicked\0"
    "on_pushButton_versao_qt_clicked\0"
    "on_pushButton_voltar_sobre_clicked\0"
    "on_pushButton_voltar_configurar_clicked\0"
    "on_pushButton_voltar_iniciar_clicked\0"
    "on_pushButton_voltar_video_clicked\0"
    "inicializaSomAmbiente\0ligaSomAmbiente\0"
    "desligaSomAmbiente"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButton_som_clicked(); break;
        case 1: _t->on_pushButton_iniciar_clicked(); break;
        case 2: _t->on_pushButton_configurar_clicked(); break;
        case 3: _t->on_pushButton_sobre_clicked(); break;
        case 4: _t->on_pushButton_versao_qt_clicked(); break;
        case 5: _t->on_pushButton_voltar_sobre_clicked(); break;
        case 6: _t->on_pushButton_voltar_configurar_clicked(); break;
        case 7: _t->on_pushButton_voltar_iniciar_clicked(); break;
        case 8: _t->on_pushButton_voltar_video_clicked(); break;
        case 9: _t->inicializaSomAmbiente(); break;
        case 10: _t->ligaSomAmbiente(); break;
        case 11: _t->desligaSomAmbiente(); break;
        default: ;
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
