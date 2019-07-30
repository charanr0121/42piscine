# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chramach <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/29 10:44:17 by chramach          #+#    #+#              #
#    Updated: 2019/07/29 15:46:23 by chramach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=bsq

SRCS=srcs/*.c

INCLUDES=-I includes/

FLAGS=-W -Werror -Wextra -Wall -g

all: comp

comp:
	gcc $(FLAGS) $(INCLUDES) $(SRCS) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	rm -rf $(NAME).dSYM

re: fclean all
