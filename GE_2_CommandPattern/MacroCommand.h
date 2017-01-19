#pragma once
#include "Command.h"
#include <vector>

class MacroCommand : public Command
{
public:
	MacroCommand();
	virtual ~MacroCommand();
	virtual void add(Command*);
	virtual void remove(Command*);
	virtual void execute();
private:
	std::vector<Command*> commands;
};