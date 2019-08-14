#include "header.h"

int  mx_vrag(int *map, t_vrag *fight,  t_player *player, int max_x, int lenX, int *flag) {	
	int x = fight->x;
	int y = fight->y;
	max_x = 0;

	if (*(map + ((fight->y + 1) * lenX) + fight->x) == 0)
		fight->y += 1;
	if  (*(map +((y+1)*lenX)+x-1) != -2   && *flag == 1)
		fight->x -= 1;
	if  (*(map +((y+1)*lenX)+x-1) == -2)
		*flag = 0;
	if  (*(map +((y+1)*lenX)+x+1) != -2   && *flag == 0)
         fight->x += 1;
	if  (*(map +((y+1)*lenX)+x+1) == -2)
         *flag = 1;
	if ( x == player->x && y == player->y)
		return 1;
	return 0;
}		

