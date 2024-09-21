/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:27:52 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/21 11:51:33 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// Prototypes :-)
// void	make_grid(unsigned int **grid, unsigned int x);
unsigned int	**make_grid(unsigned int x);
void	show_grid(unsigned int **grid, unsigned int x);

void	populate(unsigned int **grid, unsigned int x)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while(i <= x)
	{
		j = 0;
		while(j <= x)
		{
			// printf("### test\n");
			// printf("i: %d, j: %d\n", i, j);
			// printf("val: %d\n", grid[i][j]);
			grid[i][j] = 3;
			// printf("YES C BON\n");
			j++;
		}
		i++;
	}
}

int	main(void)
{
	unsigned int	**grid;
	int	x;

	x = 5;
	grid = make_grid(x);
	populate(grid, x);
	show_grid(grid, x);
}
