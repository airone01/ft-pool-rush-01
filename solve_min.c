/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_min.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:20:11 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/22 10:37:53 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// Prototypes :-)
void	get_xy(unsigned int xy[2], unsigned int index, unsigned int size);

// Solves one uint depending on the where we currently are
// Returns 1 if something was changed, 0 otherwise.
void	solve_min_xy_cond(unsigned int xy[2], unsigned int **grid, unsigned int size)
{
	// Up
	if (xy[0] == 0)
		grid[1][xy[1]] = size - 2;
	// Down
	if (xy[0] == size - 1)
		grid[size -2][xy[1]] = size - 2;
	// Left
	if (xy[1] == 0)
		grid[xy[0]][1] = size - 2;
	// Right
	if (xy[1] == size - 1)
		grid[xy[0]][size - 2] = size - 2;
}

// After a min number (1) is hit, this function loops through the table to
// set the all the buildings in the corresponding line/row by calling
// solve_min_xy_cond.
// E.g.
// x-1---?---?---?-x
// | . . . . . . . |
// 1 4 . ? . ? . ? ?
// | . . . . . . . |
// ? ? . ? . ? . ? ?
// | . . . . . . . |
// ? ? . ? . ? . ? ?
// | . . . . . . . |
// ? ? . ? . ? . ? ?
// | . . . . . . . |
// x-?---?---?---?-x
void	solve_min_xy(unsigned int xy[2], unsigned int **grid, unsigned int size)
{
	if (grid[xy[0]][xy[1]] == 1)
	{
		solve_min_xy_cond(xy, grid, size);
	}
}

// Calls solve_min_xy on every uint of the hints.
void	solve_min(unsigned int **grid, unsigned int size)
{
	unsigned int	xy[2];
	unsigned int	i;

	i = 0;
	while (i < size * 4)
	{
		get_xy(xy, i, size);
		solve_min_xy(xy, grid, size);
		i++;
	}
}
