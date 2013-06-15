#ifndef TABVIEWDIALOG_H
#define TABVIEWDIALOG_H

#include <QDialog>
#include <QTabWidget>

namespace EasyNote
{

    class TabDialog:public QDialog
    {
        Q_OBJECT

    public:
        TabDialog(QWidget* parent = 0):QDialog(parent),tab(new QTabWidget(this)){}

        virtual ~TabDialog();

    protected:
        QTabWidget* tab;


    };

}


#endif // TABVIEWDIALOG_H
