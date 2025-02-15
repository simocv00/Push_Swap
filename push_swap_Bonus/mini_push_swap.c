/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayyad <melayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:49:25 by melayyad          #+#    #+#             */
/*   Updated: 2025/02/15 11:37:38 by melayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <stdio.h>

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

static void	just_mini(t_list **stack_a, t_list **stack_b, int *flag)
{
	char	*command;

	while (1)
	{
		command = get_next_line(0);
		if (!command)
			break ;
		if (!commond_handel(stack_a, stack_b, command))
		{
			write(2, "Error\n", 6);
			free(command);
			*flag = 1;
			return ;
		}
		free(command);
	}
}

/* دالة main مختصرة تحافظ على منطقك الأصلي */
int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**all_tokens;
	int		flag;

	if (ac < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	all_tokens = extract_all_tokens(ac, av);
	flag = 0;
	if (!all_tokens)
		return (1);
	if (process_tokens(all_tokens, &stack_a) == 1)
		return (1);
	just_mini(&stack_a, &stack_b, &flag);
	if ((is_sorted(stack_a) == 1 && flag == 0) && (ft_lstsize_(stack_b) == 0))
		write(1, "OK\n", 3);
	else if ((is_sorted(stack_a) == 0 && flag == 0)
		|| (ft_lstsize_(stack_b) != 0))
		write(1, "KO\n", 3);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
