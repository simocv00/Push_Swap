/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_less.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayyad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:41:36 by melayyad          #+#    #+#             */
/*   Updated: 2025/02/10 18:41:38 by melayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	compute_prices(t_list *stack_b, int size_b, int size_a)
{
	t_list	*curr;
	int		cost_b;
	int		cost_a;

	curr = stack_b;
	while (curr)
	{
		if (!curr->target)
		{
			curr = curr->next;
			continue ;
		}
		if (curr->index >= size_b / 2)
			cost_b = size_b - curr->index;
		else
			cost_b = curr->index;
		if (curr->target->index >= size_a / 2)
			cost_a = size_a - curr->target->index;
		else
			cost_a = curr->target->index;
		curr->price = cost_b + cost_a;
		curr = curr->next;
	}
}

t_list	*find_less(t_list *stack_b, t_list *stack_a)
{
	t_list	*temp;
	t_list	*curr;
	int		cheap;
	int		size_b;
	int		size_a;

	if (!stack_b || !stack_a)
		return (NULL);
	temp = NULL;
	cheap = INT_MAX;
	size_b = ft_lstsize(stack_b);
	size_a = ft_lstsize(stack_a);
	compute_prices(stack_b, size_b, size_a);
	curr = stack_b;
	while (curr)
	{
		if (curr->price < cheap)
		{
			cheap = curr->price;
			temp = curr;
		}
		curr = curr->next;
	}
	return (temp);
}
