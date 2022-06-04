/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 12:26:52 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/05/29 16:41:55 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nessasarry.h"
#include <stdio.h>

int	inputcheck(char *argv);

int	main(int argc, char *argv[])
{
	if (argc == 2 && inputcheck(argv[1]) == 16)
	{
		generate(argv[1]);
		return (0);
	}
	else
	{
		write(1, "Error\n", 6);
		return (0);
	}
}

int	inputcheck(char *argv)
{
	int	i;
	int	nonumber;
	int	space;
	int	number;

	i = -1;
	nonumber = 0;
	while (argv[++i] != '\0')
	{
		if (argv[i] >= '1' && argv[i] <= '4' && number == 0)
		{
			nonumber++;
			space = 0;
			number = 1;
		}
		else if (argv[i] == ' ' && space == 0)
		{
			space = 1;
			number = 0;
		}
		else
			break ;
	}
	return (nonumber);
}
