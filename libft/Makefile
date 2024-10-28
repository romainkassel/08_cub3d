# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amelle <amelle@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 15:19:43 by Avandeve          #+#    #+#              #
#    Updated: 2024/07/03 16:01:52 by amelle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################
##  VARIABLES  ##
#################

INCLUDES	= libft.h

FILES		= ft_isalpha.c \
		  ft_isdigit.c \
		  ft_isalnum.c \
		  ft_isascii.c \
		  ft_isprint.c \
		  ft_strlen.c \
		  ft_memset.c \
		  ft_memmove.c \
		  ft_bzero.c \
		  ft_memcpy.c \
		  ft_strlcpy.c \
		  ft_strlcat.c \
		  ft_toupper.c \
		  ft_tolower.c \
		  ft_strchr.c \
		  ft_strrchr.c \
		  ft_strncmp.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_strnstr.c \
		  ft_atoi.c \
		  ft_calloc.c \
		  ft_strdup.c \
		  ft_substr.c \
		  ft_strtrim.c \
		  ft_split.c \
		  ft_itoa.c \
		  ft_strmapi.c \
		  ft_striteri.c \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  ft_lstnew_bonus.c \
		  ft_lstadd_front_bonus.c \
		  ft_lstsize_bonus.c \
		  ft_lstlast_bonus.c \
		  ft_lstadd_back_bonus.c \
		  ft_lstdelone_bonus.c \
		  ft_lstclear_bonus.c \
		  ft_lstiter_bonus.c \
		  ft_lstmap_bonus.c \
		  ft_printf.c \
		  ft_puthex.c \
		  ft_putnbr.c \
		  ft_putptraddress.c \
		  ft_putstr.c \
		  ft_putusnbr.c \
		  ft_putchar.c \

SRCPATH 	= $(DIRPATH)

SRC		= $(addprefix $(SRCPATH), $(FILES))

SRCB		= $(addprefix $(SRCPATH), $(FILESB))

NAME		= libft.a

OBJ		= $(SRC:.c=.o)

OBJB		= $(SRCB:.c=.o)

NORM		= norminette 

NORM_HEADER	= norminette -R CheckDefine 

AR		= @ar rcs

FRANC		= /home/avandeve/francinette/tester.sh

GCL		= git clone 

CFLAGS		= -Wall -Werror -Wextra

CC		= @gcc

#################
##   TARGETS   ##
#################

$(NAME): $(OBJ)
	$(AR) $@ $^ 

all: 	$(NAME)


norm :
	$(NORM_HEADER) $(INCLUDES) && $(NORM) $(FILES) $(FILESB)

clean:
	rm -f $(OBJ) $(OBJB)
	#@echo "${COLOUR_GREEN}All the *.o files were successfully removed!${COLOUR_END}\n"

fclean:
	rm -f $(NAME) $(OBJ) $(OBJB)

	#@echo "${COLOUR_GREEN}The library and all *.o files were successfully removed!${COLOUR_END}\n"
tests:
	$(FRANC)

re: fclean all

#help:
	@echo  "${COLOUR_PURPLE}$$HEADER${COLOUR_END}"
	@echo "${COLOUR_CYAN}			## HELP ##${COLOUR_END}"
	@echo "${COLOUR_GRAY}$$HELP${COLOUR_END}"

.PHONY: all clean fclean re bonus norm help tests
.SILENT: 

#################
##   CONTENTS  ##
#################

info:	header

define HEADER

___  ___              _   _                       _    
|  \/  |             | | | |                     | |   
| .  . |_   _    __ _| |_| |_ ___ _ __ ___  _ __ | |_  
| |\/| | | | |  / _` | __| __/ _ \ '_ ` _ \| '_ \| __| 
| |  | | |_| | | (_| | |_| ||  __/ | | | | | |_) | |_  
\_|  |_/\__, |  \__,_|\__|\__\___|_| |_| |_| .__/ \__| 
         __/ |                             | |         
        |___/                              |_|         
               _     _     _ _      __ _               
              | |   | |   (_) |    / _| |              
          __ _| |_  | |    _| |__ | |_| |_             
         / _` | __| | |   | | '_ \|  _| __|            
        | (_| | |_  | |___| | |_) | | | |_             
         \__,_|\__| \_____/_|_.__/|_|  \__|     

endef
export HEADER

info:	help

define HELP

 Feel free to try the following commands : 
- make bonus : compile the bonus files in the libft.a ;
- make norm : test files' compliance to the Norm ; 
- make tests : test the library against several Libft testers ;
- make clean : clean the *.o files ;
- make fclean : clean the libft.a and all *.o files ;

endef
export HELP

info: author

define AUTHOR

						by avandeve
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
