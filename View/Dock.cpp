#include "View/Dock.h"

using namespace EasyNote;

Dock::Dock(QWidget*):
    tooldock(new ToolDock(this)),l_view(new QListView(this)),layout(new QVBoxLayout(this))
{
    // Bon alors la dedans y'a encore des trucs à faire parce que à la fin du constructeur on perd le contenu de la
    // liste. Il faut sûrement rajouter modèle en attribut et peut être aussi list_items


    // Initialisation de la liste

    QStringList list_items;
    //numbers << "One" << "Two" << "Three" << "Four" << "Five";

    QStringListModel* model = new QStringListModel(list_items);
    l_view->setModel(model);

    // Disposition des éléments

    layout->addWidget(l_view);
    layout->addWidget(tooldock);
}

Dock::~Dock(){}
