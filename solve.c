/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:20:11 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/21 16:11:12 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	get_xy(unsigned int xy[2], unsigned int index, unsigned int x);

void	solve_max_xy(unsigned int xy[2], unsigned int **grid, unsigned int x)
{
	unsigned int	j;
	unsigned int	fake_x;

	fake_x = x - 2;
	// First line
	if (xy[0] == 0)
	{
		if (grid[xy[0]][xy[1]] == fake_x)
		{
			// Explication:
			// Si il trouve sur la premiere ligne un X
			// alors la col est x, x-1, etc...
			j = 1;
			while (j < fake_x + 1)
			{
				grid[j][xy[1]] = j;
				j++;
			}
		}
		return ;
	}
	// Last line
	if (xy[0] == x - 1)
	{
		if (grid[xy[0]][xy[1]] == fake_x)
		{
			// Explication:
			// Si il trouve sur la premiere ligne un X
			// alors la col est x, x-1, etc...
			j = 1;
			while (j < fake_x + 1)
			{
				grid[x - 1 -j][xy[1]] = j;
				j++;
			}
		}
		return ;
	}
}

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
