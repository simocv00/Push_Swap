/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayyad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:00:06 by melayyad          #+#    #+#             */
/*   Updated: 2025/02/10 20:00:08 by melayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_list **stack_b)
{
	t_list	*first;
	t_list	*second;

	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	first = *stack_b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_b = second;
	write(1, "sb\n", 3);
}
