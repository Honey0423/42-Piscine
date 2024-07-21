/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeum <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 05:22:13 by dgeum             #+#    #+#             */
/*   Updated: 2024/07/17 05:15:57 by dgeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		++i;
	return (i);
}

char	*_strcpy(char *str)
{
	int		i;
	int		len;
	char	*result;

	i = 0;
	len = _strlen(str);
	result = (char *)malloc(sizeof(char) * (len + 1));
	while (str[i] != 0)
	{
		result[i] = str[i];
		++i;
	}
	result[i] = '\0';
	return (result);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*result;

	result = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	i = 0;
	while (i < ac)
	{
		result[i].size = _strlen(av[i]);
		result[i].str = av[i];
		result[i].copy = _strcpy(av[i]);
		++i;
	}
	result[i].str = NULL;
	return (result);
}
