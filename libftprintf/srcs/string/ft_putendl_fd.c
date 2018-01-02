/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:14:43 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/23 19:06:03 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	size_t len;

	if (s == NULL)
		return ;
	len = ft_strlen(s);
	while ((((unsigned long)s & 7) != 0) && (len > 0))
	{
		ft_putchar_fd(*s, fd);
		++s;
		--len;
	}
	while (len >= 8)
	{
		write(fd, s, 8);
		s += 8;
		len -= 8;
	}
	while (len > 0)
	{
		ft_putchar_fd(*s, fd);
		++s;
		--len;
	}
	ft_putchar_fd('\n', fd);
}
