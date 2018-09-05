/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 15:27:33 by rbalbous          #+#    #+#             */
/*   Updated: 2017/11/06 19:16:19 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if ((new = (t_list*)malloc(sizeof(*new))) == 0)
		return (NULL);
	new->next = NULL;
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
		return (new);
	}
	if ((new->content = malloc(sizeof(void) * content_size + 1)) == 0)
		return (NULL);
	ft_memcpy(new->content, content, content_size);
	new->content_size = content_size;
	return (new);
}
