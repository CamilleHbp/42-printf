/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:08:32 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/12 19:30:07 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef enum {
	d = 0,
	D,
	i,
	o,
	O,
	u,
	U,
	x,
	X
} e_sp_integer;

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*tmp;
	int32_t	sp_type;

	tmp = format;
	va_start(ap, format);
	while (tmp != '\0')
	{
		if (tmp != '%')
		{
			ft_putchar(tmp);
			continue;
		}
		if ((sp_type = ft_strchr("dDioOuUxX", *(tmp + 1))) != NULL)
		// I can use the enum in another function to know which character I will
		// need to parse
			;	//parse_flag(sp_type);
		//continue checking the type of the specifier
	}
	return (SUCCESS);
}
