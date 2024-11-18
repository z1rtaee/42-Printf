NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_strlen.c
OBJS = $(SRCS:.c=.o)
AR = ar -rcs
LIBFT_DIR = ./LIBFT
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_OBJS = libft/*.o

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $(<) -o $(@)

$(NAME): $(LIBFT) $(OBJS)
	@$(AR) $(NAME) $(OBJS) $(LIBFT_OBJS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) --no-print-directory

all: $(NAME)


clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

comp: fclean all
	@$(CC) $(CFLAGS) test.c $(NAME) 

run: comp
	@./a.out
	@make fclean --no-print-directory
	@rm -f a.out

.PHONY: all clean fclean re comp run