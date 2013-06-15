#include <QStringList>
#include <QStringListModel>
#include <QDebug>
#include "View/ListViewDialog.h"

using namespace EasyNote;

namespace EasyNote
{
    ListViewDialog::ListViewDialog(QWidget*):trash(new QListView(this))
    {
        initTrash();
    }

    ListViewDialog::~ListViewDialog(){}

    // On utilise une QstringListModel mais il va falloir sous classer tout ça
    // Pour avoir une NoteListModel

    void ListViewDialog::initTrash()
    {
        qDebug() << endl << "initTrash" << endl;

        QStringList trash_items;
        //numbers << "One" << "Two" << "Three" << "Four" << "Five";

        QStringListModel* model = new QStringListModel(trash_items);
        trash->setModel(model);

        // Afficher la fenêtre

        this->setWindowTitle("Trash");
        this->setVisible(true);
    }

}
