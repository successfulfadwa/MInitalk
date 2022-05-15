/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faljaoui <faljaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 05:23:23 by faljaoui          #+#    #+#             */
/*   Updated: 2022/05/14 05:55:06 by faljaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <stdio.h>

int				ft_atoi(const char *str);
void			ft_putstr(char *s);
void			ft_putchar(char c);
void			ft_putnbr(int nb);

#endif