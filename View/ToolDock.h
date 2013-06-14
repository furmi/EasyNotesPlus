#ifndef TOOLDOCK_H
#define TOOLDOCK_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>

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
public:
    ToolDock(QWidget* =0):
        tag_mgr(new QPushButton("Tag",this)),trash(new QPushButton("Trash",this)),layout(new QHBoxLayout(this))
    {
        layout->addWidget(tag_mgr);
        layout->addWidget(trash);

        this->setLayout(layout);
    }
    virtual ~ToolDock();

private:
    QPushButton* tag_mgr; // Tag manager
    QPushButton* trash;
    QHBoxLayout* layout;
};

}

#endif // TOOLDOCK_H
