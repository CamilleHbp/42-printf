/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:56:55 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/16 16:28:53 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 != 0 && ((unsigned char)*s1 == (unsigned char)*s2))
	{
		++s1;
		++s2;
	}
	return ((int)((unsigned char)*s1 - (unsigned char)*s2));
}
