/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 14:06:57 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/17 20:20:22 by cbaillat         ###   ########.fr       */
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
	printf("Expression: %%-0.-#+*.*ld width=20 preci=10\n");
	printf("-------------------------------------------\n");
	ft_printf("Mine1:\n%*ld\n", 20);
	ft_printf("Mine2:\n%-0-#+*.*ld\n", 20, 10);
	printf("=======================================\n");
}
