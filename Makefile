# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avandeve <avandeve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/04 14:27:02 by avandeve          #+#    #+#              #
#    Updated: 2024/10/26 14:37:34 by avandeve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#### SOURCES ####

FILES       = main.c \
			parsing/file_handling.c \
			init/ft_lstnew_img_obj.c \
			init/init_data_parsing.c \
			init/init_graphisms.c \
			init/init_graphisms2.c \
			init/init_textures.c \
			init/init_main_img.c \
			parsing/errors_handling.c \
			free/free_struct.c \
			free/free_mlx.c \
			free/free_collect_utils.c \
			free/exit.c \
			parsing/parsing_file.c \
			parsing/parsing_utils.c \
			parsing/parsing_utils2.c \
			parsing/player_utils.c \
			parsing/valid_contents.c \
			parsing/parsing_textures.c \
			parsing/parsing_colors.c \
			parsing/parsing_colors_utils.c \
			parsing/collect_map.c \
			parsing/parsing_map.c \
			parsing/flood_fill.c \
			parsing/flood_fill_utils.c \
			parsing/utils_for_testing.c \
			minimap/01_init_minimap.c \
			minimap/02_draw_minimap.c \
			raycasting/01_raycaster.c \
			raycasting/02_raycaster.c \
			raycasting/03_raycaster.c \
			rendering/draw_ceiling_floor.c \
			rendering/01_draw_walls.c \
			rendering/02_draw_walls.c \
			moves/manage_hook_events.c \
			moves/manage_moves.c \
			moves/manage_camera.c \
			

FILES_BONUS = main_bonus.c \
			parsing/file_handling.c \
			init/ft_lstnew_img_obj.c \
			init/init_data_parsing.c \
			init/init_graphisms.c \
			init/init_graphisms2.c \
			init/init_textures.c \
			init/init_main_img.c \
			parsing/errors_handling.c \
			free/free_struct.c \
			free/free_mlx.c \
			free/free_collect_utils.c \
			free/exit.c \
			parsing/parsing_file.c \
			parsing/parsing_utils.c \
			parsing/parsing_utils2.c \
			parsing/player_utils.c \
			parsing/valid_contents.c \
			parsing/parsing_textures.c \
			parsing/parsing_colors.c \
			parsing/parsing_colors_utils.c \
			parsing/collect_map.c \
			parsing/parsing_map.c \
			parsing/flood_fill.c \
			parsing/flood_fill_utils.c \
			parsing/utils_for_testing.c \
			minimap/01_init_minimap.c \
			minimap/02_draw_minimap.c \
			raycasting/01_raycaster_bonus.c \
			raycasting/02_raycaster.c \
			raycasting/03_raycaster.c \
			rendering/draw_ceiling_floor.c \
			rendering/01_draw_walls.c \
			rendering/02_draw_walls.c \
			moves/manage_hook_events.c \
			moves/manage_moves.c \
			moves/manage_camera.c \

INCLUDES	= includes/cub3d.h

# INCLUDES_BONUS	= includes/cub3d_bonus.h



LIBS		= -L./mlx -lmlx_Linux -lXext -lX11 -lm -lz

#### MACROS ####

DIRPATH 		=	$(sh pwd)
SRCPATH			=	$(DIRPATH)src/
SRCPATH_BONUS 	=	$(DIRPATH) src/
SRC				=	$(addprefix $(SRCPATH), $(FILES))
SRC_BONUS 		= $(addprefix $(SRCPATH_BONUS), $(FILES_BONUS))
LIBFTDIR		= ./libft
LIBFT			= libft.a
MLX 			= mlx/libmlx_Linux.a
OBJ				= $(SRC:.c=.o)
OBJ_BONUS 		= $(SRC_BONUS:.c=.o)
NAME			= cub3D
NAME_BONUS		= cub3D_bonus
NORM			= @norminette 
NORM_HEADER		= @norminette -R CheckDefine 
CC				= @cc
CFLAGS 			= -Wall -Werror -Wextra


#### RULES ####

all : $(NAME)

$(NAME) : $(MLX) $(OBJ) $(INCLUDES)
	@make -C $(LIBFTDIR) --silent
	@mv libft/libft.a .
	$(CC) $(OBJ) $(LIBS) $(LIBFT) -o $(NAME)
	@echo "${COLOUR_PURPLE}$$HEADER${COLOUR_END}\n"
	@echo "${COLOUR_CYAN}$$AUTHOR${COLOUR_END}\n"	
	@echo "${COLOUR_GREEN}Compilation complete !\n"

$(MLX) :
	@git clone https://github.com/42Paris/minilibx-linux.git mlx
	@make -C mlx --silent

bonus: $(NAME_BONUS)

$(NAME_BONUS) : $(MLX) $(OBJ_BONUS) $(INCLUDES_BONUS)
	@make -C $(LIBFTDIR) --silent
	@mv libft/libft.a . 
	$(CC) $(OBJ_BONUS) $(LIBS) $(LIBFT) -o $(NAME_BONUS)
	@echo "${COLOUR_PURPLE}$$HEADER${COLOUR_END}\n"
	@echo "${COLOUR_CYAN}$$AUTHOR${COLOUR_END}\n"	
	@echo "${COLOUR_GREEN}Compilation of the bonus complete !\n"

clean:
	@rm -f $(OBJ) $(OBJ_BONUS)
	@make -C $(LIBFTDIR) clean --silent
	@echo "${COLOUR_GREEN} All the *.o files were successfully removed!${COLOUR_END}\n"

fclean: clean
	@rm -f $(NAME) libft.a libmlx.a
	@rm -f $(NAME_BONUS) libft.a libmlx.a
	@rm -rf ./mlx
	@echo "${COLOUR_GREEN}The library and all *.o files were successfully removed!${COLOUR_END}\n"

re: fclean all

norm :
	$(NORM_HEADER) $(INCLUDES) $(INCLUDES_BONUS) 
	$(NORM) $(SRC) $(SRC_BONUS) ./libft

.PHONY: clean fclean re bonus

#################
##   CONTENTS  ##
#################

info:	header

define HEADER

.----------------.  .----------------.  .----------------.  .----------------.  .----------------. 
| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |
| |     ______   | || | _____  _____ | || |   ______     | || |    ______    | || |  ________    | |
| |   .' ___  |  | || ||_   _||_   _|| || |  |_   _ \    | || |   / ____ `.  | || | |_   ___ `.  | |
| |  / .'   \_|  | || |  | |    | |  | || |    | |_) |   | || |   `'  __) |  | || |   | |   `. \ | |
| |  | |         | || |  | '    ' |  | || |    |  __'.   | || |   _  |__ '.  | || |   | |    | | | |
| |  \ `.___.'\  | || |   \ `--' /   | || |   _| |__) |  | || |  | \____) |  | || |  _| |___.' / | |
| |   `._____.'  | || |    `.__.'    | || |  |_______/   | || |   \______.'  | || | |________.'  | |
| |              | || |              | || |              | || |              | || |              | |
| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |
 '----------------'  '----------------'  '----------------'  '----------------'  '----------------'

endef
export HEADER

info:	help

info: author

define AUTHOR

						by rkassel && avandeve
endef
export AUTHOR

#################
##   COLORS    ##
#################

COLOUR_GREEN=$'\033[0;32m
COLOUR_RED=$'\033[0;31m
COLOUR_BLUE=$'\033[0;34m
COLOUR_END=$'\033[0m
COLOUR_GREY=$'\033[0;30m
COLOUR_RED=$'\033[0;31m
COLOUR_GREEN=$'\033[0;32m
COLOUR_YELLOW=$'\033[0;33m
COLOUR_PURPLE=$'\033[0;0;35m
COLOUR_CYAN=$'\033[0;36m
COLOUR_WHITE=$'\033[0;37m
