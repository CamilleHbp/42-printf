/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main-bak.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 14:06:57 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/10 20:04:07 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <locale.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <math.h>
#include "ft_printf.h"

int	main(void)
{
	int		ret1;
	int		ret2;
	// wchar_t *arg4 = L"ÊM-^ZM-^VÁM-^BM-^I";
	// wchar_t *arg5 = L"ŸM-^Dÿ≠ŸM-^E ÿÆŸM-^Fÿ≤ŸM-ÿ±";

	// setlocale(LC_ALL, "en_US.utf8");
	double inf = 100.04567;
	double inf2 = 2.4560000;

	setlocale(LC_ALL, "");

	ret1 = printf("%g\n", inf);
	ret2 = ft_printf("%g\n", inf);
	printf("Them: %d\nMe:  %d\n\n", ret1, ret2);

	ret1 = printf("%f\n", inf);
	ret2 = ft_printf("%f\n", inf);
	printf("Them: %d\nMe:  %d\n\n", ret1, ret2);

	ret1 = printf("%g\n", inf2);
	ret2 = ft_printf("%g\n", inf2);
	printf("Them: %d\nMe:  %d\n\n", ret1, ret2);
}
