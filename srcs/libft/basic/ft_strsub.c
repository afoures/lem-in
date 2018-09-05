/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:45:00 by rbalbous          #+#    #+#             */
/*   Updated: 2017/11/08 18:48:24 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if ((str = (char*)malloc(sizeof(char) * len + 1)) == 0)
		return (NULL);
	while (len-- > 0)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = 0;
	return (str);
}
