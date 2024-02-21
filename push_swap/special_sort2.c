/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:13:02 by rcortes-          #+#    #+#             */
/*   Updated: 2024/02/09 10:13:05 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_middle(t_list *stack)
{
	t_list	*middle;
	t_list	*aux;
	int		min;

	middle = stack->next->next;
	min = stack->num;
	aux = stack;
	while (aux)
	{
		if (aux->num > middle->num)
			return (0);
		if (min > aux->num)
			min = aux->num;
		if (!aux->next)
			break ;
		aux = aux->next;
	}
	if (min != middle->next->num && min != aux->num)
		return (0);
	if (check_last_lowers(stack, aux, middle, min))
		return (1);
	return (0);
}

int	check_last_lowers(t_list *stack, t_list *aux, t_list *middle, int min)
{
	t_list	*tmp;
	int		second_min;

	tmp = stack;
	second_min = stack->num;
	while (tmp)
	{
		if (tmp->num == min)
		{
			tmp = tmp->next;
			continue ;
		}
		if (second_min > tmp->num)
			second_min = tmp->num;
		tmp = tmp->next;
	}
	if (second_min == aux->num || second_min == middle->next->num)
		return (1);
	return (0);
}

void	order_five_a(t_list **stack)
{
	int	i;

	if ((*stack)->num > (*stack)->next->num)
		swap_function(*stack, NULL);
	i = -1;
	while (++i < 3)
		rotate_ab(*stack, NULL);
	if ((*stack)->num > (*stack)->next->num)
		swap_function(*stack, NULL);
}

int	aux_counter(t_list *stack_a, t_list *stack_b)
{
	t_list	*aux;
	int		counter;

	aux = stack_a;
	counter = 0;
	if (stack_b->num < stack_a->num)
		return (0);
	while (aux)
	{
		counter++;
		if (!aux->next)
			break ;
		if (stack_b->num > aux->num && stack_b->num < aux->next->num)
			break ;
		aux = aux->next;
	}
	return (counter);
}

void	aux_for_counter2(t_list **stack_a, t_list **stack_b)
{
	rotate_ab(*stack_a, NULL);
	push_from_to(stack_b, stack_a, "pa");
	swap_function(*stack_a, NULL);
	reverse_rotate_ab(stack_a, NULL);
}
