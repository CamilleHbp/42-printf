/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 19:23:54 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/16 15:35:28 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"

int32_t	print_pointer(t_format format, va_list *app, t_buffer *buffer)
{
	void		*ptr;
	t_unsigned	nb;

	ptr = va_arg(*app, void *);
	nb.nb = (uintmax_t)ptr;
	nb.base = 16;
	nb.prefix = "0x";
	format.flags |= POINTER;
	format.flags |= PREFIX;
	print_unsigned(nb, format, buffer);
	return (SUCCESS);
}
