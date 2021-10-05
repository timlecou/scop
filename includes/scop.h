#ifndef SCOP_H
# define SCOP_H
# define BUFFER_SIZE    32
# define SUCCESS_CODE 1
# define EOF_CODE 0
# define ERROR_CODE -1
# define GL_SILENCE_DEPRECATION
# define GLFW_DLL
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <OpenGL/gl.h>
# include <OpenGL/glu.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

//DATA STRUCTURES AND LISTS
typedef struct          s_vertex
{
    unsigned int        index;
    float               x;
    float               y;
    float               z;
    float               w;
    struct s_vertex    *next;
}                       t_vertex;

typedef struct          s_face
{
    int                 *indices;
    unsigned int        number;
    struct  s_face      *next;
}                       t_face;

typedef struct          s_mlx
{
    void                *mlx;
    void                *mlx_win;
    void                *img;
}                       t_mlx;


typedef struct          s_obj
{
    char                *name;
    t_vertex            *vertexes;
    t_face              *faces;
}                       t_obj;

//GNL_C
char			*ft_strnew(int size);
int				get_next_line(int fd, char **line);
char			*ft_strncat(char *dest, char *src, unsigned int nb);
int				contains_char(char *s, char c);
int				free_string_and_return(char **str, int return_value);

//LIST_C
void            face_list_push_back(t_face **faces, t_face *new);
void            vertex_list_push_back(t_vertex **vertex, t_vertex *new);
void            print_vertex_list(t_vertex *list);
void            print_face_list(t_face *list);

//DATA_PARSING_C
int             parse_line(char *line, t_obj *obj);
void            get_face(t_face **faces, char *line);
void            get_vertex(t_obj *obj, char *line);

//ERROR_HANDLING_C
void            error_fatal(void);

#endif