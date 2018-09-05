/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 20:15:28 by rbalbous          #+#    #+#             */
/*   Updated: 2017/11/08 21:07:20 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	if ((str = malloc(sizeof(*str) * (len + 1))) == 0)
		return (NULL);
	while (i < len)
	{
		str[i] = f(s[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
