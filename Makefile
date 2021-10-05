SRCS = srcs/main.c srcs/get_next_line.c srcs/list.c srcs/data_parsing.c\
		srcs/error_handling.c

NAME = scop

FLAGS = -Werror -Wextra -Wall #-g3 -fsanitize=address

INCLUDES = includes

LIB = mlx

FRAMEWORK = -framework OpenGL -framework AppKit

COMPIL = gcc

all:
	make -C libft all
	$(COMPIL) $(FLAGS) libft/libft.a -I $(INCLUDES) $(SRCS) -L $(LIB) -lmlx $(FRAMEWORK) -o $(NAME)

$(NAME): all

clean:
	make -C libft clean

fclean:
	/bin/rm $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re scop