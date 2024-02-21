/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:35:56 by rcortes-          #+#    #+#             */
/*   Updated: 2024/02/14 16:35:57 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_last(t_list **stack_a, t_list **stack_b)
{
	t_list	*aux;

	aux = ft_lstlast(*stack_a);
	if (aux->pos > (*stack_b)->pos)
		return (1);
	return (0);
}

void	sort_if_last(t_list **stack_a, t_list **stack_b)
{
	t_list	*aux;
	int		counter;

	aux = *stack_b;
	counter = 0;
	if (check_reverse_order(*stack_b) == 0)
		return ;
	while (aux)
	{
		if (aux->pos < (*stack_a)->pos)
			break ;
		aux = aux->next;
	}
	if (!aux)
		aux = set_ptr_bigger(stack_b);
	counter = ft_lstsize(aux);
	if (counter <= (ft_lstsize(*stack_b) / 2))
	{
		while (counter-- > 0)
			reverse_rotate_ab(NULL, stack_b);
	}
	else
		aux_for_little(stack_b, counter);
}

int	first_position(t_list **stack_a, t_list **stack_b)
{
	if (check_last(stack_a, stack_b) == 1)
	{
		if ((*stack_a)->pos > (*stack_b)->pos)
			return (1);
	}
	return (0);
}

void	if_last_isbigger(t_list **stack_b)
{
	t_list	*aux;

	aux = ft_lstlast(*stack_b);
	if (aux->pos > (*stack_b)->pos)
		reverse_rotate_ab(NULL, stack_b);
}

t_list	*set_ptr_bigger(t_list **stack_b)
{
	t_list	*aux;
	int		num;

	aux = *stack_b;
	num = aux->pos;
	while (aux)
	{
		if (num < aux->pos)
			num = aux->pos;
		aux = aux->next;
	}
	aux = *stack_b;
	while (aux)
	{
		if (aux->pos == num)
			break ;
		aux = aux->next;
	}
	return (aux);
}
