/****************************************************************************
** Meta object code from reading C++ file 'backend.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../backend.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'backend.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
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

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSBackendENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSBackendENDCLASS = QtMocHelpers::stringData(
    "Backend",
    "QML.Element",
    "auto",
    "scanProgressChanged",
    "",
    "step",
    "message",
    "newImageCaptured",
    "imagePath",
    "frameIndex",
    "recognitionComplete",
    "results",
    "startCaptureRequestd",
    "contrastChanged",
    "contrast",
    "brightnessChanged",
    "brightness",
    "startScan",
    "processAndRecognize",
    "setContrast",
    "setBrightness"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSBackendENDCLASS_t {
    uint offsetsAndSizes[42];
    char stringdata0[8];
    char stringdata1[12];
    char stringdata2[5];
    char stringdata3[20];
    char stringdata4[1];
    char stringdata5[5];
    char stringdata6[8];
    char stringdata7[17];
    char stringdata8[10];
    char stringdata9[11];
    char stringdata10[20];
    char stringdata11[8];
    char stringdata12[21];
    char stringdata13[16];
    char stringdata14[9];
    char stringdata15[18];
    char stringdata16[11];
    char stringdata17[10];
    char stringdata18[20];
    char stringdata19[12];
    char stringdata20[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSBackendENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSBackendENDCLASS_t qt_meta_stringdata_CLASSBackendENDCLASS = {
    {
        QT_MOC_LITERAL(0, 7),  // "Backend"
        QT_MOC_LITERAL(8, 11),  // "QML.Element"
        QT_MOC_LITERAL(20, 4),  // "auto"
        QT_MOC_LITERAL(25, 19),  // "scanProgressChanged"
        QT_MOC_LITERAL(45, 0),  // ""
        QT_MOC_LITERAL(46, 4),  // "step"
        QT_MOC_LITERAL(51, 7),  // "message"
        QT_MOC_LITERAL(59, 16),  // "newImageCaptured"
        QT_MOC_LITERAL(76, 9),  // "imagePath"
        QT_MOC_LITERAL(86, 10),  // "frameIndex"
        QT_MOC_LITERAL(97, 19),  // "recognitionComplete"
        QT_MOC_LITERAL(117, 7),  // "results"
        QT_MOC_LITERAL(125, 20),  // "startCaptureRequestd"
        QT_MOC_LITERAL(146, 15),  // "contrastChanged"
        QT_MOC_LITERAL(162, 8),  // "contrast"
        QT_MOC_LITERAL(171, 17),  // "brightnessChanged"
        QT_MOC_LITERAL(189, 10),  // "brightness"
        QT_MOC_LITERAL(200, 9),  // "startScan"
        QT_MOC_LITERAL(210, 19),  // "processAndRecognize"
        QT_MOC_LITERAL(230, 11),  // "setContrast"
        QT_MOC_LITERAL(242, 13)   // "setBrightness"
    },
    "Backend",
    "QML.Element",
    "auto",
    "scanProgressChanged",
    "",
    "step",
    "message",
    "newImageCaptured",
    "imagePath",
    "frameIndex",
    "recognitionComplete",
    "results",
    "startCaptureRequestd",
    "contrastChanged",
    "contrast",
    "brightnessChanged",
    "brightness",
    "startScan",
    "processAndRecognize",
    "setContrast",
    "setBrightness"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSBackendENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       1,   14, // classinfo
      10,   16, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       3,    2,   76,    4, 0x06,    1 /* Public */,
       7,    2,   81,    4, 0x06,    4 /* Public */,
      10,    1,   86,    4, 0x06,    7 /* Public */,
      12,    0,   89,    4, 0x06,    9 /* Public */,
      13,    1,   90,    4, 0x06,   10 /* Public */,
      15,    1,   93,    4, 0x06,   12 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      17,    0,   96,    4, 0x02,   14 /* Public */,
      18,    0,   97,    4, 0x02,   15 /* Public */,
      19,    1,   98,    4, 0x02,   16 /* Public */,
      20,    1,  101,    4, 0x02,   18 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    5,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    8,    9,
    QMetaType::Void, QMetaType::QVariant,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   14,
    QMetaType::Void, QMetaType::Int,   16,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   14,
    QMetaType::Void, QMetaType::Int,   16,

       0        // eod
};

Q_CONSTINIT const QMetaObject Backend::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSBackendENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSBackendENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_metaTypeArray<
        // Q_OBJECT / Q_GADGET
        Backend,
        // method 'scanProgressChanged'
        void,
        int,
        const QString &,
        // method 'newImageCaptured'
        void,
        const QString &,
        int,
        // method 'recognitionComplete'
        void,
        const QVariant &,
        // method 'startCaptureRequestd'
        void,
        // method 'contrastChanged'
        void,
        double,
        // method 'brightnessChanged'
        void,
        int,
        // method 'startScan'
        void,
        // method 'processAndRecognize'
        void,
        // method 'setContrast'
        void,
        double,
        // method 'setBrightness'
        void,
        int
    >,
    nullptr
} };

void Backend::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Backend *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->scanProgressChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 1: _t->newImageCaptured((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 2: _t->recognitionComplete((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1]))); break;
        case 3: _t->startCaptureRequestd(); break;
        case 4: _t->contrastChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 5: _t->brightnessChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->startScan(); break;
        case 7: _t->processAndRecognize(); break;
        case 8: _t->setContrast((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 9: _t->setBrightness((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Backend::*)(int , const QString & );
            if (_t _q_method = &Backend::scanProgressChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Backend::*)(const QString & , int );
            if (_t _q_method = &Backend::newImageCaptured; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Backend::*)(const QVariant & );
            if (_t _q_method = &Backend::recognitionComplete; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Backend::*)();
            if (_t _q_method = &Backend::startCaptureRequestd; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Backend::*)(double );
            if (_t _q_method = &Backend::contrastChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Backend::*)(int );
            if (_t _q_method = &Backend::brightnessChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject *Backend::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Backend::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSBackendENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Backend::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Backend::scanProgressChanged(int _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Backend::newImageCaptured(const QString & _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Backend::recognitionComplete(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Backend::startCaptureRequestd()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Backend::contrastChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Backend::brightnessChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
