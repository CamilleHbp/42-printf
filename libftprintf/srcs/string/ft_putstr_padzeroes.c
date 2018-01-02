/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_padzeroes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:56:30 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/30 15:56:31 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_padzeroes(const char *s, size_t width)
{
	size_t n;

	n = ft_strlen(s);
	if (width < n)
		return ;
	while (width > n)
	{
		ft_putchar('0');
		--width;
	}
	ft_putstr(s);
	ft_putchar('\n');
}
