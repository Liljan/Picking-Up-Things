#include "HighscoreState.h"

HighscoreState::HighscoreState()
{
}

HighscoreState::~HighscoreState()
{
}

void HighscoreState::Init(GameEngine * gameEngine, SDL_Renderer * renderer)
{
	m_GameEngine = gameEngine;
	m_Renderer = renderer;
}

void HighscoreState::CleanUp()
{
}

void HighscoreState::Pause()
{
}

void HighscoreState::Resume()
{
}

void HighscoreState::InputEvent(int mod, int state, int key)
{
	if (state == SDL_KEYUP)
	{
		switch (key)
		{
		case SDLK_ESCAPE:
			m_GameEngine->SetState(State::GAMEPLAY);
			break;

		default:
			break;
		}
	}
}

void HighscoreState::Update(float dt)
{
}

void HighscoreState::Render()
{
	SDL_SetRenderDrawColor(m_Renderer, 0, 255, 0, 255);
	SDL_RenderClear(m_Renderer);

	// Add graphics to render...

	// End of graphics to render...

	SDL_RenderPresent(m_Renderer);
}
