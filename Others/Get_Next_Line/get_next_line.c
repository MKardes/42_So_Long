/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 23:03:43 by mkardes           #+#    #+#             */
/*   Updated: 2022/08/13 04:35:56 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_putten(char *putline)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (putline[i] != '\0' && putline[i] != '\n')
		i++;
	if (!putline[i])
	{
		free(putline);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlenn(putline) - i));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (putline[i + j] != '\0')
	{
		str[j] = putline[j + i];
		j++;
	}
	str[j] = '\0';
	free(putline);
	return (str);
}

char	*get_main_line(char *putline)
{
	int		i;
	char	*str;

	i = 0;
	if (!putline[i])
		return (NULL);
	while (putline[i] != '\0' && putline[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (putline[i] != '\0' && putline[i] != '\n')
	{
		str[i] = putline[i];
		i++;
	}
	if (putline[i] == '\n')
	{
		str[i] = putline[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_read(int fd, char *putline)
{
	char	*buff;
	int		reader;

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	reader = 1;
	while (!ft_strchrr(putline, '\n') && reader != 0)
	{
		reader = read(fd, buff, BUFFER_SIZE);
		if (reader == -1)
		{
			free(buff);
			return (NULL);
		}			
		buff[reader] = '\0';
		putline = ft_strjoinn(putline, buff);
	}
	free(buff);
	return (putline);
}

char	*get_next_line(int fd)
{
	char		*mainline;
	static char	*putline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	putline = get_read(fd, putline);
	if (!putline)
		return (NULL);
	mainline = get_main_line(putline);
	putline = get_putten(putline);
	return (mainline);
}
