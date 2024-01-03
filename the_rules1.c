/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_rules1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsharma <vsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:20:25 by vsharma           #+#    #+#             */
/*   Updated: 2023/11/27 13:21:38 by vsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_up(t_list **stack_a, t_list **stack_b, char stack)
{
	if (stack == 'a' && ft_lstsize(stack_a) >= 2)
	{
		ft_rotate_up(stack_a);
		write(1, "ra\n", 3);
	}
	else if (stack == 'b' && ft_lstsize(stack_b) >= 2)
	{
		ft_rotate_up(stack_b);
		write(1, "rb\n", 3);
	}
	else if (stack == 'r' && ft_lstsize(stack_a) >= 2
		&& ft_lstsize(stack_b) >= 2)
	{
		ft_rotate_up(stack_a);
		ft_rotate_up(stack_b);
		write(1, "rr\n", 3);
	}
}

void	ft_rotate_up(t_list **stack)
{
	t_list	*stack_head;
	t_list	*temp;

	stack_head = *stack;
	temp = stack_head;
	while (temp->next != NULL)
		temp = temp->next;
	*stack = stack_head->next;
	temp->next = stack_head;
	stack_head->next = NULL;
}

void	rotate_down(t_list **stack_a, t_list **stack_b, char stack)
{
	if (stack == 'a' && ft_lstsize(stack_a) >= 2)
	{
		ft_rotate_down(stack_a);
		write(1, "rra\n", 4);
	}
	else if (stack == 'b' && ft_lstsize(stack_b) >= 2)
	{
		ft_rotate_down(stack_b);
		write(1, "rrb\n", 4);
	}
	else if (stack == 'r' && ft_lstsize(stack_b) >= 2
		&& ft_lstsize(stack_a) >= 2)
	{
		ft_rotate_down(stack_a);
		ft_rotate_down(stack_b);
		write(1, "rrr\n", 4);
	}
}

void	ft_rotate_down(t_list **stack)
{
	t_list	*stack_head;
	t_list	*last;
	t_list	*second_last;

	stack_head = *stack;
	second_last = stack_head;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	last = second_last->next;
	last->next = stack_head;
	second_last->next = NULL;
	*stack = last;
}
