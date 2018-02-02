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

t_list 	*ft_read(char **argv)
{
	t_list 	*new;
	t_list 	*head;
	char 	*line;
	int 	fd;
	int 	res;

	fd = open(argv[2], O_RDONLY);
	if ((res = get_next_line(fd, &line)) <= 0)
		return (ft_nlstnew(""));
	new = ft_nlstnew(line);
	head = new;
	free(line);
	while ((res = get_next_line(fd, &line)) > 0)
	{
		ft_nlstadd(new, line);
		printf("%s\n", new->line);
		free(line);
		line = NULL;
		// ft_bzero(line, ft_strlen(line));
	}
	return (head);
}

int		main(int argc, char **argv)
{
	t_list 	*list_read;

	if (input_param(argc, argv) == 1)
	{
		list_read = ft_read(argv);
		if (list_read->len == 0)
			return (0);
	}
}
