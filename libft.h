
#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <stdio.h>

int		ft_atoi(const char *str);
int		send_byte(char c, int pid);
int		main (int argc, char const *argv[]);
void	handler1(int signal,siginfo_t *info, void *j);
int		main(int argc, char const *argv[]);
void	ft_putstr(char *s);
void	msg_handler1(int signum);
#endif
