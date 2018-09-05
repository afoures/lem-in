/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:51:36 by rbalbous          #+#    #+#             */
/*   Updated: 2017/11/08 20:03:35 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	char	*tmp_h;
	char	*tmp_n;
	size_t	n;

	if (*needle == 0)
		return ((char*)hay);
	while (*hay != 0 && len > 0)
	{
		if (*hay == *needle)
		{
			tmp_h = (char*)hay;
			tmp_n = (char*)needle;
			n = len;
			while (*tmp_n == *tmp_h && *tmp_h != 0 && *tmp_n != 0 && n-- > 0)
			{
				tmp_n++;
				tmp_h++;
			}
			if (*tmp_n == 0)
				return ((char*)hay);
		}
		hay++;
		len--;
	}
	return (NULL);
}
