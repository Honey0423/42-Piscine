/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeum <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:16:08 by dgeum             #+#    #+#             */
/*   Updated: 2024/07/12 00:23:37 by dgeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	calc(int nb, int power, int result)
{
	if (power == 1)
		return (result * nb);
	else
		return (calc(nb, power - 1, result * nb));
}

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
		return (calc(nb, power, 1));
}
