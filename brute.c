/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:08:02 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/22 18:08:07 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

#include <stdio.h> // ;aigdoiuadbliasdbnliuasbdasd

// Returns:  1 when at least a value changed
unsigned int	brute_set(unsigned int **grid, unsigned int size, unsigned int magic, unsigned int *abcd)
{
	unsigned int	i;

	i = 1;
	while (i < size - 1)
	{
		// Satan
		if ((grid[i][1] == 0 || grid[i][1] == abcd[0]) &&
			(grid[i][2] == 0 || grid[i][2] == abcd[1]) &&
			(grid[i][3] == 0 || grid[i][3] == abcd[2]) &&
			(grid[i][4] == 0 || grid[i][4] == abcd[3]))
		{
			grid[i][1] = abcd[0];
			grid[i][2] = abcd[1];
			grid[i][3] = abcd[2];
			grid[i][4] = abcd[3];
			printf("%d%d%d%d\n", abcd[0], abcd[1], abcd[2], abcd[3]);
			// show_grid(grid, size);
			if (!ft_check(grid, size, magic))
				printf("YEEEEEEEEEEEEES\n");
			return (1);
		}
		i++;
	}
	return (0);
}

unsigned int	make_tries(unsigned int **grid, unsigned int size, unsigned int magic, unsigned int ab[2])
{
	unsigned int	abcd[4];
	unsigned int	c;
	unsigned int	d;

	c = 1;
	while (c < size - 1)
	{
		d = 1;
		while (d < size - 1)
		{
			if ((ab[0] * ab[1] * c * d) == magic)
			{
				abcd[0] = ab[0];
				abcd[1] = ab[1];
				abcd[2] = c;
				abcd[3] = d;
				brute_set(grid, size, magic, abcd);
			}
			d++;
		}
		c++;
	}
	return(0);
}

unsigned int	brute_try(unsigned int **grid, unsigned int size, unsigned int magic)
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	ab[2];

	a = 1;
	while (a < size - 1)
	{
		b = 1;
		while (b < size - 1)
		{
			ab[0] = a;
			ab[1] = b;
			make_tries(grid, size, magic, ab);
			b++;
		}
		a++;
	}
	return (0);
}
