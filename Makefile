NAME = endgame

SRCS = src/mx_main.c \
		src/mx_move_player.c \
		src/vrag.c \
		src/mx_menu.c \
		src/mx_catch_waste.c \

INC = inc/header.h

SDL =   -F inc/framework -I inc/framework/SDL2.framework/SDL2 inc/framework/SDL2_image.framework/SDL2_image inc/framework/SDL2_mixer.framework/SDL2_mixer

CFLAGS = -std=c11 -Wall -Wextra -Werror -g \
	 	 -rpath inc/framework -framework SDL2 \
		 -framework SDL2_image \
		-framework SDL2_ttf \
		-I inc/framework/SDL2_image.framework/Headers \
		-I inc/framework/SDL2_ttf.framework/Headers 
all: $(NAME)

$(NAME): install clean

install:
	@cp $(SRCS) .
	@cp $(INC) .
	@clang $(CFLAGS) -o $(NAME) $(SRCS) $(LIBS) $(SDL) -I inc

uninstall: clean
	@rm -rf $(NAME)

clean:
	@rm -rf header.h
	@rm -rf mx_main.c \
			mx_move_player.c \
			vrag.c \
			mx_menu.c \
			mx_catch_waste.c \

reinstall: all 
