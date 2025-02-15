/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayyad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:51:04 by melayyad          #+#    #+#             */
/*   Updated: 2025/02/10 19:51:06 by melayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **a)
{
	t_list	*max;
	t_list	*i;

	if (*a == NULL)
		return ;
	max = *a;
	i = (*a)->next;
	while (i)
	{
		if (max->value < i->value)
			max = i;
		i = i->next;
	}
	if (max == *a)
		ra(a);
	else if ((*a)->next == max)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}
