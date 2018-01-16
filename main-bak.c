/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main-bak.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 14:06:57 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/16 12:48:36 by cbaillat         ###   ########.fr       */
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
	double flot = 24.04567;
	double inf2 = 2.4560000;

	setlocale(LC_ALL, "");

	// ret1 = printf("%g\n", inf);
	// ret2 = ft_printf("%g\n", inf);
	// printf("Them: %d\nMe:  %d\n\n", ret1, ret2);

	/* ret1 = printf("%f\n", inf);
	ret2 = ft_printf("%f\n", inf);
	printf("Them: %d\nMe:  %d\n\n", ret1, ret2);

	ret1 = printf("%.4S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	ret2 = ft_printf("%.4S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("Them: %d\nMe:  %d\n\n", ret1, ret2);

	ret1 = printf("{%0-5.s}\n", 0);
	ret2 = ft_printf("{%0-5.s}\n", 0);
	printf("Them: %d\nMe:  %d\n\n", ret1, ret2);

	ret1 = printf("{%*s}\n", 5, 0);
	ret2 = ft_printf("{%*s}\n", 5, 0);
	printf("Them: %d\nMe:  %d\n\n", ret1, ret2);

	ret1 = printf("%.4S\n", L"我是一只猫。");
	ret2 = ft_printf("%.4S\n", L"我是一只猫。");
	printf("Them: %d\nMe:  %d\n\n", ret1, ret2);
 	*/

	ft_printf("%A\n", flot);
	ft_printf("%F\n", flot);
	ft_printf("%E\n", flot);

	ret1 = printf("%15.4S\n", L"我是一只猫。");
	ret2 = ft_printf("%15.4S\n", L"我是一只猫。");
	printf("Them: %d\nMe:  %d\n\n", ret1, ret2);


	ret1 = printf("%15.5S\n", L"ÊM-^ZM-^VÁM-^BM-^I");
	ret2 = ft_printf("%15.5S\n", L"ÊM-^ZM-^VÁM-^BM-^I");
	printf("Them: %d\nMe:  %d\n\n", ret1, ret2);
	// ret1 = printf("%g\n", inf2);
	// ret2 = ft_printf("%g\n", inf2);
	// printf("Them: %d\nMe:  %d\n\n", ret1, ret2);
}
