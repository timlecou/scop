#include "scop.h"

static int	join_line(int fd, char **string)
{
	int		r;
	char	*s;
	char	*buffer;

	if (!(buffer = ft_strnew(BUFFER_SIZE + 1)))
		return (ERROR_CODE);
	if ((r = read(fd, buffer, BUFFER_SIZE)) <= 0)
	{
		free(buffer);
		return (r);
	}
	buffer[r] = '\0';
	if (!(s = ft_strnew(ft_strlen(*string) + (r + 1))))
		return (ERROR_CODE);
	if (*string)
	{
		s = ft_strncat(s, *string, ft_strlen(*string));
		free(*string);
	}
	*string = ft_strncat(s, buffer, r);
	free(buffer);
	if (!contains_char(*string, '\n'))
		return (join_line(fd, string));
	return (SUCCESS_CODE);
}

static int	get_only_string(char **line, char **string, int *index, int *index2)
{
	char	*tmp;
	char	*s2;
	char	*s;

	while ((*string)[*index] && (*string)[*index] != '\n')
		(*index) += -(*index - (*index + 1));
	if (!(s = ft_strnew(*index + 1)))
		return (ERROR_CODE);
	*line = ft_strncat(s, *string, *index);
	*index2 = ft_strlen(*string) - *index;
	if (!(*index2))
		return (free_string_and_return(string, EOF_CODE));
	if ((s2 = ft_strnew(*index2)))
	{
		tmp = ft_strncat(s2, *string + *index + 1, *index2 - 1);
		free(*string);
		*string = tmp;
		return (SUCCESS_CODE);
	}
	return (free_string_and_return(string, ERROR_CODE));
}

static int	get_line_from_str(char **string, char **line)
{
	int	index;
	int	index2;
	int	r;

	index = 0;
	index2 = 0;
	r = 0;
	if ((r = get_only_string(line, string, &index, &index2)) != 1)
		return (free_string_and_return(string, 0));
	return (SUCCESS_CODE);
}

int			get_next_line(int fd, char **line)
{
	static char	*string = NULL;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (ERROR_CODE);
	if (!contains_char(string, '\n'))
	{
		if (join_line(fd, &string) == ERROR_CODE)
			return (free_string_and_return(&string, ERROR_CODE));
		if (!string)
		{
			*line = ft_strnew(1);
			return (EOF_CODE);
		}
	}
	return (get_line_from_str(&string, line));
}

int		contains_char(char *s, char c)
{
	int	index;

	index = 0;
	if (!s)
		return (0);
	while (s[index])
	{
		if (s[index] == c)
			return (SUCCESS_CODE);
		index++;
	}
	return (0);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	len;
	unsigned int	index;

	index = 0;
	len = ft_strlen(dest);
	while (src[index] && index < nb)
		dest[len++] = src[index++];
	dest[len] = 0;
	return (dest);
}

char	*ft_strnew(int n)
{
	char	*string;
	int		index;

	if (!(string = (char *)malloc(n)))
		return (NULL);
	index = 0;
	while (index < n)
		string[index++] = 0;
	return (string);
}

int		free_string_and_return(char **string, int val)
{
	if (*string)
		free(*string);
	*string = NULL;
	return (val);
}