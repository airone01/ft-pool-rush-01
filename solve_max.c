/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_max.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:20:11 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/22 10:16:53 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// Prototypes :-)
void	get_xy(unsigned int xy[2], unsigned int index, unsigned int x);

// Solves one uint depending on the where we currently are
// Returns 1 if something was changed, 0 otherwise.
void	solve_max_xy_cond(unsigned int xy[2], unsigned int **grid, unsigned int x, unsigned int j)
{
	// Up
	if (xy[0] == 0)
		grid[j][xy[1]] = j;
	// Down
	if (xy[0] == x - 1)
		grid[x - 1 -j][xy[1]] = j;
	// Left
	if (xy[1] == 0)
		grid[xy[0]][j] = j;
	// Right
	if (xy[1] == x - 1)
		grid[xy[0]][x - 1 - j] = j;
}

// After a max number (n) is hit, this function loops through the table to
// set the all the buildings in the corresponding line/row by calling
// solve_max_xy_cond.
// E.g.
// x-4---?---?---?-x
// | . . . . . . . |
// 4 1 . 2 . 3 . 4 ?
// | . . . . . . . |
// ? 2 . ? . ? . ? ?
// | . . . . . . . |
// ? 3 . ? . ? . ? ?
// | . . . . . . . |
// ? 4 . ? . ? . ? ?
// | . . . . . . . |
// x-?---?---?---?-x
void	solve_max_xy(unsigned int xy[2], unsigned int **grid, unsigned int x)
{
	unsigned int	j;
	unsigned int	fake_x;

	fake_x = x - 2;
	if (grid[xy[0]][xy[1]] == fake_x)
	{
		j = 1;
		while (j < fake_x + 1)
		{
			solve_max_xy_cond(xy, grid, x, j);
			j++;
		}
	}
}

// Calls solve_max_xy on every uint of the hints.
void	solve_max(unsigned int **grid, unsigned int x)
{
	unsigned int	xy[2];
	unsigned int	i;

	i = 0;
	while (i < x * 4)
	{
		get_xy(xy, i, x);
		solve_max_xy(xy, grid, x);
		i++;
	}
}
