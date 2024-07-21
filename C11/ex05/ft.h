/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeum <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 00:08:02 by dgeum             #+#    #+#             */
/*   Updated: 2024/07/20 06:28:14 by dgeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>

int		jump(char *str, int i, int *sign);
int		ft_atoi(char *str);
void	division(int num1, int num2, int oper);
int		_operator(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int input);
#endif
