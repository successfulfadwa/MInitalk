/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faljaoui <faljaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 01:00:43 by faljaoui          #+#    #+#             */
/*   Updated: 2022/05/12 01:38:44 by faljaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void sighandler(int sig)
{
	if (sig == SIGUSR1)
	{
		write(1,"message sent ..",16);
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
		if ()
			check_pid = kill(server_pid,SIGUSR1);
		else
			check_pid = kill(server_pid,SIGUSR2);
		if (check_pid == -1)
			return 1;
		i++;
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	int	i;
	int	server_pid;

	i = 0;
	if (argc != 3)
		return write(1,"not enough arguments ...",25), 1;
	server_pid = atoi(argv[1]);
	while (argv[2][i])
	{
		if(send_byte(argv[2][i],server_pid))
			return write(1,"pid error",10), 1;
		i++;
	}
	pause();
	return 0;
}
