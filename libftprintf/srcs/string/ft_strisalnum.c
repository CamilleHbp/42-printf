/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisalnum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 10:42:35 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/21 11:12:54 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns (1) if the string is alpha-numerical, (0) otherwise
*/

int		ft_strisalnum(char *s)
{
	if (s == NULL)
		return (0);
	while (*s != 0)
	{
		if (!ft_isalnum(*s))
			return (0);
		++s;
	}
	return (1);
}
