/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rowlogic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 12:27:10 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/05/29 12:27:11 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	con_rowl(char **a, int row, char argv)
{
	int		countcol;
	int		comparecol;
	char	cansee;

	countcol = 0;
	comparecol = 1;
	cansee = '1';
	while (comparecol <= 3)
	{
		if (a[row][countcol] == '4')
			break ;
		if (a[row][countcol] < a[row][comparecol])
		{
			cansee++;
			countcol = comparecol;
		}
		comparecol++;
	}
	if (cansee == argv)
		return (1);
	return (0);
}

int	con_rowr(char **a, int row, char argv)
{
	int		countcol;
	int		comparecol;
	char	cansee;

	countcol = 3;
	comparecol = 2;
	cansee = '1';
	while (comparecol >= 0)
	{
		if (a[row][countcol] == '4')
			break ;
		if (a[row][countcol] < a[row][comparecol])
		{
			cansee++;
			countcol = comparecol;
		}
		comparecol--;
	}
	if (cansee == argv)
		return (1);
	return (0);
}

int	con_row(char **a, char *argv)
{
	int	i;
	int	countrow;

	countrow = 0;
	i = 16;
	while (i <= 22)
	{
		if ((con_rowl(a, countrow, argv[i])) == 0)
			return (0);
		countrow++;
		i += 2;
	}
	countrow = 0;
	while (i <= 30)
	{
		if ((con_rowr(a, countrow, argv[i])) == 0)
			return (0);
		countrow++;
		i += 2;
	}
	return (1);
}
