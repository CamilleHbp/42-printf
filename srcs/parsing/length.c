/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 21:17:30 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/17 12:39:02 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_parsing.h"

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

/*
** We just just add the length if is not specified (unknown) or if it is
** bigger than the other flags we found.
*/

void	add_length(t_format *format, e_length len)
{
	if (format->length == length_unknown || format->length < len)
		format->length = len;
}

/*
** First we need to check for the two flag with two letters, and increment the
** string pointer iif we find a double letter.
** Else we add the length.
*/

int32_t	seek_length(char **string, t_format *format)
{
	char	*length;
	char	*found;

	length = "hljztL";
	if (**string == 'h' && *(*string + 1) == 'h')
	{
		if (format->length == length_unknown)
			format->length = hh;
		*string += 1;
		return (SUCCESS);
	}
	else if (**string == 'l' && *(*string + 1) == 'l')
	{
		add_length(format, ll);
		*string += 1;
		return (SUCCESS);
	}
	else if ((found = ft_strchr(length, **string)) != NULL)
	{
		add_length(format, (found - length));
		return (SUCCESS);
	}
	return (FAILURE);
}
