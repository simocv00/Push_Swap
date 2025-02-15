/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayyad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:32:59 by melayyad          #+#    #+#             */
/*   Updated: 2025/02/10 18:33:07 by melayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	count_tokens(int ac, char **av)
{
	int		total;
	int		i;
	char	**temp;
	int		j;

	total = 0;
	i = 1;
	while (i < ac)
	{
		temp = ft_split(av[i], ' ');
		if (temp)
		{
			j = 0;
			while (temp[j])
			{
				total++;
				j++;
			}
			free_tokens(temp);
		}
		i++;
	}
	return (total);
}
