#include "GameplayState.h"

GameplayState::GameplayState()
{
}

GameplayState::~GameplayState()
{
	//delete m_Player;
}


void GameplayState::Init(GameEngine * gameEngine, SDL_Renderer * renderer)
{
	m_GameEngine = gameEngine;
	m_Renderer = renderer;
}


void GameplayState::CleanUp()
{
}


void GameplayState::Pause()
{
}


void GameplayState::Resume()
{
}


void GameplayState::InputEvent(int mod, int state, int key)
{
	if (state == SDL_KEYUP)
	{
		switch (key)
		{
		case SDLK_ESCAPE:
			m_GameEngine->SetState(State::INTRO);
			break;

		case SDLK_SPACE:
			m_GameEngine->SetState(State::HIGHSCORE);
			break;

		default:
			break;
		}
	}
}

void GameplayState::Update(float dt)
{
}

void GameplayState::Render()
{
	SDL_SetRenderDrawColor(m_Renderer, 255, 255, 0, 255);
	SDL_RenderClear(m_Renderer);

	// Add graphics to render...

	// End of graphics to render...

	SDL_RenderPresent(m_Renderer);
}
