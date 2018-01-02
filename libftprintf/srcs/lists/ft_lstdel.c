/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 18:35:27 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/20 19:24:35 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next_elt;
	t_list	*elt;

	if (alst == NULL)
		return ;
	next_elt = *alst;
	while (next_elt->next != NULL)
	{
		elt = next_elt;
		next_elt = next_elt->next;
		if (elt->content != NULL)
			del(elt->content, elt->content_size);
		free(elt);
	}
	del(next_elt->content, next_elt->content_size);
	free(next_elt);
	*alst = NULL;
}
