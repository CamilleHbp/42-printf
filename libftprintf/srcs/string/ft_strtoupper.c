/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 10:15:06 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/21 10:41:50 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Changes all char to uppercase if they are lowercase letters.
** Needs a modifiable string as input.
*/

void	ft_strtoupper(char *s)
{
	if (s == NULL)
		return ;
	while (*s != '\0')
	{
		if (*s >= 'a' && *s <= 'z')
			*s = *s - 32;
		++s;
	}
}
