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

using namespace std;

int main()
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
    
	return EXIT_SUCCESS;
}
