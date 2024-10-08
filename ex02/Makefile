# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/26 12:41:17 by nsouchal          #+#    #+#              #
#    Updated: 2024/10/08 13:51:37 by nsouchal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = PmergeMe

SRC_FILE =	main.cpp \
			PmergeMe.cpp \
			PmergeMe_deque.cpp

DIR_BUILD		=	.build/
DIR_SRCS 		= 	srcs/
DIR_HEADERS		=	includes/

HEADERFILES =	$(DIR_HEADERS)PmergeMe.hpp

OBJS			=	$(patsubst %.cpp, $(DIR_BUILD)%.o, $(SRCS))
SRCS			=	$(addprefix $(DIR_SRCS),$(SRC_FILE))

FLAGS		=	-Wall -Werror -Wextra -g3 -std=c++98

CC = c++

.PHONY: all
all: $(NAME)

$(NAME): $(HEADERFILES) $(OBJS)
			$(CC) $(OBJS) -o $(NAME)

$(DIR_BUILD)%.o: %.cpp $(HEADERFILES) Makefile
				mkdir -p $(shell dirname $@)
				$(CC) $(FLAGS) -c $< -o $@ -Iincludes

.PHONY: clean
clean:
	rm -rf $(DIR_BUILD)

.PHONY: fclean
fclean: clean
		rm -rf $(NAME)

.PHONY: re
re: fclean
	$(MAKE) all
