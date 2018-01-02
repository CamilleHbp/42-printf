/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:26:35 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/20 19:38:53 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*cpy;
	t_list	*prev_cpy;
	t_list	*next_cpy;

	if (lst == NULL || f == NULL)
		return (NULL);
	if ((cpy = (t_list *)malloc(sizeof(*prev_cpy))) == NULL)
		return (NULL);
	cpy = f(lst);
	prev_cpy = cpy;
	while (lst->next != NULL)
	{
		if ((next_cpy = (t_list *)malloc(sizeof(*next_cpy))) == NULL)
			return (NULL);
		next_cpy = f(lst->next);
		prev_cpy->next = next_cpy;
		lst = lst->next;
		prev_cpy = next_cpy;
	}
	return (cpy);
}
