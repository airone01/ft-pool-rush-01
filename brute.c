/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:08:02 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/22 19:22:22 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

#include <stdio.h> // ;aigdoiuadbliasdbnliuasbdasd

const unsigned int tries[24] = {
	1234,
	1243,
	1324,
	1342,
	1423,
	1432,
	2134,
	2143,
	2314,
	2341,
	2413,
	2431,
	3124,
	3142,
	3214,
	3241,
	3412,
	3421,
	4123,
	4132,
	4213,
	4231,
	4312,
	4321
};

// Returns:  1 when at least a value changed
unsigned int	brute_set(unsigned int try, unsigned int **grid, unsigned int size, unsigned int magic)
{
	unsigned int	i;

	i = 1;
	while (i < size - 1)
	{
		// Satan
		if ((grid[i][1] == 0 || grid[i][1] == try / 1000) &&
			(grid[i][2] == 0 || grid[i][2] == (try / 100) % 100) &&
			(grid[i][3] == 0 || grid[i][3] == (try / 10) % 10) &&
			(grid[i][4] == 0 || grid[i][4] == try % 10))
		{
			grid[i][1] = try / 1000;
			grid[i][2] = (try / 100) % 10;
			grid[i][3] = (try / 10) % 10;
			grid[i][4] = try % 10;
			// printf("%d\n", (try / 10) % 10);
			printf("%d%d%d%d\n", grid[i][1], grid[i][2], grid[i][3], grid[i][4]);
			// show_grid(grid, size);
			if (!grid_check(grid, size, magic))
				printf("YEEEEEEEEEEEEES\n");
			return (1);
		}
		i++;
	}
	return (0);
}

unsigned int	brute_try(unsigned int **grid, unsigned int size, unsigned int magic)
{
	unsigned int	i;
	unsigned int	**duped;

	i = 0;
	while (i < 24)
	{
		duped = grid_dupe(grid, size);
		brute_set(tries[i], duped, size, magic);
		show_grid(duped, size);
		i++;
	}
	return (0);
}
