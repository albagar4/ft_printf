/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:34:08 by albagar4          #+#    #+#             */
/*   Updated: 2023/06/23 14:33:33 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parserb(char *format, int i, va_list args, t_flags *flags)
{
	int	c;

	c = 0;
	if (format[i] == 'c')
		c = ft_print_char(va_arg(args, int));
	else if (format[i] == 's')
		c = ft_print_str(va_arg(args, char *));
	else if (format[i] == 'p')
		c = ft_print_ptr(va_arg(args, unsigned long long));
	else if (format[i] == 'd' || format[i] == 'i')
		c = ft_pnbr_bonus(va_arg(args, int), flags);
	else if (format[i] == 'u')
		c = ft_print_unsigned(va_arg(args, unsigned int));
	else if (format[i] == '%')
		c = ft_print_char('%');
	else if (format[i] == 'x')
		c = ft_phlower_bonus(va_arg(args, unsigned int), flags);
	else if (format[i] == 'X')
		c = ft_phupper_bonus(va_arg(args, unsigned int), flags);
	return (c);
}

int	ft_bonus_parser(char *format, int i, t_flags *flags)
{
	while (format[i] == '+' || format[i] == ' ' || format[i] == '#'
		|| format[i] == '-' || format[i] == '0' || format[i] == '.')
	{
		if (format[i] == '+')
			flags->plus = 1;
		else if (format[i] == ' ')
			flags->space = 1;
		else if (format[i] == '#')
			flags->hash = 1;
		else if (format[i] == '-')
			flags->minus = 1;
		else if (format[i] == '0')
			flags->zero = 1;
		else if (format[i] == '.')
			flags->width = 1;
		i++;
	}
	return (i);
}

void	ft_bonus_initializer(t_flags *flags)
{
	flags->plus = 0;
	flags->space = 0;
	flags->hash = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->width = 0;
}

int	ft_passtr(char *format, t_flags *flags, va_list args)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			ft_bonus_initializer(flags);
			if (format[i] == '+' || format[i] == ' ' || format[i] == '#'
				|| format[i] == '-' || format[i] == '0' || format[i] == '.')
				i = ft_bonus_parser(format, i, flags);
			count += ft_parserb(format, i, args, flags);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_printf(char *format, ...)
{
	va_list		args;
	int			count;
	t_flags		*flags;

	count = 0;
	flags = (t_flags *)malloc(sizeof(t_flags));
	if (!flags)
		return (-1);
	va_start(args, format);
	return (ft_passtr(format, flags, args));
}
