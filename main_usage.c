/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 14:28:06 by alukyane          #+#    #+#             */
/*   Updated: 2017/11/18 14:28:09 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrim	*ft_tetrnew(char **map)
{
	t_tetrim	*tetr;
	int			i;

	i = 0;
	tetr = (t_tetrim *)malloc(sizeof(t_tetrim));
	if (!tetr)
		return (NULL);
	tetr->val = (char **)malloc(sizeof(char *) * 5);
	if (!tetr->val)
		return (NULL);
	while (i < 4)
	{
		tetr->val[i] = map[i];
		i++;
	}
	tetr->available = 1;
	tetr->next = NULL;
	return (tetr);
}

t_tetrim	*ft_array_to_list(t_tetrim *array, int count)
{
	t_tetrim	*cur;
	t_tetrim	*head;
	int			i;

	i = 0;
	cur = ft_tetrnew(array[i].val);
	head = cur;
	i++;
	while (i < count)
	{
		cur->next = ft_tetrnew(array[i].val);
		cur = cur->next;
		i++;
	}
	return (head);
}

void		ft_launch(char *file_content, t_tetrim *arr_tetrs)
{
	t_tetrim	*tetrs;
	char		**map;
	char		**figures;
	int			count;

	figures = ft_strsplit(file_content, '\n');
	count = ft_is_val_figures(figures);
	tetrs = ft_array_to_list(arr_tetrs, count);
	map = ft_make_square(count);
	map = ft_zapusk(map, tetrs);
	ft_print_map(map, ft_calc_size(map, count * 4));
}

int			main(int argc, char **argv)
{
	char		*file_content;
	t_tetrim	*arr_tetrs;

	if (argc == 2)
	{
		file_content = ft_read_from_file(argv[1]);
		if (ft_read_from_file(argv[1]) && ft_is_valid_str(file_content) == 1)
		{
			arr_tetrs = ft_make_arr_tetrs(file_content);
			if (arr_tetrs == 0)
				ft_putstr("error\n");
			else
				ft_launch(file_content, arr_tetrs);
		}
		else
			ft_putstr("error\n");
	}
	else
		ft_putstr("usage: fillit target_file\n");
	return (0);
}
