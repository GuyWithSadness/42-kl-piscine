/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraydefinitiondeclarationepicdeceleratio          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 14:49:56 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/05/29 14:51:58 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	n;

	n = -1;
	while (src[++n] != '\0')
	{
		dest[n] = src[n];
	}
	dest[n] = '\0';
	return (dest);
}

char	**fuckyounorminette(char **pos)
{
	ft_strcpy(pos[0], "1234");
	ft_strcpy(pos[1], "1324");
	ft_strcpy(pos[2], "1423");
	ft_strcpy(pos[3], "1342");
	ft_strcpy(pos[4], "1243");
	ft_strcpy(pos[5], "1432");
	ft_strcpy(pos[6], "2134");
	ft_strcpy(pos[7], "2341");
	ft_strcpy(pos[8], "2314");
	ft_strcpy(pos[9], "2413");
	ft_strcpy(pos[10], "2431");
	ft_strcpy(pos[11], "2143");
	ft_strcpy(pos[12], "3124");
	ft_strcpy(pos[13], "3142");
	ft_strcpy(pos[14], "3214");
	ft_strcpy(pos[15], "3241");
	ft_strcpy(pos[16], "3412");
	ft_strcpy(pos[17], "3421");
	ft_strcpy(pos[18], "4123");
	ft_strcpy(pos[19], "4132");
	ft_strcpy(pos[20], "4231");
	ft_strcpy(pos[21], "4213");
	ft_strcpy(pos[22], "4321");
	ft_strcpy(pos[23], "4312");
	return (pos);
}
