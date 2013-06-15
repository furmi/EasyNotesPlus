#ifndef LISTVIEWDIALOG_H
#define LISTVIEWDIALOG_H

#include <QDialog>
#include <QListView>

namespace EasyNote
{

    class ListViewDialog:public QDialog
    {
        Q_OBJECT

    public:
        ListViewDialog(QWidget* =0);

        virtual ~ListViewDialog();

        // Initialise trash

        void initTrash();


    private:
        QListView* trash;


    };

}

#endif // LISTVIEWDIALOG_H
