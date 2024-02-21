/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:48:41 by rcortes-          #+#    #+#             */
/*   Updated: 2024/02/08 19:48:42 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_args_dup(t_list *stack)
{
	t_list	*aux;
	t_list	*checker;

	aux = stack;
	while (aux)
	{
		checker = stack;
		while (checker != aux)
		{
			if ((checker->num == aux->num) || (checker->num > 2147483647)
				|| (checker->num < -2147483648))
				return (1);
			checker = checker->next;
		}
		if (aux == checker && (aux->num > 2147483647 || aux->num < -2147483648))
			return (1);
		aux = aux->next;
	}
	return (0);
}

static int	check_args_only_nums(char **split, int index)
{
	int	i;

	i = 0;
	while (split[index])
	{
		while (split[index][i] == '\t' || split[index][i] == ' ')
			i++;
		if (split[index][i] == '-' || split[index][i] == '+')
		{
			if ((split[index][i] == '+' && ft_isdigit(split[index][i + 1]) == 0)
				|| (split[index][i] == '-' && !ft_isdigit(split[index][i + 1])))
				return (1);
			i++;
		}
		while (split[index][i] >= '0' && split[index][i] <= '9')
			i++;
		if (split[index][i] == '\0' && (split[index][i - 1] == ' '
			|| split[index][i - 1] == '\t'))
			return (1);
		else if (split[index][i] == '\0')
			return (0);
		else
			return (1);
	}
	return (0);
}

static int	check_max_number(char **split, int index)
{
	int	i;
	int	isdigit;

	i = 0;
	while (split[index][i] == ' ' || split[index][i] == '\t')
		i++;
	isdigit = 0;
	while (ft_isdigit(split[index][i + isdigit]))
	{
		if (split[index][i] == '0')
			i++;
		else
			isdigit++;
	}
	if (isdigit > 10)
		return (1);
	return (0);
}

void	full_checker(char **split, int index, t_list **stack_a)
{
	if (split == NULL && index == 0)
	{
		if (stack_a)
			ft_lstclear(stack_a, &free);
		if (split)
			free(split);
	}
	else if (check_args_only_nums(split, index) || check_args_dup(*stack_a))
	{
		free(split);
		ft_lstclear(stack_a, &free);
	}
	else if (check_max_number(split, index) == 1)
	{
		free(split);
		ft_lstclear(stack_a, &free);
	}
	else
		return ;
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	check_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}
