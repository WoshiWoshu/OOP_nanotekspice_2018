/*
** EPITECH PROJECT, 2018
** MINISHELL1
** File description:
** get_next_line
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.hpp"


int		my_strlen(char *str)
{
  int		len;

  len = 0;
  while (str && *str)
    {
      len ++;
      str ++;
    }
  return (len);
}

char	*my_realloc(char *str, int len)
{
  char	*tmp;
  int	i;

  if ((tmp = (char *)malloc(my_strlen(str) + len + 1)) == NULL)
    return (NULL);
  i = 0;
  while (str && str[i])
    {
      tmp[i] = str[i];
      i += 1;
    }
  tmp[i] = 0;
  return (tmp);
}

int	new_strcat(char *str, char *buffer, int len)
{
  int	i;
  int	n;

  i = 0;
  n = my_strlen(str);
  while (i < len && buffer[i] != 10 && buffer[i] != 0)
    {
      str[n + i] = buffer[i];
      i += 1;
    }
  str[n + i] = 0;
  if (i >= len || buffer[i] != 10)
    return (0);
  str[n + i++] = 10;
  str[n + i] = 0;
  n = 0;
  while (n + i < len)
    {
      buffer[n] = buffer[n + i];
      n += 1;
    }
  buffer[n] = 0;
  return (1);
}

char		*get_next_line(const int fd)
{
  static char	buffer[READ_SIZE + 1];
  char		*str;
  int		rd_len;

  str = NULL;
  if (fd == -1)
    return (NULL);
  if ((str = my_realloc(str, my_strlen(buffer))) == NULL)
    return (NULL);
  if (new_strcat(str, buffer, my_strlen(buffer)) == 1)
    return (str);
  while ((rd_len = read(fd, buffer, READ_SIZE)) > 0)
    {
      if ((str = my_realloc(str, rd_len)) == NULL)
	return (NULL);
      if (new_strcat(str, buffer, rd_len) == 1)
	return (str);
    }
  if (rd_len <= 0)
    return (NULL);
  return (str);
}
