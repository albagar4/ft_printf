/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:34:08 by albagar4          #+#    #+#             */
/*   Updated: 2023/06/16 18:12:43 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parser(char *format, int i, va_list args)
{
	int	c;

	c = 0;
	if (format[i] == 'c')
		c = ft_print_char(va_arg(args, int));
	else if (format[i] == 's')
		c = ft_print_str(va_arg(args, char *));
/*	else if (format[i] == 'p')
	else if (format[i] == 'd') */
	return (c);
}

int	ft_printf(char *format, ...)
{
	va_list		args;
	int			i;
	int			count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			count++;
		}
		else
		{
			i++;
			count += ft_parser(format, i, args);
		}
		i++;
	}
	return (count);
}

int	main(int argc, char **argv)
{
	(void) argc;
	ft_printf("a alba le gusta solo %s\n", argv[1]);
}
