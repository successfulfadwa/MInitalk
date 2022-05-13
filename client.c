/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faljaoui <faljaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 01:00:43 by faljaoui          #+#    #+#             */
/*   Updated: 2022/05/13 05:59:31 by faljaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void sighandlermsg(int sig)
{
	if (sig == SIGUSR1)
	{
		write(1,"message sent ..",16);
		ft_putchar('\n');
		exit(EXIT_SUCCESS);
	}
}

int send_byte(char c, int server_pid)
{
	int	i;
	int	check_pid;

	i = 0;
	check_pid = 0;
	while(i < 8)
	{
		if (c >> i & 1) //1111>>0111 with annd equal 1 send siguser 1; >>4 =0000 &0001 =0 send SIGUSR2
			check_pid = kill(server_pid,SIGUSR1);
		else
			check_pid = kill(server_pid,SIGUSR2);
		if (check_pid == -1)
			return 1;// error
		i++;
		usleep(500);
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	int	i;
	int	server_pid;

	i = 0;
	signal(SIGUSR1, sighandlermsg); // should send signal from server sigusr 1 after msg recive;
	if (argc != 3)
		return write(1,"not enough arguments ...",25), 1;
	server_pid = ft_atoi(argv[1]);
	 printf("%d",server_pid);
	while (argv[2][i])
	{
		if(send_byte(argv[2][i], server_pid))
			return write(1,"pid error",10), 1;
			//1 for errors
		i++;
		
	}
	send_byte(0,server_pid);
	return 0;
}
 