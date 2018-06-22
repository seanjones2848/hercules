#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "/home/grawr/42_git/GNL/libft/libft.h"

char	*name(int i)
{
	char	*ret;

	ret = strcat(ft_itoa(i), ".poop");
	return (ret);
}

void	podargos()
{
	int	i;
	FILE	*fd;

	i = 0;
	while (1)
	{
		fd = fopen(name(i++), "w");
		fclose(fd);
		fd = NULL;
	}
}

void	lampon()
{
	while (1)
	{
		write(1, "neigh, I'm a horse named lampon\n", 32);
	}
}

void	xanthos()
{
	while (1)
	{
		write(1, "neigh, I'm a horse named xanthos\n", 33);
	}
}

void	deinos()
{
	while (1)
	{
		write(1, "neigh, I'm a horse named deinos\n", 32);
	}
}

void	wild()
{
	if (fork() == 0)
	{
		if (fork() == 0)
			podargos();
		else
			lampon();
	}
	else
	{
		if (fork() == 0)
			xanthos();
		else
			deinos();
	}
}

void	tame()
{
	int	max_horses;
	int	i;

	max_horses = 2;
	i = 0;
	while (i < max_horses)
	{
		fork();
		i++;
	}
	write(1, "I'm a grazing horse.\n", 21);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (-1);
	if (*av[1] == '0')
		tame();
	else
		wild();
	return (0);
}	
