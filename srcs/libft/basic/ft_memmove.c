/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:41:10 by rbalbous          #+#    #+#             */
/*   Updated: 2017/11/08 19:32:43 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dd;
	const char	*ss;

	dd = dest;
	ss = src;
	if (dest > src)
	{
		while (n-- > 0)
		{
			dd[n] = ss[n];
		}
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}
