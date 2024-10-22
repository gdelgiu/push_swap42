#include "commands.h"

void double_print_cmd(t_ps_comm cmd) {
	if (cmd == SSWAP)
		printf("ss\n");
	else if (cmd == RROTT)
		printf("rr\n");
	else if (cmd == RRROT)
		printf("rrr\n");
	else
		(void) cmd;
}

void print_cmd(t_ps_comm cmd) {
	if (cmd == PUSHA)
		printf("pa\n");
	else if (cmd == PUSHB)
		printf("pb\n");
	else if (cmd == SWAPA)
		printf("sa\n");
	else if (cmd == SWAPB)
		printf("sb\n");
	else if (cmd == ROTTA)
		printf("ra\n");
	else if (cmd == ROTTB)
		printf("rb\n");
	else if (cmd == RROTA)
		printf("rra\n");
	else if (cmd == RROTB)
		printf("rrb\n");
	else
		(void) cmd;
}