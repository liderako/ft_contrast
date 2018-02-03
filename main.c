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

int		main(int argc, char **argv)
{
	t_lst	*list_read;

	if (input_param(argc, argv) == 1)
	{
		list_read = ft_read(argv);
		if (list_read->len == 0)
		{
			printf("Error file\n");
			return (0);
		}
		while (list_read->next)
		{
			printf("%s\n", list_read->line);
			list_read = list_read->next;
		}
	}
}
