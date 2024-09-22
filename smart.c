/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:14:25 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/22 13:37:44 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	get_xy(unsigned int xy[2], unsigned int index, unsigned int size);

void	solve_compass_2(unsigned int **grid, unsigned int size)
{
	unsigned int	xy[2];
	unsigned int	i;

	i = 0;
	while (i <= size * size)
	{
		xy = get_xy(xy, index, size);
		if (xy[0] == 0 && grid[xy[0]][xy[1]] == 2)
		{
			grid[xy[0] - 1][xy[1]] = size - 1;
			grid[xy[0] - 1][xy[1]] = size;
		}
		if (xy[0] == (size - 1) && grid[xy[0]][xy[1]] == 2)
		{
		}
		if (xy[1] == 0 && grid[xy[0]][xy[1]] == 2)
		{
		}
		if (xy[1] == (size - 1) && grid[xy[0]][xy[1]] == 2)
		{
		}
	}
}
