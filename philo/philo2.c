/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:12:01 by seungcoh          #+#    #+#             */
/*   Updated: 2022/02/03 11:53:47 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	p_create(pthread_t **philo, t_p_data *p_data, int *esc_flag)
{
	int		i;
	long	start_t;

	*philo = (pthread_t *)malloc(sizeof(pthread_t) * p_data->n);
	if (!*philo)
		return (0);
	start_t = get_time(0);
	i = -1;
	while (++i < p_data->n / 2)
	{
		(p_data + i * 2 + 1)->start_t = start_t;
		(p_data + i * 2 + 1)->esc_flag = esc_flag;
		pthread_create((*philo + i * 2 + 1), \
		0, func, (void *)(p_data + i * 2 + 1));
	}
	usleep(50);
	i = -1;
	while (++i < p_data->n / 2 + p_data->n % 2)
	{
		(p_data + i * 2)-> start_t = start_t;
		(p_data + i * 2)->esc_flag = esc_flag;
		pthread_create((*philo + i * 2), 0, func, (void *)(p_data + i * 2));
	}
	return (1);
}

void	p_esc(pthread_t *philo, t_p_data *p_data, int *esc_flag)
{
	int	i;
	int	ret;

	while (!(*esc_flag == -1 || *esc_flag == p_data->n))
		;
	i = -1;
	while (++i < p_data->n)
		pthread_join(philo[i], (void *)&ret);
}
