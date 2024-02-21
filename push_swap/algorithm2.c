/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:51:16 by rcortes-          #+#    #+#             */
/*   Updated: 2024/02/14 16:51:16 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	group_functions(t_list **stack_a, t_list **stack_b)
{
	sort_three(stack_a);
	last_order(stack_a, stack_b);
	final_sort(stack_a, stack_b);
}

int	check_reverse_order(t_list *stack_b)
{
	t_list	*aux;

	aux = stack_b;
	while (aux->next)
	{
		if (aux->pos < aux->next->pos)
			return (1);
		aux = aux->next;
	}
	return (0);
}

void	aux_for_little(t_list **stack_b, int counter)
{
	counter = ft_lstsize(*stack_b) - counter;
	while (counter > 0)
	{
		rotate_ab(NULL, *stack_b);
		counter--;
	}
}
