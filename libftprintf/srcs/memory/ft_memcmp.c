/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:10:01 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/16 18:00:05 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*bytes_s1;
	unsigned char	*bytes_s2;
	size_t			i;

	bytes_s1 = (unsigned char *)s1;
	bytes_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (bytes_s1[i] != bytes_s2[i])
			return (bytes_s1[i] - bytes_s2[i]);
		++i;
	}
	return (0);
}
