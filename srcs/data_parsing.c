#include "scop.h"

/**
 * Function that finds the first ' ' character in a string and returns its index
 * 
 * @line : the string which is used.
 * @return : the index of the first ' ' character.
 */
int  find_space_char(char *line)
{
    int  i = 1;

    while (line[i] != '\0')
    {
        if (line[i] == ' ')
            return (i);
        i++;
    }
    return (-1);
}

/**
 * Function that get the vertex values in the *.obj file.
 * 
 * @obj : the object structure.
 * @line : a line of the *.obj file.
 */
void    get_vertex(t_obj *obj, char *line)
{
    t_vertex        *new;
    int             space = 2;

    if (!(new = malloc(sizeof(t_vertex))))
        error_fatal();

    new->next = NULL;
    new->x = 0;
    new->y = 0;
    new->z = 0;
    new->w = 1;
    new->index = 1;

    new->x = atof(&line[space]);
    space += find_space_char(&line[space]);

    new->y = atof(&line[space]);
    space += find_space_char(&line[space]);

    new->z = atof(&line[space]);

    vertex_list_push_back(&obj->vertexes, new);
}

/**
 * Function that get the face values in the *.obj file.
 * 
 * @faces : the faces structure.
 * @line : a line of the *.obj file.
 */
void    get_face(t_face **faces, char *line)
{
    t_face          *new_face;
    char            **s_values = NULL;
    int             i = 1;
    int             value_number = 0;

    if (!(new_face = malloc(sizeof(t_face))))
        error_fatal();
    new_face->next = NULL;

    s_values = ft_split(line, ' ');

    while (s_values[value_number])
        value_number++;

    if (!(new_face->indices = malloc(sizeof(int) * (value_number))))
        error_fatal();
    while (s_values[i])
    {
        new_face->indices[i - 1] = ft_atoi(s_values[i]);
        free(s_values[i]);
        i++;
    }
    free(s_values[0]);
    free(s_values);
    new_face->number = i - 1;

    face_list_push_back(faces, new_face);
}

/**
 * function that manage the parsing of the *.obj file lines.
 * 
 * @line : the *.obj file line.
 * @obj : the object structure.
 * @return: 0 if success, 1 otherwise.
 */
int     parse_line(char *line, t_obj *obj)
{
    if (line[0] == '#')
        return (0);
    // if (line[0] == 'o')
    //     obj->name = &line[2];
    else if (line[0] == 'v')
        get_vertex(obj, line);
    else if (line[0] == 'f')
    {
        get_face(&obj->faces, line);
    }
    return (0);
}