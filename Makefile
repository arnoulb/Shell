##
## Makefile for  in /home/arnould_b/Igraph
## 
## Made by jean-michel arnould
## Login   <arnould_b@epitech.net>
## 
## Started on  Mon Dec 21 09:21:05 2015 jean-michel arnould
## Last update Sun Jun  5 15:41:41 2016 Willaime Noah
##

NAME		:=	42sh

CC		:=	gcc
RM		:= 	rm -f

SRC_DIR		:= 	src
OBJ_DIR		:=	obj
INC_DIR		:=	include

#CFLAGS		:=	-Wextra -Wall -Werror -g
#CFLAGS		:=	-g
CFLAGS		+=	-I$(INC_DIR)

LDFLAGS		:=	-Llib/my/ -lmy

SRC		:=	main.c\
			get_next_line.c\
			environ.c\
			errors.c\
			errors2.c\
			setenv.c\
			tools.c\
			tools2.c\
			unsetenv.c\
			parser.c\
			separators.c\
			multipip.c\
			redirection.c\
			redirection2.c\
			my_str_to_wordtab2.c\
			epur_str.c\
			compt.c\
			gest_env.c

SRC		:=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJ		:=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))


$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c
			$(CC) $(CFLAGS) -c -o $@ $<

all:			$(NAME)


$(NAME): 		$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
			$(RM) $(OBJ)
			$(RM) $(SRC_DIR)/*~
			$(RM) $(OBJ_DIR)/*~
			$(RM) $(INC_DIR)/*~
			$(RM) *~
			$(RM) $(SRC_DIR)/*\#
			$(RM) $(OBJ_DIR)/*\#
			$(RM) $(INC_DIR)/*\#
			$(RM) *\#

fclean: 		clean
			$(RM) $(NAME)
			$(RM) $(NAME2)

re:			fclean all

.PHONY: 		all clean fclean re
