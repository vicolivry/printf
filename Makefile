# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/01/22 17:16:45 by volivry      #+#   ##    ##    #+#        #
#    Updated: 2018/02/05 18:50:23 by volivry     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc
NAME = libftprintf.a
SRC = ft_printf.c ft_parse.c ft_format.c ft_modify.c type_c.c type_di.c\
	  type_oub.c type_s.c type_x.c sized.c type_p.c type_ws.c lenfinder.c
OBJECTS = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) -I. -o $@ -c $<

$(NAME): $(OBJECTS)
	@echo "Generation de libftprintf.a"
	@make -C ./libft/
	@cp ./libft/libft.a ./$(NAME)
	@ar rcs $(NAME) $(OBJECTS)

clean:
	@echo "CLEANING"
	@make clean -C ./libft/
	@rm -f $(OBJECTS)

fclean: clean
	@echo "SUPER CLEANING"
	@make fclean -C ./libft/
	@rm -f $(NAME)

re: fclean all
