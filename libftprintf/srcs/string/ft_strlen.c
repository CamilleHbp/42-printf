/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:27:55 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/20 14:29:00 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** !!BIT MAGIC!!
** Here is how the magic is done ^^
** 1- exp1 = (word - 0x0101010101010101UL
** By substracting 1 in every byte, we get a 1 in the high bit if the byte is 0
** or greater than 0x80.
** 2- exp2 = (~word & 0x8080808080808080UL)
** By using the complement of the byte, and ANDing with 0x80, the high bit is
** set only if the byte was less than 0x80
** 3- final = exp1 & exp2
** We have one expression that has the high bit set if the number is 0 or >x080,
** and the other one has the high bit set if the number is strictly <0x80.
** By consequence if we AND the two expression, we only get 1 if the number is 0
*/

static int		ft_has_zero_byte(unsigned long word)
{
	if (((word) - 0x0101010101010101UL) & (~(word) & 0x8080808080808080UL))
		return (1);
	return (0);
}

static size_t	ft_check_word_bytes(char const *byte_ptr, char const *s)
{
	if (byte_ptr[0] == 0)
		return (byte_ptr - s);
	if (byte_ptr[1] == 0)
		return (&byte_ptr[1] - s);
	if (byte_ptr[2] == 0)
		return (&byte_ptr[2] - s);
	if (byte_ptr[3] == 0)
		return (&byte_ptr[3] - s);
	if (byte_ptr[4] == 0)
		return (&byte_ptr[4] - s);
	if (byte_ptr[5] == 0)
		return (&byte_ptr[5] - s);
	if (byte_ptr[6] == 0)
		return (&byte_ptr[6] - s);
	if (byte_ptr[7] == 0)
		return (&byte_ptr[7] - s);
	return (0);
}

/*
** We check the bytes until we are aligned to a register.
** We check the bytes 8 by 8, if we find a word that has a zero byte in it,
** we try to find which one it is.
*/

size_t			ft_strlen(const char *s)
{
	char const		*char_ptr;
	unsigned long	*word_ptr;

	char_ptr = s;
	while (((unsigned long)char_ptr & 7) != 0)
	{
		if (*char_ptr == '\0')
			return (char_ptr - s);
		++char_ptr;
	}
	word_ptr = (unsigned long *)char_ptr;
	while (1)
	{
		if (ft_has_zero_byte(*word_ptr))
		{
			char_ptr = (char const *)word_ptr;
			return (ft_check_word_bytes(char_ptr, s));
		}
		++word_ptr;
	}
}
