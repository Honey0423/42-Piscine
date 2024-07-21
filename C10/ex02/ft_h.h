/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeum <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 01:34:28 by dgeum             #+#    #+#             */
/*   Updated: 2024/07/17 04:04:54 by dgeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H_H
# define FT_H_H

# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <libgen.h>
# include <stdlib.h>

int		jump(char *str, int i, int *sign);
int		ft_atoi(char *str);
void	_printstr(char *str);
void	_printargs(char *str, char *files[], int argc, int index);
void	_printerrno(char *str1, char *str2);
#endif
