#pragma once

#include "SDL.h"
#include "SDL_ttf.h"

class Text
{
public:
	Text() = default;
	Text(Text& other);
	Text(SDL_Renderer* renderer, TTF_Font * font, const char * msg, SDL_Color color);
	~Text();

	Text& operator=(Text& other);

	//void Initialize(SDL_Renderer* renderer, TTF_Font * font, const char * msg, SDL_Color color);
	void Draw(SDL_Renderer* renderer, int x, int y);

private:
	TTF_Font* m_Font;
	SDL_Color m_Color;

	SDL_Surface* m_SurfaceMessage;
	SDL_Texture* m_Texture;
	SDL_Rect m_DrawRect;
};
