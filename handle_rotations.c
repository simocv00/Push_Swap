/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_rotations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayyad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:08:36 by melayyad          #+#    #+#             */
/*   Updated: 2025/02/10 21:08:39 by melayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_rotations(t_list **a, t_list **b, t_list *c, t_mins m)
{
	if ((c->index > m.min_b && c->target->index > m.min_a) && (c->index
			&& c->target->index))
	{
		while (c->index > 0 && c->target->index > 0)
		{
			rrr(a, b);
			update_indices(*a, *b);
		}
	}
	else if ((c->index <= m.min_b && c->target->index < m.min_a) && (c->index
			&& c->target->index))
	{
		while (c->index > 0 && c->target->index > 0)
		{
			rr(a, b);
			update_indices(*a, *b);
		}
	}
}
