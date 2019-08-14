#include "header.h"

void mx_move_right(t_player *player) {
	player->x += 1;
}

void mx_move_left(t_player *player) {
	player->x -= 1;
}

void mx_move_up(t_player *player) {
	player->y -= 1;
}

void mx_move_down(t_player *player) {
	player->y += 1;
}

void mx_move_player(SDL_Event *event , t_player *player, int *map, int lenX) {
	if ((*(map + ((player->y + 1) * lenX) + player->x) == -1
		|| *(map + ((player->y + 1) * lenX) + player->x) == -2)
		&& *(map + (player->y * lenX) + player->x) != -2) {
		if (event->key.keysym.scancode == SDL_SCANCODE_LEFT
			&& event->type == SDL_KEYDOWN
			&& *(map + (player->y * lenX) + player->x - 1) != -1)
			mx_move_left(player);
		if (event->key.keysym.scancode == SDL_SCANCODE_RIGHT
			&& event->type == SDL_KEYDOWN
			&& *(map + (player->y * lenX) + player->x + 1) != -1)
			mx_move_right(player);
		if (event->key.keysym.scancode == SDL_SCANCODE_DOWN
            && event->type == SDL_KEYDOWN
			&& *(map + ((player->y + 1) * lenX) + player->x) == -2)
            mx_move_down(player);
	}
	else if(*(map + (player->y * lenX) + player->x) == -2 || 
			*(map + ((player ->y + 1) * lenX) + player->x) == -2	) {
		if (event->key.keysym.scancode == SDL_SCANCODE_UP
			&& event->type == SDL_KEYDOWN
			&& (*(map + ((player->y - 1) * lenX) + player->x) == -2
			|| *(map + ((player->y - 1) * lenX) + player->x) == 0))
			mx_move_up(player);
		if (event->key.keysym.scancode == SDL_SCANCODE_DOWN
			&& event->type == SDL_KEYDOWN
			&& *(map + ((player->y + 1) * lenX) + player->x) == -2)
			mx_move_down(player);
		if (event->key.keysym.scancode == SDL_SCANCODE_LEFT
			&& event->type == SDL_KEYDOWN
			&& *(map + (player->y * lenX) + player->x - 1) != -1)
			mx_move_left(player);
		if (event->key.keysym.scancode == SDL_SCANCODE_RIGHT
			&& event->type == SDL_KEYDOWN
			&& *(map + (player->y * lenX) + player->x + 1) != -1)
			mx_move_right(player);
	}
	else if (*(map + ((player->y + 1) * lenX) + player->x) == 0) {
		mx_move_down(player);
	}

}

