#include "SDL.h"
#include <iostream>

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 1200
#define EARTH_IMG_HEIGHT 546
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL не может быть запущен. Ошибка: " << SDL_GetError();
		SDL_Quit(); 
		return 0;
	}

	SDL_Window* window = SDL_CreateWindow(u8"Шкиров", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);	
	if (window == NULL) 
	{ 
		std::cout << "SDL не может создать окно. Ошибка: " << SDL_GetError();
		SDL_Quit();  
		return 0; 
	}

	SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 237, 237, 237));
	
	SDL_Surface* EarthImg = SDL_LoadBMP("1.bmp");
	if (EarthImg == NULL) { std::cout << "Ошибка вывода изображения 1.bmp"; }

	SDL_Rect dest = { 0, SCREEN_HEIGHT-EARTH_IMG_HEIGHT };

	SDL_SetColorKey(EarthImg, SDL_TRUE, SDL_MapRGB(EarthImg->format, 255, 255, 255));
	SDL_BlitSurface(EarthImg, NULL, screenSurface, &dest);

	SDL_UpdateWindowSurface(window);

	SDL_Delay(5000);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
} 