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

void 	init(t_contrast *main, char **argv)
{
	main->name_new_file = ft_strdup(argv[5]);
	main->contrast_lvl = ft_atoi(argv[4]);
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
	// while (list_read->next)
	// {
	// 	printf("%s\n", list_read->line);
	// 	list_read = list_read->next;
	// }
}
