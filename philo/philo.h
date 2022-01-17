/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 11:59:16 by seungcoh          #+#    #+#             */
/*   Updated: 2022/01/17 15:04:41 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct s_p_data
{
	int n;
	int id;
	char *idc;
	int idl;
	int die_t;
	int eat_t;
	int sleep_t;
	int eat_n;
	long start_t;
	pthread_mutex_t *locks;
}	t_p_data;

int	ft_atoi(const char *str);
char *ft_itoa(long n);
int	ft_strlen(const char *str);
void all_free(t_p_data * p_data, pthread_t *philo, pthread_mutex_t *locks, int flag);
long get_time(long start_t);
void *func(void *data);

#endif