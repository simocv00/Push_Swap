/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayyad <melayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:51:49 by melayyad          #+#    #+#             */
/*   Updated: 2025/02/10 21:12:36 by melayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

t_list	*ft_lstnew(int content)
{
	t_list	*elt;

	elt = (t_list *)malloc(sizeof(*elt));
	if (!elt)
		return (NULL);
	elt->value = content;
	elt->next = NULL;
	elt->index = -1;
	return (elt);
}

static int	ft_atol(const char *str)
{
	int		i;
	long	n;
	int		s;

	i = 0;
	n = 0;
	s = 1;
	if (!str[i])
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = s * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n * s);
}

void	give_value(t_list **head, char **str)
{
	int		i;
	t_list	*temp;
	int		v;

	i = 0;
	temp = *head;
	while (str[i])
	{
		v = ft_atol(str[i]);
		if (!temp)
		{
			temp = ft_lstnew(v);
			ft_lstadd_back(head, temp);
		}
		else
		{
			temp->value = v;
		}
		temp = temp->next;
		i++;
	}
}
