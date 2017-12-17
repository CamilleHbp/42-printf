/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 14:06:57 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/17 17:40:55 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "ft_printf.h"

int	main(void)
{
	char	*arg1 = "Test this.";
	char	arg2 = 'c';
	int		arg3 = 42;

	printf("Theirs: \n string: %s\n char: %c\n int: %d\n\n", arg1, arg2, arg3);
	// ft_printf("Mine: \n string: %s\n char: %c\n int: %d\n", arg1, arg2, arg3);
	printf("\n\n=======================================\n");
	printf("Testing width detection\n");
	printf("Expression: %%-0.1-#30.*ld\n");
	printf("-------------------------------------------\n");
	ft_printf("Mine:\n%-0.1-#+30.*ld\n");
	printf("=======================================\n");
}
