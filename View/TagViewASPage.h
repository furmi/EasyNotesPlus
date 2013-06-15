#ifndef TAGVIEWASPAGE_H
#define TAGVIEWASPAGE_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>

namespace EasyNote
{

// AS pour Add et Search

class TagViewASPage:public QWidget
{
    Q_OBJECT

public:
    TagViewASPage(QWidget* parent = 0):QWidget(parent),
        text_field(0),research(0),add(0),
        v_layout(0),h_layout(0),g_layout(0)
    {}

    virtual ~TagViewASPage();

    void createPage();

private:
    QVBoxLayout* v_layout;
    QHBoxLayout* h_layout;
    QGridLayout* g_layout;
    QLineEdit* text_field;
    QPushButton* research;
    QPushButton* add;

};




}





#endif // TAGVIEWASPAGE_H
