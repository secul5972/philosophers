/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 11:46:13 by seungcoh          #+#    #+#             */
/*   Updated: 2022/01/10 13:38:31 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int print_status(t_p_data *p_data, int status)
{
	struct timeval t;
	long curr_t;
	char *curr_tc;

	curr_t = get_time(p_data->start_t);
	curr_tc = ft_itoa(curr_t);
	if (curr_tc == 0)
		return 0;
	write(1, curr_tc, ft_strlen(curr_tc));
	write(1, p_data->idc, p_data->idl);
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
	return 1;
}

int waiting(t_p_data *p_data)
{
	while (1)
	{
		if (p_data->id == p_data->n - 1)
		{
			if (pthread_mutex_lock(p_data->locks + p_data->id + 1))
				break;
			if (pthread_mutex_lock(p_data->locks + p_data->id))
				break;
			if (!print_status(p_data, 0))
				return 0;
			return 1;
		}
		else
		{
			if (pthread_mutex_lock(p_data->locks + p_data->id))
				break;
			if (pthread_mutex_lock(p_data->locks + p_data->id + 1))
				break;
			if (!print_status(p_data, 0))
				return 0;
			return 1;
		}
	}
}

int p_func(t_p_data *p_data)
{
	while (1)
	{
		if (!waiting(p_data))
			return 0;
	}
}