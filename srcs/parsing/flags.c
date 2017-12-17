/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 21:17:33 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/17 17:40:14 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_parsing.h"

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
**		it forces the output to contain a decimal point even if no digits follow.
**		By default, if no digits follow, no decimal point is written.
** 0	Left-pads the number with zeroes (0) instead when padding is specified
**		If a - flag and 0 flag appears, the - flag overrides the 0.
**		If a precision is given with dDioOuUxX, the 0 flag is ignored.
*/

/*
** We traverse the list and check if the flag is not already there.
** If it is, we do not add it, but return SUCCESS.
*/

static int32_t	add_flag(t_format *format, e_flag flag)
{
	t_flag	*list;
	t_flag	*tmp;

	if ((list = (t_flag*)malloc(sizeof(t_flag))) == NULL)
		return (MALLOC_FAIL);
	list->flag = flag;
	list->next = NULL;
	if (format->flag == NULL)
		format->flag = list;
	else
	{
		tmp = format->flag;
		if (tmp->flag == flag)
			return (SUCCESS);
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = list;
	}
	return (SUCCESS);
}

int32_t		seek_flag(char **string, t_format *format)
{
	char	*flag;
	char	*found;

	flag = "-+ #0";
	if (**string == '0' && ft_isdigit(*(*string - 1)))
		return (FAILURE);
	if ((found = ft_strchr(flag, **string)) != NULL)
		return (add_flag(format, (found - flag)));
	return (FAILURE);
}
