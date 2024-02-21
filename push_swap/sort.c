/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:35:51 by rcortes-          #+#    #+#             */
/*   Updated: 2024/02/14 16:35:52 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_back(t_list **stack_a, t_list **stack_b, int moves_a, int moves_b)
{
	if (moves_a < 0 && moves_b < 0)
	{
		while (moves_a < 0 && moves_b < 0)
		{
			reverse_rotate_ab(stack_a, stack_b);
			moves_a++;
			moves_b++;
		}
		while (moves_a < 0)
		{
			reverse_rotate_ab(stack_a, NULL);
			moves_a++;
		}
		while (moves_b < 0)
		{
			reverse_rotate_ab(NULL, stack_b);
			moves_b++;
		}
	}
}

void	move_front(t_list **stack_a, t_list **stack_b, int moves_a, int moves_b)
{
	while (moves_a > 0 && moves_b > 0)
	{
		rotate_ab(*stack_a, *stack_b);
		moves_a--;
		moves_b--;
	}
	while (moves_a > 0)
	{
		rotate_ab(*stack_a, NULL);
		moves_a--;
	}
	while (moves_b > 0)
	{
		rotate_ab(NULL, *stack_b);
		moves_b--;
	}
}

void	move_only_a(t_list **stack_a, int moves_a)
{
	if (moves_a < 0)
	{
		while (moves_a < 0)
		{
			reverse_rotate_ab(stack_a, NULL);
			moves_a++;
		}
	}
	else if (moves_a > 0)
	{
		while (moves_a > 0)
		{
			rotate_ab(*stack_a, NULL);
			moves_a--;
		}
	}
}

void	move_only_b(t_list **stack_b, int moves_b, t_list **stack_a)
{
	if (moves_b < 0)
	{
		while (moves_b < 0)
		{
			reverse_rotate_ab(NULL, stack_b);
			moves_b++;
		}
	}
	else if (moves_b > 0 && ft_lstsize(*stack_b) > moves_b)
	{
		while (moves_b > 0)
		{
			rotate_ab(NULL, *stack_b);
			moves_b--;
		}
	}
	else if (moves_b > ft_lstsize(*stack_b))
		sort_if_last(stack_a, stack_b);
}

void	last_order(t_list **stack_a, t_list **stack_b)
{
	t_list	*aux;
	int		bigger;
	int		counter;

	aux = *stack_b;
	bigger = aux->pos;
	counter = 0;
	while (aux)
	{
		if (bigger < aux->pos)
			bigger = aux->pos;
		aux = aux->next;
	}
	aux = *stack_b;
	while (aux->pos != bigger)
	{
		counter++;
		aux = aux->next;
	}
	move_only_b(stack_b, counter, stack_a);
	aux = *stack_a;
}
