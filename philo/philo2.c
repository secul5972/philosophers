/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 11:46:13 by seungcoh          #+#    #+#             */
/*   Updated: 2022/01/18 13:39:31 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int print_status(t_p_data *data, int status)
{
	long curr_t;
	char *curr_tc;

	curr_t = get_time(data->start_t);
	curr_tc = ft_itoa(curr_t);
	if (curr_tc == 0)
		return 0;
	pthread_mutex_lock(&(data->locks[data->n]));
	write(1, curr_tc, ft_strlen(curr_tc));
	write(1, " ", 1);
	write(1, data->idc, data->idl);
	if (status == 0)
		write(1, " has taken a fork\n", 18);
	if (status == 1)
		write(1, " is eating\n", 11);
	if (status == 2)
		write(1, " is sleeping\n", 13);
	if (status == 3)
		write(1, " is thinking\n", 13);
	if (status == 4)
		write(1, " died\n", 18);
	pthread_mutex_unlock(&(data->locks[data->n]));
	return 1;
}

int chk_time(long t1, long t2)
{
	if (get_time(0) - t1 >= t2)
		return 0;
	else
		return 1;
}

int waiting(t_p_data *data)
{
	if (data->id == data->n - 1)
	{
		while(pthread_mutex_lock(&(data->locks[(data->id + 1) % data->n])))
			if(!chk_time(data->start_t, data->eat_t))
				return 0;
		if (!print_status(data, 0))
			return 0;
		while(pthread_mutex_lock(&(data->locks[data->id])))
			if(!chk_time(data->start_t, data->eat_t))
				return 0;
		if (!print_status(data, 0))
		return 0;
	}
	else
	{
		while(pthread_mutex_lock(&(data->locks[data->id])))
			if(!chk_time(data->start_t, data->eat_t))
				return 0;
		if (!print_status(data, 0))
			return 0;
		while(pthread_mutex_lock(&(data->locks[(data->id + 1) % data->n])))
			if(!chk_time(data->start_t, data->eat_t))
				return 0;
		if (!print_status(data, 0))
			return 0;
	}
	return 1;
}

int eating(t_p_data *data)
{
	if (!print_status(data, 1))
		return 0;
	usleep(1000 * data->eat_t);
	pthread_mutex_unlock(&(data->locks[data->id]));
	pthread_mutex_unlock(&(data->locks[(data->id + 1) % data->n]));
	return 1;
}

int sleeping(t_p_data *data)
{
	if (!print_status(data, 2))
		return 0;
	usleep(1000 * data->sleep_t);
	return 1;
}

void *func(void *arg)
{
	int i;
	t_p_data *data;

	data = (t_p_data *)arg;
	i = 0;
	while (1)
	{
		if (!waiting(data))
			return 0;
		if (!eating(data))
			return 0;
		if (!sleeping(data))
			return 0;
		i++;
		if(data->eat_n == i)
			return (void*)1;
		if (!print_status(data, 3))
			return 0;
	}
	return 0;
}