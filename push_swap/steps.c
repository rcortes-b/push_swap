/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:35:35 by rcortes-          #+#    #+#             */
/*   Updated: 2024/02/14 16:35:40 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	amount_moves_a(t_list *stack, int index)
{
	t_list	*aux;
	int		size;
	int		counter;

	aux = stack;
	size = ft_lstsize(stack);
	counter = 0;
	while (aux && counter < index)
	{
		counter++;
		aux = aux->next;
	}
	if (((size % 2) == 1) && (counter == (size / 2)))
		return (counter);
	if (counter < (size / 2))
		return (counter);
	else if (counter >= (size / 2))
		return (counter - size);
	return (0);
}

int	abs_value(int num1, int num2)
{
	if (num1 < 0)
		num1 *= -1;
	if (num2 < 0)
		num2 *= -1;
	return (num1 + num2);
}

static int	index_for_b(t_list *stack_b, int pos)
{
	t_list	*aux;
	int		target;

	aux = stack_b;
	target = 0;
	while (aux)
	{
		if (aux->pos < pos && target < aux->pos)
		{
			target = aux->pos;
		}
		aux = aux->next;
	}
	return (target);
}

int	get_bsteps(t_list *stack_b, int counter)
{
	int	size;

	size = ft_lstsize(stack_b);
	if (counter <= (size / 2))
		return (counter);
	else if (counter > (size / 2))
		return (counter - size);
	return (0);
}

int	calc_bsteps(t_list	*stack_b, int pos)
{
	t_list	*aux;
	int		steps;
	int		counter;

	steps = 0;
	counter = 0;
	aux = stack_b;
	if (isbigger(stack_b, pos) == 0)
		return (steps_for_bigger(stack_b));
	else if (is_smaller(stack_b, pos) == 0)
		return (steps_for_smaller(stack_b));
	else
	{
		steps = index_for_b(stack_b, pos);
		while (aux)
		{
			if (steps == aux->pos)
				break ;
			counter++;
			aux = aux->next;
		}
	}
	return (get_bsteps(stack_b, counter));
}
