/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeum <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 06:40:40 by dgeum             #+#    #+#             */
/*   Updated: 2024/07/20 06:41:52 by dgeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(char **str1, char **str2)
{
	char	*temp;

	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	j;

	i = 0;
	while (tab[i] != 0)
	{
		j = 0;
		while (tab[j + 1] != 0)
		{
			if (cmp(tab[j], tab[j + 1]) > 0)
				swap(&tab[j], &tab[j + 1]);
			++j;
		}
		++i;
	}
}
