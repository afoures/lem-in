/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 17:17:59 by rbalbous          #+#    #+#             */
/*   Updated: 2018/01/11 22:28:07 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t len)
{
	char	*tmp;

	if ((tmp = (char*)malloc(sizeof(*tmp) * len)) == 0)
		return (NULL);
	ft_bzero(tmp, len);
	return (tmp);
}
