/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_for_B.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:36:09 by rcortes-          #+#    #+#             */
/*   Updated: 2024/02/14 16:36:10 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isbigger(t_list *stack_b, int pos)
{
	t_list	*aux;
	int		big;

	aux = stack_b;
	big = 0;
	while (aux)
	{
		if (aux->pos > pos)
			return (1);
		aux = aux->next;
	}
	return (0);
}

int	steps_for_bigger(t_list *stack_b)
{
	t_list	*aux;
	int		big;
	int		counter;
	int		steps;

	big = 0;
	counter = 0;
	steps = 0;
	aux = stack_b;
	while (aux)
	{
		if (big < aux->pos)
		{
			big = aux->pos;
			steps = counter;
		}
		counter++;
		aux = aux->next;
	}
	return (steps);
}

int	is_smaller(t_list *stack_b, int pos)
{
	t_list	*aux;

	aux = stack_b;
	while (aux)
	{
		if (pos > aux->pos)
			return (1);
		aux = aux->next;
	}
	return (0);
}

int	steps_for_smaller(t_list *stack_b)
{
	t_list	*aux;
	int		smaller;
	int		counter;
	int		steps;

	aux = stack_b;
	counter = 0;
	steps = 0;
	smaller = aux->pos;
	while (aux)
	{
		if (smaller > aux->pos)
		{
			smaller = aux->pos;
			steps = counter;
		}
		counter++;
		aux = aux->next;
	}
	return (counter + 1);
}
