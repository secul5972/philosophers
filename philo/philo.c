/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 11:59:22 by seungcoh          #+#    #+#             */
/*   Updated: 2022/01/28 15:02:53 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int p_init(int argc, char **argv, t_p_data **p_data)
{
	t_p_data tmp;
	int p_n;
	int i;

	*p_data = 0;
	if (argc != 5 && argc != 6)
		return 0;
	p_n = ft_atoi(argv[1]);
	tmp.die_t = ft_atoi(argv[2]);
	tmp.eat_t = ft_atoi(argv[3]);
	tmp.sleep_t = ft_atoi(argv[4]);
	if(p_n < 1 || tmp.die_t == -1 || tmp.eat_t == -1 \
	|| tmp.sleep_t == -1)
		return 0;
	tmp.eat_n = -1;
	if(argc == 6)
		tmp.eat_n = ft_atoi(argv[5]);
	if(argc == 6 && tmp.eat_n == -1)
		return 0;
	*p_data = (t_p_data *)malloc(sizeof(t_p_data) * (p_n));
	if(!*p_data)
		return 0;
	i = -1;
	while(++i < p_n)
	{
		(*p_data + i)->n = p_n;
		(*p_data + i)->id = i + 1;
		(*p_data + i)->idc = ft_itoa(i + 1);
		(*p_data + i)->idl = ft_strlen((*p_data + i)->idc);
		if(!(*p_data + i)->idc)
			return 0;
		(*p_data + i)->die_t = tmp.die_t;
		(*p_data + i)->eat_t = tmp.eat_t;
		(*p_data + i)->sleep_t = tmp.sleep_t;
		(*p_data + i)->eat_n = tmp.eat_n;
	}
	return 1;
}

int fork_init(t_locks *locks, t_p_data **p_data)
{
	int i;

	locks->p_lock = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t));
	locks->v_lock = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t));
	locks->forks = (t_fork*)malloc(sizeof(t_fork) * (*p_data)->n);
	if (!locks->p_lock || !locks->v_lock || !locks->forks)
		return 0;
	i = -1;
	while (++i < (*p_data)->n)
	{
		(locks->forks + i)->fork = i;
		(locks->forks + i)->lock = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t));
		if (pthread_mutex_init((locks->forks + i)->lock, 0))
			return 0;
	}
	i = -1;
	while (++i < (*p_data)->n - 1)
	{
		(*p_data + i)->ffork = (locks->forks + i);
		(*p_data + i)->sfork = (locks->forks + i + 1);
		(*p_data + i)->use_ffork = -1;
		(*p_data + i)->use_sfork = -1;
		(*p_data + i)->p_lock = locks->p_lock;
		(*p_data + i)->v_lock = locks->v_lock;
	}
	(*p_data + i)->ffork = (locks->forks + 0);
	(*p_data + i)->sfork = (locks->forks + i);
	(*p_data + i)->use_ffork = -1;
	(*p_data + i)->use_sfork = -1;
	(*p_data + i)->p_lock = locks->p_lock;
	(*p_data + i)->v_lock = locks->v_lock;
	return 1;
}

int p_create(pthread_t **philo, t_p_data *p_data, int *esc_flag)
{
	int i;
	long start_t;

	*philo = (pthread_t *)malloc(sizeof(pthread_t) * p_data->n);
	if(!*philo)
		return 0;
	start_t = get_time(0);
	i = -1;
	while(++i < p_data->n / 2)
	{
		(p_data + i * 2 + 1)->start_t = start_t;
		(p_data + i * 2 + 1)->esc_flag = esc_flag;
		if (pthread_create((*philo + i * 2 + 1), 0, func, (void *)(p_data + i * 2 + 1)))
			return 0;
	}
	i = -1;
	while(++i < p_data->n / 2 + p_data->n % 2)
	{
		(p_data + i * 2) -> start_t = start_t;
		(p_data + i * 2)->esc_flag = esc_flag;
		if (pthread_create((*philo + i * 2), 0, func, (void *)(p_data + i * 2)))
			return 0;
	}
	return 1;
}

void p_esc(pthread_t *philo, t_p_data *p_data, int *esc_flag)
{
	int i;
	int ret;

	while (!(*esc_flag == -1 || *esc_flag == p_data->n));
	i = -1;
	while (++i < p_data->n)
		pthread_join(philo[i], (void *)&ret);
}

int main(int argc, char **argv){
	
	t_p_data *p_data;
	pthread_t *philo;
	t_locks locks;
	int esc_flag;

	if (!p_init(argc, argv, &p_data))
	{
		write(2, "parameter error\n", 16);
		all_free(p_data, philo, &locks, 1);
		return (1);
	}
	if (!fork_init(&locks, &p_data))
	{
		write(2, "lock error\n", 10);
		all_free(p_data, philo, &locks, 3);
		return (1);
	}
	esc_flag = 0;
	if (!p_create(&philo, p_data, &esc_flag))
	{
		write(2, "thread_create error\n", 20);
		all_free(p_data, philo, &locks, 7);
		return (1);
	}
	p_esc(philo, p_data, &esc_flag);
	all_free(p_data, philo, &locks, 7);
	return 0;
}