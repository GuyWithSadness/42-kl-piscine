/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:55:22 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/06/05 16:55:23 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd of arguments.\n"
# define TRUE 1
# define FALSE 0
# define SUCCESS 0

typedef int	t_bool;

# define EVEN(nbr) (!((nbr) % 2))

#endif
