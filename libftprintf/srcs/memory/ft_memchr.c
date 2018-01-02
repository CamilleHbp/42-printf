/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:02:56 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/21 11:19:48 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*bytes_s;

	bytes_s = (unsigned char *)s;
	i = -1;
	while (++i < n)
		if (bytes_s[i] == (unsigned char)c)
			return (&bytes_s[i]);
	return (NULL);
}
