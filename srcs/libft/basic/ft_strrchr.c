/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 16:48:21 by rbalbous          #+#    #+#             */
/*   Updated: 2017/11/06 18:51:58 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*end;
	int		count;

	count = 0;
	if (c == 0)
		return ((char*)(str + ft_strlen(str)));
	while (*str != 0)
	{
		if (*str == (char)c)
		{
			end = (char*)str;
			count++;
		}
		str++;
	}
	if (count == 0)
		return (NULL);
	return (end);
}
