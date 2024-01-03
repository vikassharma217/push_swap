/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsharma <vsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:03:51 by vsharma           #+#    #+#             */
/*   Updated: 2023/12/29 14:13:12 by vsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void print_stack(t_list **stack)
{
	t_list *temp;
	
	temp = *stack;
	while(temp != NULL)
	{
		printf("%ld\n", temp->number);
		temp = temp->next;
	}
}

t_list	*char_to_int(char *string, t_list **stack)
{
	int			i;
	long int	nbr;
	char		**str;

	str = ft_split(string);
	if (!str)
	{
		free(string);
		exit(error_msg(stack));
	}
	i = 0;
	while (str[i])
	{
		nbr = ft_atoi(str[i]);
		if (ft_strlen(str[i]) > 11 || nbr < -2147483648 || nbr > 2147483647)
		{
			free(string);
			free_str(str);
			exit(error_msg(stack));
		}
		else
			ft_lstadd_back(stack, ft_lstnew(nbr));
		i++;
	}
	free_str(str);
	free(string);
	return (*stack);
}

void	free_stack(t_list **stack_a)
{
	t_list	*temp;
	t_list	*temp1;

	temp = *stack_a;
	while (temp != NULL)
	{
		temp1 = temp->next;
		free(temp);
		temp = temp1;
		if (temp1 == NULL)
			break ;
		temp1 = temp1->next;
	}
}

int	error_msg(t_list **stack_a)
{
	free_stack(stack_a);
	write(2, "Error\n", 6);
	return (-1);
}

int	main(int argc, char **argv)
{
	char	*str;
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*stack_c;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	stack_c = NULL;
	i = 2;
	str = ft_strdup(argv[1]);
	while (i < argc)
	{
		str = ft_strjoin(str, argv[i++]);
		if (!str)
			exit(error_msg(&stack_a));
	}
	stack_a = char_to_int(str, &stack_c);
	if (stack_a == NULL)
	{
		free(str);
		exit(error_msg(&stack_a));
	}
	if (!ft_rank(&stack_a))
		exit(error_msg(&stack_a));
	ft_sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
