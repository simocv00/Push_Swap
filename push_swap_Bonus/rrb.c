/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayyad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:34:32 by melayyad          #+#    #+#             */
/*   Updated: 2025/02/10 18:34:38 by melayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rrb(t_list **stack_b)
{
	t_list	*prev;
	t_list	*last;

	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	prev = NULL;
	last = *stack_b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
}
