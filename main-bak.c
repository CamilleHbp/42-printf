/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main-bak.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 14:06:57 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/09 13:49:35 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <locale.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
	int		ret1;
	int		ret2;
	int		i = 0;
	// wchar_t *arg4 = L"ÊM-^ZM-^VÁM-^BM-^I";
	// wchar_t *arg5 = L"ŸM-^Dÿ≠ŸM-^E ÿÆŸM-^Fÿ≤ŸM-ÿ±";

	// setlocale(LC_ALL, "en_US.utf8");
	setlocale(LC_ALL, "");

	ret1 = printf("%5.0d\n", 0);
	ret2 = ft_printf("%5.0d\n", 0);
	printf("Them: %d\nMe:  %d\n\n", ret1, ret2);

	ret1 = printf("%3o\n", 0);
	ret2 = ft_printf("%3o\n", 0);
	printf("Them: %d\nMe:  %d\n\n", ret1, ret2);

	ret1 = printf("%p\n", &i);
	ret2 = ft_printf("%p\n", &i);
	printf("Them: %d\nMe:  %d\n\n", ret1, ret2);

	ret1 = printf("s: %s, p: %p, d:%d\n", "a string", &i, 42);
	ret2 = ft_printf("s: %s, p: %p, d:%d\n", "a string", &i, 42);
	printf("Them: %d\nMe:  %d\n\n", ret1, ret2);

 	ret1 = printf("{%010d}\n", -42);
 	ret2 = ft_printf("{%010d}\n", -42);
	printf("Them: %d\nMe:  %d\n\n", ret1, ret2);

	ret1 = printf("{%#.0e}\n", -4.6);
	ret2 = ft_printf("{%#.0e}\n", -4.6);
	printf("Them: %d\nMe:  %d\n\n", ret1, ret2);
	/* ret1 = printf("%#o\n", 0);
	ret2 = ft_printf("%#o\n", 0);
	printf("Them: %d\nMe:  %d\n\n", ret1, ret2);

	ret1 = printf("%.o\n", 0);
	ret2 = ft_printf("%.o\n", 0);
	printf("Them: %d\nMe:  %d\n\n", ret1, ret2);

	ret1 = printf("%#.o\n", 0);
	ret2 = ft_printf("%#.o\n", 0);
	printf("Them: %d\nMe:  %d\n\n", ret1, ret2);

	ret1 = printf("{%03.2d}\n", 0);
	ret2 = ft_printf("{%03.2d}\n", 0);
	printf("Them: %d\nMe:  %d\n\n", ret1, ret2);

	ret1 = printf("%.4S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	ret2 = ft_printf("%.4S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("Them: %d\nMe:  %d\n\n", ret1, ret2);

	ret1 = printf("{%05.s}\n", 0);
	ret2 = ft_printf("{%05.s}\n", 0);
	printf("Them: %d\nMe:  %d\n\n", ret1, ret2);


	ret1 = printf("% Zoooo\n");
	ret2 = ft_printf("% Zoooo\n");
	printf("Them: %d\nMe:  %d\n\n", ret1, ret2) ;*/


	// ft_printf("%f %e\n\n", -0.10, -0.20);

	// ft_printf("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S\n",
	// L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",
	// L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
	// ft_printf("a%Sb%sc%S\n", L"我", "42", L"猫");
}
