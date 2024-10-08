# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 14:06:06 by hucorrei          #+#    #+#              #
#    Updated: 2023/09/05 10:18:48 by hucorrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME		= cub3D
NAME_BONUS	= cub3D_bonus
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
OBJ_DIR		= .objs

################################################################################
#                                  OS detection                                #
################################################################################

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	MLX		= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
	MLX_DIR	= ./mlx_linux
endif
ifeq ($(UNAME_S),Darwin)
	MLX		= -lmlx -framework OpenGL -framework AppKit
	MLX_DIR	= ./mlx_mac
endif

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS	= 		./src/mandatory/main.c \
				./src/mandatory/tools/ft_tools.c \
				./src/mandatory/parsing/ft_rgb.c \
				./src/mandatory/parsing/ft_parsing.c \
				./src/mandatory/parsing/ft_init.c \
				./src/mandatory/parsing/ft_map.c \
				./src/mandatory/parsing/ft_map_tools.c \
				./src/mandatory/3D/game_start.c \
				./src/mandatory/3D/minimap.c \
				./src/mandatory/3D/my_mlx.c \
				./src/mandatory/3D/player.c \
				./src/mandatory/3D/raycast.c \
				./src/mandatory/3D/render.c \
				./src/mandatory/3D/texture.c \
				./src/mandatory/3D/utils.c \
				./src/mandatory/3D/mouses.c \
				./src/mandatory/3D/end.c \

SRCS_BONUS =	./src/Bonus/main.c \
				./src/Bonus/tools/ft_tools_bonus.c \
				./src/Bonus/parsing/ft_rgb_bonus.c \
				./src/Bonus/parsing/ft_parsing_bonus.c \
				./src/Bonus/parsing/ft_init_bonus.c \
				./src/Bonus/parsing/ft_map_bonus.c \
				./src/Bonus/parsing/ft_map_tools_bonus.c \
				./src/Bonus/3D/game_start_bonus.c \
				./src/Bonus/3D/minimap_bonus.c \
				./src/Bonus/3D/my_mlx_bonus.c \
				./src/Bonus/3D/player_bonus.c \
				./src/Bonus/3D/raycast_bonus.c \
				./src/Bonus/3D/render_bonus.c \
				./src/Bonus/3D/texture_bonus.c \
				./src/Bonus/3D/utils_bonus.c \
				./src/Bonus/3D/mouses_bonus.c \
				./src/Bonus/3D/end_bonus.c \

OBJS	= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

OBJS_BONUS	= $(addprefix $(OBJ_DIR)/, $(SRCS_BONUS:.c=.o))

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@${CC} ${CFLAGS} -c $< -o $@ 

################################################################################
#                                  Makefile  objs                              #
################################################################################

CLR_RMV		= \033[0m
RED		    = \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
CYAN 		= \033[1;36m
RM			= rm -rf

${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}LibFT ${CLR_RMV}..."
			@${MAKE} -C ./libft >/dev/null 2>&1
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}MiniLibX ${CLR_RMV}..."
			@ $(MAKE) -C ${MLX_DIR} all >/dev/null 2>&1
			@ cp ${MLX_DIR}/libmlx.a .
			@${CC} ${CFLAGS} ${OBJS} ${MLX} ./libft/libft.a -o ${NAME}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		${NAME}

clean:
			@${MAKE} -C ./libft clean
			@${MAKE} -C ${MLX_DIR} clean >/dev/null 2>&1
			@${RM} -r $(OBJ_DIR)
			@${RM} ${OBJS}
			@${RM} ${OBJS_BONUS}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ ${RM} ${NAME_BONUS}
			@${RM} libmlx.a
			@${RM} ./libft/libft.a
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

$(NAME_BONUS):		${OBJS_BONUS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME_BONUS) ${CLR_RMV}..."
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}LibFT ${CLR_RMV}..."
			@${MAKE} -C ./libft >/dev/null 2>&1
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}MiniLibX ${CLR_RMV}..."
			@ $(MAKE) -C ${MLX_DIR} all >/dev/null 2>&1
			@ cp ${MLX_DIR}/libmlx.a .
			@${CC} ${CFLAGS} ${OBJS_BONUS} ${MLX} ./libft/libft.a -o ${NAME_BONUS}
			@echo "$(GREEN)$(NAME_BONUS) created[0m ✔️"

bonus:		${NAME_BONUS}

git:
			git add .
			git commit -m "$m"
			git push
			@ echo "$(BLUE)ALL is on your $(CYAN)GIT $(CLR_RMV)✔️"

.PHONY:	all clean fclean re bonus git