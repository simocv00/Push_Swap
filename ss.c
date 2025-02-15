/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayyad <melayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:59:37 by melayyad          #+#    #+#             */
/*   Updated: 2025/02/13 11:46:01 by melayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ss(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_a;
	t_list	*second_a;
	t_list	*first_b;
	t_list	*second_b;

	if (stack_a && *stack_a && (*stack_a)->next)
	{
		first_a = *stack_a;
		second_a = first_a->next;
		first_a->next = second_a->next;
		second_a->next = first_a;
		*stack_a = second_a;
	}
	if (stack_b && *stack_b && (*stack_b)->next)
	{
		first_b = *stack_b;
		second_b = first_b->next;
		first_b->next = second_b->next;
		second_b->next = first_b;
		*stack_b = second_b;
	}
}
