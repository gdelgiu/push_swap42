#ifndef FT_LIB_H
#define FT_LIB_H

#include <unistd.h>
#include <stdlib.h>

long	ft_atol(const char *str);
void	ft_bzero(void *s, int n);
void	*ft_calloc(int count, int size);
int	ft_isdigit(char c);
void	*ft_memset(void *b, int c, int len);
char	**ft_split(char *str, char c);
int	ft_strlen(char *str);
char	*ft_substr(char *s, int start, int len);







#endif