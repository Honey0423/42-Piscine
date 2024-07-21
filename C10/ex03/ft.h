/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeum <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:56:45 by dgeum             #+#    #+#             */
/*   Updated: 2024/07/20 08:11:42 by dgeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <libgen.h>
# include <stdlib.h>

int		check(unsigned char *str1, unsigned char *str2, int len1, int len2);
int		ft_strcpy(char *str1, char *str2, int index);
int		argv_open(int *fd, char *argv[], int i);
char	to_hex(int num);
void	print_hex(unsigned char *str, int len);
void	print_word(unsigned char *str, int len);
void	_printstr(char *str);
void	_printerrno(char *str1, char *str2);
void	ft_print_memory(void *addr, unsigned int size);
int		sizecheck(int *fd);
int		_sizecheck(char *filepath);
int		ft_strcmp(char *s1, char *s2);
void	print_addr(unsigned int addr);

#endif
