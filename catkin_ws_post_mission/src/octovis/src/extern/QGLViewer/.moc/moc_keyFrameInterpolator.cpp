/****************************************************************************
** Meta object code from reading C++ file 'keyFrameInterpolator.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../keyFrameInterpolator.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'keyFrameInterpolator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_qglviewer__KeyFrameInterpolator[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      33,   32,   32,   32, 0x05,
      48,   32,   32,   32, 0x05,

 // slots: signature, parameters, type, tag, flags
      67,   61,   32,   32, 0x0a,
      97,   86,   32,   32, 0x0a,
     122,   61,   32,   32, 0x0a,
     147,   86,   32,   32, 0x0a,
     178,   32,   32,   32, 0x0a,
     191,   61,   32,   32, 0x0a,
     218,  213,   32,   32, 0x0a,
     252,  246,   32,   32, 0x0a,
     288,  281,   32,   32, 0x0a,
     321,  316,   32,   32, 0x0a,
     348,   32,   32,   32, 0x2a,
     378,  371,   32,   32, 0x0a,
     398,   32,   32,   32, 0x2a,
     414,  281,   32,   32, 0x0a,
     438,   32,   32,   32, 0x2a,
     459,   32,   32,   32, 0x0a,
     479,   32,   32,   32, 0x0a,
     500,   32,   32,   32, 0x0a,
     522,  213,   32,   32, 0x0a,
     547,   32,   32,   32, 0x08,
     556,   32,   32,   32, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_qglviewer__KeyFrameInterpolator[] = {
    "qglviewer::KeyFrameInterpolator\0\0"
    "interpolated()\0endReached()\0frame\0"
    "addKeyFrame(Frame)\0frame,time\0"
    "addKeyFrame(Frame,float)\0"
    "addKeyFrame(Frame*const)\0"
    "addKeyFrame(Frame*const,float)\0"
    "deletePath()\0setFrame(Frame*const)\0"
    "time\0setInterpolationTime(float)\0speed\0"
    "setInterpolationSpeed(float)\0period\0"
    "setInterpolationPeriod(int)\0loop\0"
    "setLoopInterpolation(bool)\0"
    "setLoopInterpolation()\0closed\0"
    "setClosedPath(bool)\0setClosedPath()\0"
    "startInterpolation(int)\0startInterpolation()\0"
    "stopInterpolation()\0resetInterpolation()\0"
    "toggleInterpolation()\0interpolateAtTime(float)\0"
    "update()\0invalidateValues()\0"
};

void qglviewer::KeyFrameInterpolator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        KeyFrameInterpolator *_t = static_cast<KeyFrameInterpolator *>(_o);
        switch (_id) {
        case 0: _t->interpolated(); break;
        case 1: _t->endReached(); break;
        case 2: _t->addKeyFrame((*reinterpret_cast< const Frame(*)>(_a[1]))); break;
        case 3: _t->addKeyFrame((*reinterpret_cast< const Frame(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 4: _t->addKeyFrame((*reinterpret_cast< const Frame*const(*)>(_a[1]))); break;
        case 5: _t->addKeyFrame((*reinterpret_cast< const Frame*const(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 6: _t->deletePath(); break;
        case 7: _t->setFrame((*reinterpret_cast< Frame*const(*)>(_a[1]))); break;
        case 8: _t->setInterpolationTime((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 9: _t->setInterpolationSpeed((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 10: _t->setInterpolationPeriod((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->setLoopInterpolation((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->setLoopInterpolation(); break;
        case 13: _t->setClosedPath((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->setClosedPath(); break;
        case 15: _t->startInterpolation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->startInterpolation(); break;
        case 17: _t->stopInterpolation(); break;
        case 18: _t->resetInterpolation(); break;
        case 19: _t->toggleInterpolation(); break;
        case 20: _t->interpolateAtTime((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 21: _t->update(); break;
        case 22: _t->invalidateValues(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData qglviewer::KeyFrameInterpolator::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject qglviewer::KeyFrameInterpolator::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_qglviewer__KeyFrameInterpolator,
      qt_meta_data_qglviewer__KeyFrameInterpolator, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &qglviewer::KeyFrameInterpolator::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *qglviewer::KeyFrameInterpolator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *qglviewer::KeyFrameInterpolator::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_qglviewer__KeyFrameInterpolator))
        return static_cast<void*>(const_cast< KeyFrameInterpolator*>(this));
    return QObject::qt_metacast(_clname);
}

int qglviewer::KeyFrameInterpolator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    return _id;
}

// SIGNAL 0
void qglviewer::KeyFrameInterpolator::interpolated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void qglviewer::KeyFrameInterpolator::endReached()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
