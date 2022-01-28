/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:23:35 by seungcoh          #+#    #+#             */
/*   Updated: 2022/01/28 15:32:29 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_status(t_p_data *data, int status)
{
	long	curr_t;
	char	*curr_tc;

	if (*data->esc_flag == -1)
		return (0);
	curr_t = get_time(data->start_t);
	curr_tc = ft_itoa(curr_t);
	if (curr_tc == 0)
	{
		*data->esc_flag = -1;
		return (0);
	}
	pthread_mutex_lock(data->p_lock);
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
	pthread_mutex_unlock(data->p_lock);
	return (1);
}
