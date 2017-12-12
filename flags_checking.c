/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 19:00:20 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/12 19:03:15 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int32_t	is_flag(char c)
{
	uint32_t	i;

	while (g_flags[i] != '\0')
	{
		if (g_flags[i] == c)
			return (i);
		++i;
	}
	return (FAILURE);
}

int32_t	is_sp_integer(char c)
{
	uint32_t	i;

	while (g_sp_integer[i] != '\0')
	{
		if (g_sp_integer[i] == c)
			return (i);
		++i;
	}
	return (FAILURE);
}
