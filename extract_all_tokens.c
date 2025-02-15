/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_all_tokens.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayyad <melayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:41:40 by melayyad          #+#    #+#             */
/*   Updated: 2025/02/10 17:46:21 by melayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	validate_arguments(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!has_number(av[i]))
			return (0);
		i++;
	}
	return (1);
}

static char	**allocate_all_tokens(int ac, char **av)
{
	int		total;
	char	**all_tokens;

	total = count_tokens(ac, av);
	if (total == 0)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	all_tokens = malloc(sizeof(char *) * (total + 1));
	return (all_tokens);
}

static int	process_argument(char *arg, char **all_tokens, int *index)
{
	char	**temp;
	int		j;

	temp = ft_split(arg, ' ');
	if (!temp)
		return (0);
	j = 0;
	while (temp[j])
	{
		all_tokens[*index] = ft_strdup(temp[j]);
		(*index)++;
		j++;
	}
	free_tokens(temp);
	return (1);
}

char	**extract_all_tokens(int ac, char **av)
{
	char	**all_tokens;
	int		index;
	int		i;

	if (!validate_arguments(ac, av))
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	all_tokens = allocate_all_tokens(ac, av);
	if (!all_tokens)
		return (NULL);
	index = 0;
	i = 1;
	while (i < ac)
	{
		if (!process_argument(av[i], all_tokens, &index))
			return (NULL);
		i++;
	}
	all_tokens[index] = NULL;
	return (all_tokens);
}
