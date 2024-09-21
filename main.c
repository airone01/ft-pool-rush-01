/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 10:22:31 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/21 11:28:28 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Prototypes :-)
unsigned int	read_grid_axis_size(char *str);

int	main(int argc, char **argv)
{
	resolve(argv[1]);
}

void	resolve(char *str)
{
	unsigned int	x;
	unsigned int	**grid;

	x = read_grid_axis_size(str);
	make_grid(grid, x + 2);
}
