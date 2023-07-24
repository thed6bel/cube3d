# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thed6bel <thed6bel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 09:27:30 by hucorrei          #+#    #+#              #
#    Updated: 2023/07/24 18:09:01 by thed6bel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME	= cub3D
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g3 -fsanitize=address
OBJ_DIR	= .objs
#MLX		= -lmlx -framework OpenGL -framework AppKit
MLX	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

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

SRCS	= 	./src/mandatory/main.c \
			./src/mandatory/ft_map_check.c \
			./src/mandatory/ft_tools.c \
			./src/mandatory/parsing/ft_rgb.c \
			./src/mandatory/ft_read_map.c \
			./src/mandatory/parsing/ft_parsing.c \
			./src/mandatory/parsing/ft_init.c \
			./src/mandatory/parsing/ft_map.c \

OBJS	= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@${CC} ${FLAGS} -c $< -o $@ 

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
		@${MAKE} -C ./libft
		@ $(MAKE) -C ${MLX_DIR} all >/dev/null 2>&1
		@ cp ${MLX_DIR}/libmlx.a .
		@${CC} ${CFLAGS} ${OBJS} ${MLX} ./libft/libft.a -o ${NAME}
		@echo "$(GREEN)$(NAME) created[0m ✔️"

all:	${NAME}

clean:
			@${MAKE} -C ./libft clean
			@${MAKE} -C ${MLX_DIR} clean
			@${RM} -r $(OBJ_DIR)
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@${RM} libmlx.a
			@${RM} ./libft/libft.a
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

bonus:		all

git:
		git add .
		git commit -m "$m"
		git push
		@ echo "$(BLUE)ALL is on your $(CYAN)GIT $(CLR_RMV)✔️"

.PHONY:	all clean fclean re bonus git