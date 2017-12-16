#include "IntroState.h"

IntroState::IntroState()
{
}


IntroState::~IntroState()
{
	delete m_Text;
	TTF_CloseFont(m_Font);
}


void IntroState::Init(GameEngine * gameEngine, SDL_Renderer * renderer)
{
	m_GameEngine = gameEngine;
	m_Renderer = renderer;

	m_Font = TTF_OpenFont("fonts/lazy.ttf", 28);

	SDL_Color color = { 255,255,255,255 };

	m_Text = new Text(m_Renderer, m_Font, "Lazy Foo", color);
}


void IntroState::CleanUp()
{
}


void IntroState::Pause()
{
}


void IntroState::Resume()
{
}


void IntroState::InputEvent(int mod, int state, int key)
{
	if (state == SDL_KEYUP)
	{
		switch (key)
		{
		case SDLK_SPACE:
			m_GameEngine->SetState(State::GAMEPLAY);
			break;

		default:
			break;
		}
	}
}


void IntroState::Update(float dt)
{

}


void IntroState::Render()
{
	SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 1);
	SDL_RenderClear(m_Renderer);

	// Add graphics to render...

	//m_Text.Draw(m_Renderer, 100, 100);
	m_Text->Draw(m_Renderer, 100, 100);

	// End of graphics to render...

	SDL_RenderPresent(m_Renderer);
}
