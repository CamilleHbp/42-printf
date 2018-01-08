/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 21:17:30 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/08 15:00:16 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*
** LENGTH:
** As long as there is a flag, we keep looping and keep only the biggest flag
**	  | d,i			uoxX	fFeEgGaA	c		s		p		n
** -  |	int			uint	double		int		char*	void*	int*
** hh |	char		uchar										char*
** h  |	short 		ushort										short*
** l  |	long 		ulong 				wint_t	wchar_t*		long*
** ll |	long long	ulong long									long long*
** j  |	intmax_t	uintmax_t									intmax_t*
** z  |	size_t		size_t										size_t*
** t  |	ptrdiff_t	ptrdiff_t									ptrdiff_t*
** L  |						long double
*/

static void	set_flag_long(t_format *format)
{
	if (format->flags & LONG)
		format->flags |= LLONG;
	format->flags |= LONG;
}

static void	set_flag_short(t_format *format)
{
	if (format->flags & SHORT)
	{
		format->flags |= SSHORT;
		format->flags &= ~SHORT;
		return ;
	}
	format->flags |= SHORT;
}

int32_t		seek_length(char **string, t_format *format)
{
	char	*length;

	length = "hljztL";
	if (!**string)
		return (FAILURE);
	if (ft_strchr(length, **string) != NULL)
	{
		if (**string == 'h')
			set_flag_short(format);
		else if (**string == 'l')
			set_flag_long(format);
		else if (**string == 'j')
			format->flags |= INTMAX;
		else if (**string == 'z')
			format->flags |= SIZE_T;
		else if (**string == 't')
			format->flags |= PTRDIFF;
		else if (**string == 'L')
			format->flags |= LDOUBLE;
		*string += 1;
		return (SUCCESS);
	}
	return (FAILURE);
}
