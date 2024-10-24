#include "libft.h"

static void wordcopy(t_ulint *dstp, t_ulint *srcp, t_size *len)
{
	t_size xlen;

	xlen = *len / sizeof(t_ulint); 
	while (xlen--)
		((t_ulint *)*dstp)[0] = ((t_ulint *)*srcp)[0];
	*len %= sizeof(t_ulint);
}

static void pagecopy(t_ulint *dstp, t_ulint *srcp, t_size *len)
{
	t_size xlen;

	xlen = *len / (sizeof(t_ulint) * 8); 
	while (xlen--)
	{
		((t_ulint *)*dstp)[0] = ((t_ulint *)*srcp)[0];
		((t_ulint *)*dstp)[1] = ((t_ulint *)*srcp)[1];
		((t_ulint *)*dstp)[2] = ((t_ulint *)*srcp)[2];
		((t_ulint *)*dstp)[3] = ((t_ulint *)*srcp)[3];
		((t_ulint *)*dstp)[4] = ((t_ulint *)*srcp)[4];
		((t_ulint *)*dstp)[5] = ((t_ulint *)*srcp)[5];
		((t_ulint *)*dstp)[6] = ((t_ulint *)*srcp)[6];
		((t_ulint *)*dstp)[7] = ((t_ulint *)*srcp)[7];
		*dstp += sizeof(t_ulint) * 8;
		*srcp += sizeof(t_ulint) * 8;
	}
	*len %= (sizeof(t_ulint) * 8);
}

static void bytecopy(t_ulint *dstp, t_ulint *srcp, t_size len)
{
	while (len--)
		((char *)*dstp++)[0] = ((char *)*srcp++)[0];
}

void *ft_memcpy(void *dstpp, const void *srcpp, t_size len) 
{
	t_ulint dstp;
	t_ulint srcp;

	dstp = (long int) dstpp;
	srcp = (long int) srcpp;
	if (len >= sizeof(dstp))
	{
		len -= (-dstp) % sizeof(dstp);
		bytecopy(&dstp, &srcp, (-dstp) % sizeof(dstp));
		pagecopy(&dstp, &srcp, &len);
		wordcopy(&dstp, &srcp, &len);
	}
	bytecopy(&dstp, &srcp, len);
	return (dstpp);
}