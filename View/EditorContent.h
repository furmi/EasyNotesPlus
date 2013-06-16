#ifndef EDITORCONTENT_H
#define EDITORCONTENT_H
#include <QWidget>
#include <QTextEdit>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>

namespace EasyNote
{
class EditorContent:public QWidget
{
   Q_OBJECT
public:
    EditorContent(QWidget* parent=0):
        QWidget(parent),title(new QLineEdit(this)),l_title(new QLabel("Titre",this)),
        content(new QTextEdit(this)),layout(new QGridLayout(this))
    {
        // Ajoute les Widget composites au layout

        layout->addWidget(l_title,0,0);
        layout->addWidget(title,0,1);
        layout->addWidget(content,1,1);

    }
    virtual ~EditorContent();

private:
    // Attention Q_PROPERTY n'est pas utilisée

    QLineEdit* title;
    QLabel* l_title;
    QTextEdit* content;
    QGridLayout* layout;
};

}
#endif // EDITORCONTENT_H
