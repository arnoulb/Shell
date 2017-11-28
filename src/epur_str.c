/*
** epur_str.c for epur in /home/willai-n/42sh
**
** Made by Willaime Noah
** Login   <willai-n@epitech.net>
**
** Started on  Fri Jun  3 10:14:25 2016 Willaime Noah
** Last update Fri Jun  3 13:51:25 2016 Willaime Noah
*/

#include <stdlib.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

char	*epur_str(char *str, char c)
{
  char	*dest;
  int	a;
  int	i;

  a = 0;
  i = 0;
  dest = malloc(sizeof (char) * (my_strlen(str) + 1));
  while (str[i])
    {
      if (str[i] == ' ' && str[i + 1] == c
	  || str[i] == '\t' && str[i + 1] == c)
	i++;
      if (str[i] == ' ' && str[i - 1] == c
	  || str[i] == '\t' && str[i - 1] == c)
	i++;
      dest[a] = str[i];
      i++;
      a++;
    }
  dest[a] = '\0';
  return (dest);
}
