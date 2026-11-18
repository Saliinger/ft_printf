/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0009/10/20 17:56:06 by noukan            #+#    #+#             */
/*   Updated: 2023/10/30 13:13:22 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst && new)
	{
		if (!*lst)
			*lst = new;
		else
		{
			temp = *lst;
			while (temp->next)
				temp = temp->next;
			temp->next = new;
		}
	}
}
