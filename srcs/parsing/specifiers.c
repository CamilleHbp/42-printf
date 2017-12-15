/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 21:17:06 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/15 23:29:49 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_parsing.h"

e_sp_type	get_type(const char specifier)
{
	if (ft_strchr("dDioOuUxX", specifier))
		return (integer);
	else if (ft_strchr("fFeEgGaA", specifier))
		return (floating_point);
	else if (ft_strchr("cCsS", specifier))
		return (string);
	else if (strchr("p", specifier))
		return (void_ptr);
	else if (strchr("n", specifier))
		return (int_ptr);
	else
		return (unknown);
}

/*
** Either returns NULL if the specifier is found
** or the pointer to which the string should continue to be parsed if no
** specifier is found
*/

char	*get_specifier(const char *string, t_format *format)
{
	char		*traverse;
	char		*specifier;

	specifier = "dDiuUoOxXfFeEgGaAcCsSpn%";
	traverse = string;
	while (42)
	{
		if (*traverse == '\0' || *traverse == ' ')
		{
			ft_putnstr(string, (traverse - string));
			return (traverse);
		}
		if (ft_strchr(specifier, *traverse) != NULL)
		{
			if (ft_strchr("DUO", *traverse) != NULL)
			{
				format->length = l;
				*traverse += 32;
			}
			format->specifier = *traverse;
			format->type = get_type(*traverse);
			return (NULL);
		}
	}
	return (NULL);
}
