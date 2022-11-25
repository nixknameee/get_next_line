/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngjokaj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:00:18 by ngjokaj           #+#    #+#             */
/*   Updated: 2022/11/23 11:00:20 by ngjokaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char    *get_next_line(int fd)
{
        static char     *save[100];
        char            *line;

        if (fd < 0 || BUFFER_SIZE <= 0 || fd < 99)
                return (0);
        save[fd] = ft_read_save(fd, save[fd]);
        if (!save[fd])
                return (NULL);
        line = ft_get_line(save[fd]);
        save[fd] = ft_save(save[fd]);
        return (line);
}

char    *ft_read_save(int fd, char *save)
{
        int     ret;
        char    *buffer;

        ret = 1;
        buffer = malloc(BUFFER_SIZE + 1);
        if (!buffer)
                return(NULL);
        while (!ft_strchr(save, '\n') && ret != 0)
        {
                ret = read(fd, buffer, BUFFER_SIZE);
                if (ret == -1)
                {
                        free(save);
                        save = NULL;
                        free(buffer);
                        return (NULL);
                }
                buffer[ret] = '\0';
                save = ft_strjoin(save, buffer);
        }
        free(buffer);
        return (save);
}

char    *ft_save(char *save)
{
        char    *str;
        int     i;
        int     a;

        i = 0;
        while (save[i] && save[i] != '\n')
                i++;
        if (!save[i])
        {
                free(save);
                return(NULL);
        }
        str = (char *)malloc(sizeof(char) * (ft_str_len(save) - i + 1));
        if (!str)
                return (NULL);
        i++;
        a = 0;
        while (save[i])
                str[a++] = save[i++];
        str[a] = '\0';
        free(save);
        return (str);
}
char      *ft_get_line(char *save)
{
	char	*str;
	int	i;

	i = 0;
	if (!save[i])
		return(NULL);
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if(!str)
		return(NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		str[i] = save[i];
                i++;
        }
        if (save[i] == '\n')
        {
        	str[i] = save[i];
        	i++;
        }
        str[i] = '\0';
        return (str);
}