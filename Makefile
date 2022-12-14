NAME = push_swap

HEADERS = push_swap.h

SOURCES = ft_lstadd_back.c ft_lstadd_front.c algo.c ft_lstlast.c ft_lstnew.c \
		algo_radx.c ft_lstsize.c push_function.c ft_atoi.c push_swap.c ft_clear_list.c ft_itoa.c \
		ft_bzero.c parsing.c main.c ft_strjoin.c ft_split.c ft_calloc.c \

OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I .

all :    $(NAME)

$(NAME) : $(OBJECTS)
	${CC} ${CFLAG} -o $@ $^

%.o : %.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJECTS)

fclean : clean
	$(RM) $(NAME)

re : fclean
	$(MAKE) all

.PHONY: all clean fclean re