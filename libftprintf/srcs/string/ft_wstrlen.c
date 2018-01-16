/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 10:25:13 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/15 11:42:59 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** We need to calculate the length to output by checking how many bytes the
** UTF-8 char will take.
** We cannot really use the standard strlen function as we check 4 bytes at a
** time. We would only go 2 times faster. Maybe I'll implement it later.
*/

size_t	ft_wstrlen(wchar_t *ws)
{
	size_t len;

	len = 0;
	while (*ws != L'\0')
	{
		len += ft_wcharlen(*ws);
		++ws;
	}
	return (len);
}
