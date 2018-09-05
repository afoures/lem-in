/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:45:36 by rbalbous          #+#    #+#             */
/*   Updated: 2017/11/07 16:47:51 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	int i;

	i = 0;
	while (src[i] && n > 0)
	{
		dest[i] = src[i];
		i++;
		n--;
	}
	while (n > 0)
	{
		dest[i] = '\0';
		i++;
		n--;
	}
	return (dest);
}
