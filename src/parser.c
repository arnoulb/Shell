/*
** parser.c for  in /home/daelomin/rendu/PSU/PSU_2015_minishell2
**
** Made by Arnould Jean-Michel
** Login   <daelomin@epitech.net>
**
** Started on  Sun Apr  3 16:43:06 2016 Arnould Jean-Michel
** Last update Sat Jun  4 20:17:15 2016 ARNOULD Jean-Michel
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

int	nb_pipe(char *cmd)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (cmd[i])
    {
      if (cmd[i] == '|' && cmd[i - 1] != '|'
	  && (cmd[i + 1] != '|' || cmd[i + 1] == '\0'))
	++nb;
      ++i;
    }
  return (nb);
}

int	size_cmd(char *cmd)
{
  int	i;
  int	size;

  i = 0;
  size = 0;
  while (cmd[i])
    {
      if (cmd[i] == '|' && cmd[i - 1] != '|'
	  && (cmd[i + 1] != '|' || cmd[i + 1] == '\0'))
	return (i);
      ++i;
    }
  return (i);
}

char	*get_cmd(char *cmd, int nb)
{
  int	i;
  int	tmp;
  char	*res;
  int	j;

  i = -1;
  res = malloc(sizeof (char) * (size_cmd(cmd) + 10));
  while (cmd[++i] && nb > 0)
      if (cmd[i] == '|' && cmd[i - 1] != '|'
	  && (cmd[i + 1] != '|' || cmd[i + 1] == '\0'))
      --nb;
  j = -1;
  while (cmd[i])
    {
      res[++j] = cmd[i];
      if (cmd[i] == '|' && cmd[i - 1] != '|'
	  && (cmd[i + 1] != '|' || cmd[i + 1] == '\0'))
	{
	  res[j] = 0;
	  return (res);
	}
	++i;
    }
  res[j + 1] = 0;
  return (res);
}

char	***parser(char *cmd)
{
  char	***cmdout;
  char	*tmp;
  int	nb_cmd;
  int	i;

  i = 0;
  nb_cmd = nb_pipe(cmd) + 1;
  cmdout = malloc(sizeof (char *) * (nb_cmd + 1));
  while (i < nb_cmd)
    {
      cmdout[i] = my_str_to_wordtab(correctif(space_maker(get_cmd(cmd, i))));
      ++i;
    }
  cmdout[i] = 0;
  return (cmdout);
}
