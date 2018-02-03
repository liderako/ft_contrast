/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 18:00:34 by asvirido          #+#    #+#             */
/*   Updated: 2018/02/03 10:33:41 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_H
# define GENERAL_H
# include "get_next_line.h"
# include "libft/libft.h"
# include <stdio.h>

typedef struct		s_contrast
{
	int			*mapping_pixel;
	int 		size_map;
	int			lenght;
	int			height;
	int			max_grey_lvl;
	int			contrast_lvl;
	char		*name_new_file;
}					t_contrast;

typedef struct	s_lst
{
	char			*line;
	size_t			len;
	struct s_lst	*next;
}				t_lst;

t_lst			*ft_nlstnew(char *string);
void			ft_nlstadd(t_lst *nlst, char *string);
int				input_param(int argc, char **argv);
t_lst			*ft_read(char **argv);
void 			init(t_contrast *main, char **argv);
void			change_mapping(t_contrast *main);
void 			algo_contrast(t_contrast *main, int i);
void			save_file(t_contrast *main);

#endif
