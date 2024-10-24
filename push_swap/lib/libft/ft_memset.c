#include "libft.h"

static long int fillbytes(int byte) 
{
	return (0x0101010101010101 * byte);
}

static void write_page(long int *dstp, t_ulint cccc)
{
	((t_ulint *)*dstp)[0] = cccc;
	((t_ulint *)*dstp)[1] = cccc;
	((t_ulint *)*dstp)[2] = cccc;
	((t_ulint *)*dstp)[3] = cccc;
	((t_ulint *)*dstp)[4] = cccc;
	((t_ulint *)*dstp)[5] = cccc;
	((t_ulint *)*dstp)[6] = cccc;
	((t_ulint *)*dstp)[7] = cccc;
	*dstp += sizeof(t_ulint) * 8;
}

void *ft_memset(void *dstpp, int c, t_size len)
{
	long int	dstp;
	t_ulint	cccc;
	t_size xlen;
	
	if (dstpp == NULL)
		return (dstpp);
	dstp = (long int) dstpp;
	if (len >= 8) 
	{
		cccc = (t_ulint) fillbytes(c);
		while (dstp % sizeof(t_ulint) && len--)
			((char *)dstp++)[0] = c;
		xlen = len / sizeof(t_ulint) * 8;
		while (xlen--)
			write_page(&dstp, cccc);
		len %= sizeof(t_ulint) * 8;
		xlen = len / sizeof(t_ulint);
		while (xlen--)
			((t_ulint *)dstp++)[0] = cccc;
	}
	while (len--)
		((char *)dstp++)[0] = c;
	return (dstpp);
};