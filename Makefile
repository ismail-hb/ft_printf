NAME = libftprintf.a

SRC = ftprintf.c ftprintf2.c

#SRC_BONUS =

OBJ = $(SRC:.c=.o)
#OBJ_BONUS = $(SRC_BONUS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -I.

all: $(NAME)

$(NAME): $(OBJ) ft_printf.h libft/libft.a
	ar rcs $(NAME) $(OBJ)

libft/libft.a :
	cd libft; make bonus; mv libft.a ../libftprintf.a
#bonus:
#	$(MAKE) $(NAME) SRC="$(SRC) $(SRC_BONUS)"

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	cd libft; make clean
#	$(RM) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)
	cd libft; make fclean

re: fclean all

.PHONY: all clean fclean re bonus
