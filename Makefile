# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 15:47:38 by aakouhar          #+#    #+#              #
#    Updated: 2024/02/23 15:54:00 by aakouhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
CFILE = client.c minitalk_utils.c server.c
OFILE = $(CFILE:.c=.o)

all : $(NAME)

$(NAME) : $(OFILE)
	ar rc $(NAME) $(OFILE)
	
clean :
	rm -rf $(OFILE)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re