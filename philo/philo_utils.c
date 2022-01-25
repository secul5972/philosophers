/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 12:28:38 by seungcoh          #+#    #+#             */
/*   Updated: 2022/01/05 12:35:34 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

int	ft_atoi(const char *str)
{
	int		i;
	long	ret;

	i = 0;
	ret = 0;
	if(!('0' <= str[0] && str[0] <= '9'))
		return (-1);
	while ('0' <= str[i] && str[i] <= '9')
	{
		ret *= 10;
		ret += str[i] - '0';
		i++;
	}
	if(str[i])
		return (-1);
	return (ret);
}

char *ft_itoa(long n)
{
	int		size;
	char	*ret;
	long	temp;

	temp = n;
	size = 1;
	while (temp /= 10)
		size++;
	ret = (char*)malloc(sizeof(char) * (size + 1));
	if(!ret)
		return (0);
	ret[size--] = 0;
	while (size >= 0)
	{
		ret[size--] = n % 10 + '0';
		n /= 10;
	}
	return (ret);
}

int	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void all_free(t_p_data * p_data, pthread_t *philo, pthread_mutex_t *locks, int flag)
{
	int i;
	int val;

	if ((flag & 1) && p_data){
		i = -1;
		val = p_data[0].n;
		while(++i < val)
		{
			if(!p_data[i].idc)
				break;
			free(p_data[i].idc);
		}
		free(p_data);
	}
	if ((flag & 2) && philo)
		free(philo);
	if ((flag & 4) && locks)
		free(locks);
}

long get_time(long start_t)
{
	struct timeval t;

	gettimeofday(&t, 0);
	return (t.tv_sec * 1000 + t.tv_usec / 1000 - start_t);
}

int print_status(t_p_data *data, int status)
{
	long curr_t;
	char *curr_tc;

	curr_t = get_time(data->start_t);
	curr_tc = ft_itoa(curr_t);
	if (curr_tc == 0)
		return 0;
	pthread_mutex_lock(data->p_lock);
	write(1, curr_tc, ft_strlen(curr_tc));
	write(1, "ms ", 3);
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
	return 1;
}