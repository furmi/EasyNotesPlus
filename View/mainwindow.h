#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>

class QTabWidget;

namespace Ui {
class MainWindow;
}

namespace EasyNote
{
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

    // Crée la barre de tâche

    void createMenuBar();

    // Crée toutes les actions

    void createActions();

    // Crée les menus associés

    //void createMenus();

private slots:
    void newFile();
    void loadFile();
    void saveFile();
    
private:
    Ui::MainWindow *ui;


    // Menus

    QMenu *fileMenu;



    // Actions


    QAction *newAct;
    QAction* loadAct;
    QAction* saveAct;
};

}

#endif // MAINWINDOW_H
