//
//  ExportStrategy.cpp
//  EasyNotePlus_thomas
//
//  Created by Thomas Fuhrmann on 10/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#include "ExportStrategy.h"
#include "HTMLExport.h"
#include "TexExport.h"
#include "TextExport.h"

using namespace EasyNote;


namespace EasyNote
{
    ExportStrategy::~ExportStrategy() {}

    map<QString, ExportStrategy*> ExportStrategy::getStrategies()
    {
        map<QString, ExportStrategy*> strat;

        //création des différentes classes d'export
        strat["HTMLExport"] = new HTMLExport;
        strat["TexExport"] = new TexExport;
        strat["TextExport"] = new TextExport;

        return strat;
    }
}
