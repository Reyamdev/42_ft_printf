NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =	ft_printf.c \
		ft_putchar_pf.c \
		ft_puthex_pf.c \
		ft_putnbr_pf.c \
		ft_putptr_pf.c \
		ft_putstr_pf.c \
		ft_putunsigned_pf.c

OBJS = $(SRCS:.c=.o)

HEADERS = ft_printf.h

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
