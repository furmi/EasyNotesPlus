#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QTabWidget;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    // Cette méthode se charge de l'affichage de toute l'application

    void displayApp();

    void createCentralWidget(QTabWidget* tab);
    void createEditor(QTabWidget* tab);
    
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
