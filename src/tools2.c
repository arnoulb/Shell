/*
** tools2.c for  in /home/daelomin/rendu/PSU/PSU_2015_minishell1
**
** Made by Arnould Jean-Michel
** Login   <daelomin@epitech.net>
**
** Started on  Tue Jan 26 00:33:14 2016 Arnould Jean-Michel
** Last update Wed Apr 13 16:55:23 2016 Arnould Jean-Michel
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "function.h"

int	my_chdir2(char **tab, char **env)
{
  int	ret;
  char *str;

  str = get_env_value(env, "HOME", 1);
  ret = 0;
  if (str != NULL)
    ret = chdir(get_env_value(env, "HOME", 1));
  else
    my_printf("No $home variable set.\n");
  free(str);
  return (ret);
}

int	my_ch2(char **tab, char **env)
{
  char	*str;
  char	*old_pwd;
  int	ret;

  str = get_env_value(env, "OLD_PATH", 1);
  if (str != NULL)
      ret = chdir(str);
  else
    {
      printf("No $OLD_PATH variable set\n");
      ret = -2;
    }
  free(str);
  if (ret == -1)
    ret--;
  return (ret);
}

int	my_chdir(char **tab, char **env)
{
  int	ret;
  char	*str;

  ret = -1;
  if (tab[1] != NULL)
    {
      if (replace("~/", tab[1]))
	{
	  str = get_env_value(env, "HOME", 1);
	  if (str != NULL)
	    tab[1] = concat(get_env_value(env, "HOME", 1), &tab[1][1]);
	  else
	    {
	      my_printf("No $home variable set.\n");
	      free(str);
	      return (0);
	    }
	  free(str);
	}
      ret = (is_same(tab[1], "-")== 1) ? my_ch2(tab, env) : chdir(tab[1]);
    }
  else
    ret = my_chdir2(tab, env);
  return (ret);
}

int	executer(char **str, char **env, int test)
{
  int	ret;

  ret = -1;
  if ((str[0][0] == '.' || str[0][0] == '~') && str[0][1] == '/' || !test)
    ret = execve(str[0], str, env);
  return (ret);
}

char	*correctif(char *str)
{
  int	i;
  int	tmp;

  i = 0;
  tmp = 0;
  while (str[i])
    {
      if (str[i] > ' ' && str[i] <= '~')
	tmp = 0;
      if (str[i] == ' ' || str[i] == '\t')
	tmp++;
      ++i;
    }
  str[my_strlen(str) - tmp] = 0;
  return (str);
}
