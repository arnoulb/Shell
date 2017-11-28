/*
** environ.c for  in /home/daelomin/rendu/PSU/PSU_2015_minishell1
**
** Made by Arnould Jean-Michel
** Login   <daelomin@epitech.net>
**
** Started on  Thu Jan 21 14:15:31 2016 Arnould Jean-Michel
** Last update Fri Jun  3 17:24:36 2016 ARNOULD Jean-Michel
*/

#include <stdlib.h>
#include "my.h"
#include "function.h"

int	my_strlen2(char **str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

char	**env_copy(char **env, char *path)
{
  int	i;
  int	j;
  int	k;
  char	**tmp;

  i = 0;
  k = 0;
  tmp = malloc(sizeof (char *) * (my_strlen2(env) + 3));
  tmp[0] = concat("OLD_PATH=", path);
  if (get_env_value(env, "PATH", 0) == NULL)
    tmp[++k] = concat("PATH=", "/bin:/usr/bin");
  while (env[i])
    {
      j = 0;
      tmp[i + 1 + k] = malloc(sizeof (char) * (my_strlen(env[i]) + 1));
      while (env[i][j])
	{
	  tmp[i + 1 + k][j] = env[i][j];
	  j++;
	}
      tmp[i + k + 1][j] = 0;
      i++;
    }
  tmp[i + 1 + k] = 0;
  return (tmp);
}

char	*get_value(char *str, int nb)
{
  char	*ret;
  int	i;
  int	j;

  i = 0;
  j = 1;
  while (str[i] && str[i] != '=')
    i++;
  i++;
  while (str[i] && j < nb)
    {
      if (str[i] == ':')
	j++;
      i++;
    }
  ret = malloc(sizeof (char) * (my_strlen(&str[i]) + 1));
  j = 0;
  while (str[i] && str[i] != ':')
    {
      ret[j] = str[i];
      i++;
      j++;
    }
  ret[j] = 0;
  return (ret);
}

char	*get_env_value(char **env, char *str, int nb)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  if (env == 0)
    return (NULL);
  while (env[i])
    {
      j = 0;
      k = 0;
      while (env[i][j])
	{
	  if (env[i][j] == str[k])
	    k++;
	  j++;
	  if (k == my_strlen(str) && j == k && env[i][j] == '=')
	    return (get_value(env[i], nb));
	}
      i++;
    }
  return (NULL);
}

void	aff_env(char **env)
{
  int	i;

  i = 0;
  while (env[i])
    {
      my_printf("%s\n", env[i]);
      i++;
    }
}
