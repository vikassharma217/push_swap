/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsharma <vsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:54:02 by vsharma           #+#    #+#             */
/*   Updated: 2023/11/27 13:24:24 by vsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;

	first = *stack_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
}

void	swap(t_list **stack_a, t_list **stack_b, char stack_type)
{
	t_list	*a_head;
	t_list	*b_head;

	a_head = *stack_a;
	b_head = *stack_b;
	if (stack_type == 'a' && a_head && a_head->next)
	{
		ft_swap(stack_a);
		write(1, "sa\n", 3);
	}
	else if (stack_type == 'b' && b_head && b_head->next)
	{
		ft_swap(stack_b);
		write(1, "sb\n", 3);
	}
	else if (!a_head || !b_head || !a_head->next || !b_head->next)
		return ;
	else
	{
		ft_swap(stack_a);
		ft_swap(stack_b);
		write(1, "ss\n", 3);
	}
}

void	push(t_list **src_stack, t_list **dst_stack, char dst)
{
	t_list	*src_head;
	t_list	*dst_head;

	src_head = *src_stack;
	dst_head = *dst_stack;
	if (src_head == NULL)
		return ;
	*src_stack = src_head->next;
	src_head->next = dst_head;
	*dst_stack = src_head;
	if (dst == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}
