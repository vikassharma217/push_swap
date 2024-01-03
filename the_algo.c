/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsharma <vsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:40:15 by vsharma           #+#    #+#             */
/*   Updated: 2023/11/27 13:27:02 by vsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = ft_lstsize(stack_a);
	if (i <= 1)
		return ;
	else if (i == 2)
		sort_two(stack_a, stack_b);
	else if (i == 3)
		sort_three(stack_a, stack_b);
	else if (i == 4)
		sort_four(stack_a, stack_b, 1);
	else if (i == 5)
		sort_five(stack_a, stack_b);
	else
		ft_radix(stack_a, stack_b);
}

void	sort_two(t_list **stack_a, t_list **stack_b)
{
	if (!sort_check(stack_a))
	{
		swap(stack_a, stack_b, 'a');
	}
}

void	sort_three(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	temp = *stack_a;
	if (sort_check(stack_a))
		return ;
	if (temp->number < temp->next->number)
	{
		rotate_down(stack_a, stack_b, 'a');
		if (!sort_check(stack_a))
			swap(stack_a, stack_b, 'a');
	}
	else if (temp->number > temp->next->next->number)
	{
		rotate_up(stack_a, stack_b, 'a');
		if (!sort_check(stack_a))
			swap(stack_a, stack_b, 'a');
	}
	else
		swap(stack_a, stack_b, 'a');
}

void	sort_four(t_list **stack_a, t_list **stack_b, int x)
{
	t_list	*temp;

	temp = *stack_a;
	if (sort_check(stack_a))
		return ;
	while (temp->next != NULL)
		temp = temp->next;
	if (temp->rank == x)
		rotate_down(stack_a, stack_b, 'a');
	while ((*stack_a)->rank != x)
		rotate_up(stack_a, stack_b, 'a');
	push(stack_a, stack_b, 'b');
	sort_three(stack_a, stack_b);
	push(stack_b, stack_a, 'a');
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	temp = *stack_a;
	if (sort_check(stack_a))
		return ;
	while (temp->next->next != NULL)
		temp = temp->next;
	if (temp->rank == 1 || temp->next->rank == 1)
	{
		while ((*stack_a)->rank != 1)
			rotate_down(stack_a, stack_b, 'a');
	}
	else
	{
		while ((*stack_a)->rank != 1)
			rotate_up(stack_a, stack_b, 'a');
	}
	push(stack_a, stack_b, 'b');
	sort_four(stack_a, stack_b, 2);
	push(stack_b, stack_a, 'a');
}
