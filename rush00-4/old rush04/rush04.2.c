/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:56:14 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/05/21 17:04:15 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	rush(int x, int y);
char	ifelsestatement(int l, int w, int y, int x);
char	specialchar(int l, int w, int y, int x);
char	linechar(int l, int w, int y, int x);

void	rush(int x, int y)
{
	int		l;
	int		w;
	char	a;

	l = 1;
	w = 1;
	while (l <= y)
	{
		while (w <= x)
		{
			a = ifelsestatement(l, w, y, x);
			ft_putchar(a);
			++w;
		}
		w = 1;
		ft_putchar('\n');
		++l;
	}
}

char	ifelsestatement(int l, int w, int y, int x)
{
	if ((l == 1 && w == 1) || (l == 1 && w == x))
	{
		return (specialchar(l, w, y, x));
	}
	else if ((l == y && w == 1) || (l == y && w == x))
	{
		return (specialchar(l, w, y, x));
	}
	else if (l == 1 || l == y || w == 1 || w == x)
	{
		return (linechar(l, w, y, x));
	}
	else
	{
		return (' ');
	}
}

char	specialchar(int l, int w, int y, int x)
{
	if (l == 1 && w == 1)
	{
		return ('A');
	}
	else if (l == 1 && w == x)
	{
		return ('C');
	}
	else if (l == y && w == 1)
	{
		return ('C');
	}
	else if (l == y && w == x)
	{
		return ('A');
	}
}

char	linechar(int l, int w, int y, int x)
{
	if ((l == 1 || l == (y)))
	{
		return ('B');
	}
	else if (w == 1 || w == (x))
	{
		return ('B');
	}
}
