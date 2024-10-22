
NAME = push_swap

RES = *.c

LIBS = *.h

OBJ = $(RES:.c=.o)

FLAGS = -Werror -Wextra -Wall

$(NAME) : 
	gcc $(FLAGS) $(RES) $(LIBS)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

g : fclean
	gcc -g $(FLAGS) $(RES) $(LIBS)

all : $(NAME)

re : fclean all
