# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/08 17:48:59 by mpedraza          #+#    #+#              #
#    Updated: 2025/12/20 18:10:05 by mpedraza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
CC := cc
CFLAGS := -Wall -Wextra -Werror
CPPFLAGS := -I .
SOURCES := 	push_swap.c \
			ps_build_stack.c \
			ps_calculate_moves.c \
			ps_execute_rotations.c \
			ps_find_nodes.c \
			ps_instructions.c \
			ps_parse_input.c \
			utils_alloc.c \
			utils_checkers.c \
			utils_stack.c \
			utils_string.c
HEADERS := push_swap.h
OBJECTS := $(SOURCES:%.c=%.o)
TEST_SOURCES := test_push_swap.c
TEST_OBJECTS := $(TEST_SOURCES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJECTS)

clean: 
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: all $(TEST_OBJECTS)

.PHONY: all clean fclean re test