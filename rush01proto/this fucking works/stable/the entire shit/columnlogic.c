/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   columnlogic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 12:26:24 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/05/29 12:26:25 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	con_cold(char **a, int col, char argv)
{
	int		countrow;
	int		comparerow;
	char	cansee;

	countrow = 3;
	comparerow = 2;
	cansee = '1';
	while (comparerow >= 0)
	{
		if (a[countrow][col] == '4')
			break ;
		if (a[countrow][col] < a[comparerow][col])
		{
			countrow = comparerow;
			cansee++ ;
		}
		comparerow-- ;
	}
	if (cansee == argv)
		return (1);
	return (0);
}

int	con_colu(char **a, int col, char argv)
{
	int		countrow;
	int		comparerow;
	char	cansee;

	comparerow = 1;
	countrow = 0;
	cansee = '1';
	while (comparerow <= 3)
	{
		if (a[countrow][col] == '4')
			break ;
		if (a[countrow][col] < a[comparerow][col])
		{
			countrow = comparerow;
			cansee++;
		}
		comparerow++;
	}
	if (cansee == argv)
		return (1);
	return (0);
}

int	con_col(char **a, char *argv)
{
	int	i;
	int	countcol;

	countcol = 0;
	i = 0;
	while (i <= 6)
	{
		if ((con_colu(a, countcol, argv[i])) == 0)
			return (0);
		countcol++;
		i += 2;
	}
	countcol = 0;
	while (i <= 14)
	{
		if ((con_cold(a, countcol, argv[i])) == 0)
			return (0);
		countcol++;
		i += 2;
	}
	return (1);
}
