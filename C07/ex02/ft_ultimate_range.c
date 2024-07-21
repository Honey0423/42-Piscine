/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeum <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 06:03:08 by dgeum             #+#    #+#             */
/*   Updated: 2024/07/12 06:09:29 by dgeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	num;

	i = 0;
	num = min;
	(*range) = NULL;
	if (min >= max)
		return (0);
	(*range) = (int *)malloc((max - min) * sizeof(int));
	while (num < max)
		(*range)[i++] = num++;
	return (i);
}
