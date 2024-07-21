/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeum <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 03:30:34 by dgeum             #+#    #+#             */
/*   Updated: 2024/07/12 05:31:51 by dgeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ascend(char **str1, char **str2)
{
	int		i;
	char	*temp;

	i = 0;
	while ((*str1)[i] != 0 || (*str2)[i] != 0)
	{
		if ((*str1)[i] > (*str2)[i])
		{
			temp = *str1;
			*str1 = *str2;
			*str2 = temp;
			return ;
		}
		else if ((*str1)[i] < (*str2)[i])
			return ;
		i++;
	}
}

void	_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			ascend(&argv[i], &argv[j]);
			j++;
		}
		i++;
	}
	i = 1;
	while (i < argc)
	{
		_putstr(argv[i]);
		i++;
	}
}
