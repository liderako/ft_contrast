/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 18:00:34 by asvirido          #+#    #+#             */
/*   Updated: 2018/02/03 11:03:51 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H
# include "src/general/general.h"

typedef struct		s_contrast
{
	int			*mapping_pixel;
	int			lenght;
	int			height;
	int			max_grey_lvl;
	int			contrast_lvl;
	char		*name_new_file;
}					t_contrast;

#endif
