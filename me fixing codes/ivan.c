/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:24:32 by jteoh             #+#    #+#             */
/*   Updated: 2022/06/07 11:35:07 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	if (nb >= 2147483647)
		return (0);
	else if (nb > 1)
	{
		while (nb / nb == 1 || nb / 1 == nb)
		{
			if (i == nb)
				return (1);
			else if (nb % i == 0)
				return (0);
			i++;
		}
	}
	return (0);
}

#include <stdio.h>
int main()
{
	for (int i = -10; i <= 100000; i++)
	{
		if (ft_is_prime(i) == 1)
		{
			printf("%d\n", i);
		}
	}
}
