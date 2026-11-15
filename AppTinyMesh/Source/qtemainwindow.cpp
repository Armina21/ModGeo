#include "qte.h"
#include "implicits.h"
#include "ui_interface.h"

#include <random>
#include <chrono>
#include <iostream>

MainWindow::MainWindow() : QMainWindow(), uiw(new Ui::Assets)
{
	// Chargement de l'interface
    uiw->setupUi(this);

	// Chargement du GLWidget
	meshWidget = new MeshWidget;
	QGridLayout* GLlayout = new QGridLayout;
	GLlayout->addWidget(meshWidget, 0, 0);
	GLlayout->setContentsMargins(0, 0, 0, 0);
    uiw->widget_GL->setLayout(GLlayout);

	// Creation des connect
	CreateActions();

	meshWidget->SetCamera(Camera(Vector(10, 0, 0), Vector(0.0, 0.0, 0.0)));
}

MainWindow::~MainWindow()
{
	delete meshWidget;
}

void MainWindow::CreateActions()
{
	// Buttons
    connect(uiw->boxMesh, SIGNAL(clicked()), this, SLOT(BoxMeshExample()));
    connect(uiw->sphereImplicit, SIGNAL(clicked()), this, SLOT(SphereImplicitExample()));
    connect(uiw->resetcameraButton, SIGNAL(clicked()), this, SLOT(ResetCamera()));
    connect(uiw->wireframe, SIGNAL(clicked()), this, SLOT(UpdateMaterial()));
    connect(uiw->radioShadingButton_1, SIGNAL(clicked()), this, SLOT(UpdateMaterial()));
    connect(uiw->radioShadingButton_2, SIGNAL(clicked()), this, SLOT(UpdateMaterial()));

	// Buttons SDF
    connect(uiw->sdf_box, SIGNAL(clicked()), this, SLOT(Sdf_Box()));
	connect(uiw->sdf_sphere, SIGNAL(clicked()), this, SLOT(Sdf_Sphere()));
    connect(uiw->sdf_tore, SIGNAL(clicked()), this, SLOT(Sdf_Tore()));
    connect(uiw->sdf_capsule, SIGNAL(clicked()), this, SLOT(Sdf_Capsule()));
    connect(uiw->sdf_forme1, SIGNAL(clicked()), this, SLOT(Sdf_Forme1()));

    // Buttons Blob 
    connect(uiw->blob_Forme1, SIGNAL(clicked()), this, SLOT(Blob_Forme1()));
    connect(uiw->blob_Forme2, SIGNAL(clicked()), this, SLOT(Blob_Forme2()));
    
	// Widget edition
	connect(meshWidget, SIGNAL(_signalEditSceneLeft(const Ray&)), this, SLOT(editingSceneLeft(const Ray&)));
	connect(meshWidget, SIGNAL(_signalEditSceneRight(const Ray&)), this, SLOT(editingSceneRight(const Ray&)));
}

void MainWindow::editingSceneLeft(const Ray&)
{
}

void MainWindow::editingSceneRight(const Ray&)
{
}

void MainWindow::BoxMeshExample()
{
	Mesh boxMesh = Mesh(Box(1.0));

	std::vector<Color> cols;
	cols.resize(boxMesh.Vertexes());
    for (size_t i = 0; i < cols.size(); i++)
		cols[i] = Color(double(i) / 6.0, fmod(double(i) * 39.478378, 1.0), 0.0);

	meshColor = MeshColor(boxMesh, cols, boxMesh.VertexIndexes());
	UpdateGeometry();
}

void MainWindow::SphereImplicitExample()
{
  AnalyticScalarField implicit;

  Mesh implicitMesh;
  implicit.Polygonize(31, implicitMesh, Box(2.0));

  std::vector<Color> cols;
  cols.resize(implicitMesh.Vertexes());
  for (size_t i = 0; i < cols.size(); i++)
    cols[i] = Color(0.8, 0.8, 0.8);

  meshColor = MeshColor(implicitMesh, cols, implicitMesh.VertexIndexes());
  UpdateGeometry();
}

void MainWindow::UpdateGeometry()
{
	meshWidget->ClearAll();
	meshWidget->AddMesh("BoxMesh", meshColor);

    uiw->lineEdit->setText(QString::number(meshColor.Vertexes()));
    uiw->lineEdit_2->setText(QString::number(meshColor.Triangles()));

	UpdateMaterial();
}

void MainWindow::UpdateMaterial()
{
    meshWidget->UseWireframeGlobal(uiw->wireframe->isChecked());

    if (uiw->radioShadingButton_1->isChecked())
		meshWidget->SetMaterialGlobal(MeshMaterial::Normal);
	else
		meshWidget->SetMaterialGlobal(MeshMaterial::Color);
}

void MainWindow::ResetCamera()
{
	meshWidget->SetCamera(Camera(Vector(-10.0), Vector(0.0)));
}


//SDF
double MainWindow::BenchmarkSDF(const Node& shape, const std::vector<Vector>& testPoints)
{
    using Clock = std::chrono::steady_clock;

    constexpr int iterations = 10000000;

    double sum = 0.0;

    auto start = Clock::now();

    for (int i = 0; i < iterations; ++i)
    {
        const Vector& p = testPoints[i % testPoints.size()];
        sum += shape.Value(p);
    }

    auto end = Clock::now();

    // Empêcher l'élimination du résultat
    volatile double checksum = sum;
    (void)checksum;

    return std::chrono::duration<double, std::milli>(
        end - start
    ).count();
}

void MainWindow::BenchmarkPrimitive(const Node& node)
{
    // Génération des points de test
    std::vector<Vector> testPoints;

    std::mt19937 generator(42);
    std::uniform_real_distribution<double> distribution(-6.0, 6.0);

    for (int i = 0; i < 100000; ++i)
    {
        testPoints.emplace_back(
            distribution(generator),
            distribution(generator),
            distribution(generator)
        );
    }

    // Benchmark des primitives
    double timeNode = BenchmarkSDF(node, testPoints);

    uiw->lineEdit_11->setText(
        QString::number(timeNode, 'f', 3)
    );
}

void MainWindow::Sdf_Box()
{
    // Création de la box
    auto box = std::make_unique<BoxSDF>(
        Vector(0.0, 0.0, 0.0),
        Vector(1.0, 1.0, 1.0)
    );

    // Création du champ implicite à partir de la sphère
    AnalyticScalarField implicit(box.get());

    // Polygonisation
    Mesh implicitMesh;
    implicit.Polygonize(
        31,
        implicitMesh,
        Box(
            Vector(-4.0),
            Vector(4.0)
        )
    );

    // Couleur
    std::vector<Color> cols;
    cols.resize(implicitMesh.Vertexes());

    for (size_t i = 0; i < cols.size(); i++)
        cols[i] = Color(0.8, 0.8, 0.8);

    meshColor = MeshColor(
        implicitMesh,
        cols,
        implicitMesh.VertexIndexes()
    );

    BenchmarkPrimitive(*box);

    UpdateGeometry();
}

void MainWindow::Sdf_Sphere()
{
    // Création de la sphère
    auto sphere = std::make_unique<Sphere>(
        Vector(0.0, 0.0, 0.0), // Centre
        3.0                    // Rayon
    );

    // Création du champ implicite à partir de la sphère
    AnalyticScalarField implicit(sphere.get());

    // Polygonisation
    Mesh implicitMesh;
    implicit.Polygonize(
        31,
        implicitMesh,
        Box(
            Vector(-4.0),
            Vector(4.0)
        )
    );

    // Couleur
    std::vector<Color> cols;
    cols.resize(implicitMesh.Vertexes());

    for (size_t i = 0; i < cols.size(); i++)
        cols[i] = Color(0.8, 0.8, 0.8);

    meshColor = MeshColor(
        implicitMesh,
        cols,
        implicitMesh.VertexIndexes()
    );

    BenchmarkPrimitive(*sphere);

    UpdateGeometry();
}

void MainWindow::Sdf_Tore()
{
    // Création du tore
    auto tore = std::make_unique<Tore>(
        Vector(0.0, 0.0, 0.0), // Centre
        3.0,                   // Grand rayon
        1.0                    // Rayon du tube
    );

    // Création du champ implicite à partir du tore
    AnalyticScalarField implicit(tore.get());

    // Polygonisation
    Mesh implicitMesh;
    implicit.Polygonize(
        31,
        implicitMesh,
        Box(
            Vector(-4.0),
            Vector(4.0)
        )
    );

    // Couleur
    std::vector<Color> cols;
    cols.resize(implicitMesh.Vertexes());

    for (size_t i = 0; i < cols.size(); i++)
        cols[i] = Color(0.8, 0.8, 0.8);

    meshColor = MeshColor(
        implicitMesh,
        cols,
        implicitMesh.VertexIndexes()
    );

    BenchmarkPrimitive(*tore);

    UpdateGeometry();
}

void MainWindow::Sdf_Capsule()
{
	// Création de la capsule
    auto capsule = std::make_unique<Capsule>(
        Vector(-2.0, 0.0, 0.0),
        Vector(2.0, 0.0, 0.0),
        1.0 
    );

    // Création du champ implicite à partir de la capsule
    AnalyticScalarField implicit(capsule.get());

    // Polygonisation
    Mesh implicitMesh;
    implicit.Polygonize(
        31,
        implicitMesh,
        Box(
            Vector(-4.0),
            Vector(4.0)
        )
    );

    // Couleur
    std::vector<Color> cols;
    cols.resize(implicitMesh.Vertexes());

    for (size_t i = 0; i < cols.size(); i++)
        cols[i] = Color(0.8, 0.8, 0.8);

    meshColor = MeshColor(
        implicitMesh,
        cols,
        implicitMesh.VertexIndexes()
    );

    BenchmarkPrimitive(*capsule);

    UpdateGeometry();
}

void MainWindow::Sdf_Forme1() {

    auto capsule1 = std::make_unique<Capsule>(
        Vector(-2.0, 0.0, 0.0),
        Vector(2.0, 0.0, 0.0),
        0.5
    );

    auto capsule2 = std::make_unique<Capsule>(
        Vector(0.0, -2.0, 0.0),
        Vector(0.0, 2.0, 0.0),
        0.5
    );

    auto shape = std::make_unique<BooleanNode>(
        std::move(capsule1),
        std::move(capsule2),
		BooleanOperation::Union
	);

    auto capsule3 = std::make_unique<Capsule>(
        Vector(0.0, 0.0, -2.0),
        Vector(0.0, 0.0, 2.0),
        0.5
    );

    auto shape1 = std::make_unique<BooleanNode>(
        std::move(capsule3),
        std::move(shape),
        BooleanOperation::Union
    );

    auto box = std::make_unique<BoxSDF>(
        Vector(0.0, 0.0, 0.0),
        Vector(1.0, 1.0, 1.0)
    );

    auto sphere = std::make_unique<Sphere>(
        Vector(0.0, 0.0, 0.0),
        1.3
	);

    auto shape2 = std::make_unique<BooleanNode>(
        std::move(sphere),
        std::move(box),
        BooleanOperation::Intersection
    );

    auto shape3 = std::make_unique<BooleanNode>(
        std::move(shape2),
        std::move(shape1),
        BooleanOperation::Difference
	);

    AnalyticScalarField implicit(shape3.get());

    // Polygonisation
    Mesh implicitMesh;
    implicit.Polygonize(
        64,
        implicitMesh,
        Box(
            Vector(-1.5),
            Vector(1.5)
        )
    );

    // Couleur
    std::vector<Color> cols;
    cols.resize(implicitMesh.Vertexes());

    for (size_t i = 0; i < cols.size(); i++)
        cols[i] = Color(0.8, 0.8, 0.8);

    meshColor = MeshColor(
        implicitMesh,
        cols,
        implicitMesh.VertexIndexes()
    );

    BenchmarkPrimitive(*shape3);

    UpdateGeometry();
}

//BLOB
void MainWindow::CalculPerf(const Node& blob, double& timeField, double& timePolygon) {
    using Clock = std::chrono::steady_clock;

    // Points de test identiques pour chaque appel
    static const std::vector<Vector> testPoints = []()
        {
            std::vector<Vector> points;

            std::mt19937 gen(42);
            std::uniform_real_distribution<double> coord(-6.0, 6.0);

            for (int i = 0; i < 100000; ++i)
            {
                points.emplace_back(
                    coord(gen),
                    coord(gen),
                    coord(gen)
                );
            }

            return points;
        }();

    // =====================================
    // TEMPS D'EVALUATION DU CHAMP
    // =====================================

    double sum = 0.0;

    auto startField = Clock::now();

    for (const Vector& p : testPoints)
    {
        sum += blob.Value(p);
    }

    auto endField = Clock::now();

    timeField =
        std::chrono::duration<double, std::milli>(
            endField - startField
        ).count();

    // Conserver le résultat du calcul
    volatile double checksum = sum;
    (void)checksum;

    // =====================================
    // TEMPS DE POLYGONISATION
    // =====================================

    AnalyticScalarField implicit(&blob);
    Mesh mesh;

    auto startPolygon = Clock::now();

    implicit.Polygonize(
        64,
        mesh,
        Box(Vector(-6.0), Vector(6.0))
    );

    auto endPolygon = Clock::now();

    timePolygon =
        std::chrono::duration<double, std::milli>(
            endPolygon - startPolygon
        ).count();
}

void MainWindow::Blob_Forme1()
{
    auto blobWyvill = std::make_unique<BlobNode>(
        0.5, BlobKernel::Wyvill
    );

    auto blobBlinn = std::make_unique<BlobNode>(
        0.5, BlobKernel::Blinn
    );

    // =====================================
    // POINTS
    // =====================================

    blobWyvill->AddPoint(Vector(-3.0, 0.0, 0.0), 2.0);
    blobWyvill->AddPoint(Vector(-1.2, 0.0, 0.0), 1.2);

    blobBlinn->AddPoint(Vector(-3.0, 0.0, 0.0), 2.0);
    blobBlinn->AddPoint(Vector(-1.2, 0.0, 0.0), 1.2);

    // =====================================
    // SEGMENTS
    // =====================================

    blobWyvill->AddSegment(
        Vector(2.0, 0.0, 0.0),
        Vector(5.0, 3.0, 0.0),
        1.0
    );

    blobWyvill->AddSegment(
        Vector(3.0, -1.0, 0.0),
        Vector(4.0, 1.0, 0.0),
        0.6
    );

    blobBlinn->AddSegment(
        Vector(2.0, 0.0, 0.0),
        Vector(5.0, 3.0, 0.0),
        1.0
    );

    blobBlinn->AddSegment(
        Vector(3.0, -1.0, 0.0),
        Vector(4.0, 1.0, 0.0),
        0.6
    );

    // =====================================
    // CALCUL DES PERFORMANCES
    // =====================================

    double timeFieldWyvill;
    double timePolygonWyvill;

    double timeFieldBlinn;
    double timePolygonBlinn;

    CalculPerf(
        *blobWyvill,
        timeFieldWyvill,
        timePolygonWyvill
    );

    CalculPerf(
        *blobBlinn,
        timeFieldBlinn,
        timePolygonBlinn
    );

    // =====================================
    // AFFICHAGE DES PERFORMANCES
    // =====================================

    uiw->lineEdit_6->setText(
        QString::number(timeFieldWyvill, 'f', 3)
    );

    uiw->lineEdit_7->setText(
        QString::number(timePolygonWyvill, 'f', 3)
    );

    uiw->lineEdit_8->setText(
        QString::number(timeFieldBlinn, 'f', 3)
    );

    uiw->lineEdit_9->setText(
        QString::number(timePolygonBlinn, 'f', 3)
    );

    // =====================================
    // AFFICHAGE DU MAILLAGE WYVILL
    // =====================================

    AnalyticScalarField implicit(blobWyvill.get());

    Mesh implicitMesh;

    implicit.Polygonize(
        64,
        implicitMesh,
        Box(Vector(-5.0), Vector(5.0))
    );

    std::vector<Color> cols(implicitMesh.Vertexes());

    for (auto& c : cols)
        c = Color(0.2, 0.7, 0.9);

    meshColor = MeshColor(
        implicitMesh,
        cols,
        implicitMesh.VertexIndexes()
    );

    // =====================================
    // LIPSCHITZ
    // =====================================

    double lipschitz = blobWyvill->LipschitzBound();

    uiw->lineEdit_3->setText(
        QString::number(lipschitz, 'f', 3)
    );

    double lipschitzGrad =
        blobWyvill->NumericalLipschitzBound(
            Box(Vector(-5.0), Vector(5.0)),
            30,
            0.001
        );

    uiw->lineEdit_4->setText(
        QString::number(lipschitzGrad, 'f', 3)
    );

    UpdateGeometry();
}



void MainWindow::Blob_Forme2()
{
    auto blobWyvill = std::make_unique<BlobNode>(
        0.5, BlobKernel::Wyvill
    );

    auto blobBlinn = std::make_unique<BlobNode>(
        0.5, BlobKernel::Blinn
    );

    // Générateur aléatoire
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_real_distribution<double> position(-2.5, 2.5);
    std::uniform_real_distribution<double> offset(-3.0, 3.0);
    std::uniform_real_distribution<double> radius(0.5, 0.9);
    std::uniform_real_distribution<double> color(0.0, 1.0);

    // =====================================
    // GENERATION DES SPHERES
    // =====================================

    for (int i = 0; i < 50; i++)
    {
        double x = position(gen);
        double y = offset(gen);
        double z = offset(gen);

        Vector center(x, y, z);

        double r = radius(gen);

        Color c(
            color(gen),
            color(gen),
            color(gen)
        );

        blobWyvill->AddPoint(center, r, c);
        blobBlinn->AddPoint(center, r, c);
    }

    // =====================================
    // GENERATION DES SEGMENTS
    // =====================================

    for (int i = 0; i < 30; i++)
    {
        Vector a(
            position(gen),
            offset(gen),
            offset(gen)
        );

        Vector b(
            a[0] + offset(gen) * 0.5,
            a[1] + offset(gen) * 0.5,
            a[2] + offset(gen) * 0.5
        );

        double r = radius(gen);

        Color c(
            color(gen),
            color(gen),
            color(gen)
        );

        blobWyvill->AddSegment(a, b, r, c);
        blobBlinn->AddSegment(a, b, r, c);
    }

    // =====================================
    // CALCUL DES PERFORMANCES
    // =====================================

    double timeFieldWyvill;
    double timePolygonWyvill;

    double timeFieldBlinn;
    double timePolygonBlinn;

    CalculPerf(
        *blobWyvill,
        timeFieldWyvill,
        timePolygonWyvill
    );

    CalculPerf(
        *blobBlinn,
        timeFieldBlinn,
        timePolygonBlinn
    );

    // =====================================
    // AFFICHAGE DES PERFORMANCES
    // =====================================

    // Wyvill
    uiw->lineEdit_6->setText(
        QString::number(timeFieldWyvill, 'f', 3)
    );

    uiw->lineEdit_7->setText(
        QString::number(timePolygonWyvill, 'f', 3)
    );

    // Blinn
    uiw->lineEdit_8->setText(
        QString::number(timeFieldBlinn, 'f', 3)
    );

    uiw->lineEdit_9->setText(
        QString::number(timePolygonBlinn, 'f', 3)
    );

    // =====================================
    // AFFICHAGE DU MAILLAGE WYVILL
    // =====================================

    AnalyticScalarField implicit(blobWyvill.get());

    Mesh implicitMesh;

    implicit.Polygonize(
        64,
        implicitMesh,
        Box(Vector(-6.0), Vector(6.0))
    );

    std::vector<Color> cols;
    cols.reserve(implicitMesh.Vertexes());

    for (int i = 0; i < implicitMesh.Vertexes(); i++)
    {
        cols.push_back(
            blobWyvill->EvaluateColor(implicitMesh.Vertex(i))
        );
    }

    meshColor = MeshColor(
        implicitMesh,
        cols,
        implicitMesh.VertexIndexes()
    );

    // =====================================
    // LIPSCHITZ WYVILL
    // =====================================

    double lipschitz = blobWyvill->LipschitzBound();

    uiw->lineEdit_3->setText(
        QString::number(lipschitz, 'f', 3)
    );

    double lipschitzGrad =
        blobWyvill->NumericalLipschitzBound(
            Box(Vector(-6.0), Vector(6.0)),
            30,
            0.001
        );

    uiw->lineEdit_4->setText(
        QString::number(lipschitzGrad, 'f', 3)
    );

    UpdateGeometry();
}
