#include <stdio.h>

int	main(int ac, char **av)
{
	char	*line;
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return(printf("open failed"), 1);
	if (ac != 2)
		return (printf("wrong argument"), 1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line || !line[0])
			break;
		printf ("line : %s", line);
	}
	return (printf("eof"), 0);
}
