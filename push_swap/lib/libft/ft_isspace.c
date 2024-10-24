#include "libft.h"

int ft_isspace(int c)
{
	return ((c == ' ') || (c >= 0x9 && c <= 0xB));
}