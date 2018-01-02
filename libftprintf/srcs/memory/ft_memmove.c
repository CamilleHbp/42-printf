/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:44:26 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/16 17:39:36 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 1- We check if the two strings overlap somewhere.
** 2- If it overlaps at the end of dest, we copy forward.
** 3- If it overlaps at the beginning of dest, we copy backwards.
** My implementation of memcpy copies backwards, lets use that. That is why I
** only check if they overlap at the end of src.
** 4- If there is no overlap, we can just use memcpy.
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*byte_src;
	unsigned char	*byte_dst;
	size_t			overlap;
	size_t			i;

	byte_dst = (unsigned char *)dst;
	byte_src = (unsigned char *)src;
	overlap = -1;
	while (++overlap < len)
	{
		if (src + overlap == dst + len)
		{
			i = 0;
			while (i < len)
			{
				byte_dst[i] = byte_src[i];
				++i;
			}
			return ((void *)byte_dst);
		}
	}
	return (ft_memcpy(dst, src, len));
}
