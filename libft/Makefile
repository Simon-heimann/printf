NAME = libft.a

HEADERS = libft.h

SRC = ft_itoa.c \
ft_memcpy.c \
ft_putchar.c \
ft_strchr.c \
ft_strdup.c \
ft_strjoin.c \
ft_strlen.c \
ft_strupper.c \
ft_substr.c \
ft_utoa.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $^
	ranlib $(NAME)
bonus: $(NAME)

$(OBJ):
	gcc -Wall -Wextra -Werror -c $(SRC)

clean:
	@rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY:	all clean fclean re bonus