/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <asvirido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 18:00:34 by asvirido          #+#    #+#             */
/*   Updated: 2018/02/04 18:26:58 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H
# include "src/general/general.h"
# define FILE name_new_file
# include <pthread.h>

int		*get_borders(t_contrast *main_list);
void	save_two(t_contrast *main, int fd);
void	*ft_copy(void *data, size_t size);
void	*thread_change(void *parameter);
void	thread_change_mapping(t_contrast *main_x);
void	thread_save_file(t_thread *tmp);
#endif
