/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayyad <melayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:38:07 by melayyad          #+#    #+#             */
/*   Updated: 2025/02/10 17:41:13 by melayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	give_index(t_list *stack)
{
	t_list	*temp;
	int		index;

	temp = stack;
	index = 0;
	while (temp)
	{
		temp->index = index++;
		temp = temp->next;
	}
}
