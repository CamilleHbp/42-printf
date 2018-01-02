/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:20:41 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/20 16:18:52 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	size_t	size;
	size_t	i;

	if (s == NULL || f == NULL)
		return ;
	size = ft_strlen(s);
	i = 0;
	while (i < size)
	{
		f(&s[i]);
		++i;
	}
}
