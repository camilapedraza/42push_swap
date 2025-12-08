# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/08 17:48:59 by mpedraza          #+#    #+#              #
#    Updated: 2025/12/08 18:03:31 by mpedraza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
CC := cc
CFLAGS := -Wall -Wextra -Werror
CPPFLAGS := -I
SOURCES: push_swap.c
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