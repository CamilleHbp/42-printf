/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:22:39 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/16 12:01:07 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 1- If the size given is zero, we return the total size we need, which is the
** src size.
** !! During all future operations, we check if the total size never exceeds
** the given size. We write a '\0' but only if we have a bigger given space than
** dest size.
** 2- We skip to the end of dest.
** 3- We start copying the src string until we reached the end 9or we have no
** allowed space left.
** 4- We return the destination size, + the length of src, to return the size
** needed, or written (whichever the case).
*/

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t total_size;
	size_t dest_size;

	total_size = 0;
	dest_size = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dest[total_size] != '\0' && total_size < size)
		++total_size;
	dest_size = total_size;
	while (src[total_size - dest_size] != '\0' && total_size < size - 1)
	{
		dest[total_size] = src[total_size - dest_size];
		total_size++;
	}
	if (dest_size < size)
		dest[total_size] = '\0';
	return (dest_size + ft_strlen(src));
}
