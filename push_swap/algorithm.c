/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:36:16 by rcortes-          #+#    #+#             */
/*   Updated: 2024/02/14 16:36:17 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_step(t_list **stack_a, t_list **stack_b)
{
	push_from_to(stack_a, stack_b, "pb");
	push_from_to(stack_a, stack_b, "pb");
	if ((*stack_b)->num < (*stack_b)->next->num)
		swap_function(NULL, *stack_b);
}

void	move_cheapest(t_list **stack_a, t_list **stack_b,
		int moves_a, int moves_b)
{
	if (moves_a < 0 && moves_b < 0)
		move_back(stack_a, stack_b, moves_a, moves_b);
	else if (moves_a > 0 && moves_b > 0)
		move_front(stack_a, stack_b, moves_a, moves_b);
	else if (moves_b == 1 && moves_a == 0)
	{
		push_from_to(stack_a, stack_b, "pb");
		swap_function(NULL, *stack_b);
		return ;
	}
	else
	{
		move_only_a(stack_a, moves_a);
		move_only_b(stack_b, moves_b, stack_a);
	}
	push_from_to(stack_a, stack_b, "pb");
}

int	get_cheapest(t_list **stack_a, t_list **stack_b, int index)
{
	t_list	*aux;
	int		moves;
	int		tmp_moves_a;
	int		tmp_moves_b;
	int		tmp_moves;

	aux = *stack_a;
	moves = ft_lstsize(*stack_a);
	while (aux)
	{
		tmp_moves_a = amount_moves_a(*stack_a, index);
		tmp_moves_b = calc_bsteps(*stack_b, aux->pos);
		tmp_moves = abs_value(tmp_moves_a, tmp_moves_b);
		if (tmp_moves < moves)
			moves = tmp_moves;
		index++;
		aux = aux->next;
	}
	return (moves);
}

void	final_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*aux;

	aux = ft_lstlast(*stack_b);
	if ((*stack_b)->pos < aux->pos)
		reverse_rotate_ab(NULL, stack_b);
	while (ft_lstsize(*stack_b) != 0)
	{
		while (check_last(stack_a, stack_b) == 1)
		{
			if (!check_if_sorted(*stack_a) && first_position(stack_a, stack_b))
				break ;
			reverse_rotate_ab(stack_a, NULL);
		}
		push_from_to(stack_b, stack_a, "pa");
	}
	while (check_if_sorted(*stack_a))
		reverse_rotate_ab(stack_a, NULL);
}

void	push_swap(t_list **stack_a, t_list **stack_b, int abs)
{
	t_list	*aux;
	int		moves;
	int		moves_a;
	int		moves_b;
	int		index;

	first_step(stack_a, stack_b);
	while (ft_lstsize(*stack_a) != 3)
	{
		aux = *stack_a;
		moves = get_cheapest(stack_a, stack_b, 0);
		index = 0;
		while (aux)
		{
			moves_a = amount_moves_a(*stack_a, index);
			moves_b = calc_bsteps(*stack_b, aux->pos);
			abs = abs_value(moves_a, moves_b);
			if (moves == abs)
				break ;
			aux = aux->next;
			index++;
		}
		move_cheapest(stack_a, stack_b, moves_a, moves_b);
	}
	group_functions(stack_a, stack_b);
}
