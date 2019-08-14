#include "header.h"

SDL_Surface *mx_catch_waist1(t_player *player, int *map, int lenX, SDL_Surface *src, SDL_Surface *img) {
	if (*(map + (player->y * lenX) + player->x) == 1
		&& player->waste == 0) {
		player->waste = 1;
		*(map + (player->y * lenX) + player->x) = 0;
		return img;
	}
	return src;
}

SDL_Surface *mx_catch_waist2(t_player *player, int *map, int lenX, SDL_Surface *src, SDL_Surface *img) {
	if (*(map + (player->y * lenX) + player->x) == 2
		&& player->waste == 0) {
		player->waste = 2;
		*(map + (player->y * lenX) + player->x) = 0;
		return img;
	}
	return src;
}

int mx_trash_can1(t_player *player, int *map, int lenX, int organicCount) {
	if (*(map + (player->y * lenX) + player->x) == 3
		&& player->waste == 1) {
		player->waste = 0;
		return organicCount - 1;
	}
	return organicCount;
}

int mx_trash_can2(t_player *player, int *map, int lenX, int metalCount) {
	if (*(map + (player->y * lenX) + player->x) == 4
		&& player->waste == 2) {
		player->waste = 0;
		return metalCount - 1;
	}
	return metalCount;
}

