/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 10:34:21 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/21 15:54:29 by elagouch         ###   ########.fr       */
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
			if (grid[i][j] == 0)
				ft_putchar('.');
			else
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

// Put a character on the grid
void	get_xy(unsigned int xy[2], unsigned int index, unsigned int x)
{
	unsigned int	fake_x;

	fake_x = x - 2;
	if (index < fake_x)
	// Top
	{
		xy[0] = 0;
		xy[1] = 1 + index;
		return ;
	}
	if (index < (fake_x * 2))
	// Bot
	{
		xy[0] = x - 1;
		xy[1] = (index % fake_x) + 1;
		return ;
	}
	if (index < (fake_x * 3))
	// Left
	{
		xy[0] = (index % fake_x) + 1;
		xy[1] = 0;
		return ;
	}
	// Right
	xy[0] = (index % fake_x) + 1;
	xy[1] = x - 1;
	return ;
}

// Read the grid values from string
void	read_grid(char *str, unsigned int **grid, unsigned int x)
{
	unsigned int	i;
	unsigned int	index;
	unsigned int	xy[2];

	i = 0;
	index = 0;
	while(str[i] != '\0')
	{
		get_xy(xy, index, x);
		if (str[i] >= '0' && str[i] <= '9')
		{
			grid[xy[0]][xy[1]] = str[i] - '0';
			index++;
		}
		i++;
	}
}

