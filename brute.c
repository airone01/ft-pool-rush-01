/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:08:02 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/22 15:38:41 by elagouch         ###   ########.fr       */
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
			printf("x: %d, y: %d\n", i, j);
			if (grid[i][j] == 0)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

// Returns:  1 when at least a value changed
unsigned int	brute_set(unsigned int **grid, unsigned int size, unsigned int z, unsigned int count)
{
	unsigned int	i;
	unsigned int	j;

	i = 1;
	while (i <= size - 2)
	{
		j = 1;
		while (j <= size - 2)
		{
			if (grid[i][j] == 0)
			{
				// a = (n % 1000) / 100;
				// b = (n % 100 ) / 10;
				// c = (n % 10  ) / 1;
				printf("%d\n", z);
				// printf("x: %d, y: %d, val: %d\n", i, j, (z % ft_pow(size, count + 1)) / ft_pow(size, count + 1));
				grid[i][j] = (z % ft_pow(size, count + 1)) / ft_pow(size, count + 1);
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
	unsigned int	count;
	unsigned int	j;
	unsigned int	n;

	n = brute_count_unknown(grid, size);
	j = 0;
	count = 0;
	printf("n: %d\n", n);
	while (j <= ft_pow(size, n))
	{
		while (count <= n)
		{
			duped = ft_dupe(grid, size);
			if (brute_set(duped, size, j, count))
			{
				show_grid(duped, size);
			}
			if (!ft_check(duped, size, magic))
			{
				ft_putstr("SOLUTION !!!!!!!!!!!\n");
				show_grid(duped, size);
				ft_putstr("SOLUTION !!!!!!!!!!!\n");
				return (1);
			}
			count++;
		}
		j++;
	}
	return (0);
}
