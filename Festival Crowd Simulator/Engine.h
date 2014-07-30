#ifndef __Engine_H_
#define __Engine_H_

#include "Util.h"
#include "AbstractGame.h"

class Engine
{
private:
	//-----------------
	//Member Variables
	//-----------------
	RenderWindow*					m_pWindow;
	AbstractGame*					m_pGame;

	//static pointer for singleton
	static Engine*					s_pEngine;

	// private constructor for the singleton implementations
	Engine();
	
public:
	virtual ~Engine();

	//---------
	//Methods
	//---------
	static Engine*					GetSingleton();
	bool							InitWindow();
	bool							Run();
	void							SetGame(AbstractGame* game);
	RenderWindow*					GetWindow() const;
	void							Render(Drawable* drawable);
};
#endif // __Engine_H_