/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:35:02 by rbalbous          #+#    #+#             */
/*   Updated: 2017/11/07 17:55:36 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (c == 0)
		return ((char*)(str + ft_strlen(str)));
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char*)(str + i));
		i++;
	}
	return (NULL);
}
