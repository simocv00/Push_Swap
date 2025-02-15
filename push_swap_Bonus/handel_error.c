/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayyad <melayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:56:19 by melayyad          #+#    #+#             */
/*   Updated: 2025/02/10 18:02:49 by melayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	is_valid_token(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[0] == '+' || str[0] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_atol(char *str, int *num)
{
	long	n;
	int		sign;
	int		i;

	n = 0;
	sign = 1;
	i = 0;
	if (str[0] == '+' || str[0] == '-')
	{
		if (str[0] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (1);
	while (str[i])
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	n *= sign;
	if (n > 2147483647 || n < -2147483648)
		return (1);
	*num = (int)n;
	return (0);
}

static int	check_duplicates(int *nums, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (nums[i] == nums[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	*validate_and_convert(char **tokens, int *count)
{
	int	i;
	int	cnt;
	int	*numbers;

	cnt = 0;
	while (tokens[cnt])
		cnt++;
	*count = cnt;
	numbers = malloc(sizeof(int) * cnt);
	if (!numbers)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	i = 0;
	while (tokens[i])
	{
		if (!is_valid_token(tokens[i]) || ft_atol(tokens[i], &numbers[i]))
		{
			write(2, "Error\n", 6);
			return (free(numbers), NULL);
		}
		i++;
	}
	return (numbers);
}

int	handel_error(char **tokens)
{
	int	count;
	int	*numbers;

	numbers = validate_and_convert(tokens, &count);
	if (!numbers)
		return (1);
	if (check_duplicates(numbers, count))
	{
		write(2, "Error\n", 6);
		free(numbers);
		return (1);
	}
	free(numbers);
	return (0);
}
