/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 11:59:16 by seungcoh          #+#    #+#             */
/*   Updated: 2021/12/28 13:06:06 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

typedef struct s_philo_data
{
	int philo_n;
	int philo_id;
	char *philo_idc;
	int die_t;
	int eat_t;
	int sleep_t;
	int eat_n;
}	t_philo_data;

int	ft_atoi(const char *str);
void all_free(t_philo_data * philo_data, pthread_t *philo, pthread_mutex_t *locks, int flag);

#endif