# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paperrin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/29 19:37:35 by paperrin          #+#    #+#              #
#*   Updated: 2017/10/19 17:39:41 by paperrin         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME		=	wolf3d

CC			=	gcc

CFLAGS		=	-O3 -Wall -Wextra -Werror

RM			=	rm -rf

SRC_DIR		=	./src/

OBJ_DIR		=	./obj/

INC_DIRS	=	./include/			\
				./mlx/				\
				./libft/include/

LIB_DIRS	=	./libft/			\
				./mlx/

LIBS		=	-lft				\
				-lmlx

INC_PARAMS	=	$(INC_DIRS:%=-I%)

LIB_PARAMS	=	$(LIB_DIRS:%=-L%)

CFILES		=	main.c					\
				image.c					\
				event.c					\
				render.c				\
				map.c					\
				player.c

HFILES		=	./include/wolf3d.h			\
				./include/x11.h

SRC			=	$(CFILES:%=$(SRC_DIR)%)

OBJ			=	$(CFILES:%.c=$(OBJ_DIR)%.o)

# # # # #

all				:	libs $(NAME)

$(NAME)			:	$(OBJ) $(HFILES) ./libft/libft.a ./mlx/libmlx.a
						$(CC) $(OBJ) -o $@ $(LIB_PARAMS) $(LIBS) \
							-framework OpenGL -framework Appkit

libs			:
						make -C ./mlx/
						make -C ./libft/

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c
						mkdir -p $(OBJ_DIR)
						$(CC) $(CFLAGS) $(INC_PARAMS) -c $< -o $@

clean			:
						$(RM) $(OBJ_DIR)
						make -C ./mlx/ clean
						make -C ./libft/ clean


fclean			:	clean
						$(RM) $(NAME)
						make -C ./libft/ fclean

re				:	fclean all

norm			:
	@echo "\x1b[35m\n.==================[ \x1b[0m\c"
	@echo "\x1b[35;1mNormi-Check\x1b[0m\c"
	@echo " \x1b[35m]==================.\x1b[31;1m"
	@norminette include/ src/ \
		| tr "\n" "@" \
		| sed -e "s/Norme: /$$/g" \
		| tr "$$" "\n" \
		| grep -e Error -e Warning \
		| tr "@" "\n" \
		| sed "N;$$!P;$$!D;$$d"
	@echo "\x1b[0m\x1b[35m\c"
	@echo ".___________________________________________________.\n\x1b[0m"

.PHONY : all, clean, fclean, re, norm
