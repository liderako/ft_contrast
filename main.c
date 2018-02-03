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
	init_demo(main);
	change_mapping(main);
	save_file(main);
}
