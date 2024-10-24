#ifndef FT_COMMONS_H
#define FT_COMMONS_H

#include "unistd.h"
#include "stdlib.h"

typedef unsigned int t_size;
typedef unsigned long int t_ulint;

int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);
int ft_isspace(int c);

t_size ft_strlen(const char *str);

void *ft_memset(void *dstpp, int c, t_size len);
void *ft_bzero(void *dstpp, t_size len);

#endif