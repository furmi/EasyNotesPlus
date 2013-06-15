#include "View/ListViewDialog.h"
#include <QStringList>
#include <QStringListModel>
#include <QDebug>

using namespace EasyNote;

namespace EasyNote
{
    ListViewDialog::ListViewDialog(QWidget*):trash(new QListView(this))
    {
        initTrash();
    }

    ListViewDialog::~ListViewDialog(){}

    void ListViewDialog::initTrash()
    {
        qDebug() << endl << "initTrash" << endl;

        //QListView* trash = new QListView(this);

        QStringList trash_items;
        //numbers << "One" << "Two" << "Three" << "Four" << "Five";

        QStringListModel* model = new QStringListModel(trash_items);
        trash->setModel(model);

        // Afficher la fenêtre

        this->setWindowTitle("Trash");
        this->setVisible(true);
    }

}
