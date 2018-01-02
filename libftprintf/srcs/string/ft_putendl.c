/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:32:51 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/23 19:06:03 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	size_t len;

	if (s == NULL)
		return ;
	len = ft_strlen(s);
	while ((((unsigned long)s & 7) != 0) && (len > 0))
	{
		ft_putchar(*s);
		++s;
		--len;
	}
	while (len >= 8)
	{
		write(1, s, 8);
		s += 8;
		len -= 8;
	}
	while (len > 0)
	{
		ft_putchar(*s);
		++s;
		--len;
	}
	ft_putchar('\n');
}
