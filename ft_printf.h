/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:34:17 by albagar4          #+#    #+#             */
/*   Updated: 2023/06/22 20:17:06 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_flags {
	int	hash;
	int	zero;
	int	plus;
	int	minus;
	int	space;
	int	width;
}	t_flags;

int	ft_print_char(char c);
int	ft_print_str(char *str);
int	ft_print_hex_lower(unsigned long long nbr);
int	ft_print_ptr(unsigned long long ptr);
int	ft_phlower_bonus(int n, t_flags *flags);
int	ft_phupper_bonus(int n, t_flags *flags);
int	ft_pnbr_bonus(int n, t_flags *flags);
int	ft_print_unsigned(unsigned int nbr);
#endif
