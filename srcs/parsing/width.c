/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 22:56:18 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/16 17:00:33 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_parsing.h"

/*
** WIDTH:
** (nb)	Minimum number of characters to be printed. If the value to be
**		printed is shorter than this number, the result is padded with blank
**		spaces. The value is not truncated even if the result is larger.
** *	The width is not specified in the format string, but as an
**		additional integer value argument preceding the argument that has
**		to be formatted.
*/

/*
** If the char is a *, we need to turn on the flag, and later get the next
** argument to get the real width.
** If we find a number, ft_atoi will get us the number up to the next non-digit
** char, and we will need to offset the string pointer, to avoid parsing them
** again.
*/

t_bool	seek_width(const char **string, t_format *format)
{
	uint32_t	digits;

	if (**string == '*')
	{
		format->width_flag = 1;
		return (SUCCESS);
	}
	else if (ft_isdigit(**string))
	{
		format->width = ft_atoi(*string);
		digits = format->width;
		while (digits > 9)
		{
			*string += 1;
			digits /= 10;
		}
		return (SUCCESS);
	}
	return (FAILURE);
}