/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:48:54 by rcortes-          #+#    #+#             */
/*   Updated: 2024/02/08 19:48:55 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list **stack)
{
	t_list	*new;
	t_list	*last;
	t_list	*aux;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return ;
	last = ft_lstlast(*stack);
	new->num = last->num;
	new->pos = last->pos;
	new->next = NULL;
	new->content = NULL;
	ft_lstadd_front(stack, new);
	aux = *stack;
	while (aux->next->next)
		aux = aux->next;
	aux->next = NULL;
	if (last->content)
		free(last->content);
	free(last);
}

void	reverse_rotate_ab(t_list **stack_a, t_list **stack_b)
{
	int	ret;

	ret = 0;
	if (stack_a)
	{
		if (!(*stack_a)->next && !stack_b)
			return ;
		else if (!(*stack_a)->next)
			ret = 1;
		if (ret == 0)
			reverse_rotate(stack_a);
		if (!stack_b && ret == 0)
			ft_printf("rra\n");
	}
	if (stack_b)
	{
		if (!(*stack_b)->next)
			return ;
		reverse_rotate(stack_b);
		if (!stack_a || ret == 1)
			ft_printf("rrb\n");
	}
	if (ret == 0 && stack_a && stack_b)
		ft_printf("rrr\n");
}

void	push_from_to(t_list **stack_from, t_list **stack_to, const char *move)
{
	t_list	*new;
	t_list	*aux;

	if (!*stack_from)
		return ;
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return ;
	new->num = (*stack_from)->num;
	new->pos = (*stack_from)->pos;
	new->next = NULL;
	new->content = NULL;
	ft_lstadd_front(stack_to, new);
	aux = *stack_from;
	*stack_from = (*stack_from)->next;
	if (aux->content)
		free(aux->content);
	free(aux);
	if (ft_strncmp(move, "pb", 2) == 0)
		ft_printf("pb\n");
	else if (ft_strncmp(move, "pa", 2) == 0)
		ft_printf("pa\n");
}
