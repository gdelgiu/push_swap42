/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 22:52:46 by gdel-giu          #+#    #+#             */
/*   Updated: 2022/03/01 22:52:48 by gdel-giu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

void	ft_bzero(void *s, int n);
void	*ft_memset(void *b, int c, int len);
void    *ft_calloc(int count, int size);

int     ft_isdigit(char c);
int     ft_strlen(char *str);

char    *ft_substr(char *s, int start, int len);
char    **ft_split(char *str, char c);

long	ft_atol(const char *str);


#endif
