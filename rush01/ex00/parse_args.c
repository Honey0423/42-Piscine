/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonjuki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:50:35 by yeonjuki          #+#    #+#             */
/*   Updated: 2024/07/10 19:42:54 by dgeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush01.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	arg_is_valid(char *ptr)
{
	if (*(ptr + 1) != ' ' && *(ptr + 1) != '\0')
		return (0);
	if ('1' > ptr[0] || ptr[0] > '4')
		return (0);
	if (ptr[1] == '0')
		ptr[1] = ptr[1];
	return (1);
}

int	arg_validation(char *str)
{
	int	idx;
	int	len;

	len = ft_strlen(str);
	if (len != 31)
		return (0);
	idx = 0;
	while (idx < len)
	{
		if (!arg_is_valid(&str[idx]))
			return (0);
		idx += 2;
	}
	return (1);
}

int	parse_args(int *args, char *str, int len)
{
	int	idx;
	int	cnt;

	idx = 0;
	cnt = 0;
	while (idx < len && cnt < 16)
	{
		args[cnt] = *(str + idx) - '0';
		cnt++;
		idx += 2;
	}
	if (cnt != 16)
		return (0);
	return (1);
}
