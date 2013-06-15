#include "View/TagViewASPage.h"

namespace EasyNote
{
    TagViewASPage::~TagViewASPage(){}


    //Lors de l'jout à un parent il faudra faire un setParent(0) pour chaque


    void TagViewASPage::createPage()
    {
        // Création des widgets de la fenêtre

        text_field = new QLineEdit(this);
        research = new QPushButton("Search",this);
        add = new QPushButton("Add",this);

        // Création des layouts

        v_layout = new QVBoxLayout(this);
        h_layout = new QHBoxLayout(this);

        // Ajout des widgets aux layouts

        // Horizontal

        h_layout->addWidget(research);
        h_layout->addWidget(add);

        // Vertical

        v_layout->addWidget(text_field);
        v_layout->addLayout(h_layout);

        this->setLayout(v_layout);
    }



}
