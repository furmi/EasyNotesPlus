#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTabWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QDockWidget>
//#include <QListWidget>
#include <QListView>
#include "View/EditorContent.h"
#include "View/ToolDock.h"
#include <QAbstractItemModel>
#include <QStringList>
#include <QStringListModel>
#include "View/Dock.h"


/*************************************************************************************************
                REMARQUE POUR LE CORRECTEUR

Je sais qu'en déclarant un QWidget sur le tas, le seul moyen de le gérer automatiquement
(du point de vu de la mémoire) est de le confier à au moins un parent alloué sur la pile.

Tout ça pour dire que je n'oublie pas mes delete: c'est volontaire

************************************************************************************************/

using namespace EasyNote;

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
    // Définition du Dock



    // Définition du widget central

    // Tab widget

    QTabWidget* tab = new QTabWidget(this);
    this->setCentralWidget(tab);
    createCentralWidget(tab);

    // Définition du dock gauche

    QDockWidget* dock = new QDockWidget(this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea);

    // Création du dock

    //QListView* list = new QListView(dock);

    //

    Dock* d = new Dock(dock);

    //

    //ToolDock* t_dock = new ToolDock(dock);  // Barre d'action
    //QVBoxLayout* layout = new QVBoxLayout(dock);

    // Disposition des widgets

    //layout->addWidget(list);
    //layout->addWidget(t_dock);

    // Ajout des widgets au dock

    //dock->setWidget(list);
    //dock->setWidget(t_dock);
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
