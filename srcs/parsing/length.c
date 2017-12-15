/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 21:17:30 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/15 23:25:18 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_parsing.h"

void	add_length(t_format *format, e_length len)
{
	if (format->length == unknown || format->length < len)
		format->length = len;
}

/*
** First we need to check for the two flag with two letters, and increment the
** string pointer iif we find a double letter.
** Else we just just add the length if is not specified (unknown) or if it is
** bigger than the other flags we found.
*/

t_bool	seek_length(const char **string, t_format *format)
{
	char	*length;
	char	*found;

	length = "hljztL";
	if (**string == 'h' && *(*string + 1) == 'h')
	{
		if (format->length == unknown)
			format->length = hh;
		*string += 1;
		return (SUCCESS);
	}
	else if (**string == 'l' && *(*string + 1) == 'l')
	{
		add_length(format, ll);
		*string += 1;
		return (SUCCESS);
	}
	else if ((found = ft_strchr(length, **string)) != NULL)
	{
		add_length(format, (found - length));
		return (SUCCESS);
	}
	return (FAILURE);
}
