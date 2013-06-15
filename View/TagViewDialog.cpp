#include <QDebug>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>
#include "View/TabViewDialog.h"
#include "View/TagViewDialog.h"
#include "View/TagViewASPage.h"


using namespace EasyNote;


namespace EasyNote
{
TagViewDialog::TagViewDialog(QWidget* parent):TabDialog(parent),tab_view(0)
    {

        //tab_view = new QTableView(tab);

        //initTag();
    }

    TagViewDialog::~TagViewDialog() {}

    void TagViewDialog::initTag()
    {
        qDebug() << endl << "InitTag" << endl;

        // Définition générale des propriétés du conteneur

        tab->setMovable(true);

        // Onglet d'ajout/Recherche

        createAddSearchItem();

        // Onglet de filtrage




        // Afficher la fenêtre

        this->setWindowTitle("Tag");
        this->setVisible(true);

    }

    void TagViewDialog::createAddSearchItem()
    {
        // Création de la page

        qDebug() << endl << "createAddSearchItem" << endl;

        // Création de la page

        TagViewASPage* page = new TagViewASPage(tab);

        page->createPage();

        // Insertion dans la première page du TabItem

        tab->insertTab(0,page,"Add/Search");

    }



}
