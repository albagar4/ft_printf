/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:14:51 by albagar4          #+#    #+#             */
/*   Updated: 2023/06/19 12:53:38 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	static_ft_putchar(char c)
{
	write(1, &c, 1);
}

int	static_hex_conversion(int nbr)
{
	char	*base;
	int		cpy;

	base = "0123456789abcdef";
	cpy = nbr;
	if (nbr < 0)
		return (0);
	else if (nbr >= 0 && nbr <= 15)
		static_ft_putchar(base[nbr]);
	else
	{
		nbr = nbr / 16;
		static_ft_putchar(base[nbr]);
		nbr = cpy;
		static_hex_conversion(nbr);
	}
}

/*int	ft_print_ptr(unsigned long long ptr)
{
	
}*/

int	main(void)
{
	static_hex_conversion(95);
	return (0);
}
