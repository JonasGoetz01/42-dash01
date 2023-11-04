# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 19:14:44 by lzipp             #+#    #+#              #
#    Updated: 2023/10/13 13:34:57 by lzipp            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wextra -Wall -Werror

SOURCES = ft_atoi.c\
ft_bzero.c\
ft_calloc.c\
ft_isalnum.c\
ft_isalpha.c\
ft_isascii.c\
ft_isdigit.c\
ft_isprint.c\
ft_itoa.c\
ft_memchr.c\
ft_memcmp.c\
ft_memcpy.c\
ft_memmove.c\
ft_memset.c\
ft_putchar_fd.c\
ft_putendl_fd.c\
ft_putnbr_fd.c\
ft_putstr_fd.c\
ft_split.c\
ft_strchr.c\
ft_strdup.c\
ft_striteri.c\
ft_strjoin.c\
ft_strlcat.c\
ft_strlcpy.c\
ft_strlen.c\
ft_strmapi.c\
ft_strncmp.c\
ft_strrchr.c\
ft_strnstr.c\
ft_strtrim.c\
ft_substr.c\
ft_tolower.c\
ft_toupper.c\

OBJECTS = $(SOURCES:.c=.o)

INCLUDES = libft.h

BONUS_SOURCES = ft_lstadd_back_bonus.c\
ft_lstadd_front_bonus.c\
ft_lstclear_bonus.c\
ft_lstdelone_bonus.c\
ft_lstiter_bonus.c\
ft_lstlast_bonus.c\
ft_lstmap_bonus.c\
ft_lstsize_bonus.c\
ft_lstnew_bonus.c\

BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rc $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS) $(BONUS_OBJECTS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re

bonus: $(BONUS_OBJECTS) $(OBJECTS)
	ar -rc $(NAME) $(OBJECTS) $(BONUS_OBJECTS)
