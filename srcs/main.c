/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 14:06:57 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/02 19:54:39 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <locale.h>
#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	char	*arg1 = "Test this.";
	char	arg2 = 'c';
	int		arg3 = 42;
	wchar_t	*arg4 = L"◀▣▶ἀἐἠ";
	wchar_t	arg5 = L'■';
	// int		arg6 = 0b1010;
	int		arg7 = 010;
	int		width = 20;
	int		arg8 = 0xF;
	double	arg9 = -10;
	double	arg10 = 0.7;
	int		them = 0;
	int		me = 0;

	setlocale(LC_ALL, "en_US.utf8");
	printf   ("Them: \n \
		string:  |%-10.2s|\n \
		char:    |%2c|\n \
		int:     |%-6.4d|\n \
		wstring: |%-20S|\n \
		wchar:   |%12C|\n \
		octal:   |%#10o|\n \
		hexa:    |%#0*X|\n \
		double:  |%#020f|\n \
		scient:  |%.e|\n \
		hexscien:|%0.A|\n \
		ptr:     |%p|\n \
		written: |%n|\n\n", \
			arg1, arg2, arg3, arg4, arg5, arg7, width, arg8, arg9, arg9, arg10, &arg10, &them);
	ft_printf   ("Me  : \n \
		string:  |%-10.2s|\n \
		char:    |%2c|\n \
		int:     |%-6.4d|\n \
		wstring: |%-20S|\n \
		wchar:   |%12C|\n \
		octal:   |%#10o|\n \
		hexa:    |%#0*X|\n \
		double:  |%#020f|\n \
		scient:  |%.e|\n \
		hexscien:|%0.A|\n \
		ptr:     |%p|\n \
		written: |%n|\n\n", \
			arg1, arg2, arg3, arg4, arg5, arg7, width, arg8, arg9, arg9, arg10, &arg10, &me);

	printf("Written them: %d\n", them);
	printf("Written me: %d\n", me);
}

		// binary:  |%#-10b|\n
			// arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg9, arg10, &arg10);
