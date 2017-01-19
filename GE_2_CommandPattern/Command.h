#pragma once
#include <iostream>

class Command
{
public:
	virtual ~Command() { }
	virtual void execute() = 0;
protected:
	Command() { }
};


class JumpCommand : public Command
{

public:
	virtual void execute()
	{
		std::cout << "Jumping" << std::endl;
	}
};

class LeftCommand : public Command
{

public:
	virtual void execute()
	{
		std::cout << "MovingLeft" << std::endl;
	}
};

class RightCommand : public Command
{

public:
	virtual void execute()
	{
		std::cout << "MovingRight" << std::endl;
	}
};

class ProneCommand : public Command
{

public:
	virtual void execute()
	{
		std::cout << "going Prone" << std::endl;
	}
};

class UndoCommand : public Command
{

public:
	virtual void execute()
	{
		std::cout << "Undo";
	}
};