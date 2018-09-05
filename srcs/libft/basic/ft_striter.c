/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 20:02:28 by rbalbous          #+#    #+#             */
/*   Updated: 2017/11/08 21:06:01 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int	i;
	int	len;

	i = 0;
	if (!s || !f)
		return ;
	len = ft_strlen(s);
	while (i < len)
	{
		f(&s[i]);
		i++;
	}
}
