/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:14:54 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/22 14:30:30 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Prototypes :-)
unsigned int	**make_grid(unsigned int size);

// Duplicate a grid
unsigned int	**ft_dupe(unsigned int **grid, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	**duped;

	duped = make_grid(size);
	i = 0;
	while(i < size)
	{
		j = 0;
		while(j < size)
		{
			duped[i][j] = grid[i][j];
			j++;
		}
		i++;
	}
	return (duped);
}
