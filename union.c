#include <unistd.h>

int		check_char(char *s, char c, int index)
{
	int i = 0;

	while (i < index)
	{
		if (s[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void	ft_union(char *s1, char *s2)
{
	int i = 0;
	int j = 0;

	while (s1[i])
	{
		if (check_char(s1, s1[i], i) == 1)
			write(1, &s1[i], 1);
		i++;
	}
	while (s2[j])
	{
		if (check_char(s1, s2[j], i) == 1 && check_char(s2, s2[j], j) == 1)
			write(1, &s2[j], 1);
		j++;
	}
	write(1, "\n", 1);
}

int main(int ac, char **av)
{
	if (ac != 3)
	{
		write (1, "\n", 1);
		return (0);
	}

	ft_union(av[1], av[2]);
	return (0);
}
