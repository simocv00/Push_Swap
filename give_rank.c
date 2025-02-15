/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_rank.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayyad <melayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:44:51 by melayyad          #+#    #+#             */
/*   Updated: 2025/02/10 18:45:11 by melayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	give_rank(t_list *stack_a)
{
	t_list	*temp1;
	t_list	*temp2;
	int		rank;

	temp1 = stack_a;
	while (temp1)
	{
		temp2 = stack_a;
		rank = 0;
		while (temp2)
		{
			if (temp2->value < temp1->value)
				rank++;
			temp2 = temp2->next;
		}
		temp1->rank = rank;
		temp1 = temp1->next;
	}
}
