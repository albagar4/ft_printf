# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/13 18:34:20 by albagar4          #+#    #+#              #
#    Updated: 2023/06/16 18:07:54 by albagar4         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf

SOURCE = ft_printf.c ft_print_char.c ft_print_str.c

OBJS = $(SOURCE:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: libft $(NAME)

 $(NAME):  $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft/libft.a 

 $(OBJS):
	$(CC) $(CFLAGS) -c $(SOURCE)

libft:
	make -C libft/ all

clean:
	$(RM) $(OBJS) 
	make -C libft/ clean

fclean: clean
	$(RM) $(NAME)
	make -C libft/ fclean

re: fclean all

.PHONY: all libft clean fclean re