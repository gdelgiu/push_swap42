#ifndef COMMANDS_H
#define COMMANDS_H

typedef enum e_PS_COMMANDS {
	PUSHA,
	PUSHB,
	SWAPA,
	SWAPB,
	ROTTA,
	ROTTB,
	RROTA,
	RROTB,
	SSWAP,
	RROTT,
	RRROT,
} t_ps_comm;

void print_cmd(t_ps_comm cmd);
void double_print_cmd(t_ps_comm cmd);

#endif