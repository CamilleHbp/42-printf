/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 10:20:50 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/21 10:41:39 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Changes all char to lower case if they are uppercase letters.
** Needs a modifiable string as input.
*/

void	ft_strtolower(char *s)
{
	if (s == NULL)
		return ;
	while (*s != '\0')
	{
		if (*s >= 'A' && *s <= 'Z')
			*s = *s + 32;
		++s;
	}
}
