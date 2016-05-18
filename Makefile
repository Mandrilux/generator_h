##
## Makefile for  in /home/baptiste/rendu/CPE_colle_semaine3
## 
## Made by 
## Login   <baptiste@epitech.net>
## 
## Started on  Wed May 11 17:39:05 2016 
## Last update Wed May 18 11:03:50 2016 
##


NAME	=	gen

SRC	=	main.c \
		space.c \
		init.c \
		read.c \
		get_line.c \
		check.c \
		str.c \
		strtoword.c \
		write.c \
		doublon.c \
		free.c

INC_DIR	=	include

OBJ	=	$(SRC:.c=.o)

CC	=	/usr/bin/gcc

CFLAGS	=	-W -Wall -Wextra -ansi -pedantic
CFLAGS  +=      -I$(INC_DIR)

RM	=	rm -f
ECHO	=	echo -e

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)
		@$(ECHO) '\033[0;32m> gen Compiled\033[0m'

clean	:
		-@$(RM) $(OBJ)
		-@$(RM) *~
		-@$(RM) \#*#
		@$(ECHO) '\033[0;31m> Directory cleaned\033[0m'


fclean	:	clean
		-@$(RM) $(NAME)
		@$(ECHO) '\033[0;31m> Remove executable\033[0m'

re	:	fclean all

.PHONY	:	all clean fclean re
