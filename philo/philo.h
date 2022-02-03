/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 11:59:16 by seungcoh          #+#    #+#             */
/*   Updated: 2022/01/29 16:20:10 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_fork
{
	int				fork;
	pthread_mutex_t	*lock;
}	t_fork;

typedef struct s_locks
{
	pthread_mutex_t	*p_lock;
	pthread_mutex_t	*v_lock;
	t_fork			*forks;
}	t_locks;

typedef struct s_p_data
{
	int				n;
	int				id;
	char			*idc;
	int				idl;
	int				die_t;
	int				eat_t;
	int				sleep_t;
	int				eat_n;
	int				*esc_flag;
	long			start_t;
	long			wait_start_t;
	int				use_ffork;
	int				use_sfork;
	t_fork			*ffork;
	t_fork			*sfork;
	pthread_mutex_t	*p_lock;
	pthread_mutex_t	*v_lock;
}	t_p_data;

int		ft_atoi(const char *str);
char	*ft_itoa(long n);
int		ft_strlen(const char *str);
int		all_free(t_p_data *p_data, pthread_t *philo, t_locks *locks, int flag);
long	get_time(long start_t);
int		print_status(t_p_data *data, int status);
void	*func(void *data);
int		p_create(pthread_t **philo, t_p_data *p_data, int *esc_flag);
void	p_esc(pthread_t *philo, t_p_data *p_data, int *esc_flag);

#endif
