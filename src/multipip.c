/*
** main.c for  in /home/daelomin/rendu/bootstrap/PSU_2015_my_exec2
**
** Made by Arnould Jean-Michel
** Login   <daelomin@epitech.net>
**
** Started on  Mon Mar 28 14:19:11 2016 Arnould Jean-Michel
** Last update Tue Jun  7 17:09:50 2016 ARNOULD Jean-Michel
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
#include "sep.h"

void	my_pipe2(int *p, char ***cmd, int fd_in, char **env)
{
  dup2(fd_in, 0);
  if (*(cmd + 1) != NULL)
    dup2(p[1], 1);
  close(p[0]);
  exit (argument(*cmd, &env));
}

int	my_pipe(char ***cmd, char **env)
{
  int	p[2];
  pid_t	pid;
  int	fd_in;
  char	***tmp;

  fd_in = 0;
  tmp = cmd;
  while (*cmd != NULL)
    {
      pipe(p);
      pid = fork();
      if (pid == -1)
      	exit (-1);
      else if (pid == 0)
	my_pipe2(p, cmd, fd_in, env);
      else
      	{
      	  wait(&pid);
      	  close(p[1]);
      	  fd_in = p[0];
      	  ++cmd;
	  pid = WEXITSTATUS(pid);
	}
    }
  return (pid);
}

int	strlen_cmd(char ***cmd)
{
  int	i;

  i = 0;
  while (cmd[i])
    ++i;
  return (i);
}

void	gestionaire(char *cmd, char ***env)
{
  separ	sep;

  sep.i = 0;
  sep.a = 0;
  sep.str = epur_str(cmd, ' ');
  sep.tab = my_str_to_wordtab2(sep.str, '&');
  sep.compt = how_many(sep.str);
  while (sep.tab[sep.a])
    {
      sep.b = gestionaire2(sep.tab[sep.a], env);
      sep.b = 1;
      if (sep.b == 1 && sep.compt[sep.i] == '&')
      	sep.a++;
      else if (sep.b == 1 && sep.compt[sep.i] == '|')
	return ;
      else if (sep.b != 1 && sep.compt[sep.i] == '|')
	sep.a++;
      else if (sep.b != 1 && sep.compt[sep.i] == '&')
	return ;
      if (sep.compt[sep.i] != '\0')
	sep.i++;
      else
	return ;
    }
}

int	gestionaire2(char *cmd, char ***env)
{
  char	***tab;
  char	**tab2;

  if (nb_pipe(cmd) == 0)
    {
      tab2 = my_str_to_wordtab(correctif(space_maker(cmd)));
      return (argument(tab2, env));
    }
  else
    {
      tab = parser(cmd);
      return (my_pipe(tab, *env));
    }
}
