/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 15:09:31 by rbalbous          #+#    #+#             */
/*   Updated: 2018/05/16 15:09:32 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	dest_size;
	size_t	src_size;
	int		i;

	i = 0;
	src_size = ft_strlen(src);
	dest_size = ft_strlen(dest);
	if (n == 0)
		return (src_size);
	while (src[i] != '\0' && dest_size + i < n - 1)
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[dest_size + i] = '\0';
	if (n < dest_size)
		return (n + src_size);
	return (dest_size + src_size);
}
