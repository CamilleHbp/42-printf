/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputnstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 19:31:03 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/29 21:42:52 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_wputnstr(wchar_t *ws, size_t n)
{
	if (ws == NULL)
		return ;
	while (n)
	{
		ft_wputchar(*ws);
		--n;
		++ws;
	}
}
