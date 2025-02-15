/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayyad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:57:51 by melayyad          #+#    #+#             */
/*   Updated: 2025/02/10 19:57:57 by melayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*tail;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tail = get_last_stack(stack);
	tmp->next = NULL;
	tail->next = tmp;
}

void	ra(t_list **stack_a)
{
	rotate(stack_a);
}
