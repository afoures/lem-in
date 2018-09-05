/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 21:52:38 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/18 18:20:42 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if ((str = (char*)malloc(sizeof(*str) * len + 1)) == 0)
		return (NULL);
	while (i < len + 1)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
