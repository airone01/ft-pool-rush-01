/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:27:52 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/22 10:14:26 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// Prototypes :-)
// void	make_grid(unsigned int **grid, unsigned int x);
unsigned int	**make_grid(unsigned int x);
unsigned int	read_grid_axis_size(char *str);
void	show_grid(unsigned int **grid, unsigned int x);
void	read_grid(char *str, unsigned int **grid, unsigned int x);
void	solve_max(unsigned int **grid, unsigned int x);
void	ft_putstr(char *str);

// void populate(unsigned int **grid, unsigned int x)
// {
// 	unsigned int i;
// 	unsigned int j;
//
// 	i = 0;
// 	while (i <= x)
// 	{
// 		j = 0;
// 		while (j <= x)
// 		{
// 			// printf("### test\n");
// 			// printf("i: %d, j: %d\n", i, j);
// 			// printf("val: %d\n", grid[i][j]);
// 			grid[i][j] = 3;
// 			// printf("YES C BON\n");
// 			j++;
// 		}
// 		i++;
// 	}
// }

int main(void)
{
	unsigned int **grid;
	int x;
	char *entry;

	//       |up   | |down | |left | |right|
	// entry = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 4";
	entry = "8 3 2 1 8 2 2 2 8 3 2 1 1 2 2 2 8 3 2 1 1 2 2 2 8 3 2 1 1 2 2 2";
	x = read_grid_axis_size(entry) + 2;
	grid = make_grid(x);

	show_grid(grid, x);
	// populate(grid, x);	// debug

	read_grid(entry, grid, x);
	ft_putstr("\n");
	show_grid(grid, x);

	solve_max(grid, x);
	ft_putstr("\n");
	show_grid(grid, x);
}

// NE PAS OUBLIER LE FREE PAR PITIE
// ET TESTER VALGRIND
// ET CHANGER LES COMMITS
// ET RENOMMER 'x' EN 'size'
// ET METTRE LE PROTO DANS LE MAIN PRINCIPAL
