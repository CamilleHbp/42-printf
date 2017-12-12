/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:08:53 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/12 19:07:41 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_PRINTF_H
# define  FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include "libft.h"

# define SUCCESS (int32_t)0
# define FAILURE (int32_t)-1


/*
** Those extern definitions are used to check the specifier flags
*/

extern const char	*g_flags;
extern const char	*g_sp_integer;
extern const char	*g_length;
extern const char	*g_sp_char;
extern const char	*g_sp_float;
extern const char	*g_sp_special;

int	ft_printf(const char *format, ...);

#endif
