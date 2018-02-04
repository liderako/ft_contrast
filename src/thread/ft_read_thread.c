/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 10:28:32 by asvirido          #+#    #+#             */
/*   Updated: 2018/02/03 10:28:33 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

t_lst	*ft_read_thread(char **argv)
{
	t_lst	*new;
	t_lst	*head;
	char	*line;
	int		fd;
	int		res;

	fd = open(argv[2], O_RDONLY);
	if ((res = read_from_file(fd, &line)) != 1)
	{
		close(fd);
		return (ft_nlstnew(""));
	}
	new = ft_nlstnew(line);
	head = new;
	free(line);
	while ((res = read_from_file(fd, &line)) > 0)
	{
		ft_nlstadd(new, line);
		free(line);
		line = NULL;
	}
	close(fd);
	return (head);
}
