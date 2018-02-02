/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 20:17:32 by asvirido          #+#    #+#             */
/*   Updated: 2018/02/02 20:17:33 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <string.h>

size_t		ft_strlen(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strdup(const char *s1);
void		ft_bzero(void *s, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
int			ft_atoi(const char *str);
#endif
