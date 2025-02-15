/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_last_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayyad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:56:04 by melayyad          #+#    #+#             */
/*   Updated: 2025/02/10 19:56:06 by melayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_last_stack(t_list **stack)
{
	t_list	*temp;

	if (*stack == NULL)
		return (NULL);
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}
