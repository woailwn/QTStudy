/****************************************************************************
** Meta object code from reading C++ file 'cameraworker.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../cameraworker.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cameraworker.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSCameraWorkerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSCameraWorkerENDCLASS = QtMocHelpers::stringData(
    "CameraWorker",
    "progressUpdated",
    "",
    "step",
    "message",
    "imageCaptured",
    "image",
    "frameIndex",
    "captureFinished",
    "errorOccurred",
    "errorMessage",
    "startCapture",
    "setContrast",
    "contrast",
    "setBrightness",
    "brightness",
    "processCapturedImage",
    "requestId",
    "img",
    "triggerNextCapture"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSCameraWorkerENDCLASS_t {
    uint offsetsAndSizes[40];
    char stringdata0[13];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[8];
    char stringdata5[14];
    char stringdata6[6];
    char stringdata7[11];
    char stringdata8[16];
    char stringdata9[14];
    char stringdata10[13];
    char stringdata11[13];
    char stringdata12[12];
    char stringdata13[9];
    char stringdata14[14];
    char stringdata15[11];
    char stringdata16[21];
    char stringdata17[10];
    char stringdata18[4];
    char stringdata19[19];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSCameraWorkerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSCameraWorkerENDCLASS_t qt_meta_stringdata_CLASSCameraWorkerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "CameraWorker"
        QT_MOC_LITERAL(13, 15),  // "progressUpdated"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 4),  // "step"
        QT_MOC_LITERAL(35, 7),  // "message"
        QT_MOC_LITERAL(43, 13),  // "imageCaptured"
        QT_MOC_LITERAL(57, 5),  // "image"
        QT_MOC_LITERAL(63, 10),  // "frameIndex"
        QT_MOC_LITERAL(74, 15),  // "captureFinished"
        QT_MOC_LITERAL(90, 13),  // "errorOccurred"
        QT_MOC_LITERAL(104, 12),  // "errorMessage"
        QT_MOC_LITERAL(117, 12),  // "startCapture"
        QT_MOC_LITERAL(130, 11),  // "setContrast"
        QT_MOC_LITERAL(142, 8),  // "contrast"
        QT_MOC_LITERAL(151, 13),  // "setBrightness"
        QT_MOC_LITERAL(165, 10),  // "brightness"
        QT_MOC_LITERAL(176, 20),  // "processCapturedImage"
        QT_MOC_LITERAL(197, 9),  // "requestId"
        QT_MOC_LITERAL(207, 3),  // "img"
        QT_MOC_LITERAL(211, 18)   // "triggerNextCapture"
    },
    "CameraWorker",
    "progressUpdated",
    "",
    "step",
    "message",
    "imageCaptured",
    "image",
    "frameIndex",
    "captureFinished",
    "errorOccurred",
    "errorMessage",
    "startCapture",
    "setContrast",
    "contrast",
    "setBrightness",
    "brightness",
    "processCapturedImage",
    "requestId",
    "img",
    "triggerNextCapture"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSCameraWorkerENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   68,    2, 0x06,    1 /* Public */,
       5,    2,   73,    2, 0x06,    4 /* Public */,
       8,    0,   78,    2, 0x06,    7 /* Public */,
       9,    1,   79,    2, 0x06,    8 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      11,    0,   82,    2, 0x0a,   10 /* Public */,
      12,    1,   83,    2, 0x0a,   11 /* Public */,
      14,    1,   86,    2, 0x0a,   13 /* Public */,
      16,    2,   89,    2, 0x08,   15 /* Private */,
      19,    0,   94,    2, 0x08,   18 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QImage, QMetaType::Int,    6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   13,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int, QMetaType::QImage,   17,   18,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject CameraWorker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSCameraWorkerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSCameraWorkerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSCameraWorkerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<CameraWorker, std::true_type>,
        // method 'progressUpdated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'imageCaptured'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QImage &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'captureFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'errorOccurred'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'startCapture'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setContrast'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'setBrightness'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'processCapturedImage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QImage &, std::false_type>,
        // method 'triggerNextCapture'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void CameraWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CameraWorker *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->progressUpdated((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 1: _t->imageCaptured((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 2: _t->captureFinished(); break;
        case 3: _t->errorOccurred((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->startCapture(); break;
        case 5: _t->setContrast((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 6: _t->setBrightness((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->processCapturedImage((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QImage>>(_a[2]))); break;
        case 8: _t->triggerNextCapture(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CameraWorker::*)(int , const QString & );
            if (_t _q_method = &CameraWorker::progressUpdated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CameraWorker::*)(const QImage & , int );
            if (_t _q_method = &CameraWorker::imageCaptured; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CameraWorker::*)();
            if (_t _q_method = &CameraWorker::captureFinished; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CameraWorker::*)(const QString & );
            if (_t _q_method = &CameraWorker::errorOccurred; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject *CameraWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CameraWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSCameraWorkerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CameraWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void CameraWorker::progressUpdated(int _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CameraWorker::imageCaptured(const QImage & _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CameraWorker::captureFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void CameraWorker::errorOccurred(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
