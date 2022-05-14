/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faljaoui <faljaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 01:34:33 by faljaoui          #+#    #+#             */
/*   Updated: 2022/05/14 04:35:23 by faljaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sigaction_hand(int signal, siginfo_t *info, void *barbie)
{
	static	int i;
	static	char c;
	static	int	cid;
	(void)barbie;
	if (cid != info->si_pid)
	{
		c = 0;
		i = 0;
	}//if pid process tbdl process back to zero and stop process
	
	cid = info->si_pid;
	if(i < 8)
	{
		if(signal== SIGUSR1)
			c = c | (1<<i);
		i++;
	}
	if (i==8)
	{
		if (c==0)
			kill(info->si_pid,SIGUSR1);
		write(1, &c, 1);
		i=0;
		c=0;
	}
}

int main()
{
	struct sigaction	clsa;
	int pid;
	pid=getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
	clsa.sa_flags = SA_SIGINFO;
	clsa.sa_sigaction = &sigaction_hand;
	sigaction(SIGUSR1, &clsa, NULL);
	sigaction(SIGUSR2, &clsa, NULL);
	while(1)
		pause();
	// return 0;
}
