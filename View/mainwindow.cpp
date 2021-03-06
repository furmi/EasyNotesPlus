#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTabWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QDockWidget>
#include <QMenu>
#include <QMenuBar>
#include <QListView>
#include "View/EditorContent.h"
#include "View/ToolDock.h"
#include <QAbstractItemModel>
#include <QStringList>
#include <QStringListModel>
#include <QErrorMessage>
#include <QDebug>
#include <QAction>
#include <QActionGroup>
#include "View/Dock.h"


/*************************************************************************************************
                REMARQUE POUR LE CORRECTEUR

Je sais qu'en déclarant un QWidget sur le tas, le seul moyen de le gérer automatiquement
(du point de vu de la mémoire) est de le confier à au moins un parent alloué sur la pile.

Tout ça pour dire que je n'oublie pas mes delete: c'est volontaire

************************************************************************************************/

namespace EasyNote
{

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayApp()
{
    // Barre du menu principal

    createMenuBar();

    // Définition du widget central

    // Tab widget

    QTabWidget* tab = new QTabWidget(this);
    this->setCentralWidget(tab);
    createCentralWidget(tab);

    // Définition du dock gauche

    QDockWidget* dock = new QDockWidget(this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea);

    // Création du dock

    Dock* d = new Dock(dock);

    dock->setWidget(d);

    // Ajout du dock dans la fenêtre

    this->addDockWidget(Qt::LeftDockWidgetArea,dock);

    show();
}

void MainWindow::createCentralWidget(QTabWidget* tab)
{
    tab->setMovable(true); // Autorise l'utilisateur à déplacer les onglets à sa guise

    // Editor

    createEditor(tab);

    // Html

    QTextEdit* html_cnt = new QTextEdit(tab);
    html_cnt->toPlainText();
    tab->insertTab(1,html_cnt,"HTML");

    // LaTex

    QTextEdit* tex_cnt = new QTextEdit(tab);
    tex_cnt->toPlainText();
    tab->insertTab(2,tex_cnt,"TEX");

    // Texte

    QTextEdit* txt_cnt = new QTextEdit(tab);
    txt_cnt->toPlainText(); // Formatte le texte correctment pour l'export ou éventuellement la copie
    tab->insertTab(3,txt_cnt,"Text");
}

void MainWindow::createEditor(QTabWidget* tab)
{
    EditorContent* editor = new EditorContent(tab);

    // Ajout des widgets au tab

    tab->insertTab(0,editor,"Editor");

}

void MainWindow::createMenuBar()
{
    // Crée la barre de menu principale

    // Ajout des actions

    createActions();

    //

}

void MainWindow::createActions()
{
    /*************************************************

                        MENU FILE

    ************************************************/

    // New File

    newAct = new QAction(tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));
    connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));

    //  Load

    loadAct = new QAction(tr("&Load"), this);
    loadAct->setShortcuts(QKeySequence::Open);
    loadAct->setStatusTip(tr("Create a new file"));
    connect(loadAct, SIGNAL(triggered()), this, SLOT(loadFile()));

    // Save

    saveAct = new QAction(tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Create a new file"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(saveFile()));

    // Ajout des actions à la barre

    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(loadAct);
    fileMenu->addAction(saveAct);
}

void MainWindow::newFile()
{
    qDebug() << endl << "createArticle" << endl;

    QErrorMessage* err = new QErrorMessage(this);
    err->showMessage("Ça roule ma poule");
    err->setVisible(true);
}

void MainWindow::loadFile()
{
    qDebug() << endl << "createArticle" << endl;

    QErrorMessage* err = new QErrorMessage(this);
    err->showMessage("Ça roule mon bichon");
    err->setVisible(true);
}

void MainWindow::saveFile()
{
    qDebug() << endl << "createArticle" << endl;

    QErrorMessage* err = new QErrorMessage(this);
    err->showMessage("Ça roule ma biche");
    err->setVisible(true);
}

}
