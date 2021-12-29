/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 11:59:22 by seungcoh          #+#    #+#             */
/*   Updated: 2021/12/28 13:30:33 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int philo_init(int argc, char **argv, t_philo_data **philo_data)
{
	t_philo_data tmp;
	int philo_n;
	int i;

	*philo_data = 0;
	if (argc != 5 && argc != 6)
		return 0;
	philo_n = ft_atoi(argv[1]);
	tmp.die_t = ft_atoi(argv[2]);
	tmp.eat_t = ft_atoi(argv[3]);
	tmp.sleep_t = ft_atoi(argv[4]);
	if(philo_n < 1 || tmp.die_t == -1 || tmp.eat_t == -1 \
	|| tmp.sleep_t == -1 || tmp.eat_n == -1)
		return 0;
	if(argc == 6)
		tmp.eat_n = ft_atoi(argv[5]);
	if(argc == 6 && tmp.eat_n == -1)
		return 0;
	*philo_data = malloc(sizeof(t_philo_data) * (philo_n));
	if(!*philo_data)
		return 0;
	i = -1;
	while(++i < philo_n)
	{
		(*philo_data)[i].philo_n = philo_n;
		(*philo_data)[i].philo_id = i;
		(*philo_data)[i].philo_idc = ft_itoa(i);
		if((*philo_data)[i].philo_idc)
			return 0;
		(*philo_data)[i].die_t = tmp.die_t;
		(*philo_data)[i].eat_t = tmp.eat_t;
		(*philo_data)[i].sleep_t = tmp.sleep_t;
		(*philo_data)[i].eat_n = tmp.eat_n;
	}
	return 1;
}

int lock_init(pthread_mutex_t **locks, int philo_n)
{
	int i;

	*locks = malloc(sizeof(pthread_mutex_t) * (philo_n + 1));
	if(!locks)
		return 0;
	i = -1;
	while(++i < philo_n + 1)
		if(pthread_mutex_init(&(*locks)[i], 0))
			return 0;
	return 1;
}

void philo_func(pthread_mutex_t *locks)
{
	while(1)
	{
		
	}
}

int philo_create(pthread_t **philo, int philo_n, pthread_mutex_t *locks)
{
	int i;

	*philo = malloc(sizeof(pthread_t) * philo_n);
	if(!philo)
		return 0;
	i = -1;
	while(++i < philo_n)
		if(pthread_create(&(*philo)[i], 0, philo_func, (void *)locks))
			return 0;
	return 1;
}

int main(int argc, char **argv){
	
	t_philo_data *philo_data;
	pthread_t *philo;
	pthread_mutex_t *locks;

	if (!philo_init(argc, argv, &philo_data))
	{
		write(2, "parameter error\n", 16);
		all_free(philo_data, philo, locks, 1);
		return (0);
	}
	if (!lock_init(&locks, philo_data[0].philo_n))
	{
		write(2, "lock error\n", 10);
		all_free(philo_data, philo, locks, 3);
		return (0);
	}
	if (!philo_create(&philo, philo_data[0].philo_n, locks))
	{
		write(2, "thread_create error\n", 20);
		all_free(philo_data, philo, locks, 7);
		return (0);
	}

}