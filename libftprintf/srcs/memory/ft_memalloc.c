/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 10:54:35 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/17 11:03:45 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	t_byte	*memory;

	if ((memory = malloc(sizeof(memory) * size)) == NULL)
		return (NULL);
	ft_memset((void *)memory, 0, size);
	return ((void *)memory);
}
