/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeum <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 05:47:49 by dgeum             #+#    #+#             */
/*   Updated: 2024/07/12 05:52:16 by dgeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	num;
	int	*result;

	i = 0;
	num = min;
	result = NULL;
	if (min >= max)
		return (result);
	result = (int *)malloc((max - min) * sizeof(int));
	while (num < max)
	{
		result[i++] = num++;
	}
	return (result);
}
