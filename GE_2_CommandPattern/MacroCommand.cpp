#include "MacroCommand.h"
#include <algorithm>    // std::remove_if

MacroCommand::MacroCommand()
{
}

MacroCommand::~MacroCommand()
{

}

void MacroCommand::add(Command *c)
{
	commands.push_back(c);
}

void MacroCommand::remove(Command *c)
{
	commands.erase(std::remove(commands.begin(), commands.end(), c), commands.end());
}

void MacroCommand::execute()
{
	for (std::vector<Command*>::iterator i = commands.begin(); i != commands.end(); i++)
	{
		Command *c = *i;
		c->execute();
	}
}