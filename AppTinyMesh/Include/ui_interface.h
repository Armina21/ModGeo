/********************************************************************************
** Form generated from reading UI file 'interface.ui'
**
** Created by: Qt User Interface Compiler version 6.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE_H
#define UI_INTERFACE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Assets
{
public:
    QAction *actionExit;
    QAction *actionNew_Scene;
    QAction *actionExport_obj;
    QAction *actionExport_ma;
    QAction *actionLoad_ma;
    QAction *actionGL;
    QAction *actionVectorized;
    QAction *actionExport_svg;
    QAction *actionSphere_Tracing_png;
    QWidget *centralwidget;
    QHBoxLayout *hboxLayout;
    QGroupBox *Objects_groupBox;
    QPushButton *boxMesh;
    QPushButton *sdf_box;
    QPushButton *sdf_sphere;
    QPushButton *sdf_tore;
    QPushButton *sdf_capsule;
    QPushButton *sdf_forme1;
    QPushButton *blob_Forme1;
    QPushButton *blob_Forme2;
    QPushButton *resetcameraButton;
    QPushButton *sphereImplicit;
    QWidget *widget_GL;
    QGroupBox *Parameters_groupBox;
    QGroupBox *groupBox_4;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QLabel *label_5;
    QLineEdit *lineEdit_4;
    QLabel *label_11;
    QLineEdit *lineEdit_11;
    QGroupBox *groupBox_5;
    QLabel *label_6;
    QLineEdit *lineEdit_6;
    QLabel *label_7;
    QLineEdit *lineEdit_7;
    QGroupBox *groupBox_6;
    QLabel *label_8;
    QLineEdit *lineEdit_8;
    QLabel *label_9;
    QLineEdit *lineEdit_9;
    QGroupBox *groupBox_13;
    QRadioButton *radioShadingButton_1;
    QCheckBox *wireframe;
    QRadioButton *radioShadingButton_2;
    QMenuBar *menubar;
    QMenu *menuFile;

    void setupUi(QMainWindow *Assets)
    {
        if (Assets->objectName().isEmpty())
            Assets->setObjectName("Assets");
        Assets->resize(1200, 1000);
        Assets->setMinimumSize(QSize(420, 300));
        actionExit = new QAction(Assets);
        actionExit->setObjectName("actionExit");
        actionNew_Scene = new QAction(Assets);
        actionNew_Scene->setObjectName("actionNew_Scene");
        actionExport_obj = new QAction(Assets);
        actionExport_obj->setObjectName("actionExport_obj");
        actionExport_ma = new QAction(Assets);
        actionExport_ma->setObjectName("actionExport_ma");
        actionLoad_ma = new QAction(Assets);
        actionLoad_ma->setObjectName("actionLoad_ma");
        actionGL = new QAction(Assets);
        actionGL->setObjectName("actionGL");
        actionVectorized = new QAction(Assets);
        actionVectorized->setObjectName("actionVectorized");
        actionExport_svg = new QAction(Assets);
        actionExport_svg->setObjectName("actionExport_svg");
        actionSphere_Tracing_png = new QAction(Assets);
        actionSphere_Tracing_png->setObjectName("actionSphere_Tracing_png");
        centralwidget = new QWidget(Assets);
        centralwidget->setObjectName("centralwidget");
        hboxLayout = new QHBoxLayout(centralwidget);
        hboxLayout->setSpacing(0);
        hboxLayout->setObjectName("hboxLayout");
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        Objects_groupBox = new QGroupBox(centralwidget);
        Objects_groupBox->setObjectName("Objects_groupBox");
        Objects_groupBox->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Objects_groupBox->sizePolicy().hasHeightForWidth());
        Objects_groupBox->setSizePolicy(sizePolicy);
        Objects_groupBox->setMinimumSize(QSize(350, 250));
        boxMesh = new QPushButton(Objects_groupBox);
        boxMesh->setObjectName("boxMesh");
        boxMesh->setGeometry(QRect(20, 20, 101, 23));
        sdf_box = new QPushButton(Objects_groupBox);
        sdf_box->setObjectName("sdf_box");
        sdf_box->setGeometry(QRect(140, 130, 101, 23));
        sdf_sphere = new QPushButton(Objects_groupBox);
        sdf_sphere->setObjectName("sdf_sphere");
        sdf_sphere->setGeometry(QRect(20, 100, 101, 23));
        sdf_tore = new QPushButton(Objects_groupBox);
        sdf_tore->setObjectName("sdf_tore");
        sdf_tore->setGeometry(QRect(140, 100, 101, 23));
        sdf_capsule = new QPushButton(Objects_groupBox);
        sdf_capsule->setObjectName("sdf_capsule");
        sdf_capsule->setGeometry(QRect(20, 130, 101, 23));
        sdf_forme1 = new QPushButton(Objects_groupBox);
        sdf_forme1->setObjectName("sdf_forme1");
        sdf_forme1->setGeometry(QRect(20, 160, 101, 23));
        blob_Forme1 = new QPushButton(Objects_groupBox);
        blob_Forme1->setObjectName("blob_Forme1");
        blob_Forme1->setGeometry(QRect(20, 210, 101, 23));
        blob_Forme2 = new QPushButton(Objects_groupBox);
        blob_Forme2->setObjectName("blob_Forme2");
        blob_Forme2->setGeometry(QRect(140, 210, 101, 23));
        resetcameraButton = new QPushButton(Objects_groupBox);
        resetcameraButton->setObjectName("resetcameraButton");
        resetcameraButton->setGeometry(QRect(140, 20, 81, 23));
        resetcameraButton->setCheckable(true);
        resetcameraButton->setAutoDefault(false);
        resetcameraButton->setFlat(false);
        sphereImplicit = new QPushButton(Objects_groupBox);
        sphereImplicit->setObjectName("sphereImplicit");
        sphereImplicit->setGeometry(QRect(20, 50, 101, 23));

        hboxLayout->addWidget(Objects_groupBox);

        widget_GL = new QWidget(centralwidget);
        widget_GL->setObjectName("widget_GL");

        hboxLayout->addWidget(widget_GL);

        Parameters_groupBox = new QGroupBox(centralwidget);
        Parameters_groupBox->setObjectName("Parameters_groupBox");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Parameters_groupBox->sizePolicy().hasHeightForWidth());
        Parameters_groupBox->setSizePolicy(sizePolicy1);
        Parameters_groupBox->setMinimumSize(QSize(450, 141));
        groupBox_4 = new QGroupBox(Parameters_groupBox);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(10, 20, 171, 180));
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 20, 61, 21));
        lineEdit_2 = new QLineEdit(groupBox_4);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(70, 50, 81, 20));
        lineEdit_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 50, 61, 21));
        lineEdit = new QLineEdit(groupBox_4);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(70, 20, 81, 20));
        lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 80, 61, 21));
        lineEdit_3 = new QLineEdit(groupBox_4);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(70, 80, 81, 20));
        lineEdit_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 110, 61, 21));
        lineEdit_4 = new QLineEdit(groupBox_4);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(70, 110, 81, 20));
        lineEdit_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 140, 61, 21));
        lineEdit_11 = new QLineEdit(groupBox_4);
        lineEdit_11->setObjectName("lineEdit_11");
        lineEdit_11->setGeometry(QRect(70, 140, 81, 20));
        lineEdit_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        groupBox_5 = new QGroupBox(Parameters_groupBox);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(10, 210, 190, 80));
        label_6 = new QLabel(groupBox_5);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 20, 80, 21));
        lineEdit_6 = new QLineEdit(groupBox_5);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(90, 20, 81, 20));
        lineEdit_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_7 = new QLabel(groupBox_5);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 50, 61, 21));
        lineEdit_7 = new QLineEdit(groupBox_5);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(70, 50, 81, 20));
        lineEdit_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        groupBox_6 = new QGroupBox(Parameters_groupBox);
        groupBox_6->setObjectName("groupBox_6");
        groupBox_6->setGeometry(QRect(210, 210, 190, 80));
        label_8 = new QLabel(groupBox_6);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 20, 80, 21));
        lineEdit_8 = new QLineEdit(groupBox_6);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(90, 20, 81, 20));
        lineEdit_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_9 = new QLabel(groupBox_6);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 50, 61, 21));
        lineEdit_9 = new QLineEdit(groupBox_6);
        lineEdit_9->setObjectName("lineEdit_9");
        lineEdit_9->setGeometry(QRect(70, 50, 81, 20));
        lineEdit_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        groupBox_13 = new QGroupBox(Parameters_groupBox);
        groupBox_13->setObjectName("groupBox_13");
        groupBox_13->setGeometry(QRect(190, 20, 251, 121));
        radioShadingButton_1 = new QRadioButton(groupBox_13);
        radioShadingButton_1->setObjectName("radioShadingButton_1");
        radioShadingButton_1->setGeometry(QRect(20, 20, 61, 20));
        radioShadingButton_1->setChecked(true);
        wireframe = new QCheckBox(groupBox_13);
        wireframe->setObjectName("wireframe");
        wireframe->setGeometry(QRect(90, 20, 81, 17));
        wireframe->setChecked(true);
        radioShadingButton_2 = new QRadioButton(groupBox_13);
        radioShadingButton_2->setObjectName("radioShadingButton_2");
        radioShadingButton_2->setGeometry(QRect(20, 50, 61, 20));

        hboxLayout->addWidget(Parameters_groupBox);

        Assets->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Assets);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1200, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        Assets->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());

        retranslateUi(Assets);

        resetcameraButton->setDefault(false);


        QMetaObject::connectSlotsByName(Assets);
    } // setupUi

    void retranslateUi(QMainWindow *Assets)
    {
        Assets->setWindowTitle(QCoreApplication::translate("Assets", "Implicit Terrain", nullptr));
        actionExit->setText(QCoreApplication::translate("Assets", "Exit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("Assets", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        actionNew_Scene->setText(QCoreApplication::translate("Assets", "New Scene", nullptr));
        actionExport_obj->setText(QCoreApplication::translate("Assets", "OBJ File (.obj)", nullptr));
        actionExport_ma->setText(QCoreApplication::translate("Assets", "Maya File (.ma)", nullptr));
        actionLoad_ma->setText(QCoreApplication::translate("Assets", "Load", nullptr));
        actionGL->setText(QCoreApplication::translate("Assets", "GL", nullptr));
        actionVectorized->setText(QCoreApplication::translate("Assets", "Vectorized", nullptr));
        actionExport_svg->setText(QCoreApplication::translate("Assets", "SVG File (.svg)", nullptr));
        actionSphere_Tracing_png->setText(QCoreApplication::translate("Assets", "Sphere Tracing (.png)", nullptr));
        Objects_groupBox->setTitle(QString());
        boxMesh->setText(QCoreApplication::translate("Assets", "Box Mesh", nullptr));
        sdf_box->setText(QCoreApplication::translate("Assets", "sdf_box", nullptr));
        sdf_sphere->setText(QCoreApplication::translate("Assets", "sdf_sphere", nullptr));
        sdf_tore->setText(QCoreApplication::translate("Assets", "sdf_tore", nullptr));
        sdf_capsule->setText(QCoreApplication::translate("Assets", "sdf_capsule", nullptr));
        sdf_forme1->setText(QCoreApplication::translate("Assets", "sdf_forme1", nullptr));
        blob_Forme1->setText(QCoreApplication::translate("Assets", "blob_Forme1", nullptr));
        blob_Forme2->setText(QCoreApplication::translate("Assets", "blob_Forme2", nullptr));
        resetcameraButton->setText(QCoreApplication::translate("Assets", "Reset Camera", nullptr));
        sphereImplicit->setText(QCoreApplication::translate("Assets", "Sphere Implicit", nullptr));
        Parameters_groupBox->setTitle(QString());
        groupBox_4->setTitle(QCoreApplication::translate("Assets", "Statistics", nullptr));
        label_2->setText(QCoreApplication::translate("Assets", "Vertex", nullptr));
        label_3->setText(QCoreApplication::translate("Assets", "Triangles", nullptr));
        label_4->setText(QCoreApplication::translate("Assets", "Lipschitz", nullptr));
        label_5->setText(QCoreApplication::translate("Assets", "Lipschitz Gradient", nullptr));
        label_11->setText(QCoreApplication::translate("Assets", "Perf", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("Assets", "Performance Wyvill", nullptr));
        label_6->setText(QCoreApplication::translate("Assets", "Tps eval champ", nullptr));
        label_7->setText(QCoreApplication::translate("Assets", "Tps exec", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("Assets", "Performance Blinn", nullptr));
        label_8->setText(QCoreApplication::translate("Assets", "Tps eval champ", nullptr));
        label_9->setText(QCoreApplication::translate("Assets", "Tps exec", nullptr));
        groupBox_13->setTitle(QCoreApplication::translate("Assets", "Shading", nullptr));
        radioShadingButton_1->setText(QCoreApplication::translate("Assets", "Normal", nullptr));
        wireframe->setText(QCoreApplication::translate("Assets", "Wireframe", nullptr));
        radioShadingButton_2->setText(QCoreApplication::translate("Assets", "Color", nullptr));
        menuFile->setTitle(QCoreApplication::translate("Assets", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Assets: public Ui_Assets {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_H
