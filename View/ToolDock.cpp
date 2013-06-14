#include "View/ToolDock.h"


using namespace EasyNote;

ToolDock::~ToolDock()
{
    layout->removeWidget(tag_mgr);
    layout->removeWidget(trash);
}
