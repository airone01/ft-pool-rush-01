/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 10:24:45 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/22 13:59:31 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Put a string
void	ft_putstr(char *str)
{
	if (*str == '\0')
		return ;
	write(1, str, 1);
	ft_putstr(str + sizeof(char));
}

// Put a char
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

// Get length of string
int	ft_strlen(char *str)
{
	if (*str == '\0')
		return (0);
	return (ft_strlen(str + sizeof(char)) + 1);
}

unsigned int	ft_pow(const unsigned int x, const unsigned int y)
{
	if (y == 0)
		return (1);
	return (ft_pow(x, y - 1) + (x * x));
}
