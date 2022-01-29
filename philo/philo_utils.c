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
	if (!('0' <= str[0] && str[0] <= '9'))
		return (-1);
	while ('0' <= str[i] && str[i] <= '9')
	{
		ret *= 10;
		ret += str[i] - '0';
		i++;
	}
	if (str[i])
		return (-1);
	return (ret);
}

char	*ft_itoa(long n)
{
	int		size;
	char	*ret;
	long	temp;

	temp = n;
	size = 1;
	while (temp / 10)
	{
		temp /= 10;
		size++;
	}
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
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
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	all_free(t_p_data *p_data, pthread_t *philo, t_locks *locks, int flag)
{
	int	i;
	int	n;

	if ((flag & 1) && p_data)
	{
		n = p_data[0].n;
		i = -1;
		while (++i < n)
		{
			if (!p_data[i].idc)
				break ;
			free(p_data[i].idc);
		}
		free(p_data);
	}
	if ((flag & 2) && locks->p_lock)
		free(locks->p_lock);
	if ((flag & 2) && locks->v_lock)
		free(locks->v_lock);
	if ((flag & 2) && locks->forks)
	{
		i = -1;
		while (++i < n)
		{
			if (!(locks->forks + i)->lock)
				break ;
			free((locks->forks + i)->lock);
		}
		free(locks->forks);
	}
	if ((flag & 4) && philo)
		free(philo);
}

long	get_time(long start_t)
{
	struct timeval	t;

	gettimeofday(&t, 0);
	return (t.tv_sec * 1000 + t.tv_usec / 1000 - start_t);
}
