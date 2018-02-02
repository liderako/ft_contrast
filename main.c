/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 20:03:39 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/02 20:03:42 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

/* input parameters validation */

int		ft_check_nb(char *nb)
{
	int i;

	i = ft_atoi(nb);
	if (0 <= i && i <= 100)
		return (1);
	return (-1);
}

int		ft_check_filename(char *filename)
{
	int		i;
	char	*str;

	i = 0;
	while (filename[i] != '\0' && filename[i] != '.')
		i++;
	str = ft_strsub(filename, i, ft_strlen(filename));
	if (filename[i] && i && !(ft_strcmp(str, ".pgm")))
	{
		free(str);
		return (1);
	}
	return (-1);
}

int		ft_check_args(int argc, char **av)
{
	if (argc == 7 && ft_strcmp(av[0], "./ft_contrast") == 0 &&
		ft_strcmp(av[1], "-f") == 0 && ft_check_filename(av[2]) == 1 &&
		ft_strcmp(av[3], "-c") == 0 && ft_check_nb(av[4]) == 1 &&
		ft_strcmp(av[5], "-o") == 0 && ft_check_filename(av[6]) == 1)
		return (1);
	return (-1);
}

int 	input_param(int argc, char **argv)
{
	if (ft_check_args(argc, argv) != 1)
	{
		printf("%s%s%s%s%s", "usage: ", argv[0], " -f source_file -c x -o ",
			"new_file\nsource_file and new_file must have .pgm ",
			"expansion\n0 <= x <= 100\n");
		return (-1);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	if (input_param(argc, argv) == 1)
	{
		// code
	}
	return (0);
}
