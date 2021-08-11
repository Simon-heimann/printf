SRC		:=	ft_printf.c cspdi.c uxX%.c put.c tag.c ft_int_to_hex.c

OBJS    :=	$(SRC:.c=.o)

NAME	:=	libftprintf.a
RLIB    :=	ranlib
CC		:=	clang
LIB		:=	ar rcs

CFLAGS	=	-Wall -Wextra -Werror
LFLAGS	=	-I.
RM		:=	rm -rf

LIBFT	:=	libft
LIBFT_L :=	libft/libft.a

all:		libft $(NAME)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $@ $(LFLAGS)/$(LIBFT)

$(NAME):	$(OBJS)
			cp ./libft/libft.a $(NAME)
			$(LIB) $(NAME) $(OBJS)
			$(RLIB) $(NAME)

clean:
			$(MAKE) -C $(LIBFT) clean
			$(RM) $(OBJS)

fclean: 	clean
			$(MAKE) -C $(LIBFT) fclean
			$(RM) $(NAME)

libft:
			$(MAKE) -C $(LIBFT)
test:
			@(printf "Enter flag: "; read arg; cd sant/ && sh test $$arg; cd ../tripp/ && make $$arg)
			@($(MAKE) fclean)
comp:
			gcc -Wall -Wextra -Werror *.c libft/*.c;
re: 		@(fclean all)

.PHONY: 	all clean fclean re libft
