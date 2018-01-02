/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:08:12 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/17 15:25:50 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int				start;
	char			*s_new;
	char			*s_end;

	if (s == NULL)
		return (NULL);
	start = 0;
	if (*s == '\0')
		return (ft_strnew(1));
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		++start;
	if (s[start] == '\0')
		return (ft_strnew(1));
	s_end = (char *)s;
	while (*s_end != '\0')
		++s_end;
	--s_end;
	while ((*s_end == ' ' || *s_end == '\n' || *s_end == '\t') && s_end != s)
		--s_end;
	s_new = ft_strsub(s, start, (s_end - s - start + 1));
	return (s_new);
}
