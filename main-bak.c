/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main-bak.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 14:06:57 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/04 18:10:26 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <locale.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
	// char	*arg1 = "abc";
	int		arg2 = -15;
	char	arg3 = 42;
	// unsigned long	arg3 = ULONG_MAX;
	// wchar_t *arg4 = L"ÊM-^ZM-^VÁM-^BM-^I";
	// wchar_t *arg5 = L"ŸM-^Dÿ≠ŸM-^E ÿÆŸM-^Fÿ≤ŸM-ÿ±";
	/* wchar_t	*arg4 = L"◀▣▶ἀἐἠ";
	wchar_t	arg5 = L'■';
	// int		arg6 = 0b1010;
	int		arg7 = 010;
	int		width = 20;
	int		arg8 = 0xF;
	long double	arg9 = -10;
	double	arg10 = 0.7;
	int		them = 0;
	int		me = 0; */

	setlocale(LC_ALL, "en_US.utf8");
	/* printf   ("Them: \n \
		string:  |%05.s|\n \
		octal:   |%05.*d|\n\n", \
			arg1, arg2, arg3);
 */
	ft_printf   ("Me: \n \
		string:  |%05.s|\n \
		octal:   |%05.*d|\n\n", \
			0, arg2, arg3);
}

/* 		wstring: |%-20S|\n \
		wchar:   |%12C|\n \
		octal:   |%#10o|\n \
		hexa:    |%#0*X|\n \
		double:  |%#020Lf|\n \
		scient:  |%.Le|\n \
		hexscien:|%0.A|\n \
		ptr:     |%p|\n \
		written: |%n|\n\n", \
			arg1, arg2, arg3, arg4, arg5, arg7, width, arg8, arg9, arg9, arg10, &arg10, &them) */;

/*
	ft_printf   ("Me  : \n \
		string:  |%-10.2s|\n \
		char:    |%2c|\n \
		int:     |%-6.4d|\n \
		wstring: |%-20S|\n \
		wchar:   |%12C|\n \
		octal:   |%#10o|\n \
		hexa:    |%#0*X|\n \
		double:  |%#020Lf|\n \
		scient:  |%.Le|\n \
		hexscien:|%0.A|\n \
		ptr:     |%p|\n \
		written: |%n|\n\n", \
			arg1, arg2, arg3, arg4, arg5, arg7, width, arg8, arg9, arg9, arg10, &arg10, &me);

	printf("Written them: %d\n", them);
	printf("Written me: %d\n", me);
}*/

		// binary:  |%#-10b|\n
			// arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg9, arg10, &arg10);
