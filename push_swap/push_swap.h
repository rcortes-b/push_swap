/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:08:37 by rcortes-          #+#    #+#             */
/*   Updated: 2024/02/03 15:08:38 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

void	swap_aux(t_list **stack);
void	swap_function(t_list *stack, t_list *stack2);

void	rotate_ab(t_list *stack_a, t_list *stack_b);
void	rotate_function(t_list *stack);

void	reverse_rotate_ab(t_list **stack_a, t_list **stack_b);
void	reverse_rotate(t_list **stack);

void	push_from_to(t_list **stack_from, t_list **stack_to, const char *move);

//Checking && Taking Arguments
int		check_empty(char *str);
void	full_checker(char **split, int index, t_list **stack_a);
t_list	*get_args(char **argv, t_list *stack, int j);
int		check_if_sorted(t_list *stack);

void	assign_position(t_list **stack);
int		aux_position(t_list	**stack, int last, int index);

//Temporal Function for Checking / Debugging
void	temp_check_function(t_list *stack_a, t_list *stack_b);
void	print_stack(t_list *stack);
void	little_print(t_list	*stack_a, t_list *stack_b);

//Algorithm for Cases (2, 3, 4, 5)
int		check_if_middle(t_list *stack);
int		aux_counter(t_list *stack_a, t_list *stack_b);
int		check_last_lowers(t_list *stack, t_list *aux, t_list *middle, int min);
void	aux_for_counter2(t_list **stack_a, t_list **stack_b);
void	sort_three(t_list **stack);
void	sort_five(t_list **stack_a, t_list **stack_b);
void	sort_four_from_five_aux(t_list **stack_a, t_list **stack_b);
void	sort_last_from_five(t_list **stack_a, t_list **stack_b);
void	order_five_a(t_list **stack);
void	sort_special_case(t_list **stack_a, t_list **stack_b, int amount);

//Algorithm for +5 Case
void	push_swap(t_list **stack_a, t_list **stack_b, int abs);
void	first_step(t_list **stack_a, t_list **stack_b);
void	move_cheapest(t_list **stack_a, t_list **stack_b,
			int moves_a, int moves_b);
int		get_cheapest(t_list **stack_a, t_list **stack_b, int index);

int		amount_moves_a(t_list *stack, int index);
int		abs_value(int num1, int num2);

int		calc_bsteps(t_list	*stack_b, int pos);

//Getting B
int		isbigger(t_list *stack_b, int pos);
int		steps_for_bigger(t_list *stack_b);
int		is_smaller(t_list *stack_b, int pos);
int		steps_for_smaller(t_list *stack_b);
int		get_bsteps(t_list *stack_b, int counter);

//Sorting
void	move_front(t_list **stack_a, t_list **stack_b,
			int moves_a, int moves_b);
void	move_back(t_list **stack_a, t_list **stack_b, int moves_a, int moves_b);
void	move_only_a(t_list **stack_a, int moves_a);
void	move_only_b(t_list **stack_b, int moves_b, t_list **stack_a);
void	last_order(t_list **stack_a, t_list **stack_b);
void	final_sort(t_list **stack_a, t_list **stack_b);
void	group_functions(t_list **stack_a, t_list **stack_b);

int		check_last(t_list **stack_a, t_list **stack_b);
void	sort_if_last(t_list **stack_a, t_list **stack_b);
int		first_position(t_list **stack_a, t_list **stack_b);
void	if_last_isbigger(t_list **stack_b);
t_list	*set_ptr_bigger(t_list **stack_b);
int		check_reverse_order(t_list *stack_b);
void	aux_for_little(t_list **stack_b, int counter);
#endif
