/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:26:15 by rbalbous          #+#    #+#             */
/*   Updated: 2017/11/10 13:26:19 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countwords(const char *s, char c)
{
	size_t	count_words;
	size_t	i;

	count_words = 0;
	if (s[0] != c)
		count_words++;
	i = 0;
	while (s[++i])
		if (s[i] != c && s[i - 1] == c)
			count_words++;
	return (count_words);
}
