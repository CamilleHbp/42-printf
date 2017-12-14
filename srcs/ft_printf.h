/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 09:47:02 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/14 13:25:08 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>

# include "libft.h"
# include "format_parsing.h"

# define SUCCESS (int32_t)0
# define FAILURE (int32_t) - 1

int ft_printf(const char *format, ...);

#endif
