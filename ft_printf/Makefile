# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/01/09 12:06:53 by volivry      #+#   ##    ##    #+#        #
#    Updated: 2018/01/09 12:13:32 by volivry     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = ft_printf

OBJS = ft_format.o ft_parse.o ft_printf.o

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L libft/ -lft

./%.o: ./%.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJS)
	make -C ./libft clean

fclean: clean
	make -C ./libft fclean
	rm -rf $(NAME)
	rm -rf $(OBJS)

re: fclean all

.PHONY: all clean fclean re
