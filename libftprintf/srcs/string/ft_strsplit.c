/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.alt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:00:40 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/21 09:49:46 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*ft_skip_delim(const char *str, char c)
{
	while (*str != '\0' && *str == c)
		str++;
	return (str);
}

static const char	*ft_skip_word(const char *str, char c)
{
	while (*str != '\0' && *str != c)
		str++;
	return (str);
}

static int			ft_count_words(const char *str, char c)
{
	int		wordcount;

	wordcount = 0;
	while (*str != '\0')
	{
		str = ft_skip_delim(str, c);
		if (*str != '\0')
		{
			++wordcount;
			str = ft_skip_word(str, c);
		}
	}
	return (wordcount);
}

static char			**ft_free_array(char **array, int len)
{
	int i;

	i = 0;
	while (i < len)
		free(array[i]);
	free(array);
	return (NULL);
}

char				**ft_strsplit(char const *str, char c)
{
	char		**str_array;
	int			i;
	const char	*end_word;

	if (str == NULL)
		return (NULL);
	i = ft_count_words(str, c);
	if ((str_array = (char**)malloc(sizeof(*str_array) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (*str != '\0')
	{
		str = ft_skip_delim(str, c);
		if (*str != '\0')
		{
			end_word = ft_skip_word(str, c);
			str_array[i] = ft_strsub(str, 0, end_word - str);
			if (str_array[i] == NULL)
				return (ft_free_array(str_array, i));
			i++;
			str = end_word;
		}
	}
	str_array[i] = 0;
	return (str_array);
}
