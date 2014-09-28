#include "../include/EventListener.h"
#include <stdio.h>

EventListener::EventListener() {
}

EventListener::~EventListener() {
	//Do nothing
}

void EventListener::onEvent(SDL_Event* Event) {
	switch(Event->type) {

		case SDL_KEYDOWN: {
			onKeyDown(Event->key.keysym.sym);
			break;
		}

		case SDL_KEYUP: {
			onKeyUp(Event->key.keysym.sym);
			break;
		}

		case SDL_MOUSEMOTION: {
			onMouseMove(Event->motion.x,Event->motion.y,Event->motion.xrel,Event->motion.yrel,(Event->motion.state&SDL_BUTTON(SDL_BUTTON_LEFT))!=0,(Event->motion.state&SDL_BUTTON(SDL_BUTTON_RIGHT))!=0,(Event->motion.state&SDL_BUTTON(SDL_BUTTON_MIDDLE))!=0);
			break;
		}

		case SDL_MOUSEBUTTONDOWN: {
			switch(Event->button.button) {
				case SDL_BUTTON_LEFT: {
					onLButtonDown(Event->button.x,Event->button.y);
					break;
				}
				case SDL_BUTTON_RIGHT: {
					onRButtonDown(Event->button.x,Event->button.y);
					break;
				}
				case SDL_BUTTON_MIDDLE: {
					onMButtonDown(Event->button.x,Event->button.y);
					break;
				}
			}
			break;
		}

		case SDL_MOUSEBUTTONUP:	{
			switch(Event->button.button) {
				case SDL_BUTTON_LEFT: {
					onLButtonUp(Event->button.x,Event->button.y);
					break;
				}
				case SDL_BUTTON_RIGHT: {
					onRButtonUp(Event->button.x,Event->button.y);
					break;
				}
				case SDL_BUTTON_MIDDLE: {
					onMButtonUp(Event->button.x,Event->button.y);
					break;
				}
			}
			break;
		}

		case SDL_JOYAXISMOTION: {
			onJoyAxis(Event->jaxis.which,Event->jaxis.axis,Event->jaxis.value);
			break;
		}

		case SDL_JOYBALLMOTION: {
			onJoyBall(Event->jball.which,Event->jball.ball,Event->jball.xrel,Event->jball.yrel);
			break;
		}

		case SDL_JOYHATMOTION: {
			onJoyHat(Event->jhat.which,Event->jhat.hat,Event->jhat.value);
			break;
		}
		case SDL_JOYBUTTONDOWN: {
			onJoyButtonDown(Event->jbutton.which,Event->jbutton.button);
			break;
		}

		case SDL_JOYBUTTONUP: {
			onJoyButtonUp(Event->jbutton.which,Event->jbutton.button);
			break;
		}

		case SDL_QUIT: {
			onExit();
			break;
		}

		case SDL_SYSWMEVENT: {
			//Ignore
			break;
		}

		default: {
			onUser(Event->user.type,Event->user.code,Event->user.data1,Event->user.data2);
			break;
		}
	}
}

void EventListener::onInputFocus() {
	//Pure virtual, do nothing
}

void EventListener::onInputBlur() {
	//Pure virtual, do nothing
}

void EventListener::onKeyDown(SDL_Keycode sym) {
	//Pure virtual, do nothing
}

void EventListener::onKeyUp(SDL_Keycode sym) {
	//Pure virtual, do nothing
}

void EventListener::onMouseFocus() {
	//Pure virtual, do nothing
}

void EventListener::onMouseBlur() {
	//Pure virtual, do nothing
}

void EventListener::onMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle) {
	//Pure virtual, do nothing
}

void EventListener::onMouseWheel(bool Up, bool Down) {
	//Pure virtual, do nothing
}

void EventListener::onLButtonDown(int mX, int mY) {
	//Pure virtual, do nothing
}

void EventListener::onLButtonUp(int mX, int mY) {
	//Pure virtual, do nothing
}

void EventListener::onRButtonDown(int mX, int mY) {
	//Pure virtual, do nothing
}

void EventListener::onRButtonUp(int mX, int mY) {
	//Pure virtual, do nothing
}

void EventListener::onMButtonDown(int mX, int mY) {
	//Pure virtual, do nothing
}

void EventListener::onMButtonUp(int mX, int mY) {
	//Pure virtual, do nothing
}

void EventListener::onJoyAxis(Uint8 which,Uint8 axis,Sint16 value) {
	//Pure virtual, do nothing
}

void EventListener::onJoyButtonDown(Uint8 which,Uint8 button) {
	//Pure virtual, do nothing
}

void EventListener::onJoyButtonUp(Uint8 which,Uint8 button) {
	//Pure virtual, do nothing
}

void EventListener::onJoyHat(Uint8 which,Uint8 hat,Uint8 value) {
	//Pure virtual, do nothing
}

void EventListener::onJoyBall(Uint8 which,Uint8 ball,Sint16 xrel,Sint16 yrel) {
	//Pure virtual, do nothing
}

void EventListener::onMinimize() {
	//Pure virtual, do nothing
}

void EventListener::onRestore() {
	//Pure virtual, do nothing
}

void EventListener::onResize(int w,int h) {
	//Pure virtual, do nothing
}

void EventListener::onExpose() {
	//Pure virtual, do nothing
}

void EventListener::onExit() {
	//Pure virtual, do nothing
}

void EventListener::onUser(Uint8 type, int code, void* data1, void* data2) {
	//Pure virtual, do nothing
}
