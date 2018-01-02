/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 10:36:28 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/21 11:02:52 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Changes all occurences of the char c by a substitute
*/

void	ft_strcrepl(char *s, char c, char substitute)
{
	if (s == NULL)
		return ;
	while (*s != '\0')
	{
		if (*s == c)
			*s = substitute;
		++s;
	}
}
