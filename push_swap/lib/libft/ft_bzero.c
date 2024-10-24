#include "libft.h"

void *ft_bzero(void *dstpp, t_size len) 
{
	return (ft_memset(dstpp, 0, len));
}