#ifndef TOOLDOCKITEMSMANAGER_H
#define TOOLDOCKITEMSMANAGER_H

#include <QWidget>
#include <QStringListModel>
#include <QListView>
#include <QDebug>
#include "View/TagViewDialog.h"
#include "View/ListViewDialog.h"

namespace EasyNote
{

class ToolDockItemsManager:public QWidget
{
    Q_OBJECT
public:
    ToolDockItemsManager(QObject* =0):trash_window(0),tag_window(0){}
    virtual ~ToolDockItemsManager();

public slots:
    void openTrash()
    {
        trash_window = new ListViewDialog(this);
        trash_window->initTrash();
    }

    void openTagManager()
    {
        //if ()

        tag_window = new TagViewDialog(this);
        tag_window->initTag();
    }

private:
    ListViewDialog* trash_window; // La fenêtre est crée lors de l'appel à openTrash()
    TagViewDialog* tag_window; // La fenêtre est crée lors de l'appel à openTagManager()
};

}


#endif // TOOLDOCKITEMSMANAGER_H
