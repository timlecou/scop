#include "scop.h"

/**
 * function that initialises the object structure.
 * 
 * @obj: the object structure.
 */
void    init_obj(t_obj *obj)
{
    obj->name = NULL;
    if (!(obj->vertexes = malloc(sizeof(t_vertex))))
        error_fatal();
    obj->vertexes = NULL;
    if (!(obj->faces = malloc(sizeof(t_face))))
        error_fatal();
    obj->faces = NULL;
}

/**
 * Function the initialises the program, parses the *.obj file
 * 
 * @obj_file : *.obj file name
 * @obj : structure that contains informations about the object
 * @return : 0 if success, 1 if failure
 */
int     init_scop(char *obj_file, t_obj *obj)
{
    int     fd;
    int     ret;
    char    *line;
    int     i = 0;

    ret = 1;
    line = NULL;
    init_obj(obj);
    fd = open(obj_file, O_RDONLY);
    if (fd < 1)
        return (1);
    while (ret == 1)
    {
        ret = get_next_line(fd, &line);
        i = parse_line(line, obj);
        if (i == -1)
            return (1);
        free(line);
    }
    print_vertex_list(obj->vertexes);
    print_face_list(obj->faces);
    return (0);
}

void    launch_rendering(void)
{
    write(1, "OK1\n", 4);
    glBegin(GL_POINTS);
    write(1, "OK2\n", 4);
    glEnd();
}

/**
 * main function
 * 
 * Launches the program.
 */
int     main(int ac, char **av)
{
    t_obj       obj;
    t_mlx       mlx;
    int         ret = 0;

    if (ac != 2)
        return (0);
    ret = init_scop(av[1], &obj);
    if (ret != 0)
        return (ret);

    mlx.mlx = mlx_init();
    mlx.mlx_win = mlx_new_window(mlx.mlx, 300, 200, "42 Scop");

    //mlx_loop(mlx.mlx);

    // launch_rendering();
    // while (1);
    return (0);
}