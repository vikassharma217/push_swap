/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsharma <vsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:07:45 by vsharma           #+#    #+#             */
/*   Updated: 2023/11/27 16:39:08 by vsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rank(t_list **stack)
{
	t_list	*marker;
	t_list	*index;
	int		i;

	i = 1;
	while (i <= ft_lstsize(stack))
	{
		index = *stack;
		marker = *stack;
		while (index != NULL)
		{
			while (marker->rank != 0)
				marker = marker->next;
			if (index->number < marker->number && index->rank == 0)
				marker = index;
			else if (index->number == marker->number && index != marker)
				return (0);
			index = index->next;
		}
		marker->rank = i;
		i++;
	}
	return (1);
}

void	ft_radix(t_list **stack_a, t_list **stack_b)
{
	int	temp;
	int	digit;

	temp = 0;
	digit = 1;
	while (!sort_check(stack_a))
	{
		while (!((*stack_a)->rank == temp))
		{
			if (((*stack_a)->rank & digit) == 0)
				push(stack_a, stack_b, 'b');
			else
			{
				if (temp == 0)
					temp = (*stack_a)->rank;
				rotate_up(stack_a, stack_b, 'a');
			}
		}
		temp = 0;
		while (*stack_b != NULL)
			push(stack_b, stack_a, 'a');
		digit = digit * 2;
	}
}
