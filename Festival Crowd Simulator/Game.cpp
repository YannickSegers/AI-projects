#include "Game.h"
#include "Engine.h"

Game::Game()
:m_pText(0)
,m_pCircle(0)
,m_pCircle2(0)
{
}

Game::~Game()
{
	DELETE_AND_CLEAN(m_pFont);
	DELETE_AND_CLEAN(m_pText);
	DELETE_AND_CLEAN(m_pCircle);
	DELETE_AND_CLEAN(m_pCircle2);
}

void Game::InitializeElements()
{
	m_pFont = new Font();
	if(!m_pFont->loadFromFile("Resources\\Fonts\\arial.ttf"))
	{
		//std::cout << "There was a problem while loading your font";
		LOG("There was a problem while loading your font\n")
		LOG_W(L"There was a problem while loading your font wide\n")
	}

	m_pText = new Text();
	m_pText->setFont(*m_pFont);
	m_pText->setString("This is a test string\non another line");
	m_pText->setCharacterSize(16);
	//text.setColor(Color::White);
	m_pText->setColor(Color(192,192,192,255));
	m_pText->setPosition(5,5);
	//text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    m_pCircle = new CircleShape(100.f);
	m_pCircle2 = new CircleShape(150.f);
	//shape.setFillColor(sf::Color::Green);
	m_pCircle->setFillColor(Color(255,0,0,255));
	m_pCircle2->setFillColor(Color(0,255,0,125));
}

void Game::Update()
{
	m_pCircle->setPosition(350.f,250.f);
	m_pCircle2->setPosition(150.f,150.f);
}

void Game::Render()
{
	ENGINE->Render(m_pText);
	ENGINE->Render(m_pCircle);
	ENGINE->Render(m_pCircle2);
}
