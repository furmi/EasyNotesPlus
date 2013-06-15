#ifndef TOOLDOCK_H
#define TOOLDOCK_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include "View/ToolDockItemsManager.h"

/***************************************************************
 Il faudra surement spécialiser QPushButton pour ouvrir
Le tag manager et la corbeille

***************************************************************/

// Rq pourrait être généralisé en dock de N bouton en utilisant les vectors

namespace EasyNote
{

class ToolDock:public QWidget
{
    Q_OBJECT
    //Q_PROPERTY(QPushButton* trash READ Trash NOTIFY trash_clicked)
    //Q_PROPERTY(QPushButton* tag_mgr READ TagManager NOTIFY tag_mgr_clicked)

public:
    ToolDock(QWidget* =0):
        tag_mgr(new QPushButton("Tag",this)),trash(new QPushButton("Trash",this)),layout(new QHBoxLayout(this)),
        items_manager(new ToolDockItemsManager(this))
    {
        layout->addWidget(tag_mgr);
        layout->addWidget(trash);

        this->setLayout(layout);

        // Récupération du click sur la corbeille

        QObject::connect(trash,SIGNAL(clicked()),items_manager,SLOT(openTrash()));

        // Récupération du click sur le Tag Manager

        QObject::connect(tag_mgr,SIGNAL(clicked()),items_manager,SLOT(openTagManager()));


    }
    virtual ~ToolDock();

    // Ne sont pas rigoureusement des accesseurs en écriture, avec les connaissances dont je dispose,
    // Qt ne permet pas de gérer finement les pointeur comme attribut dans Q_PROPERTY

    QPushButton* Trash() {return trash;}
    QPushButton* TagManager() {return tag_mgr;}

private:
    QPushButton* tag_mgr; // Tag manager
    QPushButton* trash;
    QHBoxLayout* layout;
    ToolDockItemsManager* items_manager;
};

}

#endif // TOOLDOCK_H
