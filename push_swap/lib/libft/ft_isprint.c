#include "libft.h"

int ft_isprint(int c)
{
	return (!(c < ' ' || c >= 127) || ft_isspace(c));
}