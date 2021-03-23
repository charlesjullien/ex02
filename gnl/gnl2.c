#include <stdlib.h>

int		get_next_line(char **line)
{
	int i = 0;
	int	ret = 0;
	int buf = 0;

	*line = malloc(200000);
	if (!line)
		return (-1);
	while (ret = read(0, (char *)&buf, 1) = 1 && buf != '\n')
		(*line)[i++] = buf;
	(*line)[i] = '\0';
	return (ret);
}
