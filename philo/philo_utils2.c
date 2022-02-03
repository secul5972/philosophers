/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:23:35 by seungcoh          #+#    #+#             */
/*   Updated: 2022/02/03 13:52:39 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_data(t_p_data *data, int status, char *curr_tc)
{
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
		write(1, " died\n", 6);
}

int	print_status(t_p_data *data, int status)
{
	long	curr_t;
	char	*curr_tc;

	pthread_mutex_lock(data->p_lock);
	if (*data->esc_flag == -1)
	{
		pthread_mutex_unlock(data->p_lock);
		return (0);
	}
	curr_t = get_time(data->start_t);
	curr_tc = ft_itoa(curr_t);
	if (curr_tc == 0)
	{
		*data->esc_flag = -1;
		free(curr_tc);
		pthread_mutex_unlock(data->p_lock);
		return (0);
	}
	write_data(data, status, curr_tc);
	pthread_mutex_unlock(data->p_lock);
	free(curr_tc);
	return (1);
}

long	get_time(long start_t)
{
	struct timeval	t;

	gettimeofday(&t, 0);
	return (t.tv_sec * 1000 + t.tv_usec / 1000 - start_t);
}
