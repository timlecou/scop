INC=/usr/include

INCLIB=$(INC)/../lib

CC=clang++

CFLAGS= -I$(INC) -Iincludes -Werror -Wextra -Wall

NAME= scop

SRC = srcs/main.cpp \
		srcs/Mlx.cpp

OBJ = $(SRC:%.cpp=%.o)

LFLAGS = -Lmlx_linux -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd

all: $(NAME)

$(NAME): minilib $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LFLAGS)

minilib:
		cd mlx_linux ; ./configure ; cd ..

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean all
