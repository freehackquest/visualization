#include "commandscollection.h"
#include <iostream>
#include <QString>
#include "commands/background.h"
#include "commands/draw.h"
#include "commands/fix.h"
#include "commands/line.h"
#include "commands/pixel.h"
#include "commands/table.h"
#include "commands/text.h"
#include "commands/fhqvisualization.h"

CommandsCollection::CommandsCollection(){
	registr(new CommandBackground());
	registr(new CommandDraw());
	registr(new CommandFix());
	registr(new CommandLine());
	registr(new CommandPixel());
	registr(new CommandTable());
	registr(new CommandText());
	registr(new CommandFHQVisualization());
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


