#ifndef HEADER_H
#define HEADER_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "SDL2_image/SDL_image.h"
#include "SDL2_ttf/SDL_ttf.h"


typedef struct s_player {
	int x;
	int y;
	short int waste;
} t_player;

typedef struct s_vrag {
int x;
int y;
} t_vrag;

typedef struct mx_sdl
{
	SDL_Surface *p1;
	SDL_Surface *p2;
	SDL_Surface *p3;
	SDL_Surface *w;
} mx_sdl;



void            		put_pixel(SDL_Surface *winsurface, int x, int y, int32_t pixel);

void                    draw_scaled_bmp(SDL_Surface *w, SDL_Surface *bmp,
                        int win_y, int win_x);

void           			draw_bmp(SDL_Surface *winsurface, SDL_Surface *bmp, int win_y, int win_x);

void 					mx_move_player(SDL_Event *event, t_player *player, int *map, int lenX);

void            		draw_menu(SDL_Surface *w, SDL_Surface *pict1, SDL_Surface *pict2, SDL_Surface *pict3);

void    				gui_buttondown(SDL_Event event);

void  					start_menu(SDL_Window *window, mx_sdl m);



void mx_move_player(SDL_Event *event, t_player *player, int *map, int lenX);
int mx_vrag(int *map, t_vrag *fight,  t_player *player, int max_x, int lenX, int *flag);

SDL_Surface *mx_catch_waist1(t_player *player, int *map, int lenX, SDL_Surface *src, SDL_Surface *img);
SDL_Surface *mx_catch_waist2(t_player *player, int *map, int lenX, SDL_Surface *src, SDL_Surface *img);
int mx_trash_can1(t_player *player, int *map, int lenX, int organicCount);
int mx_trash_can2(t_player *player, int *map, int lenX, int metalCount);

#endif

