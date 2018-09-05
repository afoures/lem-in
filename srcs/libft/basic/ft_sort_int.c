/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 10:48:47 by rbalbous          #+#    #+#             */
/*   Updated: 2017/08/08 10:50:51 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_int(int *tab, size_t size)
{
	size_t i;
	size_t j;
	size_t s;

	i = 1;
	j = 0;
	while (j < size)
	{
		while (i < size - j)
		{
			if (tab[j] >= tab[i + j])
			{
				s = tab[j];
				tab[j] = tab[i + j];
				tab[i + j] = s;
			}
			i++;
		}
		i = 1;
		j++;
	}
}
