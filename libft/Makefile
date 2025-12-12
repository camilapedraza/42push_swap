# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/08 17:45:39 by mpedraza          #+#    #+#              #
#    Updated: 2025/12/12 14:25:38 by mpedraza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
CC := cc
CFLAGS := -Wall -Wextra -Werror
CPPFLAGS := -I .
CPP_LIB_FLAGS := -L . -l:$(NAME) 
FTS := ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_strlen \
	   ft_strlcpy ft_strlcat ft_strncmp ft_strchr ft_strrchr ft_strnstr \
	   ft_atoi ft_toupper ft_tolower ft_memset ft_bzero ft_memcpy ft_memmove \
	   ft_memchr ft_memcmp ft_calloc ft_strdup ft_substr ft_strjoin ft_strtrim \
	   ft_split ft_itoa ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd \
	   ft_putendl_fd ft_putnbr_fd
SRCS := $(FTS:%=%.c)
OBJS := $(SRCS:%.c=%.o)
BONUS := ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back \
		 ft_lstdelone ft_lstclear ft_lstiter ft_lstmap
BONUS_SRCS := $(BONUS:%=%_bonus.c)
BONUS_OBJS := $(BONUS_SRCS:%.c=%.o)
ALL_SRCS := $(SRCS) $(BONUS_SRCS)
ALL_OBJS := $(OBJS) $(BONUS_OBJS)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

bonus: $(ALL_OBJS)
	ar rcs $(NAME) $^

clean:
	$(RM) $(ALL_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
