/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 12:26:36 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/05/29 14:52:28 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "nessasarry.h"

void	generate(char *argv)
{
	int		row;
	char	**a;

	row = 0;
	a = (char **) malloc (4 * sizeof (char *));
	while (row < 4)
	{
		a[row] = (char *) malloc (5 * sizeof (char));
		row++;
	}
	if (runtest(a, argv, -1, -1) == 1)
	{
		printarray(a);
		row = 0;
		while (row < 4)
		{
			free(a[row]);
			row++;
		}
		free(a);
	}
	else
		write(1, "Error\n", 5);
}

void	printarray(char **a)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (row < 4)
	{
		while (col < 4)
		{
			write(1, &a[row][col], 1);
			write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		col = 0;
		row++;
	}
}

char	**rando1half(int frow, int srow, char **a)
{
	char	**pos;
	int		row;

	row = 0;
	pos = (char **) malloc (24 * sizeof (char *));
	while (row < 24)
	{
		pos[row] = (char *) malloc (5 * sizeof (char));
		row++;
	}
	fuckyounorminette(pos);
	a[0] = pos[frow];
	a[1] = pos[srow];
	return (a);
}

char	**rando2half(int trow, int forow, char **a)
{
	char	**pos;
	int		row;

	row = 0;
	pos = (char **) malloc (24 * sizeof (char *));
	while (row < 24)
	{
		pos[row] = (char *) malloc (5 * sizeof (char));
		row++;
	}
	fuckyounorminette(pos);
	a[2] = pos[trow];
	a[3] = pos[forow];
	return (a);
}

int	runtest(char **e, char *argv, int c, int d)
{
	int	a;
	int	b;

	b = -1;
	a = -1;
	while (++a != 24)
	{
		while (++b != 24)
		{
			while (++c != 24)
			{
				while (++d != 24)
				{
					rando1half(a, b, e);
					rando2half(c, d, e);
					if (logic(e, argv) == 1)
						return (1);
				}
				d = -1;
			}
			c = -1;
		}
		b = -1;
	}
	return (a);
}
