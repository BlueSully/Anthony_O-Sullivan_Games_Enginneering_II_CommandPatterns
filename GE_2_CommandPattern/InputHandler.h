#pragma once

#include "Command.h"
#include "SDL.h"
#include <iostream>

class InputHandler
{
public:
	void handleInput(SDL_Event & event);
	// Methods to bind commands...
	void buttonBind();
private:
	Command* jump_;
	Command* moveLeft_;
	Command* goProne_;
	Command* moveRight_;

	Command* undo_;

};

void  InputHandler::buttonBind()
{
	jump_ = new JumpCommand;
	moveLeft_ = new LeftCommand;
	goProne_ = new ProneCommand;
	moveRight_ = new RightCommand;;

	undo_ = new UndoCommand;
}

void InputHandler::handleInput(SDL_Event & evt)
{
	if (evt.key.keysym.sym == SDLK_w || evt.key.keysym.sym == SDLK_UP || evt.key.keysym.sym == SDLK_SPACE)
	{
		jump_->execute();
	}

	if (evt.key.keysym.sym == SDLK_a || evt.key.keysym.sym == SDLK_LEFT)
	{
		moveLeft_->execute();
	}

	if (evt.key.keysym.sym == SDLK_d || evt.key.keysym.sym == SDLK_RIGHT)
	{
		moveRight_->execute();
	}

	if (evt.key.keysym.sym == SDLK_s || evt.key.keysym.sym == SDLK_DOWN)
	{
		goProne_->execute();
	}

	if (evt.key.keysym.sym == SDLK_BACKSPACE)
	{
		undo_->execute();
	}
}