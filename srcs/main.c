#include "scop.h"

int     parse_line(char *line, t_obj *obj)
{
    if (line[0] == '#')
        return (0);
    if (line[0] == 'o')
        obj->name = ft_strdup(&line[2]);
    else if (line[0] == 'v')
    {
        //recuperer les vertex ici
    }
    return (0);
}

int     init_scop(char *obj_file, t_obj *obj)
{
    int     fd;
    int     ret;
    char    *line;
    int        i = 0;

    ret = 1;
    line = NULL;
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
    printf("name = [%s]\n", obj->name);
    return (0);
}

int     main(int ac, char **av)
{
    t_obj       obj;
    int         ret = 0;

    if (ac != 2)
        return (0);
    ret = init_scop(av[1], &obj);
    if (ret != 0)
        return (ret);
    return (0);
}