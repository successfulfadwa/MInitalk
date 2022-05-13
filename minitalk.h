
#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void			sighandlermsg(int sig);
int				send_byte(char c, int server_pid);
int				main(int argc, char const *argv[]);
void			handler1(int signal ,siginfo_t *info, void *nthng);
int				main();
int				hexa_len(unsigned long int nb);
void			print_hexa_nb(unsigned long int nb, char *base);
int				ft_hexax_p(unsigned long int nb, char *base);
int				hexa_len2(unsigned int nb);
void			print_hexa_nb1(unsigned int nb, char *base);
int				ft_print_x(unsigned int nb, char *base);
char			*ft_strchr(const char *s, int c);
int				ft_printf_check(va_list list, char c);
int				ft_printf(const char *str, ...);
int				ft_putchar(char c);
unsigned int	ft_nb_len1(unsigned int n);
unsigned int	ft_putnbr_unsignedint(unsigned int nb);
size_t			ft_nb_len(int n);
int				ft_putnbr2(int nb);
int				ft_putnbr(int nb);
int				ft_putstr(char const *s);
int				ft_atoi(const char *str);

#endif
