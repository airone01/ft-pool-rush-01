/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:27:52 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/22 10:22:33 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// Prototypes :-)
// void	make_grid(unsigned int **grid, unsigned int size);
unsigned int	**make_grid(unsigned int size);
unsigned int	read_grid_axis_size(char *str);
void	show_grid(unsigned int **grid, unsigned int size);
void	read_grid(char *str, unsigned int **grid, unsigned int size);
void	solve_max(unsigned int **grid, unsigned int size);
void	ft_putstr(char *str);

int main(void)
{
	unsigned int **grid;
	int size;
	char *entry;

	//       |up   | |down | |left | |right|
	// entry = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 4";
	entry = "8 3 2 1 8 2 2 2 8 3 2 1 1 2 2 2 8 3 2 1 1 2 2 2 8 3 2 1 1 2 2 2";
	size = read_grid_axis_size(entry) + 2;
	grid = make_grid(size);

	show_grid(grid, size);
	// populate(grid, size);	// debug

	read_grid(entry, grid, size);
	ft_putstr("\n");
	show_grid(grid, size);

	solve_max(grid, size);
	ft_putstr("\n");
	show_grid(grid, size);
}

// NE PAS OUBLIER LE FREE PAR PITIE
// ET TESTER VALGRIND
// ET CHANGER LES COMMITS
// -> ET RENOMMER 'size' EN 'size'
// ET METTRE LE PROTO DANS LE MAIN PRINCIPAL
