#ifndef DOCK_H
#define DOCK_H

#include <QWidget>
#include "View/ToolDock.h"
#include <QListView>
#include <QVBoxLayout>
#include <QStringList>
#include <QStringListModel>

namespace EasyNote
{


class Dock:public QWidget
{
    Q_OBJECT
public:
    Dock(QWidget* =0);

    virtual ~Dock();

private:
    ToolDock* tooldock;
    QListView* l_view;
    QVBoxLayout* layout;
};









}



#endif // DOCK_H
