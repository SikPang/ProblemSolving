# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/13 19:22:49 by kwsong            #+#    #+#              #
#    Updated: 2023/11/24 21:53:05 by kwsong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = merge_sort

CC = c++
CXXFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

SRCS_FILE = main.cpp \
			merge_sort.cpp
OBJS_FILE = $(SRCS_FILE:.cpp=.o)

SRCS_DIR = ./srcs/

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILE))

all 	: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CXXFLAGS) -o $@ $^

%.o		: %.cpp
	$(CC) $(CXXFLAGS) -o $@ -c $<
	
clean	:
	rm  -rf $(OBJS)

fclean	:
	$(MAKE) clean
	rm -rf $(NAME)

re		:
	$(MAKE) fclean
	$(MAKE) all

nc		:
	nc -c 127.0.0.1 4242

c1		:
	irssi -c 127.0.0.1 -p 4242 -n one -w 1234

c2		:
	irssi -c 127.0.0.1 -p 4242 -n two -w 1234

c3		:
	irssi -c 127.0.0.1 -p 4242 -n three -w 1234

c4		:
	irssi -c 127.0.0.1 -p 4242 -n four -w 1234

c5		:
	irssi -c 127.0.0.1 -p 4242 -n five -w 1234


.PHONY	: all clean fclean re debug nc c1 c2 c3 c4 c5
