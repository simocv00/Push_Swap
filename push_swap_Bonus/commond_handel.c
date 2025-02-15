/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commond_handel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayyad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:53:48 by melayyad          #+#    #+#             */
/*   Updated: 2025/02/13 11:53:50 by melayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	commond_handel(t_list **stack_a, t_list **stack_b, char *command)
{
	if (ft_strcmp(command, "sa\n") == 0)
		sa(stack_a);
	else if (ft_strcmp(command, "sb\n") == 0)
		sb(stack_b);
	else if (ft_strcmp(command, "ss\n") == 0)
		ss(stack_a, stack_b);
	else if (ft_strcmp(command, "pa\n") == 0)
		pa(stack_a, stack_b);
	else if (ft_strcmp(command, "pb\n") == 0)
		pb(stack_a, stack_b);
	else if (ft_strcmp(command, "ra\n") == 0)
		ra(stack_a);
	else if (ft_strcmp(command, "rb\n") == 0)
		rb(stack_b);
	else if (ft_strcmp(command, "rr\n") == 0)
		rr(stack_a, stack_b);
	else if (ft_strcmp(command, "rra\n") == 0)
		rra(stack_a);
	else if (ft_strcmp(command, "rrb\n") == 0)
		rrb(stack_b);
	else if (ft_strcmp(command, "rrr\n") == 0)
		rrr(stack_a, stack_b);
	else
		return (0);
	return (1);
}
