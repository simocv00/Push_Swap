/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finde_max.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayyad <melayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:48:46 by melayyad          #+#    #+#             */
/*   Updated: 2025/02/10 18:49:41 by melayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	finde_max(t_list *stack)
{
	int		max;
	t_list	*temp;

	temp = stack;
	max = -2147483648;
	while (temp)
	{
		if (temp->value > max)
			max = temp->value;
		temp = temp->next;
	}
	return (max);
}
