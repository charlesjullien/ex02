#include <stdlib.h>

int	ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

char *ft_srcpy(char *src, char *dest)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = dest[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int get_next_line(char **line)
{
	int rd = 1;
	int ret = 1;
	char str[10000];
	int i = 0;

	if (!line)
		return (-1);

	while (i < 10000)
	{
		rd = read(0, &str[i], 1);
		if (rd == 0)
		{
			ret = 0;
			break ;
		}
		else if (str[i] == '\n')
			break ;
		else if (rd < 0)
			return (-1);
		i++;
	}
	str[i] = '\0';
	if (!(*line = malloc(sizeof(char) * ft_strlen(str))))
		return (-1);
	*line = ft_strcpy(str, *line);
	return (ret);
}
