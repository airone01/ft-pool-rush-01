/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:27:52 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/22 14:35:44 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Prototypes :-)
// void	make_grid(unsigned int **grid, unsigned int size);
unsigned int	**make_grid(unsigned int size);
unsigned int	read_grid_axis_size(char *str);
unsigned int	solve_max(unsigned int **grid, unsigned int size);
unsigned int	solve_min(unsigned int **grid, unsigned int size);
unsigned int	get_magic(unsigned int size);
unsigned int	brute_try(unsigned int **grid, unsigned int size, unsigned int magic);
void	show_grid(unsigned int **grid, unsigned int size);
void	read_grid(char *str, unsigned int **grid, unsigned int size);
void	ft_putstr(char *str);

int main(void)
{
	unsigned int	**grid;
	unsigned int	magic;
	int				size;
	char				*entry;

	//       |up   | |down | |left | |right|
	entry = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"; // Original
	// entry = "8 3 2 1 8 2 2 2 8 3 2 1 1 2 2 2 8 3 2 1 1 2 2 2 8 3 2 1 1 2 2 2";
	size = read_grid_axis_size(entry) + 2;
	magic = get_magic(size);
	grid = make_grid(size);

	// show_grid(grid, size);
	// populate(grid, size);	// debug

	read_grid(entry, grid, size);
	// show_grid(grid, size);

	// Solve maybe half of the thing already
	if (solve_max(grid, size) || solve_min(grid, size))
	{
		ft_putstr("Error\n");
		return (1);
	}

	// Brute-force our way into a solution
	if (!brute_try(grid, size, magic))
	{
		ft_putstr("Error\n");
		return (1);
	}
	// show_grid(grid, size);
}

// NE PAS OUBLIER LE FREE PAR PITIE
// ET TESTER VALGRIND
// ET CHANGER LES COMMITS
// ET METTRE LE PROTO DANS LE MAIN PRINCIPAL
