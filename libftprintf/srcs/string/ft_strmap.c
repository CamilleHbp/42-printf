/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:28:33 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/20 16:22:30 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	size;
	size_t	i;
	char	*s_new;

	if (s == NULL || f == NULL)
		return (NULL);
	size = ft_strlen(s);
	if ((s_new = (char *)malloc(sizeof(*s_new) * (size + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		s_new[i] = f(s[i]);
		++i;
	}
	s_new[i] = '\0';
	return (s_new);
}
