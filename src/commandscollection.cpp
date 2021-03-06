#include "commandscollection.h"
#include <iostream>
#include <QString>
#include "commands/background.h"
#include "commands/createframe.h"
#include "commands/draw.h"
#include "commands/fhqvisualization.h"
#include "commands/line.h"
#include "commands/pixel.h"
#include "commands/pushframes.h"
#include "commands/showexploitrun.h"
#include "commands/showwiringandlightnings.h"
#include "commands/table.h"
#include "commands/text.h"
#include "commands/tree.h"

CommandsCollection::CommandsCollection(){
	registr(new CommandBackground());
	registr(new CommandCreateFrame());
	registr(new CommandDraw());
	registr(new CommandFHQVisualization());
	registr(new CommandLine());
	registr(new CommandPixel());
	registr(new CommandPushFrames());
	registr(new CommandShowExploitRun());
	registr(new ShowWiringAndLightnings());
	registr(new CommandTable());
	registr(new CommandText());
	registr(new CommandTree());
	
};

bool CommandsCollection::contains(QString name){
	return m_mapCommands.contains(name);
};

ICommand *CommandsCollection::create(QString name){
	if(m_mapCommands.contains(name)){
		return m_mapCommands[name]->create();
	}
	return NULL;
};

bool CommandsCollection::isMultiLine(QString name){
	if(m_mapCommands.contains(name)){
		return m_mapCommands[name]->isMultiLine();
	}
	return false;
};

void CommandsCollection::registr(ICommand* pCommand){
	m_mapCommands[pCommand->name()] = pCommand;
};


