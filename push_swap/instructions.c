/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:48:50 by rcortes-          #+#    #+#             */
/*   Updated: 2024/02/08 19:48:51 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:08:11 by rcortes-          #+#    #+#             */
/*   Updated: 2024/02/03 15:08:12 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_aux(t_list **stack)
{
	int	tmp;
	int	tmp_pos;

	tmp = (*stack)->num;
	tmp_pos = (*stack)->pos;
	(*stack)->num = (*stack)->next->num;
	(*stack)->pos = (*stack)->next->pos;
	(*stack)->next->num = tmp;
	(*stack)->next->pos = tmp_pos;
}

void	swap_function(t_list *stack, t_list *stack2)
{
	if (stack)
		swap_aux(&stack);
	if (stack2)
		swap_aux(&stack2);
	if (stack && !stack2)
		ft_printf("sa\n");
	else if (!stack && stack2)
		ft_printf("sb\n");
	else
		ft_printf("ss\n");
}

void	rotate_function(t_list *stack)
{
	int		tmp;
	int		tmp_pos;
	t_list	*aux;

	tmp = stack->num;
	tmp_pos = stack->pos;
	aux = stack;
	while (aux->next)
	{
		aux->num = aux->next->num;
		aux->pos = aux->next->pos;
		aux = aux->next;
	}
	aux->pos = tmp_pos;
	aux->num = tmp;
}

void	rotate_ab(t_list *stack_a, t_list *stack_b)
{
	int	ret;

	ret = 0;
	if (stack_a)
	{
		if (!stack_a->next && !stack_b)
			return ;
		else if (!stack_a->next)
			ret = 1;
		if (ret == 0)
			rotate_function(stack_a);
		if (!stack_b && ret == 0)
			ft_printf("ra\n");
	}
	if (stack_b)
	{
		if (!stack_b->next)
			return ;
		rotate_function(stack_b);
		if (!stack_a || ret == 1)
			ft_printf("rb\n");
	}
	if (ret == 0 && stack_a && stack_b)
		ft_printf("rr\n");
}
