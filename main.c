/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <asvirido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 20:03:39 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/03 15:28:54 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	init_demo(t_contrast *main_x)
{
	main_x->lenght = 10;
	main_x->height = 10;
	main_x->mapping_pixel = (int*)malloc(sizeof(int) * (10 * 10) + 1);
	main_x->size_map = 10 * 10;
	main_x->max_grey_lvl = 5;
	int x = 0;
	int y = 0;
	int i = 0;
	while (y < main_x->lenght)
	{
		x = 0;
		while (x < main_x->height)
		{
			main_x->mapping_pixel[i] = 5;
			i++;
			x++;
		}
		y++;
	}
}


int		main(int argc, char **argv)
{
	t_lst			*list_read;
	t_contrast		*main_x;

	if (input_param(argc, argv) != 1)
		return (-1);
	list_read = ft_read(argv);
	if (list_read->len == 0)
	{
		printf("Error file\n");
		return (0);
	}
	main_x = (t_contrast*)malloc(sizeof(t_contrast));
	init(main_x, argv);
	init_demo(main_x);
	change_mapping(main_x);
	save_file(main_x);
}
