/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitfree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:53:12 by rbalbous          #+#    #+#             */
/*   Updated: 2017/11/08 19:24:37 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplitfree(const char *s, char c)
{
	size_t	i;
	size_t	index;
	size_t	ct_let;
	char	**str;

	index = 0;
	i = 0;
	if ((str = (char**)malloc(sizeof(char*) * ft_countwords(s, c) + 1)) == 0)
		return (NULL);
	while (index < ft_strlen(s))
	{
		ct_let = 0;
		if (s[ct_let + index] != c && s[ct_let + index] != '\0')
		{
			while (s[ct_let + index] != c && index + ct_let < ft_strlen(s))
				ct_let++;
			str[i] = ft_strsub(s, (unsigned int)index, ct_let);
			index += ct_let - 1;
			i++;
		}
		index++;
	}
	str[i] = 0;
	free(&s);
	return (str);
}
