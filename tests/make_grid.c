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
unsigned int **make_grid(unsigned int x);
void show_grid(unsigned int **grid, unsigned int x);
void read_grid(char *str, unsigned int **grid, unsigned int x);
unsigned int read_grid_axis_size(char *str);
void ft_putstr(char *str);

void populate(unsigned int **grid, unsigned int x)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (i <= x)
	{
		j = 0;
		while (j <= x)
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

int main(void)
{
	unsigned int **grid;
	int x;
	char *entry;

	//       |up   | |down | |left | |right|
	entry = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
	x = read_grid_axis_size(entry);
	grid = make_grid(x + 2);

	show_grid(grid, x + 2);
	// populate(grid, x);	// debug

	read_grid(entry, grid, x + 2);
	ft_putstr("\n");
	show_grid(grid, x + 2);
}

// NE PAS OUBLIER LE FREE PAR PITIE
// ET TESTER VALGRIND
