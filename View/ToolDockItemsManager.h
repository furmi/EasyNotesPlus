#ifndef TOOLDOCKITEMSMANAGER_H
#define TOOLDOCKITEMSMANAGER_H

#include <QWidget>
#include <QStringListModel>
#include <QListView>
#include <QDebug>
#include "View/ListViewDialog.h"

namespace EasyNote
{

class ToolDockItemsManager:public QWidget
{
    Q_OBJECT
public:
    ToolDockItemsManager(QObject* =0):trash_window(0){}
    virtual ~ToolDockItemsManager();

public slots:
    void openTrash()
    {
        trash_window = new ListViewDialog(this);
        trash_window->initTrash();
    }

private:
    ListViewDialog* trash_window; // La fenêtre est crée lors de l'appel à openTrash()

};

}


#endif // TOOLDOCKITEMSMANAGER_H
