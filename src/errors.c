/*
** errors.c for  in /home/daelomin/rendu/PSU/PSU_2015_minishell1
**
** Made by Arnould Jean-Michel
** Login   <daelomin@epitech.net>
**
** Started on  Thu Jan 21 22:50:35 2016 Arnould Jean-Michel
** Last update Tue Jun  7 18:07:54 2016 ARNOULD Jean-Michel
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"
#include "function.h"

void	free_all(char **tab, char **env)
{
  int	i;

  i = 0;
  while (tab[i])
    free(tab[i++]);
  free(tab);
  i = 0;
  while (env[i])
    free(env[i++]);
  free(env);
}

int	argument3(char **tab, char ***env, pid_t child)
{
  int	red;
  int	std;

  if ((red = is_redir(tab)))
    {
      if (is_redir_left(tab))
	{
	  std = dup(1);
	  get_redir_left(tab);
	}
      if (is_redir_right(tab))
	{
	  std = dup(0);
	  get_redir(tab);
	}
      redir_lol(tab);
    }
  gestion(tab, *env);
}
int	argument2(char **tab, char ***env)
{
  pid_t	child;
  int	a;
  int	i;

  i = 0;
  if (!is_same(tab[0], "cd") && !is_same(tab[0], "exit")
      && !is_same(tab[0], "env") && !is_same(tab[0], "setenv")
      && !is_same(tab[0], "unsetenv"))
    {
      child = fork();
      if (child == 0)
	argument3(tab, env, child);
      else
      	wait(&child);
      error_seg(child, tab);
      if (WIFEXITED(child))
      	return (1);
    }
  else
    a = gestion2(tab, env);
  while (tab[i])
    free(tab[i++]);
  free(tab);
  return (a);
}

int	test_char(char *str)
{
  int	i;
  int	k;

  i = 0;
  k = 0;
  while (str[i])
    {
      if (str[i] == ' ' || str[i] == '\t')
	++k;
      ++i;
    }
  if (i == k)
    return (0);
  else
    return (1);
}

void	display_prompt(char **env)
{
  if (get_env_value(env, "USER", 1) && getcwd(0, 1000))
    my_printf("\e[31m%s \e[33m%s >\e[00m ", get_env_value(env, "USER", 1),
	      getcwd(0, 1000));
  else
    my_printf("$> ");
}
