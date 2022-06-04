/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nessasarry.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 12:27:00 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/05/29 14:52:48 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NESSASARRY_H
# define NESSASARRY_H

# include <unistd.h>
# include <stdlib.h>

void	generate(char *argv);
void	printarray(char **a);
char	**rando1half(int frow, int srow, char **a);
char	**rando2half(int trow, int forow, char **a);
int		runtest(char **e, char *argc, int c, int d);
int		con_cold(char **a, int col, char argv);
int		con_colu(char **a, int col, char argv);
int		con_col(char **a, char *argv);
int		con_rowl(char **a, int row, char argv);
int		con_rowr(char **a, int row, char argv);
int		con_row(char **a, char *argv);
int		duplicatecol(char **a);
int		logic(char **a, char *argc);
char	*ft_strcpy(char *dest, char *src);
char	**fuckyounorminette(char **pos);

#endif
