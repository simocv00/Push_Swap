/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayyad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:33:43 by melayyad          #+#    #+#             */
/*   Updated: 2025/02/10 18:33:53 by melayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	reverse_rotate(t_list **stack)
{
	t_list	*prev;
	t_list	*last;

	if (stack && *stack && (*stack)->next)
	{
		prev = NULL;
		last = *stack;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		if (prev)
		{
			prev->next = NULL;
			last->next = *stack;
			*stack = last;
		}
	}
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
