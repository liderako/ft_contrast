/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 20:03:39 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/03 10:50:16 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

// void	ft_putnbr_fd(int n, int fd)
// {
// 	unsigned int	new;

// 	if (n < 0)
// 	{
// 		new = -n;
// 		ft_putchar_fd('-', fd);
// 	}
// 	else
// 		new = n;
// 	if (new >= 10)
// 	{
// 		ft_putnbr_fd(new / 10, fd);
// 		ft_putchar_fd(new % 10 + '0', fd);
// 	}
// 	else
// 		ft_putchar_fd(new + '0', fd);
// } 

void 	init(t_contrast *main, char **argv)
{
	main->name_new_file = ft_strdup(argv[6]);
	main->contrast_lvl = ft_atoi(argv[4]);
}

void 	algo_contrast(t_contrast *main, int i)
{
	int 	res;

	res = main->mapping_pixel[i];
	res = res * main->contrast_lvl * main->max_grey_lvl;
	main->mapping_pixel[i] = res;
}

void	change_mapping(t_contrast *main)
{
	int 	i;

	i = 0;
	while (i < main->size_map)
	{
		algo_contrast(main, i);
		i++;
	}
}

void 	print_demo(t_contrast *main)
{
	int x = 0;
	int y = 0;
	int i = 0;
	while (y < main->lenght)
	{
		x = 0;
		while (x < main->height)
		{
			printf("%d ",main->mapping_pixel[i]);
			i++;
			x++;
		}
		printf("\n");
		y++;
	}
}

void	init_demo(t_contrast *main)
{
	main->lenght = 10;
	main->height = 10;
	main->mapping_pixel = (int*)malloc(sizeof(int) * (10 * 10) + 1);
	main->size_map = 10 * 10;
	main->max_grey_lvl = 5;
	int x = 0;
	int y = 0;
	int i = 0;
	while (y < main->lenght)
	{
		x = 0;
		while (x < main->height)
		{
			main->mapping_pixel[i] = 5;
			i++;
			x++;
		}
		y++;
	}
	//print_demo(main);
}

void	save_file(t_contrast *main)
{
	int 	x;
	int 	y;
	int 	i;
	int 	fd;

	i = 0;
	y = 0;
	fd = open(main->name_new_file, O_CREAT | O_RDWR);
	while (y < main->height)
	{
		x = 0;
		while (x < main->lenght)
		{
			// write(fd, ft_atoi())
			x++;
		}
		y++;
	}
}

int		main(int argc, char **argv)
{
	t_lst			*list_read;
	t_contrast		*main;

	if (input_param(argc, argv) != 1)
		return (-1);
	list_read = ft_read(argv);
	if (list_read->len == 0)
	{
		printf("Error file\n");
		return (0);
	}
	main = (t_contrast*)malloc(sizeof(t_contrast));
	init(main, argv);
	// init_demo(main); // validator(main, list_read);
	//change_mapping(main);
	//printf("change\n");
	//print_demo(main);
	//save_file(main);
	// while (list_read->next)
	// {
	// 	printf("%s\n", list_read->line);
	// 	list_read = list_read->next;
	// }
}
