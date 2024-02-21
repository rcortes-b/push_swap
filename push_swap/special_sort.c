/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:49:13 by rcortes-          #+#    #+#             */
/*   Updated: 2024/02/08 19:49:14 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack)
{
	t_list	*aux;

	aux = ft_lstlast(*stack);
	if (((*stack)->num > (*stack)->next->num) && ((*stack)->num > aux->num))
		rotate_ab(*stack, NULL);
	else if (((*stack)->num < (*stack)->next->num)
		&& ((*stack)->next->num > aux->num))
		reverse_rotate_ab(stack, NULL);
	if ((*stack)->num > (*stack)->next->num)
		swap_function(*stack, NULL);
}

void	sort_last_from_five(t_list **stack_a, t_list **stack_b)
{
	int		counter;

	counter = aux_counter(*stack_a, *stack_b);
	if (counter == 0)
		push_from_to(stack_b, stack_a, "pa");
	else if (counter == 1)
	{
		push_from_to(stack_b, stack_a, "pa");
		swap_function(*stack_a, NULL);
	}
	else if (counter == 2)
		aux_for_counter2(stack_a, stack_b);
	else if (counter == 3)
	{
		reverse_rotate_ab(stack_a, NULL);
		push_from_to(stack_b, stack_a, "pa");
		rotate_ab(*stack_a, NULL);
		rotate_ab(*stack_a, NULL);
	}
	else
	{
		push_from_to(stack_b, stack_a, "pa");
		rotate_ab(*stack_a, NULL);
	}
}

void	sort_four_from_five_aux(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;

	last = ft_lstlast(*stack_a);
	if ((*stack_b)->num > last->num)
	{
		push_from_to(stack_b, stack_a, "pa");
		rotate_ab(*stack_a, NULL);
	}
	else if ((*stack_b)->num < last->num
		&& (*stack_b)->num > (*stack_a)->next->num)
	{
		reverse_rotate_ab(stack_a, NULL);
		push_from_to(stack_b, stack_a, "pa");
		rotate_ab(*stack_a, NULL);
		rotate_ab(*stack_a, NULL);
	}
	else if ((*stack_b)->num < (*stack_a)->next->num
		&& (*stack_b)->num > (*stack_a)->num)
	{
		push_from_to(stack_b, stack_a, "pa");
		swap_function(*stack_a, NULL);
	}
	else
		push_from_to(stack_b, stack_a, "pa");
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	if (check_if_middle(*stack_a))
	{
		order_five_a(stack_a);
		return ;
	}
	push_from_to(stack_a, stack_b, "pb");
	push_from_to(stack_a, stack_b, "pb");
	if (check_if_sorted(*stack_a))
		sort_three(stack_a);
	sort_four_from_five_aux(stack_a, stack_b);
	sort_last_from_five(stack_a, stack_b);
}

void	sort_special_case(t_list **stack_a, t_list **stack_b, int amount)
{
	if (amount == 2)
	{
		if ((*stack_a)->num > (*stack_a)->next->num)
			swap_function(*stack_a, NULL);
		return ;
	}
	else if (amount == 3)
		sort_three(stack_a);
	else if (amount == 4)
	{
		push_from_to(stack_a, stack_b, "pb");
		sort_three(stack_a);
		sort_four_from_five_aux(stack_a, stack_b);
	}
	else
		sort_five(stack_a, stack_b);
}
