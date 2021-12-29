/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 12:28:38 by seungcoh          #+#    #+#             */
/*   Updated: 2021/12/28 13:30:06 by seungcoh         ###   ########.fr       */
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

char *ft_itoa(int n)
{
	int		size;
	char	*ret;
	int		temp;

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

void all_free(t_philo_data * philo_data, pthread_t *philo, pthread_mutex_t *locks, int flag)
{
	int i;
	int val;

	if ((flag & 1) && philo_data){
		i = -1;
		val = philo_data[0].philo_n;
		while(++i < val)
		{
			if(!philo_data[i].philo_idc)
				break;
			free(philo_data[i].philo_idc);
		}
		free(philo_data);
	}
	if ((flag & 2) && philo)
		free(philo);
	if ((flag & 4) && locks)
		free(locks);
}