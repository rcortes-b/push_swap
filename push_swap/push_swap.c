/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:08:31 by rcortes-          #+#    #+#             */
/*   Updated: 2024/02/03 15:08:32 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	aux_position(t_list	**stack, int last, int index)
{
	t_list	*aux;
	int		num;

	aux = *stack;
	num = 2147483647;
	while (aux)
	{
		if (aux->num == last)
		{
			aux = aux->next;
			continue ;
		}
		if (last <= aux->num && num > aux->num)
			num = aux->num;
		aux = aux->next;
	}
	aux = *stack;
	while (aux)
	{
		if (aux->num == num)
			break ;
		aux = aux->next;
	}
	aux->pos = index;
	return (num);
}

void	assign_position(t_list **stack)
{
	t_list	*aux;
	int		min;
	int		index;

	aux = *stack;
	index = 0;
	while (aux)
	{
		if (aux->num == -2147483648)
		{
			aux->pos = 1;
			index++;
		}
		aux->pos = 0;
		aux = aux->next;
	}
	index++;
	min = -2147483648;
	while (index < ft_lstsize(*stack) + 1)
	{
		min = aux_position(stack, min, index);
		index++;
	}
}

int	check_if_sorted(t_list *stack)
{
	t_list	*aux;
	int		num;

	num = 0;
	aux = stack;
	while (aux->next)
	{
		if (aux->num > aux->next->num)
			return (1);
		aux = aux->next;
	}
	return (0);
}

t_list	*get_args(char **argv, t_list *stack, int j)
{
	int		i;
	char	**split;
	t_list	*aux;

	while (argv[++j])
	{
		i = -1;
		if (argv[j][0] == '\0' || check_empty(argv[j]))
			full_checker(NULL, 0, &stack);
		split = ft_split(argv[j], ' ', '\t');
		while (split[++i])
		{
			aux = (t_list *)malloc(sizeof(t_list));
			if (!aux)
				return (NULL);
			aux->next = NULL;
			aux->content = split[i];
			aux->num = ft_atoi(aux->content);
			ft_lstadd_back(&stack, aux);
			full_checker(split, i, &stack);
		}
		free(split);
	}
	return (stack);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		amount;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	stack_a = get_args(argv, stack_a, 0);
	amount = ft_lstsize(stack_a);
	assign_position(&stack_a);
	if (check_if_sorted(stack_a))
	{
		if (amount >= 2 && amount <= 5)
			sort_special_case(&stack_a, &stack_b, amount);
		else
			push_swap(&stack_a, &stack_b, 0);
	}
	ft_lstclear(&stack_a, &free);
	if (stack_b)
		ft_lstclear(&stack_b, &free);
	return (0);
}
