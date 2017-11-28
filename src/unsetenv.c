/*
** unsetenv.c for  in /home/daelomin/rendu/PSU/PSU_2015_minishell1
**
** Made by Arnould Jean-Michel
** Login   <daelomin@epitech.net>
**
** Started on  Sat Jan 23 17:43:25 2016 Arnould Jean-Michel
** Last update Mon Apr  4 22:38:06 2016 Arnould Jean-Michel
*/

#include <stdlib.h>
#include "my.h"
#include "function.h"

int	is_value(char *env, char *value)
{
  int	i;

  i = 0;
  while (env[i] && value[i])
    {
      if (env[i] != value[i])
	return (0);
      ++i;
    }
  if (env[i] == '=')
  return (1);
  else
    return (0);
}

void	my_unsetenv2(char *env, char ***new, int *i, char *param)
{
  int	j;

  new[0][i[1]] = malloc(sizeof (char) * (my_strlen(env) + 1));
  if (!is_value(env, param))
    {
      j = 0;
      while (env[j])
	{
	  new[0][i[1]][j] = env[j];
	  j++;
	}
      new[0][i[1]][j] = 0;
      i[1] += 1;
    }
  i[0] += 1;
}

void	my_unsetenv(char ***env, char *param)
{
  int	i[2];
  int	j;
  char	**new;

  i[0] = 0;
  i[1] = 0;
  new = malloc(sizeof (char *) * (my_strlen2(env[0]) + 1));
  while (env[0][i[0]])
    {
      my_unsetenv2(env[0][i[0]], &new, i, param);
    }
  new[i[1]] = 0;
  j = 0;
  while (env[0][j])
    free(env[0][j++]);
  free(env[0]);
  env[0] = new;
}
