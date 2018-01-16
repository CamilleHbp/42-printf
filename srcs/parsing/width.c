/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 22:56:18 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/16 14:10:55 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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

static char	*set_width(char *string, t_format *format)
{
	uint32_t	digits;

	if ((format->width = ft_atoi(string)) < 0)
	{
		format->width = ft_abs(format->width);
		format->flags |= RIGHT_PAD;
	}
	digits = format->width;
	while (digits > 0)
	{
		++string;
		digits /= 10;
	}
	return (string);
}

int32_t		seek_width(char **string, t_format *format, va_list *app)
{
	if (**string == '*')
	{
		if ((format->width = (int32_t)va_arg(*app, int)) < 0)
		{
			format->width = ft_abs(format->width);
			format->flags |= RIGHT_PAD;
		}
		*string += 1;
		return (SUCCESS);
	}
	else if (ft_isdigit(**string))
	{
		*string = set_width(*string, format);
		return (SUCCESS);
	}
	return (FAILURE);
}
