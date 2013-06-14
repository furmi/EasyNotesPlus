#include "EditorContent.h"

using namespace EasyNote;

EditorContent::~EditorContent()
{
    // Vidage du layout

    layout->removeWidget(title);
    layout->removeWidget(content);
}
