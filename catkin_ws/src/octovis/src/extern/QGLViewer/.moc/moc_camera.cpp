/****************************************************************************
** Meta object code from reading C++ file 'camera.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../camera.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'camera.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_qglviewer__Camera[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      42,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   19,   18,   18, 0x0a,
      42,   40,   18,   18, 0x0a,
      79,   69,   18,   18, 0x0a,
     117,  107,   18,   18, 0x0a,
     142,  139,   18,   18, 0x2a,
     169,  159,   18,   18, 0x0a,
     198,  191,   18,   18, 0x0a,
     210,   18,   18,   18, 0x0a,
     242,  228,   18,   18, 0x0a,
     271,  263,   18,   18, 0x0a,
     305,  295,   18,   18, 0x0a,
     328,   18,   18,   18, 0x0a,
     348,  342,   18,   18, 0x0a,
     381,   18,   18,   18, 0x0a,
     417,  405,   18,   18, 0x0a,
     449,  444,   18,   18, 0x0a,
     467,  463,   18,   18, 0x0a,
     494,  489,   18,   18, 0x0a,
     526,   18,   18,   18, 0x0a,
     552,  545,   18,   18, 0x0a,
     587,  574,   18,   18, 0x0a,
     625,  620,   18,   18, 0x0a,
     652,  620,   18,   18, 0x0a,
     690,  683,   18,   18, 0x0a,
     719,  712,   18,   18, 0x0a,
     744,  342,  739,   18, 0x0a,
     776,  263,   18,   18, 0x0a,
     809,  805,   18,   18, 0x0a,
     836,  342,  739,   18, 0x0a,
     879,  875,   18,   18, 0x0a,
     924,  918,   18,   18, 0x0a,
     982,  980,   18,   18, 0x0a,
    1005,  980,   18,   18, 0x0a,
    1019,  980,   18,   18, 0x0a,
    1035,  980,   18,   18, 0x0a,
    1050,   18,   18,   18, 0x0a,
    1071, 1065,   18,   18, 0x0a,
    1099, 1090,   18,   18, 0x0a,
    1120, 1090,   18,   18, 0x0a,
    1161, 1155,   18,   18, 0x0a,
    1191, 1090,   18,   18, 0x0a,
    1223, 1215,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_qglviewer__Camera[] = {
    "qglviewer::Camera\0\0pos\0setPosition(Vec)\0"
    "q\0setOrientation(Quaternion)\0theta,phi\0"
    "setOrientation(float,float)\0up,noMove\0"
    "setUpVector(Vec,bool)\0up\0setUpVector(Vec)\0"
    "direction\0setViewDirection(Vec)\0target\0"
    "lookAt(Vec)\0showEntireScene()\0"
    "center,radius\0fitSphere(Vec,float)\0"
    "min,max\0fitBoundingBox(Vec,Vec)\0"
    "rectangle\0fitScreenRegion(QRect)\0"
    "centerScene()\0pixel\0"
    "interpolateToZoomOnPixel(QPoint)\0"
    "interpolateToFitScene()\0fr,duration\0"
    "interpolateTo(Frame,float)\0type\0"
    "setType(Type)\0fov\0setFieldOfView(float)\0"
    "hfov\0setHorizontalFieldOfView(float)\0"
    "setFOVToFitScene()\0aspect\0"
    "setAspectRatio(float)\0width,height\0"
    "setScreenWidthAndHeight(int,int)\0coef\0"
    "setZNearCoefficient(float)\0"
    "setZClippingCoefficient(float)\0radius\0"
    "setSceneRadius(float)\0center\0"
    "setSceneCenter(Vec)\0bool\0"
    "setSceneCenterFromPixel(QPoint)\0"
    "setSceneBoundingBox(Vec,Vec)\0rap\0"
    "setRevolveAroundPoint(Vec)\0"
    "setRevolveAroundPointFromPixel(QPoint)\0"
    "mcf\0setFrame(ManipulatedCameraFrame*const)\0"
    "i,kfi\0setKeyFrameInterpolator(int,KeyFrameInterpolator*const)\0"
    "i\0addKeyFrameToPath(int)\0playPath(int)\0"
    "deletePath(int)\0resetPath(int)\0"
    "drawAllPaths()\0speed\0setFlySpeed(float)\0"
    "distance\0setIODistance(float)\0"
    "setPhysicalDistanceToScreen(float)\0"
    "width\0setPhysicalScreenWidth(float)\0"
    "setFocusDistance(float)\0element\0"
    "initFromDOMElement(QDomElement)\0"
};

void qglviewer::Camera::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Camera *_t = static_cast<Camera *>(_o);
        switch (_id) {
        case 0: _t->setPosition((*reinterpret_cast< const Vec(*)>(_a[1]))); break;
        case 1: _t->setOrientation((*reinterpret_cast< const Quaternion(*)>(_a[1]))); break;
        case 2: _t->setOrientation((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 3: _t->setUpVector((*reinterpret_cast< const Vec(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->setUpVector((*reinterpret_cast< const Vec(*)>(_a[1]))); break;
        case 5: _t->setViewDirection((*reinterpret_cast< const Vec(*)>(_a[1]))); break;
        case 6: _t->lookAt((*reinterpret_cast< const Vec(*)>(_a[1]))); break;
        case 7: _t->showEntireScene(); break;
        case 8: _t->fitSphere((*reinterpret_cast< const Vec(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 9: _t->fitBoundingBox((*reinterpret_cast< const Vec(*)>(_a[1])),(*reinterpret_cast< const Vec(*)>(_a[2]))); break;
        case 10: _t->fitScreenRegion((*reinterpret_cast< const QRect(*)>(_a[1]))); break;
        case 11: _t->centerScene(); break;
        case 12: _t->interpolateToZoomOnPixel((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 13: _t->interpolateToFitScene(); break;
        case 14: _t->interpolateTo((*reinterpret_cast< const Frame(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 15: _t->setType((*reinterpret_cast< Type(*)>(_a[1]))); break;
        case 16: _t->setFieldOfView((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 17: _t->setHorizontalFieldOfView((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 18: _t->setFOVToFitScene(); break;
        case 19: _t->setAspectRatio((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 20: _t->setScreenWidthAndHeight((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 21: _t->setZNearCoefficient((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 22: _t->setZClippingCoefficient((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 23: _t->setSceneRadius((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 24: _t->setSceneCenter((*reinterpret_cast< const Vec(*)>(_a[1]))); break;
        case 25: { bool _r = _t->setSceneCenterFromPixel((*reinterpret_cast< const QPoint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 26: _t->setSceneBoundingBox((*reinterpret_cast< const Vec(*)>(_a[1])),(*reinterpret_cast< const Vec(*)>(_a[2]))); break;
        case 27: _t->setRevolveAroundPoint((*reinterpret_cast< const Vec(*)>(_a[1]))); break;
        case 28: { bool _r = _t->setRevolveAroundPointFromPixel((*reinterpret_cast< const QPoint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 29: _t->setFrame((*reinterpret_cast< ManipulatedCameraFrame*const(*)>(_a[1]))); break;
        case 30: _t->setKeyFrameInterpolator((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< KeyFrameInterpolator*const(*)>(_a[2]))); break;
        case 31: _t->addKeyFrameToPath((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->playPath((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: _t->deletePath((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->resetPath((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 35: _t->drawAllPaths(); break;
        case 36: _t->setFlySpeed((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 37: _t->setIODistance((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 38: _t->setPhysicalDistanceToScreen((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 39: _t->setPhysicalScreenWidth((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 40: _t->setFocusDistance((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 41: _t->initFromDOMElement((*reinterpret_cast< const QDomElement(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData qglviewer::Camera::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject qglviewer::Camera::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_qglviewer__Camera,
      qt_meta_data_qglviewer__Camera, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &qglviewer::Camera::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *qglviewer::Camera::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *qglviewer::Camera::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_qglviewer__Camera))
        return static_cast<void*>(const_cast< Camera*>(this));
    return QObject::qt_metacast(_clname);
}

int qglviewer::Camera::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 42)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 42;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
