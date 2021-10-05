#include "scop.h"

/**
 * LIST FILE
 * 
 * file that contains all of the list handling functions.
 */

/**
 * function that pushes a new element in the back of a t_vertex list.
 * 
 * @vertex : the list.
 * @new : the new element.
 */
void    vertex_list_push_back(t_vertex **vertex, t_vertex *new)
{
    t_vertex   *tmp;

    if (*vertex == NULL)
    {
        *vertex = new;
        return ;
    }
    if (vertex && *vertex && new)
    {
        tmp = *vertex;
        new->index++;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
            new->index++;
        }
        tmp->next = new;
    }
}

/**
 * function that pushes a new element in the back of a t_face list.
 * 
 * @faces : the list.
 * @new : the new element.
 */
void    face_list_push_back(t_face **faces, t_face *new)
{
    t_face   *tmp;

    if (*faces == NULL)
    {
        *faces = new;
        return ;
    }
    if (faces && *faces && new)
    {
        tmp = *faces;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new;
    }
}

/**
 * function that prints every element of a t_vertex list
 * 
 * @list : the list which we print the elements.
 */
void    print_vertex_list(t_vertex *list)
{
    t_vertex   *tmp = list;

    while (tmp != NULL)
    {
        printf("index = [%d] ", tmp->index);
        printf("x = [%f] ", tmp->x);
        printf("y = [%f] ", tmp->y);
        printf("z = [%f]\n", tmp->z);
        tmp = tmp->next;
    }
}

/**
 * function that prints every element of a t_face list
 * 
 * @list : the list which we print the elements.
 */
void    print_face_list(t_face *list)
{
    t_face          *tmp = list;
    unsigned int    i;

    while (tmp != NULL)
    {
        i = 0;
        while (i < tmp->number)
        {
            printf("[%d] ", tmp->indices[i]);
            i++;
        }
        printf("\n");
        tmp = tmp->next;
    }
}