NAME = test

CC = cc

CFLAGS = -Wextra -Wall -Werror

SOURCES = test_parsing.c\
../src/parsing.c \
../libs/printf/libft/ft_calloc.c \
../libs/printf/libft/ft_split.c \
../libs/printf/libft/ft_strdup.c \
../libs/printf/libft/ft_strjoin.c \
../libs/printf/libft/ft_strlen.c \
../libs/printf/libft/ft_bzero.c \
../libs/printf/libft/ft_substr.c \
../libs/get_next_line/get_next_line.c

OBJECTS = $(SOURCES:.c=.o)

INCLUDES = ../includes/parsing.h

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re