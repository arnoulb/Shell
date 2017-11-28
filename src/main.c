/*
** main.c for  in /home/daelomin/rendu/PSU/PSU_2015_minishell1
**
** Made by Arnould Jean-Michel
** Login   <daelomin@epitech.net>
**
** Started on  Sat Jan 23 11:25:59 2016 Arnould Jean-Michel
** Last update Sun Jun  5 15:40:56 2016 Willaime Noah
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

int	gestion3(char **tab, char ***env)
{
  if (is_same("exit", tab[0]))
    {
      if (tab[1] == NULL)
	{
	  free_all(tab, *env);
	  my_printf("exit\n");
	  exit(0);
	}
      else
	my_exit(tab, *env);
    }
}

int	gestion2(char **tab, char ***env)
{
  int	ret;
  char	*path;
  int	i;

  if (is_same("cd", tab[0]))
    {
      path = getcwd(0, 1000);
      ret = my_chdir(tab, *env);
      if (ret == -1 && tab[0] != NULL && tab[1] != NULL)
	{
	  my_printf("Error %s does not exist.\n", tab[1]);
	  return (-1);
	}
      else
	my_setenv(env, "OLD_PATH", path);
      return (1);
    }
  i = gest_env(tab, env);
  if (i != 0)
    return (i);
  gestion3(tab, env);
}

void	gestion(char **tab, char **env)
{
  int	ret;
  char	*str;
  int	i;

  i = 1;
  while (i <= 100)
    {
      str = concat(get_env_value(env, "PATH", i), "/");
      str = concat(str, tab[0]);
      ret = (str == NULL || tab[0][0] == '/' || tab[0][0] == '.') ? -1 :
	execve(str, tab, env);
      ++i;
      free(str);
    }
  if (replace("~/", tab[0]))
    {
      tab[0] = concat(get_env_value(env, "HOME", 1), &tab[0][1]);
      i = 0;
    }
  ret = (is_exec(tab[0]) == 1) ? execve(tab[0], tab, env) : -1;
  if (ret == -1)
    my_printf("%s: Command not found.\n", tab[0]);
  free_all(env, tab);
  kill(getpid(), SIGTERM);
}

int	main(int ac, char **av, char **env)
{
  char	*s;
  char	**tab;
  char	***cmd;
  char	**cpy;

  tab = NULL;
  cpy = env_copy(env, getcwd(0, 1000));
  display_prompt(cpy);
  signal(SIGINT, SIG_IGN);
  signal(SIGQUIT, SIG_IGN);
  while ((s = get_next_line(0)))
    {
      main_boucle(s, &cpy);
      display_prompt(cpy);
      free(s);
    }
}
