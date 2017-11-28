/*
** setenv.c for  in /home/daelomin/rendu/PSU/PSU_2015_minishell1
**
** Made by Arnould Jean-Michel
** Login   <daelomin@epitech.net>
**
** Started on  Fri Jan 22 18:27:32 2016 Arnould Jean-Michel
** Last update Tue Apr 12 13:23:21 2016 Arnould Jean-Michel
*/

#include <stdlib.h>
#include <stdio.h>
#include "function.h"
#include "my.h"

void	set_env(char ***env, char *param, char *value, int i)
{
  free(env[0][i]);
  env[0][i] = malloc (sizeof (char) *
		      (my_strlen(param) + my_strlen(value) + 2));
  env[0][i] = concat(param, "=");
  env[0][i] = concat(env[0][i], value);
}

int	get_env_nb(char ***env, char *str, char *value)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  while (env[0][i])
    {
      j = 0;
      k = 0;
      while (env[0][i][j])
	{
	  if (env[0][i][j] == str[k])
	    k++;
	  j++;
	  if (k == my_strlen(str) && j == k)
	    {
	      set_env(env, str, value, i);
	      return (1);
	    }
	}
      i++;
    }
  return (0);
}

void	my_setenv(char ***env, char *param, char *value)
{
  int	i;
  int	j;
  char	**new;

  if (get_env_nb(env, param, value))
    return ;
  new = malloc(sizeof (char *) * (my_strlen2(env[0]) + 2));
  i = 0;
  while (env[0][i])
    {
      j = 0;
      new[i] = malloc(sizeof (char) * (my_strlen(env[0][i]) + 1));
      while (env[0][i][j])
	new[i][j] = env[0][i][j++];
      new[i][j] = 0;
      ++i;
    }
  new[i] = concat(param, "=");
  new[i] = concat(new[i], value);
  new[i + 1] = 0;
  i = 0;
  while (env[0][i])
    free(env[0][i++]);
  free(env[0]);
  env[0] = new;
}
