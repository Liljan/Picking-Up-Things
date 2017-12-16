#include "Text.h"

Text::Text(Text & other)
{
	// Why can this object read from other?

	m_SurfaceMessage = other.m_SurfaceMessage;
	m_Texture = other.m_Texture;
	m_DrawRect = other.m_DrawRect;
}

Text::Text(SDL_Renderer * renderer, TTF_Font * font, const char * msg, SDL_Color color)
{
	m_SurfaceMessage = TTF_RenderText_Blended(font, msg, color);
	m_Texture = SDL_CreateTextureFromSurface(renderer, m_SurfaceMessage);

	m_DrawRect.w = m_SurfaceMessage->w;
	m_DrawRect.h = m_SurfaceMessage->h;
}


Text::~Text()
{
	SDL_FreeSurface(m_SurfaceMessage);
	SDL_DestroyTexture(m_Texture);
}

Text & Text::operator=(Text & other)
{
	// Why can this object read from other?

	m_SurfaceMessage = other.m_SurfaceMessage;
	m_Texture = other.m_Texture;
	m_DrawRect = other.m_DrawRect;

	return *this;
}


void Text::Draw(SDL_Renderer * renderer, int x, int y)
{
	m_DrawRect.x = x;
	m_DrawRect.y = y;

	SDL_RenderCopy(renderer, m_Texture, nullptr, &m_DrawRect);
}

