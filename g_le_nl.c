#include <stdlib.h>
#include <unistd.h>

int get_next_line(char **line)
{
	int i = 0;
	int buf = 0;
	int ret = 1; //declarer i, buf et ret à 0.
	
	*line = malloc(200000); //malloc *line à 200000.

	while ((ret = read(0, (char *)&buf, 1)) == 1 && buf != '\n') //tant que ret = 1 && buf != '\n'. caster &buf en char * et avant mettre 0 puis 1 ensuite. (fd, nb octet lu.
		(*line)[i++] = buf; //on increment i ici.

	(*line)[i] = '\0'; //on met bien un \0 à la fin de (*line) ... à [i].

	return (ret); //on renvoie ret.
}
