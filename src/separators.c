/*
** separators.c for  in /home/daelomin/rendu/PSU/PSU_2015_minishell2
**
** Made by Arnould Jean-Michel
** Login   <daelomin@epitech.net>
**
** Started on  Sat Apr  9 21:18:21 2016 Arnould Jean-Michel
** Last update Fri Jun  3 18:16:03 2016 ARNOULD Jean-Michel
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include "my.h"
#include "function.h"

int	size_sep(char *str)
{
  int	i;

  i = 0;
  while (str[i] && str[i] != ';')
    ++i;
  return (i);
}

void	main_boucle(char *s, char ***env)
{
  char	*s2;
  int	i;

  i = 0;
  while ((s2 = split_sep(s, i)))
    {
      if (my_strlen(s2) != 0 && test_char(s2))
	{
	  if (is_good(s2))
	    gestionaire(s2, env);
	  else
	    my_printf("wrong charactère in arguments\n");
	}
      free(s2);
      ++i;
    }
}

char	*split_sep(char *str, int nb)
{
  char	*out;
  int	i;
  int	j;
  int	size;

  i = 0;
  while (str[i] && nb)
    {
      if (str[i] == ';')
	--nb;
      ++i;
    }
  size = my_strlen(&str[i]);
  out = malloc(sizeof (char) * (size_sep(&str[i]) + 1));
  j = 0;
  while (str[i] && str[i] != ';')
    {
      out[j] = str[i];
      ++i;
      ++j;
    }
  out[j] = 0;
  return ((size != 0) ? out : NULL);
}
