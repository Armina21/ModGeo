/****************************************************************************
** Meta object code from reading C++ file 'qte.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Include/qte.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qte.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.12.0. It"
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
struct qt_meta_tag_ZN10MainWindowE_t {};
} // unnamed namespace

template <> constexpr inline auto MainWindow::qt_create_metaobjectdata<qt_meta_tag_ZN10MainWindowE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "MainWindow",
        "editingSceneLeft",
        "",
        "Ray",
        "editingSceneRight",
        "BoxMeshExample",
        "SphereImplicitExample",
        "ResetCamera",
        "UpdateMaterial",
        "BenchmarkSDF",
        "Node",
        "shape",
        "std::vector<Vector>",
        "testPoints",
        "BenchmarkPrimitive",
        "node",
        "Sdf_Box",
        "Sdf_Sphere",
        "Sdf_Tore",
        "Sdf_Capsule",
        "Sdf_Forme1",
        "CalculPerf",
        "blob",
        "double&",
        "timeField",
        "timePolygon",
        "Blob_Forme1",
        "Blob_Forme2"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'editingSceneLeft'
        QtMocHelpers::SlotData<void(const Ray &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 2 },
        }}),
        // Slot 'editingSceneRight'
        QtMocHelpers::SlotData<void(const Ray &)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 2 },
        }}),
        // Slot 'BoxMeshExample'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'SphereImplicitExample'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'ResetCamera'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'UpdateMaterial'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'BenchmarkSDF'
        QtMocHelpers::SlotData<double(const Node &, const std::vector<Vector> &)>(9, 2, QMC::AccessPublic, QMetaType::Double, {{
            { 0x80000000 | 10, 11 }, { 0x80000000 | 12, 13 },
        }}),
        // Slot 'BenchmarkPrimitive'
        QtMocHelpers::SlotData<void(const Node &)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 10, 15 },
        }}),
        // Slot 'Sdf_Box'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'Sdf_Sphere'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'Sdf_Tore'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'Sdf_Capsule'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'Sdf_Forme1'
        QtMocHelpers::SlotData<void()>(20, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'CalculPerf'
        QtMocHelpers::SlotData<void(const Node &, double &, double &)>(21, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 10, 22 }, { 0x80000000 | 23, 24 }, { 0x80000000 | 23, 25 },
        }}),
        // Slot 'Blob_Forme1'
        QtMocHelpers::SlotData<void()>(26, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'Blob_Forme2'
        QtMocHelpers::SlotData<void()>(27, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<MainWindow, qt_meta_tag_ZN10MainWindowE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10MainWindowE_t>.metaTypes,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MainWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->editingSceneLeft((*reinterpret_cast<std::add_pointer_t<Ray>>(_a[1]))); break;
        case 1: _t->editingSceneRight((*reinterpret_cast<std::add_pointer_t<Ray>>(_a[1]))); break;
        case 2: _t->BoxMeshExample(); break;
        case 3: _t->SphereImplicitExample(); break;
        case 4: _t->ResetCamera(); break;
        case 5: _t->UpdateMaterial(); break;
        case 6: { double _r = _t->BenchmarkSDF((*reinterpret_cast<std::add_pointer_t<Node>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<std::vector<Vector>>>(_a[2])));
            if (_a[0]) *reinterpret_cast<double*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->BenchmarkPrimitive((*reinterpret_cast<std::add_pointer_t<Node>>(_a[1]))); break;
        case 8: _t->Sdf_Box(); break;
        case 9: _t->Sdf_Sphere(); break;
        case 10: _t->Sdf_Tore(); break;
        case 11: _t->Sdf_Capsule(); break;
        case 12: _t->Sdf_Forme1(); break;
        case 13: _t->CalculPerf((*reinterpret_cast<std::add_pointer_t<Node>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<double&>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<double&>>(_a[3]))); break;
        case 14: _t->Blob_Forme1(); break;
        case 15: _t->Blob_Forme2(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.strings))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
