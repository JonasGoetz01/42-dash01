# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 08:04:13 by lzipp             #+#    #+#              #
#    Updated: 2023/10/17 12:33:20 by lzipp            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wextra -Wall -Werror

SOURCES = ft_printf.c\
ft_putchars_int.c\
ft_putnbrs_int.c\
ft_puthexes_int.c

OBJECTS = $(SOURCES:.c=.o)

LIBFTSOURCES = ft_atoi.c\
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
ft_lstadd_back_bonus.c\
ft_lstadd_front_bonus.c\
ft_lstclear_bonus.c\
ft_lstdelone_bonus.c\
ft_lstiter_bonus.c\
ft_lstlast_bonus.c\
ft_lstmap_bonus.c\
ft_lstsize_bonus.c\
ft_lstnew_bonus.c\

LIBFTOBJECTS = $(addprefix $(LIBFTDIR)/, $(LIBFTSOURCES:.c=.o))


INCLUDES = ft_printf.h

LIBFTDIR = ./libft

LIBFT = $(LIBFTDIR)/libft.a

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar -rc $(NAME) $(OBJECTS)
	ranlib $(NAME)
	chmod +x $(NAME)

$(LIBFT):
	make -C $(LIBFTDIR)
	cp $(LIBFT) $(NAME)

clean:
	rm -f $(OBJECTS)
	rm -f $(LIBFTOBJECTS)

	
fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re
