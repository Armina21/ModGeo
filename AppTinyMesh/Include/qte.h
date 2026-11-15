#ifndef __Qte__
#define __Qte__

#include <QtWidgets/qmainwindow.h>
#include "realtime.h"
#include "meshcolor.h"

QT_BEGIN_NAMESPACE
	namespace Ui { class Assets; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT
private:
  Ui::Assets* uiw;           //!< Interface

  MeshWidget* meshWidget;   //!< Viewer
  MeshColor meshColor;		//!< Mesh.

public:
  MainWindow();
  ~MainWindow();
  void CreateActions();
  void UpdateGeometry();

public slots:
  void editingSceneLeft(const Ray&);
  void editingSceneRight(const Ray&);
  void BoxMeshExample();
  void SphereImplicitExample();
  void ResetCamera();
  void UpdateMaterial();

  //SDF
  double BenchmarkSDF(const Node& shape, const std::vector<Vector>& testPoints);
  void BenchmarkPrimitive(const Node& node);
  void Sdf_Box();
  void Sdf_Sphere();
  void Sdf_Tore();
  void Sdf_Capsule();
  void Sdf_Forme1();

  // BLOB
  void CalculPerf(const Node& blob, double& timeField, double& timePolygon);
  void Blob_Forme1();
  void Blob_Forme2();

};

#endif
