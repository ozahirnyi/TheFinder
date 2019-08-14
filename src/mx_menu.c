#include "header.h"

int is_started = 0;

#define HEIGHT 1200
#define WIDTH 1200

void            put_pixel(SDL_Surface *winsurface, int x, int y, int32_t pixel)
{
    int         *target_pixel;


    if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT - 1)
        return ;
    target_pixel = winsurface->pixels + y * winsurface->pitch + x * winsurface->format->BytesPerPixel;
    *target_pixel = pixel;
}

void            draw_bmp(SDL_Surface *winsurface, SDL_Surface *bmp, int win_y, int win_x)
{
    int         x;
    int         y;
    int         *color;

    y = -1;
    while (++y < bmp->h)
    {
        x = -1;
        while (++x < bmp->w)
        {
            color = bmp->pixels + y * bmp->pitch + x * bmp->format->BytesPerPixel;
            if (*color != ~0xFF0F00 && *color != 0x000000)
                put_pixel(winsurface, win_x + x, win_y + y, *color);
        }
    }
}

void            draw_menu(SDL_Surface *w, SDL_Surface *pict1, SDL_Surface *pict2, SDL_Surface *pict3)
{
    draw_bmp(w, pict1, 500, 480);
    draw_bmp(w, pict2, 600, 480);
    draw_bmp(w, pict3, 200, 293);
}

void    gui_buttondown(SDL_Event event)
{

    int         i;
    int         x;
    int         y;

    i = -1;
    x = event.motion.x;
    y = event.motion.y;
    if ((y >= 500 && y <= 600) && (x >= 480 && x <= 680))
       is_started = 1;
    if ((y >= 600 && y <= 700) && (x >= 480 && x <= 680))
        exit(0);
}


void  start_menu(SDL_Window *window, mx_sdl m)
{
    int         running;
    SDL_Event   event;

    running = 1;
    while (running)
    {
        draw_menu(m.w, m.p1, m.p2, m.p3);
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT ||
                    (event.type == SDL_KEYDOWN &&
                    event.key.keysym.scancode == SDL_SCANCODE_ESCAPE))
                running = 0;
            if (event.type == SDL_MOUSEBUTTONDOWN)
               gui_buttondown(event);
            if (is_started)
                running = 0;
            SDL_UpdateWindowSurface(window);
        }
    }
}
