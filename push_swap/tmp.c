#include <libft.h>

typedef unsigned long int t_ulint;

// memmove
static void wordcpy(t_ulint *dstp, t_ulint *srcp, t_size *len)
{
	while ((*len)--)
	{
		((t_ulint *)*dstp)--[0] = ((t_ulint *)*srcp)--[0];
	}
}

static void bytecpy(t_ulint *dstp, t_ulint *srcp, t_size len)
{
	while (len--)
		((char *)*dstp--)[0] = ((char *)*srcp--)[0];
}

void *ft_memmove(void *dstpp, const void *srcpp, t_size len) 
{
	t_ulint dstp;
	t_ulint srcp;
	
	dstp = (long int) dstpp;
	srcp = (long int) srcpp;
	if (dstp - srcp >= len)
		return (ft_memcpy(dstpp, srcpp, len));	
	srcp += len;
	dstp += len;
	if (len >= sizeof(t_ulint))
	{
		len -= dstp % sizeof(t_ulint);
		bytecpy(&dstp, &srcp, dstp % sizeof(t_ulint));
		wordcpy(&dstp, &srcp, &len);
	}
	bytecpy(&dstp, &srcp, len);
	return (dstpp);
}

// memchr

static const unsigned char	*checkword(const t_ulint *w_ptr, int c, int *n)
{
	t_ulint repeated_one;
	t_ulint repeated_c;
	t_ulint w_tmp;
	
	repeated_one = 0x0101010101010101U;
	repeated_c = 0x0101010101010101U * (c & 0xff);
	while (*n >= sizeof(t_ulint))
	{
		w_tmp = *w_ptr ^ repeated_c;
		if ((((w_ptr - repeated_one) & ~w_ptr) & (repeated_one << 7)))
			break;
		w_ptr++;
		*n -= sizeof(t_ulint);
	}
	return ((const unsigned char *) w_ptr);
}

void *ft_memchr(void const *s, int c, t_size n)
{
	const unsigned char *c_ptr;
	unsigned char chr;
	
	c_ptr = (const unsigned char *) s;
	chr = c;
	while ((t_ulint) c_ptr % sizeof(t_ulint) && n-- > 0)
	{
		if (*c_ptr == chr)
			return (void *) c_ptr;
		c_ptr++;
	}
	c_ptr = checkword(&(const t_ulint *) c_ptr, chr, &n);
	while (n-- > 0)
	{
		if (*c_ptr == chr)
			return (void *) c_ptr;
		c_ptr++;
	}
	return (NULL);
}

// memcmp

static int memcmp_common_alignment(t_ulint srcp1, t_ulint srcp2, t_size len)
{
	
}


static int memcmp_uncomm_alignment(t_ulint srcp1, t_ulint srcp2, t_size len)
{
	
}

int ft_memcmp(const void *s1, const void *s2, t_size len)
{
	int res;
	t_ulint srcp1;
	t_ulint srcp2;
	
	srcp1 = (t_ulint) s1;
	srcp2 = (t_ulint) s2;
	if (len >= sizeof(t_ulint))
	{
		while (srcp2 % sizeof(t_ulint) && len--)
		{
			res = (int)*((char *)srcp1++) - (int)*((char *)srcp2++);
			if (res)
				return (res);
		}
		if (srcp1 % sizeof(t_ulint))
			res = memcmp_uncomm_alignment(srcp1, srcp2, len / sizeof(t_ulint));
		else
			res = memcmp_common_alignment(srcp1, srcp2, len / sizeof(t_ulint));
		if (res)
			return (res);
		srcp1 += len & -sizeof(t_ulint);
		srcp2 += len & -sizeof(t_ulint);
		len %= sizeof(t_ulint);
	}
	while (len--)
	{
		res = ((int)*((char *)srcp1++)) - ((int)*((char *)srcp2++));
		if (res)
			return (res);
	}
	return (0);
}
