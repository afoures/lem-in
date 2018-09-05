/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:42:20 by rbalbous          #+#    #+#             */
/*   Updated: 2017/11/08 21:28:18 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	int		beg_trim;
	int		end_trim;
	int		len_tot;
	char	*str;
	int		i;

	i = -1;
	beg_trim = 0;
	if (!s)
		return (NULL);
	end_trim = ft_strlen(s) - 1;
	while (s[beg_trim] == ' ' || s[beg_trim] == '\t' || s[beg_trim] == '\n')
		beg_trim++;
	while (s[end_trim] == ' ' || s[end_trim] == '\t' || s[end_trim] == '\n')
		end_trim--;
	if (end_trim < 0)
		return (ft_strnew(1));
	len_tot = end_trim - beg_trim + 1;
	if ((str = (char*)malloc(sizeof(char) * len_tot + 1)) == 0)
		return (NULL);
	while (++i < len_tot)
		str[i] = s[beg_trim + i];
	str[i] = 0;
	return (str);
}
