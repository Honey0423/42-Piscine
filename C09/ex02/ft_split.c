/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeum <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 03:21:19 by dgeum             #+#    #+#             */
/*   Updated: 2024/07/16 04:44:44 by dgeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_arrsize(char *str, char *charset)
{
	int	i;
	int	j;
	int	count;
	int	before;

	i = 0;
	before = 0;
	count = 1;
	while (str[i] != 0)
	{
		j = 0;
		while (charset[j] != 0)
		{
			if (str[i] == charset[j] && (i - before) != 1)
			{
				++count;
				before = i;
			}
			++j;
		}
		++i;
	}
	return (count);
}

int	get_strlen(char *str, int index, char *charset)
{
	int	i;
	int	j;

	i = 0;
	while (str[index + i] != 0)
	{
		j = 0;
		while (charset[j] != 0)
		{
			if (str[index + i] == charset[j])
			{
				return (i);
			}
			++j;
		}
		++i;
	}
	return (i);
}

char	*str_allocation(char *str, int index, char *charset)
{
	int		i;
	int		len;
	char	*result;

	i = 0;
	len = get_strlen(str, index, charset);
	result = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		result[i] = str[index + i];
		++i;
	}
	result[i] = '\0';
	return (result);
}

int	check_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != 0)
	{
		if (charset[i] == c)
			return (1);
		++i;
	}
	return (0);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		i;
	int		k;
	int		before;

	result = (char **)malloc(sizeof(char *) * (get_arrsize(str, charset) + 1));
	i = -1;
	k = 0;
	before = 0;
	while (str[++i] != 0)
	{
		if (check_charset(str[i], charset))
		{
			if (i != before)
				result[k++] = str_allocation(str, before, charset);
			before = i + 1;
		}
	}
	if (i != before)
		result[k++] = str_allocation(str, before, charset);
	result[k] = 0;
	return (result);
}
