#include "get_next_line.h"

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int get_next_line(char **line)
{
	int i = 0;
	int rd = 1;
	int ret = 1;
	char str[200000];

	if (!line)
		return (-1);
	while (i < 200000)
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
	*line = ft_strcpy(*line, str);
	return (ret);
}


