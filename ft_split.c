/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsharma <vsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:34:03 by vsharma           #+#    #+#             */
/*   Updated: 2023/12/29 12:58:02 by vsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strncpy(char *s1, char *s2, int n)
{
	char	*s1_start;

	s1_start = s1;
	while (n > 0 && *s2)
	{
		*s1++ = *s2++;
		n--;
	}
	*s1 = '\0';
	return (s1_start);
}

int	word_counter(char *str)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	int len = ft_strlen(str);
	while (i < len) // changed from str[i]
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
			wc++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
	}
	return (wc); // changed from i
}

void free_prev(char **str, int len)
{
	while (len)
	{
		free(str[len]);
		len--;
	}
}

char	**ft_split(char *s)
{
	t_split	d;

	d.out = (char **)malloc(sizeof(char *) * (word_counter(s) + 1));
	if (!d.out)
	{
		free(s);
		return (0);
	}
	d.i = 0;
	d.k = 0;
	int len = ft_strlen(s);
	while (d.i < len)
	{
		while (s[d.i] && (s[d.i] == ' ' || s[d.i] == '\t' || s[d.i] == '\n'))
			d.i++;
		d.j = d.i;
		while (s[d.i] && (s[d.i] != ' ' && s[d.i] != '\t' && s[d.i] != '\n'))
			d.i++;
		if (d.i > d.j)
		{
			d.out[d.k] = (char *)malloc(d.i - d.j + 1);
			d.out[d.k] = NULL;
			if (!d.out[d.k])
			{
				free_str(d.out);
				return (0);
			}
			ft_strncpy(d.out[d.k++], &s[d.j], d.i - d.j);
		}
	}
	d.out[d.k] = NULL;
	free(s);
	return (d.out);
}

/*int	main(void)
{
	char	*str;
	int		i;
	char	**output;

	str = "   Split this     string!!  ";
	i = 0;
	output = ft_split(str);
	if (!output)
		return (0);
	while (output[i])
	{
		printf("str[%d]: %s\n", i, output[i]);
		i++;
	}
	i = 0;
	while (output[i])
		free(output[i++]);
	free(output);
	return (0);
}*/
