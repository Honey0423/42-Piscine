/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeum <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 06:09:52 by dgeum             #+#    #+#             */
/*   Updated: 2024/07/19 23:41:07 by dgeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	dest_len;

	i = 0;
	dest_len = _strlen(dest);
	while (src[i] != '\0')
		dest[dest_len++] = src[i++];
	dest[dest_len] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		total_len;
	char	*result;

	i = 0;
	total_len = 0;
	while (i < size)
		total_len += _strlen(strs[i++]);
	if (size > 0)
		total_len += (size - 1) * _strlen(sep);
	result = (char *)malloc(sizeof(char) * (total_len + 1));
	result[0] = '\0';
	if (result == 0)
		return (0);
	i = -1;
	while (++i < size)
	{
		result = ft_strcat(result, strs[i]);
		if (i < size - 1)
			result = ft_strcat(result, sep);
	}
	result[total_len] = '\0';
	return (result);
}
