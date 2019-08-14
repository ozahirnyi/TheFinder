#include "header.h"

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include "SDL2_image/SDL_image.h"
#include "SDL2_mixer/SDL_mixer.h"

static const char *MY_COOL_MP3 = "resource/sound.mp3";
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 1200;

int main() {
	int result = 0;
    int flags = MIX_INIT_MP3;
	int running = 1;
	SDL_Event event;
	mx_sdl member;
	int organicCount = 2;
	int metalCount = 2;

	int lenX = 24;
	int lenY = 24;
	int max_x = 24*24;
	int *map = (int *)malloc(sizeof(int) * lenX * lenY);
	int arr[24][24] =  {{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
						{-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1},
						{-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1},
						{-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1},
						{-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1},
						{-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1},
						{-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1},
						{-1, 0, 0, 0,-2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-2, 0, 0, 0, 0,-1},
						{-1, 0, 0, 0,-2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-2, 0, 0, 0, 0,-1},
						{-1, 0, 0, 0,-2,-1,-1, 0, 0, 0,-1,-1,-1, 0, 0, 0,-1,-1,-2, 0, 0, 0, 0,-1},
						{-1, 0, 0, 0,-2,-1,-1, 0, 0, 0,-1,-1,-1, 0, 0, 0,-1,-1,-2, 0, 0, 0, 0,-1},
						{-1, 0, 0, 0,-2,-1,-1, 0, 0, 0,-1,-1,-1,-1,-1,-1,-1,-1,-2, 0, 0, 0, 0,-1},
						{-1, 0, 0, 0,-2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-2, 0, 0, 0, 0,-1},
						{-1, 0, 0, 0,-2,-1,-1,-1,-1,-1, 0,-2, 0,-1,-1,-1,-1,-1,-2, 0, 0, 0, 0,-1},
						{-1, 0, 0, 0,-2,-1,-1,-1,-1,-1, 0,-2, 0,-1,-1,-1,-1,-1,-2, 0, 0, 0, 0,-1},
						{-1, 0, 0, 0,-2, 0, 0, 0,-1,-1,-1,-2,-1,-1,-1, 0, 0, 0,-2, 0, 0, 0, 0,-1},
						{-1, 0, 0, 0,-1,-1,-1,-2, 0,-1,-1,-2,-1,-1, 0,-2,-1,-1,-1, 0, 0, 0, 0,-1},
						{-1, 0, 0, 0, 0, 0, 0,-2, 0,-1,-1,-2,-1,-1, 0,-2, 0, 0, 0, 0, 0, 0, 0,-1},
						{-1, 0, 0, 0, 0, 0, 0,-2, 0, 0, 0,-2, 0, 0, 0,-2, 0, 0, 0, 0, 0, 0, 0,-1},
						{-1, 0, 0, 0, 0, 0, 0,-2,-1,-1,-1,-1,-1,-1,-1,-2, 0, 0, 0, 0, 0, 0, 0,-1},
						{-1, 0, 0, 0, 0, 0, 0,-2,-1,-2,-1,-2,-1,-2,-1,-2, 0, 0, 0, 0, 0, 0, 0,-1},
						{-1, 0, 0, 0, 0, 0, 0,-2,-1,-2,-1,-2,-1,-2,-1,-2, 0, 0, 0, 0, 0, 0, 0,-1},
						{-1, 3, 0, 0, 0, 0, 0,-2,-1,-2,-1,-2,-1,-2,-1,-2, 0, 0, 0, 0, 0, 0, 4,-1},
						{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}};
	
	
        if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        printf("Failed to init SDL\n");
        exit(1);
    }

    if (flags != (result = Mix_Init(flags))) {
        printf("Could not initialize mixer (result: %d).\n", result);
        printf("Mix_Init: %s\n", Mix_GetError());
        exit(1);
    }

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2250);
    Mix_Music *music = Mix_LoadMUS(MY_COOL_MP3);
    Mix_PlayMusic(music, 1);



for (int y = 0; y < lenY; y++) {
		for (int x = 0; x < lenX; x++) {
			*(map + y * lenX + x) = arr[y][x];
		}
	}


	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window = SDL_CreateWindow("Map", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
	SDL_Surface *surface = SDL_GetWindowSurface(window); 
	member.w = surface;
	SDL_Surface *img[12];
    img[0] = IMG_Load("resource/GIF1.png"); 
	img[1] = IMG_Load("resource/GIF2.png");
	img[2] = IMG_Load("resource/GIF3.png"); 
	img[3] = IMG_Load("resource/GIF4.png");
	img[4] = IMG_Load("resource/GIF5.png");
	img[5] = IMG_Load("resource/GIF6.png");
	img[6] = IMG_Load("resource/GIF7.png");
	img[7] = IMG_Load("resource/GIF8.png");
	img[8] = IMG_Load("resource/GIF9.png");
	img[9] = IMG_Load("resource/GIF10.png");
	img[10] = IMG_Load("resource/GIF11.png");
	img[11] = IMG_Load("resource/GIF12.png");

	SDL_Rect wasteRect1 = {9 * 50, 6 * 50, 50, 50};
	SDL_Surface *wasteSurface1 = IMG_Load("resource/trash/trash1.png");

	SDL_Rect wasteRect2 = {20 * 50, 22 * 50, 50, 50};
    SDL_Surface *wasteSurface2 = IMG_Load("resource/trash/trash2.png");

	SDL_Rect wasteRect3 = {3 * 50, 20 * 50, 50, 50};
    SDL_Surface *wasteSurface3 = IMG_Load("resource/trash/trash4.png");

	SDL_Rect wasteRect4 = {12 * 50, 13 * 50, 50, 50};
    SDL_Surface *wasteSurface4 = IMG_Load("resource/trash/trash5.png");


	SDL_Surface *texture[lenX * lenY];
	for (int y = 0; y < 24; y++) {
		for (int x = 0; x < 24; x++) {
			if (arr[y][x] == -1)
				texture[lenX * y + x ] = IMG_Load("resource/texture/blockofplatform.png");
			if (arr[y][x] == -2)
				texture[lenX * y + x] = IMG_Load("resource/texture/download.png");
			if (arr[y][x] == 0)
				texture[lenX * y + x] = IMG_Load("resource/texture/space.png");
			if (arr[y][x] == 3)
				texture[lenX * y + x] = IMG_Load("resource/trash/trashbox1.png");
			if (arr[y][x] == 4)
                texture[lenX * y + x] = IMG_Load("resource/trash/trashbox2.png");
		}
	}

	SDL_Surface *move_right[8];
	move_right[0] = IMG_Load("resource/player/right/moveright1.png");
    move_right[1] = IMG_Load("resource/player/right/moveright2.png");
    move_right[2] = IMG_Load("resource/player/right/moveright3.png");
    move_right[3] = IMG_Load("resource/player/right/moveright4.png");
    move_right[4] = IMG_Load("resource/player/right/moveright5.png");
    move_right[5] = IMG_Load("resource/player/right/moveright6.png");
    move_right[6] = IMG_Load("resource/player/right/moveright7.png");
    move_right[7] = IMG_Load("resource/player/right/moveright8.png");
    

 SDL_Surface *move_left[8];
    move_left[0] = IMG_Load("resource/player/left/moveleft1.png"); 
    move_left[1] = IMG_Load("resource/player/left/moveleft2.png");
    move_left[2] = IMG_Load("resource/player/left/moveleft3.png");
    move_left[3] = IMG_Load("resource/player/left/moveleft4.png");
    move_left[4] = IMG_Load("resource/player/left/moveleft5.png");
    move_left[5] = IMG_Load("resource/player/left/moveleft6.png");
    move_left[6] = IMG_Load("resource/player/left/moveleft7.png");
	move_left[7] = IMG_Load("resource/player/left/moveleft8.png");

SDL_Surface *enemy = IMG_Load("resource/enemy/enemies1.png");





	SDL_Rect rect = {0, 0, SCREEN_HEIGHT, SCREEN_WIDTH}; 







	if (window == NULL)
		exit(1);


	
     SDL_Surface *logo = IMG_Load("resource/logo.bmp");
     SDL_Surface *start = IMG_Load("resource/play1.bmp");
     SDL_Surface *quit = IMG_Load("resource/quit1.bmp");

     member.p1 = start;
     member.p2 = quit;
     member.p3 = logo;


	t_player *player = (t_player *)malloc(sizeof(t_player));
	player->x = 4;
	player->y = 4;
	player->waste = 0; 

	t_vrag *vrag = (t_vrag *)malloc(sizeof(t_vrag));
	vrag->x = 12; 
	vrag->y = 5;

	int j = 0;
	int i = 0;
	int flag = 1;
	SDL_Surface *direction = move_right[j];

	start_menu(window, member);

	while (running) {
		while(SDL_PollEvent(&event)) {
			if ((SDL_QUIT == event.type)
				|| (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE))
                running = 0;

			if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
				direction = move_left[j];
			else
				direction = move_right[j];
        }

		mx_move_player(&event, player, map, lenX);
		mx_vrag(map, vrag, player ,  max_x, lenX, &flag);
			
		if (player->x == vrag->x && player->y == vrag->y) 
			break;

		if (player->x == (wasteRect1.x / 50)
			&& player->y == (wasteRect1.y / 50)
			&& player->waste == 0) {
			wasteSurface1 = IMG_Load("resource/texture/space.png");
			player->waste = 1;
		}

		if (player->x == (wasteRect2.x / 50)
            && player->y == (wasteRect2.y / 50)
            && player->waste == 0) {
            wasteSurface2 = IMG_Load("resource/texture/space.png");
			player->waste = 1;
        }

		if (player->x == (wasteRect3.x / 50)
            && player->y == (wasteRect3.y / 50)
            && player->waste == 0) {
            wasteSurface3 = IMG_Load("resource/texture/space.png");
			player->waste = 2;
        }

		if (player->x == (wasteRect4.x / 50)
            && player->y == (wasteRect4.y / 50)
            && player->waste == 0) {
            wasteSurface4 = IMG_Load("resource/texture/space.png");
			player->waste = 2;
        }

		organicCount = mx_trash_can1(player, map, lenX, organicCount);
		metalCount = mx_trash_can2(player, map, lenX, metalCount);

		

			SDL_BlitSurface(img[i], NULL, surface, &rect); 
			

			for (int y = 0; y < 24; y++) {
				for (int x = 0; x < 24; x++) {
					SDL_Rect rect = {50 * x, 50 * y, 50, 50};
					SDL_BlitSurface(texture[lenX * y + x], NULL, img[i], &rect);
				}
			}
		SDL_BlitSurface(wasteSurface1, NULL, surface, &wasteRect1);
		SDL_BlitSurface(wasteSurface2, NULL, surface, &wasteRect2);

		SDL_BlitSurface(wasteSurface3, NULL, surface, &wasteRect3);
		SDL_BlitSurface(wasteSurface4, NULL, surface, &wasteRect4);

		if (organicCount == 0 && metalCount == 0) {
			SDL_Delay(3000);
			break;
		}

			
			SDL_Rect playerRect = {player->x * 50, player->y * 50, 50, 50};
			SDL_BlitSurface(direction, NULL, surface, &playerRect);

			SDL_Rect enemyRect = {vrag->x * 50, vrag->y * 50, 50, 50};
			SDL_BlitSurface(enemy, NULL, surface, &enemyRect);

		if (Mix_PlayingMusic() == 0)
			Mix_PlayMusic(music, 1);


		SDL_UpdateWindowSurface(window);
		SDL_Delay(120);
		i++;
		j++;
		if (i == 12)
			i = 0;
		if (j == 8)
			j= 0;
    }
    
	free(player);
	free(map);
	free(vrag);

	SDL_FreeSurface(wasteSurface1);
    wasteSurface1 = NULL;

	SDL_FreeSurface(wasteSurface2);
    wasteSurface2 = NULL;

	SDL_FreeSurface(wasteSurface3);
    wasteSurface3 = NULL;

	SDL_FreeSurface(wasteSurface4);
    wasteSurface4 = NULL;


	SDL_FreeSurface(surface);
	surface = NULL;
	Mix_FreeMusic(music);
    SDL_DestroyWindow(window);
	window = NULL;
	SDL_Quit();
    return (0);
}

