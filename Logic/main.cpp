#include <iostream>
#include "Note.h"
#include "Article.h"
#include "Media.h"
#include "Image.h"
#include "Video.h"
#include "Audio.h"
#include "ArticleFactory.h"
#include "Logic/NotesManager.h"
#include "NotesIterator.h"
#include <QApplication>
#include "View/mainwindow.h"
#include "View/EditorContent.h"

using namespace std;
using namespace EasyNote;

int main(int argc,char* argv[])
{
    /*************************   LOGIQUE   **************************/

    NotesManager* nm = NotesManager::getInstance();
    nm->loadNM();

    /************* Qt À ne surtout pas supprimer!!!! ****************/

    QApplication app(argc,argv);
    MainWindow mw;
    mw.setWindowTitle("EasyNote++");
    mw.displayApp();

    // Redimensionnement de la fenêtre principale

    mw.setMinimumSize(480, 320);
    mw.resize(640, 480);

    return app.exec();
}
