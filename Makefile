NAME = libftprintf.a

SRC = ft_printf.c \
converters.c \
cspdi.c \
uxX%.c

OBJS    =	$(SRC:.c=.o)

all:		libft $(NAME)

%.o : %.c
			clang -Wall -Wextra -Werror -c $< -o $@ -I/libft

$(NAME):	$(OBJS)
			cp ./libft/libft.a $(NAME)
			ar rcs $(NAME) $(OBJS)
			ranlib $(NAME)

clean:
			$(MAKE) -C libft clean
			rm -rf $(OBJS)

fclean: 	clean
			$(MAKE) -C libft fclean
			$(RM) $(NAME)

libft:
			$(MAKE) -C libft

re: 		@(fclean all)

.PHONY: 	all clean fclean re libft