/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 15:09:17 by rbalbous          #+#    #+#             */
/*   Updated: 2018/05/16 15:09:17 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	i = -1;
	if ((dest = (char*)malloc(sizeof(*dest) * ft_strlen(src) + 1)) == 0)
		return (0);
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
