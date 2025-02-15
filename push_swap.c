/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayyad <melayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:49:25 by melayyad          #+#    #+#             */
/*   Updated: 2025/02/13 20:01:42 by melayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	process_tokens(char **all_tokens, t_list **stack_a)
{
	int	k;
	int	total_tokens;

	k = 0;
	while (all_tokens[k])
		k++;
	total_tokens = k;
	if (handel_error(all_tokens) == 1)
		return (ft_free(all_tokens, total_tokens), 1);
	give_value(stack_a, all_tokens);
	k = 0;
	while (all_tokens[k])
	{
		free(all_tokens[k]);
		k++;
	}
	free(all_tokens);
	return (0);
}

static void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int		pivot;
	t_list	*temp_node;

	give_rank(*stack_a);
	if (ft_lstsize(*stack_a) == 5)
		sort_five(stack_a, stack_b);
	while (ft_lstsize(*stack_a) > 3 && is_sorted(*stack_a) == 0)
	{
		give_rank(*stack_a);
		pivot = ft_lstsize(*stack_a) / 3;
		while ((*stack_a) && ((*stack_a)->rank > pivot)
			&& is_sorted(*stack_a) == 0)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	temp_node = *stack_b;
	while (temp_node)
	{
		give_target(*stack_a, temp_node);
		temp_node = temp_node->next;
	}
	if (ft_lstsize(*stack_a) == 3)
		sort_three(stack_a);
	sort_me(stack_a, stack_b);
}

static void	final_align(t_list **stack_a)
{
	t_list	*temp_node;

	give_index(*stack_a);
	temp_node = find_min(*stack_a);
	while (temp_node->index != 0 && is_sorted(*stack_a) == 0)
	{
		if (temp_node->index >= (ft_lstsize(*stack_a) + 1) / 3)
			rra(stack_a);
		else
			ra(stack_a);
		give_index(*stack_a);
		temp_node = find_min(*stack_a);
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**all_tokens;

	if (ac < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	all_tokens = extract_all_tokens(ac, av);
	if (!all_tokens)
		return (1);
	if (process_tokens(all_tokens, &stack_a) == 1)
		return (1);
	sort_stack(&stack_a, &stack_b);
	final_align(&stack_a);
	free_stack(&stack_a);
	return (0);
}
