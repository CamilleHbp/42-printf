/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 21:17:33 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/16 14:10:33 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*
** FLAGS:
** -	Left-justify within the given field width; Right justification is the
**		default (see width sub-specifier).
** +	Forces to preceed the result with a plus or minus sign (+ or -) even for
**		positive numbers. By default, only negative numbers have a - sign.
** (space)	If no sign is going to be written, a blank space is inserted before
**		the value.
** #		oxX:
**		value is preceeded with 0, 0x or 0X for values different than zero.
**			aAeEfFgG:
**		it forces the output to contain a decimal point even if no digits follow
**		By default, if no digits follow, no decimal point is written.
** 0	Left-pads the number with zeroes (0) instead when padding is specified
**		If a - flag and 0 flag appears, the - flag overrides the 0.
**		If a precision is given with dDioOuUxX, the 0 flag is ignored.
*/

int32_t		seek_flag(char **string, t_format *format)
{
	char	*flag;

	flag = "-+ #0";
	if (!**string)
		return (FAILURE);
	if (ft_strchr(flag, **string) != NULL)
	{
		if (**string == '#')
			format->flags |= PREFIX;
		else if (**string == '-')
		{
			format->flags |= RIGHT_PAD;
			format->flags &= ~ZERO_PAD;
		}
		else if (**string == '+')
			format->flags |= SIGN;
		else if (**string == ' ')
			format->flags |= SPACE;
		else if (**string == '0')
			if (!(format->flags & RIGHT_PAD))
				format->flags |= ZERO_PAD;
		*string += 1;
		return (SUCCESS);
	}
	return (FAILURE);
}
