/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:22:42 by edforte           #+#    #+#             */
/*   Updated: 2024/02/09 07:10:45 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*reading_lines(int fd, int *i, char *buffer, char *str)
{
	char			*newline;

	newline = NULL;
	*i = read(fd, buffer, BUFFER_SIZE);
	if (*i == 0 || *i == -1)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	newline = ft_strchr(buffer, '\n');
	if (!str)
		str = ft_strdup(buffer);
	else
		str = ft_strjoin(str, buffer);
	while (*i != -1 && (!newline))
	{
		*i = read(fd, buffer, BUFFER_SIZE);
		if (*i == 0 || *i == -1)
			return (NULL);
		buffer[BUFFER_SIZE] = '\0';
		str = ft_strjoin(str, buffer);
		newline = ft_strchr(buffer, '\n');
	}
	return (str);
}

char	*trimmed_string(char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	while (s1[i] != '\n')
		i ++;
	s2 = (char *)malloc((i + 2) * sizeof(char));
	i = 0;
	while (s1[i] != '\n')
	{
		s2[i] = s1[i];
		i ++;
	}
	s2[i++] = '\n';
	s2[i] = '\0';
	return (s2);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	char			*str;
	int				i;
	char			*newline;
	char			*tmp;

	i = 0;
	newline = NULL;
	str = NULL;
	tmp = NULL;
	if (buffer[0] != '\0')
	{
		str = ft_strdup(buffer);
		if (!str)
			return (NULL);
	}
	str = reading_lines(fd, &i, buffer, str);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(buffer, (ft_strchr(str, '\n') + 1), (BUFFER_SIZE));
	tmp = trimmed_string(str);
	free(str);
	return (tmp);
}

int	main(void)
{
	int fd = open("./txt.txt", O_RDONLY);
	char *str = get_next_line(fd);
	printf("str = %s\n", str);
	free (str);
	str = get_next_line(fd);
	printf("str = %s\n", str);
	free (str);
	str = get_next_line(fd);
	printf("str = %s\n", str);
	free (str);
	str = get_next_line(fd);
	printf("str = %s\n", str);
	free (str);
	str = get_next_line(fd);
	printf("str = %s\n", str);
	free (str);
	str = get_next_line(fd);
	printf("str = %s\n", str);
	free (str);
	str = get_next_line(fd);
	printf("str = %s\n", str);
	free (str);
	str = get_next_line(fd);
	printf("str = %s\n", str);
	free (str);
	str = get_next_line(fd);
	printf("str = %s\n", str);
	free (str);
	str = get_next_line(fd);
	printf("str = %s\n", str);
	free (str);
	str = get_next_line(fd);
	printf("str = %s\n", str);
	free (str);
	str = get_next_line(fd);
	printf("str = %s\n", str);
	free (str);
	str = get_next_line(fd);
	printf("str = %s\n", str);
	free (str);
	str = get_next_line(fd);
	printf("str = %s\n", str);
	free (str);
	return (0);
}