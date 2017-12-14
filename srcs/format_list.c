/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 10:08:20 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/14 11:44:49 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_list.h"

static void			format_init(t_format *state, const char *format);
static e_specifier	format_get(t_format *state);
static void			format_next(t_format *state);

void		format_init(t_format *state, const char *format)
{
	state->format = format;
	state->int_queue = 0;
	state->type = type_none;
	format_next(state);
}

e_specifier	format_get(t_format *state)
{
	if (state->int_queue > 0)
	{
		return type_int;
	}
	return state->type;
}

void		format_next(t_format *state)
{
	if (state->int_queue > 0)
	{
		state->int_queue--;
		return;
	}
	while (*state->format)
	{
		if (state->format[0] == '%')
		{
			state->format++;
			if (state->format[0] == '%')
			{
				state->format++;
				continue;
			}
			state->format = seek_flag(state->format);
			state->format = seek_width(state->format, &state->int_queue);
			int mod;
			state->format = seek_mod(state->format, &mod);
			state->format = seek_specifier(state->format, mod, &state->type);
			return;
		}
		else
		{
			state->format++;
		}
	}
	state->type = type_none;
}
