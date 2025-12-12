# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/08 17:48:59 by mpedraza          #+#    #+#              #
#    Updated: 2025/12/12 18:01:52 by mpedraza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
CC := cc
CFLAGS := -Wall -Wextra -Werror
CPPFLAGS := -I .
SOURCES := 	push_swap.c ps_alloc_utils.c ps_parse_utils.c ps_stack_utils.c \
			ps_string_utils.c ps_check_utils.c
HEADERS := push_swap.h
OBJECTS := $(SOURCES:%.c=%.o)
TEST_SOURCES := test_push_swap.c
TEST_OBJECTS := $(TEST_SOURCES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)

$(OBJECTS): $(SOURCES)

clean: 
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: all $(TEST_OBJECTS)

.PHONY: all clean fclean re test