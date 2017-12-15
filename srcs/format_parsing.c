/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 10:04:50 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/15 19:04:49 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_parsing.h"

int32_t	seek_flag(const char *string, uint32_t index)
{
	char	*flag;
	char	*found;

	flag = "-+ #0";
	if (string[index] == '0' && is_digit(string[index - 1]))
		return (FAILURE);
	if ((found = ft_strchr(flag, string[index])) != NULL)
		return (found - flag);
	return (FAILURE);
}

const char *seek_width(const char *format, int *int_queue)
{
	*int_queue = 0;
	if (*format == '*')
	{
		format++;
		(*int_queue)++;
	}
	else
	{
		while (ft_isdigit((unsigned char)*format))
			format++;
	}
	if (*format == '.')
	{
		if (*format == '*')
		{
			format++;
			(*int_queue)++;
		}
		else
		{
			while (ft_isdigit((unsigned char)*format))
				format++;
		}
	}
	return format;
}

const char *seek_mod(const char *format, int *mod)
{
	*mod = 0;
	if (format[0] == 'h' && format[1] == 'h')
	{
		format += 2;
	}
	else if (format[0] == 'l' && format[1] == 'l')
	{
		*mod = ('l' << CHAR_BIT) + 'l';
		format += 2;
	}
	else if (ft_strchr("ljztL", *format))
	{
		*mod = *format;
		format++;
	}
	else if (ft_strchr("h", *format))
	{
		format++;
	}
	return format;
}

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
			break ;
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
			break ;
		}
	}
}
