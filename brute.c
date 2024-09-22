/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:08:02 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/22 16:15:37 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Prototypes :-)
unsigned int	ft_pow(const unsigned int x, const unsigned int y);
unsigned int	**ft_dupe(unsigned int **grid, unsigned int size);
unsigned int	ft_check(unsigned int **grid, unsigned int size, unsigned int magic);
void	show_grid(unsigned int **grid, unsigned int size);
void	ft_putstr(char *str);

#include <stdio.h> // ;aigdoiuadbliasdbnliuasbdasd

// Don't touc; it works!
unsigned int	brute_count_unknown(unsigned int **grid, unsigned int size)
{
	unsigned int	count;
	unsigned int	i;
	unsigned int	j;

	i = 1;
	count = 0;
	while (i <= size - 2)
	{
		j = 1;
		while(j <= size - 2)
		{
			if (grid[i][j] == 0)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

// Returns:  1 when at least a value changed
unsigned int	brute_set(unsigned int **grid, unsigned int size, unsigned int try, unsigned int box)
{
	unsigned int	i;
	unsigned int	j;

	(void) try;
	(void) box;

	i = 1;
	while (i < size - 1)
	{
		j = 1;
		while (j < size - 1)
		{
			if (grid[i][j] == 0)
			{
				// a = (n % 1000) / 100;
				// b = (n % 100 ) / 10;
				// c = (n % 10  ) / 1;
				// printf("x: %d, y: %d\n", i, j);
				// printf("%d\n", (try % ft_pow(size, box + 1)) / ft_pow(size, box));

				grid[i][j] = ((try % ft_pow(size, box + 1)) / ft_pow(size, box)) % (size - 2);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

unsigned int	brute_try(unsigned int **grid, unsigned int size, unsigned int magic)
{
	unsigned int	**duped;
	unsigned int	box;
	unsigned int	try;
	unsigned int	n;

	n = brute_count_unknown(grid, size);
	try = 0;
	// printf("pow: %d\n", ft_pow(size - 2, n));
	while (try <= ft_pow(size - 2, n))
	{
		duped = ft_dupe(grid, size);
		box = 0;
		while (box <= n)
		{
			if (brute_set(duped, size, try, box))
			{
				show_grid(duped, size);
			}
			box++;
		}
		if (!ft_check(duped, size, magic))
		{
			ft_putstr("SOLUTION !!!!!!!!!!!\n");
			show_grid(duped, size);
			ft_putstr("SOLUTION !!!!!!!!!!!\n");
			return (1);
		}
		try++;
	}
	return (0);
}
