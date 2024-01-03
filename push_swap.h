/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsharma <vsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:04:08 by vsharma           #+#    #+#             */
/*   Updated: 2023/12/29 12:58:33 by vsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	long int		number;
	int				rank;
	struct s_list	*next;
}					t_list;

typedef struct s_split
{
	char			**out;
	int				i;
	int				k;
	int				j;
}					t_split;

long int			ft_atoi(const char *str);
int					ft_lstsize(t_list **lst);
t_list				*ft_lstnew(long int nbr);
void				ft_lstadd_back(t_list **lst, t_list *new);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char *s1, char const *s2);

char				*ft_strncpy(char *s1, char *s2, int n);
int					word_counter(char *str);
char				**ft_split(char *str);

void				ft_sort(t_list **stack_a, t_list **stack_b);
int					sort_check(t_list **stack);
void				sort_two(t_list **stack_a, t_list **stack_b);
void				sort_three(t_list **stack_a, t_list **stack_b);
void				sort_four(t_list **stack_a, t_list **stack_b, int x);
void				sort_five(t_list **stack_a, t_list **stack_b);
void				ft_radix(t_list **stack_a, t_list **stack_b);

void				ft_swap(t_list **stack_a);
void				swap(t_list **stack_a, t_list **stack_b, char stack_type);
void				push(t_list **src_stack, t_list **dst_stack, char dst);
void				rotate_up(t_list **stack_a, t_list **stack_b, char stack);
void				ft_rotate_up(t_list **stack);
void				rotate_down(t_list **stack_a, t_list **stack_b, char stack);
void				ft_rotate_down(t_list **stack);
void				display_rank(t_list **stack);
int					ft_rank(t_list **stack);
int					error_msg(t_list **stack_a);
void				free_str(char **str);

#endif
