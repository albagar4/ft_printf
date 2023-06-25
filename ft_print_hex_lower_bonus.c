/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_lower_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:19:27 by albagar4          #+#    #+#             */
/*   Updated: 2023/06/22 20:14:55 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_lowerb(unsigned long long nbr)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (nbr < 0)
		return (0);
	else if (nbr >= 0 && nbr <= 15)
		count += ft_print_char(base[nbr]);
	else
	{
		count += ft_print_hex_lowerb(nbr / 16);
		count += ft_print_char(base[nbr % 16]);
	}
	return (count);
}

int	ft_phlower_bonus(int n, t_flags *flags)
{
	int	count;

	count = 0;
	if (n > 0)
	{
		if (flags->hash == 1)
			ft_print_str("0x");
		count = 1;
	}
	count += ft_print_hex_lowerb(n);
	return (count);
}
