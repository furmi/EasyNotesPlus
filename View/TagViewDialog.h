#ifndef TAGVIEWDIALOG_H
#define TAGVIEWDIALOG_H

#include <QTableView>
#include "View/TabViewDialog.h"

namespace EasyNote
{

class TagViewDialog:public TabDialog
{
    Q_OBJECT

public:
    TagViewDialog(QWidget* =0);
    virtual ~TagViewDialog();


    // Initialise tag

    void initTag();

    // Crée le premier onglet du TagManager

    void createAddSearchItem();


private:
    QTableView* tab_view;


};


}



#endif // TAGVIEWDIALOG_H
