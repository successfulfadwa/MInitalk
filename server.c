/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faljaoui <faljaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 01:34:33 by faljaoui          #+#    #+#             */
/*   Updated: 2022/05/13 01:47:43 by faljaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handler1(int signal ,siginfo_t *info, void *nthng)
{
	(void)nthng;
	(void)info;
	static int i ;
	static char c ;
	if(i<8)
	{
		if(signal== SIGUSR1)
		{
		(c = c | (1<<i));
		}
		i++;
	}
	if (i==8)
	{
		write(1,&c,1);
		i=0;
		c=0;
	}
}
int main()
{
	 int id;
	 struct sigaction action;
	id=getpid();
	ft_putnbr(id);
	action.sa_sigaction=&handler1;
	sigaction(SIGUSR1,&action,NULL);
	sigaction(SIGUSR2,&action,NULL);
	while(1)
	pause();
	return 0;
}
