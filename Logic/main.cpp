#include <iostream>
#include "Note.h"
#include "Article.h"
#include "Media.h"
#include "Image.h"
#include "Video.h"
#include "Audio.h"
#include "ArticleFactory.h"
#include "NotesManager.h"
#include "NotesIterator.h"
#include <QApplication>
#include "View/mainwindow.h"

using namespace std;
using namespace EasyNote;

int main(int argc,char* argv[])
{
	EasyNote::ArticleFactory af;
	EasyNote::Article* aa = af.factory();
	EasyNote::Article a(*aa);
	a.setTitle("Hello bobby");
    EasyNote::Article b(a);
    EasyNote::Article c(a);
	
	
    /*a.generateTimeStamp();
	 
	 cout <<"a : \n";
	 cout << a << endl;
	 b.setTitle("Titre2 B");
	 cout<<b.getTitle()<<"\n";
	 a.setText("Mon premier text pour mother fucking a !");
	 cout<<a.getText()<<"\n";*/
	
	
    cout <<"a : \n";
    cout << a << endl;
    a.setTitle("tire a mod");
    EasyNote::Article d = a;
    cout <<"b : \n";
    cout << b << endl;
    cout <<"c : \n";
    cout << c << endl;
    cout <<"d : \n";
    cout << d << endl;


    /************* À ne surtout pas supprimer!!!! ****************/

    QApplication app(argc,argv);
    MainWindow mw;
    mw.setWindowTitle("EasyNote++");
    mw.displayApp();

    return app.exec();
}
