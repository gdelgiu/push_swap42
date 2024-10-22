#ifndef FT_COMMONS_H
#define FT_COMMONS_H

#include "unistd.h"
#include "stdlib.h"
#include "ft_bytes.h"

int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);
int ft_isspace(int c);

t_size ft_strlen(const char *str);

#endif