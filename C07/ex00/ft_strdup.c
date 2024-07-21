/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeum <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 05:42:39 by dgeum             #+#    #+#             */
/*   Updated: 2024/07/12 06:02:28 by dgeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*new;

	i = 0;
	while (src[i] != 0)
		i++;
	new = (char *)malloc(sizeof(char) * i);
	i = 0;
	while (src[i] != 0)
	{
		new[i] = src[i];
		i++;
	}
	new[i] = src[i];
	return (new);
}
