/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_min.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:20:11 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/22 10:43:35 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Prototypes :-)
void	get_xy(unsigned int xy[2], unsigned int index, unsigned int size);

// After a min number (1) is hit, this function loops through the table to
// set the all the buildings in the corresponding line/row.
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
void	solve_min(unsigned int **grid, unsigned int size)
{
	unsigned int	xy[2];
	unsigned int	i;

	i = 0;
	while (i < size * 4)
	{
		get_xy(xy, i, size);
		if (grid[xy[0]][xy[1]] == 1)
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
		i++;
	}
}
