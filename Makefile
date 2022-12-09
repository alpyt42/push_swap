NAME = push_swap

HEADERS = push_swap.h

SOURCES = ft_lstadd_back.c ft_lstadd_front.c \
algo.c ft_lstlast.c algo_bis_100_500_naze.c ft_lstnew.c \
algo_radx.c ft_lstsize.c check_error.c push_function.c \
ft_atoi.c push_swap.c ft_clear_list.c ft_itoa.c

OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I .

all :    $(NAME)

$(NAME) : $(OBJECTS)
	$(AR) rcs $@ $^

%.o : %.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJECTS)

fclean : clean
	$(RM) $(NAME)

re : fclean
	$(MAKE) all

.PHONY: all clean fclean re