/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 20:08:06 by asvirido          #+#    #+#             */
/*   Updated: 2018/02/02 20:08:07 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../general.h"

t_list		*ft_nlstnew(char *string)
{
	t_list	*nw;

	nw = (t_list *)malloc(sizeof(t_list));
	if (nw)
	{
		nw->line = string;
		nw->next = NULL;
		return (nw);
	}
	else
		return (NULL);
}
