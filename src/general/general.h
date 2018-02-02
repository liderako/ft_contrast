/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 18:00:34 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/17 22:49:38 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_H
# define GENERAL_H
# include "get_next_line.h"
# include "libft/libft.h"
# include <stdio.h>

typedef struct 	s_list
{
	char 			*line;
	size_t			len;
	struct s_list	*next;
}				t_list;


t_list		*ft_nlstnew(char *string);
void		ft_nlstadd(t_list *nlst, char *string);
int 		input_param(int argc, char **argv);

#endif
