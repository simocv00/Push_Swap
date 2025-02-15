/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayyad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:46:56 by melayyad          #+#    #+#             */
/*   Updated: 2025/02/10 18:47:06 by melayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*find_smallest_greater(t_list *stack_a, int value)
{
	t_list	*candidate;
	t_list	*current;
	long	min_candidate;

	candidate = NULL;
	current = stack_a;
	min_candidate = LONG_MAX;
	while (current)
	{
		if (current->value > value && current->value < min_candidate)
		{
			min_candidate = current->value;
			candidate = current;
		}
		current = current->next;
	}
	return (candidate);
}

static t_list	*find_smallest(t_list *stack_a)
{
	t_list	*candidate;
	t_list	*current;

	candidate = stack_a;
	current = stack_a;
	while (current)
	{
		if (current->value < candidate->value)
			candidate = current;
		current = current->next;
	}
	return (candidate);
}

void	give_target(t_list *stack_a, t_list *stack_b)
{
	t_list	*current_b;
	t_list	*target;

	current_b = stack_b;
	while (current_b)
	{
		target = find_smallest_greater(stack_a, current_b->value);
		if (!target)
			target = find_smallest(stack_a);
		current_b->target = target;
		current_b = current_b->next;
	}
}
