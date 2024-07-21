/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush01.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonjuki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:10:14 by yeonjuki          #+#    #+#             */
/*   Updated: 2024/07/10 19:45:18 by dgeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUSH01_H
# define FT_RUSH01_H

# include <stdlib.h>
# include <unistd.h>

void	init_grid(int *grid);
int		arg_is_valid(char *ptr);
int		ft_strlen(char *str);
void	move_idx(int *row, int *col, int direction);
void	fill_hint(int *board, int hint, int hint_type, int hint_idx);
int		read_hint(int *hint_ptr, int *board);
int		is_valid(int *grid, int index, int num);
void	find_all_solutions(int *grid, int index, int *flag, int *input);
int		check_main(int *buffer, int *input, int i);
int		check_1(int *buffer, int index, int *input);
int		check_2(int *buffer, int index, int *input);
int		check_3(int *buffer, int index, int *input);
int		check_4(int *buffer, int index, int *input);
void	_putchar(char c);
void	print_result(int *result);
int		arg_validation(char *str);
int		parse_args(int *args, char *str, int len);

#endif
