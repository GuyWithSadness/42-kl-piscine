/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 12:26:44 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/05/29 12:26:45 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nessasarry.h"

int	duplicatecol(char **a)
{
	int	row;
	int	rowcompare;
	int	col;

	row = 0;
	rowcompare = 1;
	col = 0;
	while (col < 4)
	{
		while (row < 3)
		{
			while (rowcompare < 4)
			{
				if (a[row][col] == a[rowcompare++][col])
					return (1);
			}
			row++;
			rowcompare = row + 1;
		}
		col++;
		row = 0;
		rowcompare = 1;
	}
	return (0);
}

int	logic(char **a, char *argc)
{
	if (duplicatecol(a) == 1)
		return (0);
	if (con_row(a, argc) == 0)
		return (0);
	if (con_col(a, argc) == 0)
		return (0);
	return (1);
}
