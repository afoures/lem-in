/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 12:37:58 by rbalbous          #+#    #+#             */
/*   Updated: 2017/11/07 16:23:32 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*ss;
	unsigned char		*dd;
	int					i;

	i = 0;
	dd = (unsigned char*)dest;
	ss = (unsigned char*)src;
	while (n-- > 0)
	{
		dd[i] = ss[i];
		i++;
		if ((unsigned char)c == ss[i - 1])
			return (dest + i);
	}
	return (NULL);
}
