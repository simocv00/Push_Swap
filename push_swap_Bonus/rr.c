/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayyad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:58:21 by melayyad          #+#    #+#             */
/*   Updated: 2025/02/10 19:58:24 by melayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	rotate_stack(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (stack && *stack && (*stack)->next)
	{
		first = *stack;
		last = *stack;
		while (last->next)
			last = last->next;
		*stack = first->next;
		first->next = NULL;
		last->next = first;
	}
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate_stack(stack_a);
	rotate_stack(stack_b);
}
