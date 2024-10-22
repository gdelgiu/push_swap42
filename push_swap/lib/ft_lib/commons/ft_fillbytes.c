#include "ft_bytes.h"

t_int64 ft_fillbytes(int byte) 
{
	return (0x0101010101010101 * byte);
}