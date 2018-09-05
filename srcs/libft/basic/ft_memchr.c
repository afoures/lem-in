/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 22:21:02 by rbalbous          #+#    #+#             */
/*   Updated: 2017/11/08 19:32:13 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*ss;
	size_t			i;

	i = 0;
	ss = (unsigned char*)str;
	while (n-- > 0)
	{
		if (*ss == (unsigned char)c)
			return ((void*)(str + i));
		ss++;
		i++;
	}
	return (NULL);
}
