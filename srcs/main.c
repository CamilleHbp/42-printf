/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 14:06:57 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/02 17:49:44 by cbaillat         ###   ########.fr       */
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
	int		arg6 = 0b1010;
	int		arg7 = 010;
	int		arg8 = 0xF;
	double	arg9 = -0.1212;

	setlocale(LC_ALL, "en_US.utf8");
	printf   ("Them: \n \
		string:  |%-10.2s|\n \
		char:    |%2c|\n \
		int:     |%-6.4d|\n \
		wstring: |%-20S|\n \
		wchar:   |%12C|\n \
		octal:   |%#10o|\n \
		hexa:    |%#040X|\n \
		double:  |%020f|\n \
		scient:  |%e|\n\n", \
			arg1, arg2, arg3, arg4, arg5, arg7, arg8, arg9, arg9);
	ft_printf   ("Me  : \n \
		string:  |%-10.2s|\n \
		char:    |%2c|\n \
		int:     |%-6.4d|\n \
		wstring: |%-20S|\n \
		wchar:   |%12C|\n \
		binary:  |%#-10b|\n \
		octal:   |%#10o|\n \
		hexa:    |%#040X|\n \
		double:  |%020f|\n \
		scient:  |%e|\n\n", \
			arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg9);
}
