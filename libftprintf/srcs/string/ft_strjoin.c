/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:01:09 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/17 13:06:31 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s_new;
	size_t	size;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if ((s_new = (char *)malloc(sizeof(*s_new) * (size + 1))) == NULL)
		return (NULL);
	i = 0;
	while (*s1 != '\0' && i < size)
	{
		s_new[i] = *s1;
		++s1;
		++i;
	}
	while (*s2 != '\0' && i < size)
	{
		s_new[i] = *s2;
		++s2;
		++i;
	}
	s_new[i] = '\0';
	return (s_new);
}
