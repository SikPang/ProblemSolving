# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/26 20:51:01 by kwsong            #+#    #+#              #
#    Updated: 2023/11/29 13:00:39 by kwsong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = heapSort

CC = c++
CXXFLAGS = -Wall -Wextra -Werror -fsanitize=address

SRCS = main.cpp \
	HeapSort.cpp
OBJS = $(SRCS:.cpp=.o)

TESTER = ../sortTester.sh

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

test	:
	@$(TESTER) ./$(NAME)

.PHONY	: all clean fclean re
