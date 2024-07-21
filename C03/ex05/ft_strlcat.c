/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeum <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 03:12:12 by dgeum             #+#    #+#             */
/*   Updated: 2024/07/09 04:10:12 by dgeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dstlen;
	unsigned int	srclen;

	i = 0;
	dstlen = _strlen(dest);
	srclen = _strlen(src);
	while (src[i] != 0 && dstlen + i + 1 < size)
	{
		dest[dstlen + i] = src[i];
		i++;
	}
	dest[dstlen + i] = '\0';
	if (dstlen >= size)
		return (srclen + size);
	return (srclen + dstlen);
}
