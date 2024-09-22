/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 12:58:00 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/22 13:06:04 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	get_magic(unsigned int size)
{
	if (size == 1)
		return (1);
	return (get_magic(size - 1) + size);
}

// Checks for the solution
// Returns 1 if bad, 0 otherwise
unsigned int	check(unsigned int **grid, unsigned int size, unsigned int magic)
{
	unsigned int	countX;
	unsigned int	countY;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i <= size)
	{
		while (j <= size)
		{
			countX += grid[i][j];
			countY += grid[j][i];
			j++;
		}
		if (countX != magic || countY != magic)
			return (1);
		i++;
	}
	return (0);
}
