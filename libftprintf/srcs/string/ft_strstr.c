/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:18:22 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/16 15:39:30 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		found;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0')
	{
		if (*haystack == *needle)
		{
			found = 1;
			while (haystack[found] == needle[found]
					&& haystack[found] != '\0' && needle[found] != '\0')
				++found;
			if (needle[found] == '\0')
				return ((char *)haystack);
		}
		++haystack;
	}
	return (NULL);
}
