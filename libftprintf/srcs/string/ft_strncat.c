/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:19:14 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/14 18:21:45 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*s1_original;

	s1_original = s1;
	while (*s1 != '\0')
		++s1;
	while (*s2 != '\0' && n > 0)
	{
		*s1 = *s2;
		++s1;
		++s2;
		--n;
	}
	*s1 = '\0';
	return (s1_original);
}
