/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeum <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:23:49 by dgeum             #+#    #+#             */
/*   Updated: 2024/07/11 16:40:50 by dgeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alphanumeric(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (i == 0)
				str[i] += 'A' - 'a';
			else
			{
				if (!is_alphanumeric(str[i - 1]))
					str[i] += 'A' - 'a';
			}
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (i != 0)
			{
				if (is_alphanumeric(str[i - 1]))
					str[i] -= 'A' - 'a';
			}
		}
		i++;
	}
	return (str);
}
