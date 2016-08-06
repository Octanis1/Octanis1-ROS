/****************************************************************************
** Meta object code from reading C++ file 'manipulatedCameraFrame.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../manipulatedCameraFrame.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'manipulatedCameraFrame.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_qglviewer__ManipulatedCameraFrame[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      41,   35,   34,   34, 0x0a,
      63,   60,   34,   34, 0x0a,
      83,   34,   34,   34, 0x09,
      98,   90,   34,   34, 0x0a,
     130,   34,   34,   34, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_qglviewer__ManipulatedCameraFrame[] = {
    "qglviewer::ManipulatedCameraFrame\0\0"
    "speed\0setFlySpeed(float)\0up\0"
    "setFlyUpVector(Vec)\0spin()\0element\0"
    "initFromDOMElement(QDomElement)\0"
    "flyUpdate()\0"
};

void qglviewer::ManipulatedCameraFrame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ManipulatedCameraFrame *_t = static_cast<ManipulatedCameraFrame *>(_o);
        switch (_id) {
        case 0: _t->setFlySpeed((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->setFlyUpVector((*reinterpret_cast< const Vec(*)>(_a[1]))); break;
        case 2: _t->spin(); break;
        case 3: _t->initFromDOMElement((*reinterpret_cast< const QDomElement(*)>(_a[1]))); break;
        case 4: _t->flyUpdate(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData qglviewer::ManipulatedCameraFrame::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject qglviewer::ManipulatedCameraFrame::staticMetaObject = {
    { &ManipulatedFrame::staticMetaObject, qt_meta_stringdata_qglviewer__ManipulatedCameraFrame,
      qt_meta_data_qglviewer__ManipulatedCameraFrame, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &qglviewer::ManipulatedCameraFrame::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *qglviewer::ManipulatedCameraFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *qglviewer::ManipulatedCameraFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_qglviewer__ManipulatedCameraFrame))
        return static_cast<void*>(const_cast< ManipulatedCameraFrame*>(this));
    return ManipulatedFrame::qt_metacast(_clname);
}

int qglviewer::ManipulatedCameraFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ManipulatedFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
