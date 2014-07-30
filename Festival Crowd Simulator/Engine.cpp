#include "Engine.h"

//Initialize statics
Engine* Engine::s_pEngine = NULL;

Engine::Engine()
	:m_pGame(0)
	,m_pWindow(0)
{
}

Engine::~Engine()
{
	DELETE_AND_CLEAN(m_pWindow);
	DELETE_AND_CLEAN(m_pGame);
}

Engine* Engine::GetSingleton()
{
	if ( s_pEngine == NULL) s_pEngine = new Engine();
	return s_pEngine;
}

bool Engine::InitWindow()
{
	m_pWindow = new RenderWindow(sf::VideoMode(800, 600), "AI project");
	return true;
}

void Engine::SetGame(AbstractGame* game)
{
	m_pGame = game;
}

bool Engine::Run()
{
	// create the game engine object, exit if failure
	if (Engine::GetSingleton() == NULL) return false;

	// If no game has been set, exit
	if(m_pGame == NULL) return false;

	m_pGame->InitializeElements();

	// Enter the main message loop
	while (m_pWindow->isOpen())
    {
		//Poll the events (in this case windows events)
        Event event;
        while (m_pWindow->pollEvent(event))
        {
            if (event.type == Event::Closed)
                m_pWindow->close();
        }

		//Run the update logic
		m_pGame->Update();

		//Run the render logic
        m_pWindow->clear();
		m_pGame->Render();
        m_pWindow->display();
    }
	
	
	//Cleanup
	delete this;
	//return msg.wParam?true:false;
	return true;
}

RenderWindow* Engine::GetWindow() const
{
	return m_pWindow;
}

void Engine::Render(Drawable* drawable)
{
	m_pWindow->draw(*drawable);
}