/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 11:46:13 by seungcoh          #+#    #+#             */
/*   Updated: 2022/01/28 13:34:14 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int unlock(t_p_data *data, int flag)
{
	if (flag & 1)
		pthread_mutex_unlock(data->ffork->lock);
	if (flag & 2)
		pthread_mutex_unlock(data->sfork->lock);
	return 0;
}

int waiting(t_p_data *data)
{
	data->wait_start_t = get_time(0);
	pthread_mutex_lock(data->ffork->lock);
	data->use_ffork = data->ffork->fork;
	if (!print_status(data, 0))
		return (unlock(data, 1));
	pthread_mutex_lock(data->sfork->lock);
	data->use_sfork = data->sfork->fork;
	if (!print_status(data, 0))
		return (unlock(data, 3));
	return 1;
}

int eating(t_p_data *data)
{
	long eat_start_t;

	if (!print_status(data, 1))
		return (unlock(data, 3));
	eat_start_t = get_time(0);
	while (eat_start_t + data->eat_t > get_time(0))
	{
		if (data->wait_start_t + data->die_t < get_time(0))
		{
			print_status(data, 4);
			*data->esc_flag = -1;
			return (unlock(data, 3));
		}
		usleep(100);
	}
	pthread_mutex_unlock(data->ffork->lock);
	data->use_ffork = -1;
	pthread_mutex_unlock(data->sfork->lock);
	data->use_sfork = -1;
	return 1;
}

int sleeping(t_p_data *data)
{
	long sleep_start_t;
	
	if (!print_status(data, 2))
		return 0;
	sleep_start_t = get_time(0);
	while (sleep_start_t + data->sleep_t > get_time(0))
		usleep(100);
	return 1;
}

void *func(void *arg)
{
	int i;
	t_p_data *data;

	data = (t_p_data *)arg;
	i = 0;
	while (++i)
	{
		if (!waiting(data) || !eating(data))
			return 0;
		if (data->eat_n == i)
		{
			pthread_mutex_lock(data->v_lock);
			(*data->esc_flag)++;
			pthread_mutex_unlock(data->v_lock);
			return (void*)1;
		}
		if (!sleeping(data))
			return 0;
		if (!print_status(data, 3))
			return 0;
	}
	return 0;
}