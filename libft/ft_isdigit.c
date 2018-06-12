/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 15:57:00 by adubugra          #+#    #+#             */
/*   Updated: 2018/02/21 15:57:04 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_isdigit(int c)
{
	return (c <= '9' && c >= '0');
}

int		ft_only_digits(char *str)
{
	char *tmp;

	if (!str)
		return (0);
	str = ft_strtrim(str);
	tmp = str;
	while (*str)
	{
		if (!ft_isdigit(*str))
		{
			free(tmp);
			return (0);
		}
		str++;
	}
	free(tmp);
	return (1);
}
