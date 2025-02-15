/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayyad <melayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:06:09 by melayyad          #+#    #+#             */
/*   Updated: 2025/02/10 18:28:23 by melayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_index(t_list *lst)
{
	int		min_index;
	int		index;
	t_list	*tmp;
	int		min_val;

	min_index = 0;
	index = 0;
	tmp = lst;
	min_val = tmp->value;
	while (tmp)
	{
		if (tmp->value < min_val)
		{
			min_val = tmp->value;
			min_index = index;
		}
		tmp = tmp->next;
		index++;
	}
	return (min_index);
}

static void	push_min_to_b(t_list **stack_a, t_list **stack_b)
{
	int	min_index;
	int	i;
	int	rotations;

	min_index = find_min_index(*stack_a);
	if (min_index <= ft_lstsize(*stack_a) / 2)
	{
		i = 0;
		while (i < min_index)
		{
			ra(stack_a);
			i++;
		}
	}
	else
	{
		i = 0;
		rotations = ft_lstsize(*stack_a) - min_index;
		while (i < rotations)
		{
			rra(stack_a);
			i++;
		}
	}
	pb(stack_a, stack_b);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_a) > 3 && is_sorted(*stack_a) == 0)
		push_min_to_b(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		pa(stack_a, stack_b);
		if ((*stack_a)->next && ((*stack_a)->value > (*stack_a)->next->value))
			sa(stack_a);
	}
}
