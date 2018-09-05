/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:51:36 by rbalbous          #+#    #+#             */
/*   Updated: 2017/11/06 18:49:21 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *hay, const char *needle)
{
	char	*tmp_h;
	char	*tmp_n;

	if (*needle == 0)
		return ((char*)hay);
	while (*hay != 0)
	{
		if (*hay == *needle)
		{
			tmp_h = (char*)hay;
			tmp_n = (char*)needle;
			while (*tmp_n != 0 && *tmp_h != 0 && (*tmp_n == *tmp_h))
			{
				tmp_n++;
				tmp_h++;
			}
			if (*tmp_n == 0)
				return ((char*)hay);
		}
		hay++;
	}
	return (NULL);
}
