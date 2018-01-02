/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:15:55 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/16 15:17:18 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occurence;

	last_occurence = NULL;
	if (c == '\0')
	{
		while (*s != '\0')
			++s;
		return ((char *)s);
	}
	while (*s != '\0')
	{
		if (*s == (char)c)
			last_occurence = (char *)s;
		++s;
	}
	return (last_occurence);
}
