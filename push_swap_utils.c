/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsharma <vsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:07:24 by vsharma           #+#    #+#             */
/*   Updated: 2023/11/27 16:27:04 by vsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_check(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while (temp->next != NULL)
	{
		if (temp->number > temp->next->number)
			return (0);
		temp = temp->next;
	}
	return (1);
}

long int	ft_atoi(const char *s)
{
	int			i;
	int			sign;
	long int	result;

	sign = 1;
	i = 0;
	result = 0;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == '\v' || s[i] == '\f'
		|| s[i] == '\r' || s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = sign * -1;
		i++;
	}
	if (!(s[i] >= '0' && s[i] <= '9'))
		return (2147483649);
	while (s[i] >= '0' && s[i] <= '9')
		result = result * 10 + s[i++] - '0';
	if (s[i])
		return (2147483649);
	return (result * sign);
}

int	ft_lstsize(t_list **lst)
{
	t_list	*index;
	int		i;

	if (*lst == NULL)
		return (0);
	index = *lst;
	i = 0;
	while (index != NULL)
	{
		index = index->next;
		i++;
	}
	return (i);
}

t_list	*ft_lstnew(long int nbr)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (0);
	node->number = nbr;
	node->rank = 0;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}
