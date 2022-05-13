
#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <stdio.h>

int				ft_atoi(const char *str);
int				ft_putstr(char const *s);
int				ft_putchar(char c);
size_t			ft_nb_len(int n);
int				ft_putnbr2(int nb);
int				ft_putnbr(int nb);

#endif
