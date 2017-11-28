/*
** gest_env.c for gest_env in /home/willai-n/PSU_2015_42sh/PSU_2015_42sh
**
** Made by Willaime Noah
** Login   <willai-n@epitech.net>
**
** Started on  Sun Jun  5 15:40:21 2016 Willaime Noah
** Last update Sun Jun  5 15:40:54 2016 Willaime Noah
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include "my.h"
#include "get_next_line.h"
#include "function.h"

int	gest_env(char **tab, char ***env)
{
  int	i;

  if (is_same("env", tab[0]))
    {
      aff_env(*env);
      return (1);
    }
  if (is_same("setenv", tab[0]) && tab[1])
    {
      tab[2] != 0 ? my_setenv(env, tab[1], tab[2]) :
	my_setenv(env, tab[1], "");
      return (1);
    }
  if (is_same("setenv", tab[0]) && !tab[1])
    {
      aff_env(*env);
      return (1);
    }
  return (gest_env2(tab, env));
}

int	gest_env2(char **tab, char ***env)
{
  int	i;

  if (is_same("unsetenv", tab[0]) && tab[1])
    {
      i = 1;
      while (i < my_strlen2(tab))
	my_unsetenv(env, tab[i++]);
      return (1);
    }
  if (is_same("unsetenv", tab[0]) && !tab[1])
    {
      my_printf("Error unsetenv too few argument\n");
      return (-1);
    }
  return (0);
}
