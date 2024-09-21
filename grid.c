/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 10:34:21 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/21 11:54:04 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// Prototypes :-)
void    ft_putchar(char c);

// Read the size of one axis (X or Y) of the grid from string
unsigned int	read_grid_axis_size(char *str)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			len++;
		i++;
	}
	return ((len + 1) / 4);
}

// unsigned int	make_grid(unsigned int **grid, unsigned int x)
unsigned int	**make_grid(unsigned int x)
{
	unsigned int	**grid;
	unsigned int	i;

	grid = malloc(x * (x * sizeof(unsigned int)));
	i = 0;
	while (i <= x)
	{
		grid[i] = malloc(x * sizeof(unsigned int));
		i++;
	}
	return (grid);
}

// Show the grid (lol)
void	show_grid(unsigned int **grid, unsigned int x)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while(i < x)
	{
		j = 0;
		while(j < x)
		{
			ft_putchar(grid[i][j] + '0');
			if (j < x - 1)
				ft_putchar(' ');
			j++;
		}
		if (i < x - 1)
			ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}

// Read the grid values from string
// void	read_grid(char *str)
// {
// 	int	i;
//
// 	i = 0;
// 	while(str[i] != '\0')
// 	{
// 	}
// }

