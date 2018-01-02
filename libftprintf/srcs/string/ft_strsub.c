/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:35:17 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/20 16:30:31 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s_new;

	if (s == NULL)
		return (NULL);
	if ((s_new = (char *)malloc(sizeof(*s_new) * (len + 1))) == NULL)
		return (NULL);
	s_new[len] = '\0';
	while (len > 0)
	{
		--len;
		s_new[len] = s[start + (int)len];
	}
	return (s_new);
}
