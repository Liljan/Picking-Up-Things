#include "Text.h"

Text::Text(SDL_Renderer * renderer, TTF_Font * font, const char * msg, SDL_Color color)
{
	m_SurfaceMessage = TTF_RenderText_Blended(font, msg, color);
	m_Texture = SDL_CreateTextureFromSurface(renderer, m_SurfaceMessage);
}

Text::~Text()
{
	SDL_FreeSurface(m_SurfaceMessage);
	SDL_DestroyTexture(m_Texture);
}

void Text::Initialize(SDL_Renderer * renderer, TTF_Font * font, const char * msg, SDL_Color color)
{
	m_SurfaceMessage = TTF_RenderText_Blended(font, msg, color);
	m_Texture = SDL_CreateTextureFromSurface(renderer, m_SurfaceMessage);
}

void Text::Draw(SDL_Renderer * renderer, int x, int y, int w, int h)
{
	m_DrawRect.x = x;
	m_DrawRect.y = y;
	m_DrawRect.w = w;
	m_DrawRect.h = h;

	SDL_RenderCopy(renderer, m_Texture, nullptr, &m_DrawRect);
}
