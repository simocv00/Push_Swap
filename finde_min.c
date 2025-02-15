/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finde_min.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayyad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:49:33 by melayyad          #+#    #+#             */
/*   Updated: 2025/02/10 19:49:41 by melayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_min(t_list *stack)
{
	int		min;
	t_list	*min_node;
	t_list	*temp;

	min = 2147483647;
	min_node = NULL;
	temp = stack;
	while (temp)
	{
		if (temp->value < min)
		{
			min = temp->value;
			min_node = temp;
		}
		temp = temp->next;
	}
	return (min_node);
}
