INC=/usr/include

INCLIB=$(INC)/../lib

CC= clang++

CFLAGS= -I$(INC) -Iincludes -Imlx_linux -g -Werror -Wextra -Wall

NAME= scop

SRC = srcs/main.cpp srcs/Mlx.cpp

OBJ = $(SRC:%.cpp=%.o)

LFLAGS = -Lmlx_linux -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd

%.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

all: $(NAME)

$(NAME): mlx $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LFLAGS)

mlx:
	cd mlx_linux ; ./configure ; cd ..

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
