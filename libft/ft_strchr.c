/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:15:10 by albagar4          #+#    #+#             */
/*   Updated: 2023/04/25 16:37:25 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)&(s[i]));
		else
			i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (0);
}

/*int	main(void)
{
	char	s[] = "ayuda me están matando";
	int		c = 'z';

	ft_strchr(s, c);
	strchr(s, c);
	printf("ft_strchr found %c here: %p\n", c, ft_strchr(s, c));
	printf("strchr found %c here: %p\n", c, strchr(s, c));
	return (0);
}*/
