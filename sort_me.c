/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_me.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayyad <melayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:50:25 by melayyad          #+#    #+#             */
/*   Updated: 2025/02/10 21:06:46 by melayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*find_cheapest_node(t_list *a, t_list *b)
{
	give_target(a, b);
	return (find_less(b, a));
}

static void	handle_rotations(t_list **a, t_list **b, t_list *c, t_mins m)
{
	if ((c->index > m.min_b && c->target->index > m.min_a) && (c->index
			&& c->target->index))
	{
		while (c->index > 0 && c->target->index > 0)
		{
			rrr(a, b);
			give_index(*a);
			give_index(*b);
		}
	}
	else if ((c->index <= m.min_b && c->target->index < m.min_a) && (c->index
			&& c->target->index))
	{
		while (c->index > 0 && c->target->index > 0)
		{
			rr(a, b);
			give_index(*a);
			give_index(*b);
		}
	}
}

static void	rotate_b(t_list **b, t_list *c, int min_b)
{
	if (c->index <= min_b && c->index)
	{
		while (c->index)
		{
			rb(b);
			give_index(*b);
		}
	}
	else if (c->index > min_b && c->index)
	{
		while (c->index)
		{
			rrb(b);
			give_index(*b);
		}
	}
}

static void	rotate_a(t_list **a, t_list *t, int min_a)
{
	while (*a != t)
	{
		give_index(*a);
		if (t->index <= min_a && t->index > 0)
			ra(a);
		else if (t->index > min_a && t->index > 0)
			rra(a);
		give_index(*a);
	}
}

void	sort_me(t_list **sa, t_list **sb)
{
	t_list	*c;
	t_mins	m;

	while (ft_lstsize(*sb) > 0)
	{
		give_index(*sa);
		give_index(*sb);
		c = find_cheapest_node(*sa, *sb);
		m.min_b = (ft_lstsize(*sb) + 1) / 2;
		m.min_a = (ft_lstsize(*sa) + 1) / 2;
		handle_rotations(sa, sb, c, m);
		rotate_b(sb, c, m.min_b);
		rotate_a(sa, c->target, m.min_a);
		pa(sa, sb);
		give_target(*sa, *sb);
	}
}
