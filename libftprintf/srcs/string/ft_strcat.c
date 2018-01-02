/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:02:20 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/23 19:06:03 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char *s1_original;

	s1_original = s1;
	while (*s1 != '\0')
		++s1;
	while (*s2 != '\0')
	{
		*s1 = *s2;
		++s1;
		++s2;
	}
	*s1 = '\0';
	return (s1_original);
}
