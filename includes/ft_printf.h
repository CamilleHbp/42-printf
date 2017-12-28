/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 09:47:02 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/27 22:30:06 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>

# include "libft.h"
# include "parsing.h"

# define SUCCESS		(int32_t)0
# define FAILURE		(int32_t)-1
# define MALLOC_FAIL	(int32_t)-2

int	ft_printf(const char *format, ...);

#endif
