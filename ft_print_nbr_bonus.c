/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:54:47 by albagar4          #+#    #+#             */
/*   Updated: 2023/06/22 20:15:03 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_nbrb(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		ft_print_str("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		ft_print_char('-');
		count++;
		n = -n;
	}
	if (n >= 10)
		count += ft_print_nbrb(n / 10);
	ft_print_char(n % 10 + '0');
	count++;
	return (count);
}

int	ft_pnbr_bonus(int n, t_flags *flags)
{
	int	count;

	count = 0;
	if (n > 0)
	{
		if (flags->plus == 1)
			ft_print_char('+');
		else if (flags->space == 1)
			ft_print_char(' ');
		count = 1;
	}
	count += ft_print_nbrb(n);
	return (count);
}
