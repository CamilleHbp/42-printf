/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 13:11:44 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/17 19:57:59 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg_print.h"
#include "stdio.h"

static void	print_flags(t_format format)
{
	uint8_t	flag_nb = 0;

	if (format.flag == NULL)
	{
		printf("No flags.\n");
		return ;
	}
	while (format.flag != NULL)
	{
		++flag_nb;
		printf ("flag %02u: ", flag_nb);
		switch (format.flag->flag) {
			case minus:
				printf("-\n");
				break ;
			case plus:
				printf("+\n");
				break ;
			case space:
				printf("space\n");
				break ;
			case pound:
				printf("#\n");
				break ;
			case zero:
				printf("0\n");
				break ;
			case flag_unknown:
				printf("unknown\n");
				break ;
			default:
				printf("error\n");
				break ;
		}
		format.flag = format.flag->next;
	}
}

static void	print_length(t_format format)
{
	printf("length: ");
	switch (format.length) {
		case hh:
			printf("hh\n");
			break ;
		case h:
			printf("h\n");
			break ;
		case l:
			printf("l\n");
			break ;
		case ll:
			printf("ll\n");
			break ;
		case j:
			printf("j\n");
			break ;
		case z:
			printf("z\n");
			break ;
		case t:
			printf("t\n");
			break ;
		case L:
			printf("L\n");
			break ;
		case length_unknown:
			printf("unknown\n");
			break ;
		default:
			printf("error\n");
			break ;
	}
}

static void	print_type(t_format format)
{
	printf("specifier type: ");
	switch (format.type) {
		case integer:
			printf("integer\n");
			break ;
		case floating_point:
			printf("floating_point\n");
			break ;
		case string:
			printf("string\n");
			break ;
		case void_ptr:
			printf("void_ptr\n");
			break ;
		case int_ptr:
			printf("int_ptr\n");
			break ;
		case type_unknown:
			printf("unknown\n");
			break ;
		default:
			printf("error\n");
			break ;
	}
}
void	print_test(t_format format)
{
	//va_arg(*app, int);
	// printf("\n----------------\n");
	print_flags(format);
	printf("width: %d\n", format.width);
	printf("precision: %u\n", format.precision);
	print_length(format);
	print_type(format);
	printf("specifier: %c\n", format.specifier);
	// printf("----------------\n");
}
