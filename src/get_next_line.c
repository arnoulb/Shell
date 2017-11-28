/*
** get_next_line.c for  in /home/daelomin/rendu/PSU/PSU_2015_minishell1
**
** Made by Arnould Jean-Michel
** Login   <daelomin@epitech.net>
**
** Started on  Sun Jan 24 10:23:54 2016 Arnould Jean-Michel
** Last update Sat Apr  9 23:38:22 2016 Arnould Jean-Michel
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

static char	buf[READ_SIZE];
static int	ret = 0;
static int	tmp2 = 0;

char     *my_strcpy(char *dest, char *src)
{
  int           i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      ++i;
    }
  dest[i] = '\0';
  return (dest);
}

char	*my_strncpy(char *dest, char *src, int nb)
{
  int	i;
  int	a;

  a = 0;
  i = 0;
  while (src[a])
    a++;
  while (i < nb)
    {
      dest[i] = src[i];
      i++;
      if (nb > a)
	dest[i] = '\0';
    }
  return (dest);
}

char     *get_next_line2(char *line, int var)
{
  char          *tmp;
  int           len;

  len = (line != NULL) ? my_strlen(line) : 0;
  tmp = malloc(sizeof (char) * (len + var + 1));
  if (!line)
    tmp[len] = '\0';
  else
    my_strcpy(tmp, line);
  tmp[len + var] = '\0';
  my_strncpy(&tmp[len], &buf[tmp2], var);
  tmp2 += var + 1;
  free(line);
  return (tmp);
}

char	*get_next_line(const int fd)
{
  char	*line;
  int	var;

  var = 0;
  line = NULL;
  while (ret != -1)
    {
      if (tmp2 >= ret)
	{
	  tmp2 = 0;
	  ret = read(fd, buf, READ_SIZE);
	  if (ret == -1 || ret == 0)
	    return (ret == -1) ? NULL : line;
	  else
	    var = 0;
	}
      if (buf[tmp2 + var] == '\n')
	return (get_next_line2(line, var));
      else if (tmp2 + var == ret - 1)
	line = get_next_line2(line, var + 1);
      else
	++var;
    }
  return (NULL);
}
