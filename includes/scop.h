#ifndef SCOP_H
# define SCOP_H
# define BUFFER_SIZE    32
# define SUCCESS_CODE 1
# define EOF_CODE 0
# define ERROR_CODE -1
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct  s_obj
{
    char        *name;
    float       *vertex[3];
}               t_obj;

char			*ft_strnew(int size);
int				get_next_line(int fd, char **line);
char			*ft_strncat(char *dest, char *src, unsigned int nb);
int				contains_char(char *s, char c);
int				free_string_and_return(char **str, int return_value);

#endif