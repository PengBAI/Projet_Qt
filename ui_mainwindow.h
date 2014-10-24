/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuitter;
    QAction *actionClient;
    QAction *actionPersonnel;
    QAction *actionA_propos;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_4;
    QTabWidget *tabWidget;
    QWidget *personnel;
    QVBoxLayout *verticalLayout;
    QTreeView *PersonnelTreeView;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QPushButton *modifierBtn;
    QPushButton *suppBtn;
    QWidget *recherche;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *nomlabel;
    QLineEdit *nomlineEdit;
    QLabel *prenomlabel;
    QLineEdit *prenomlineEdit;
    QLabel *label;
    QDateEdit *datedebutEdit;
    QLabel *datefinlabel;
    QDateEdit *datefinEdit;
    QLabel *numidenlabel;
    QLineEdit *idlineEdit;
    QPushButton *rechercheButton;
    QTableView *clientView;
    QGroupBox *clientGrp;
    QGridLayout *gridLayout_4;
    QPushButton *modBtn;
    QPushButton *supBtn;
    QWidget *planification;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_6;
    QPushButton *PlanifierButton;
    QPushButton *enregistrePB;
    QDateEdit *planDateEdit;
    QLabel *label_4;
    QTableView *planificationView;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuAjouter;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(855, 460);
        MainWindow->setIconSize(QSize(18, 18));
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        actionClient = new QAction(MainWindow);
        actionClient->setObjectName(QStringLiteral("actionClient"));
        actionPersonnel = new QAction(MainWindow);
        actionPersonnel->setObjectName(QStringLiteral("actionPersonnel"));
        actionA_propos = new QAction(MainWindow);
        actionA_propos->setObjectName(QStringLiteral("actionA_propos"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_4 = new QHBoxLayout(centralWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        personnel = new QWidget();
        personnel->setObjectName(QStringLiteral("personnel"));
        verticalLayout = new QVBoxLayout(personnel);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        PersonnelTreeView = new QTreeView(personnel);
        PersonnelTreeView->setObjectName(QStringLiteral("PersonnelTreeView"));
        PersonnelTreeView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout->addWidget(PersonnelTreeView);

        groupBox = new QGroupBox(personnel);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        modifierBtn = new QPushButton(groupBox);
        modifierBtn->setObjectName(QStringLiteral("modifierBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(modifierBtn->sizePolicy().hasHeightForWidth());
        modifierBtn->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(modifierBtn, 0, 0, 1, 1);

        suppBtn = new QPushButton(groupBox);
        suppBtn->setObjectName(QStringLiteral("suppBtn"));
        sizePolicy1.setHeightForWidth(suppBtn->sizePolicy().hasHeightForWidth());
        suppBtn->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(suppBtn, 0, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        tabWidget->addTab(personnel, QString());
        recherche = new QWidget();
        recherche->setObjectName(QStringLiteral("recherche"));
        verticalLayout_2 = new QVBoxLayout(recherche);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        nomlabel = new QLabel(recherche);
        nomlabel->setObjectName(QStringLiteral("nomlabel"));
        sizePolicy1.setHeightForWidth(nomlabel->sizePolicy().hasHeightForWidth());
        nomlabel->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(nomlabel);

        nomlineEdit = new QLineEdit(recherche);
        nomlineEdit->setObjectName(QStringLiteral("nomlineEdit"));
        sizePolicy1.setHeightForWidth(nomlineEdit->sizePolicy().hasHeightForWidth());
        nomlineEdit->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(nomlineEdit);

        prenomlabel = new QLabel(recherche);
        prenomlabel->setObjectName(QStringLiteral("prenomlabel"));
        sizePolicy1.setHeightForWidth(prenomlabel->sizePolicy().hasHeightForWidth());
        prenomlabel->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(prenomlabel);

        prenomlineEdit = new QLineEdit(recherche);
        prenomlineEdit->setObjectName(QStringLiteral("prenomlineEdit"));
        sizePolicy1.setHeightForWidth(prenomlineEdit->sizePolicy().hasHeightForWidth());
        prenomlineEdit->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(prenomlineEdit);

        label = new QLabel(recherche);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label);

        datedebutEdit = new QDateEdit(recherche);
        datedebutEdit->setObjectName(QStringLiteral("datedebutEdit"));
        sizePolicy1.setHeightForWidth(datedebutEdit->sizePolicy().hasHeightForWidth());
        datedebutEdit->setSizePolicy(sizePolicy1);
        datedebutEdit->setCalendarPopup(true);

        horizontalLayout->addWidget(datedebutEdit);

        datefinlabel = new QLabel(recherche);
        datefinlabel->setObjectName(QStringLiteral("datefinlabel"));
        sizePolicy1.setHeightForWidth(datefinlabel->sizePolicy().hasHeightForWidth());
        datefinlabel->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(datefinlabel);

        datefinEdit = new QDateEdit(recherche);
        datefinEdit->setObjectName(QStringLiteral("datefinEdit"));
        sizePolicy1.setHeightForWidth(datefinEdit->sizePolicy().hasHeightForWidth());
        datefinEdit->setSizePolicy(sizePolicy1);
        datefinEdit->setDateTime(QDateTime(QDate(2020, 1, 1), QTime(0, 0, 0)));
        datefinEdit->setCalendarPopup(true);

        horizontalLayout->addWidget(datefinEdit);

        numidenlabel = new QLabel(recherche);
        numidenlabel->setObjectName(QStringLiteral("numidenlabel"));
        sizePolicy1.setHeightForWidth(numidenlabel->sizePolicy().hasHeightForWidth());
        numidenlabel->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(numidenlabel);

        idlineEdit = new QLineEdit(recherche);
        idlineEdit->setObjectName(QStringLiteral("idlineEdit"));
        sizePolicy1.setHeightForWidth(idlineEdit->sizePolicy().hasHeightForWidth());
        idlineEdit->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(idlineEdit);

        rechercheButton = new QPushButton(recherche);
        rechercheButton->setObjectName(QStringLiteral("rechercheButton"));
        sizePolicy1.setHeightForWidth(rechercheButton->sizePolicy().hasHeightForWidth());
        rechercheButton->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(rechercheButton);


        verticalLayout_2->addLayout(horizontalLayout);

        clientView = new QTableView(recherche);
        clientView->setObjectName(QStringLiteral("clientView"));
        clientView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_2->addWidget(clientView);

        clientGrp = new QGroupBox(recherche);
        clientGrp->setObjectName(QStringLiteral("clientGrp"));
        sizePolicy1.setHeightForWidth(clientGrp->sizePolicy().hasHeightForWidth());
        clientGrp->setSizePolicy(sizePolicy1);
        gridLayout_4 = new QGridLayout(clientGrp);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        modBtn = new QPushButton(clientGrp);
        modBtn->setObjectName(QStringLiteral("modBtn"));
        sizePolicy1.setHeightForWidth(modBtn->sizePolicy().hasHeightForWidth());
        modBtn->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(modBtn, 0, 0, 1, 1);

        supBtn = new QPushButton(clientGrp);
        supBtn->setObjectName(QStringLiteral("supBtn"));
        sizePolicy1.setHeightForWidth(supBtn->sizePolicy().hasHeightForWidth());
        supBtn->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(supBtn, 0, 1, 1, 1);


        verticalLayout_2->addWidget(clientGrp);

        tabWidget->addTab(recherche, QString());
        planification = new QWidget();
        planification->setObjectName(QStringLiteral("planification"));
        verticalLayout_3 = new QVBoxLayout(planification);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox_2 = new QGroupBox(planification);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        gridLayout_6 = new QGridLayout(groupBox_2);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        PlanifierButton = new QPushButton(groupBox_2);
        PlanifierButton->setObjectName(QStringLiteral("PlanifierButton"));
        sizePolicy1.setHeightForWidth(PlanifierButton->sizePolicy().hasHeightForWidth());
        PlanifierButton->setSizePolicy(sizePolicy1);

        gridLayout_6->addWidget(PlanifierButton, 0, 2, 1, 1);

        enregistrePB = new QPushButton(groupBox_2);
        enregistrePB->setObjectName(QStringLiteral("enregistrePB"));
        sizePolicy1.setHeightForWidth(enregistrePB->sizePolicy().hasHeightForWidth());
        enregistrePB->setSizePolicy(sizePolicy1);

        gridLayout_6->addWidget(enregistrePB, 0, 3, 1, 1);

        planDateEdit = new QDateEdit(groupBox_2);
        planDateEdit->setObjectName(QStringLiteral("planDateEdit"));
        sizePolicy1.setHeightForWidth(planDateEdit->sizePolicy().hasHeightForWidth());
        planDateEdit->setSizePolicy(sizePolicy1);
        planDateEdit->setDateTime(QDateTime(QDate(2013, 6, 1), QTime(0, 0, 0)));
        planDateEdit->setCalendarPopup(true);

        gridLayout_6->addWidget(planDateEdit, 0, 1, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_6->addWidget(label_4, 0, 0, 1, 1);


        verticalLayout_3->addWidget(groupBox_2);

        planificationView = new QTableView(planification);
        planificationView->setObjectName(QStringLiteral("planificationView"));
        planificationView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_3->addWidget(planificationView);

        tabWidget->addTab(planification, QString());

        horizontalLayout_4->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 855, 21));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        menuAjouter = new QMenu(menuFichier);
        menuAjouter->setObjectName(QStringLiteral("menuAjouter"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menu->menuAction());
        menuFichier->addAction(menuAjouter->menuAction());
        menuFichier->addAction(actionQuitter);
        menuAjouter->addAction(actionClient);
        menuAjouter->addAction(actionPersonnel);
        menu->addAction(actionA_propos);
        mainToolBar->addSeparator();

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0));
        actionClient->setText(QApplication::translate("MainWindow", "Client", 0));
        actionPersonnel->setText(QApplication::translate("MainWindow", "Personnel", 0));
        actionA_propos->setText(QApplication::translate("MainWindow", "A propos", 0));
        groupBox->setTitle(QString());
        modifierBtn->setText(QApplication::translate("MainWindow", "Modifier", 0));
        suppBtn->setText(QApplication::translate("MainWindow", "Supprimer", 0));
        tabWidget->setTabText(tabWidget->indexOf(personnel), QApplication::translate("MainWindow", "Personnel", 0));
        nomlabel->setText(QApplication::translate("MainWindow", "Nom", 0));
        prenomlabel->setText(QApplication::translate("MainWindow", "Pr\303\251nom", 0));
        label->setText(QApplication::translate("MainWindow", "Du", 0));
        datefinlabel->setText(QApplication::translate("MainWindow", "Au", 0));
        numidenlabel->setText(QApplication::translate("MainWindow", "No\302\260 ID", 0));
        rechercheButton->setText(QApplication::translate("MainWindow", "Recherche", 0));
        clientGrp->setTitle(QString());
        modBtn->setText(QApplication::translate("MainWindow", "Modifier", 0));
        supBtn->setText(QApplication::translate("MainWindow", "Supprimer", 0));
        tabWidget->setTabText(tabWidget->indexOf(recherche), QApplication::translate("MainWindow", "Recherche", 0));
        groupBox_2->setTitle(QString());
        PlanifierButton->setText(QApplication::translate("MainWindow", "Planifier", 0));
        enregistrePB->setText(QApplication::translate("MainWindow", "Enregistrer", 0));
        label_4->setText(QApplication::translate("MainWindow", "Date", 0));
        tabWidget->setTabText(tabWidget->indexOf(planification), QApplication::translate("MainWindow", "Planification", 0));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0));
        menuAjouter->setTitle(QApplication::translate("MainWindow", "Ajouter", 0));
        menu->setTitle(QApplication::translate("MainWindow", "?", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
