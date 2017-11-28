/*
** redirection.c for  in /home/daelomin/rendu/PSU/PSU_2015_42sh
**
** Made by ARNOULD Jean-Michel
** Login   <daelomin@epitech.net>
**
** Started on  Thu Jun  2 17:37:49 2016 ARNOULD Jean-Michel
** Last update Tue Jun  7 18:08:09 2016 ARNOULD Jean-Michel
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

int	is_redir2(char *tab)
{
  int	i;

  i = -1;
  while (tab[++i])
    {
      if (tab[i] == '<' || tab[i] == '>')
	return (1);
    }
  return (0);
}

char	*space_maker(char *cmd)
{
  int	i;
  int	j;
  char	*res;

  j = -1;
  if (!is_redir2(cmd))
    return (cmd);
  res = malloc(sizeof (char) * (my_strlen(cmd) + 3));
  i = -1;
  while (cmd[++i] && cmd[i] != '<' && cmd[i] != '>')
    res[++j] = cmd[i];
  if (i > 0 && cmd[i - 1] != ' ' && cmd[i] != '\t')
    res[++j] = ' ';
  res[++j] = cmd[i++];
  if (cmd[i] == '<' || cmd[i] == '>')
    res[++j] = cmd[i++];
  if (cmd[i] && cmd[i] != ' ' && cmd[i] != '\t')
    res[++j] = ' ';
  while (cmd[i])
    {
      res[++j] = cmd[i];
      ++i;
    }
  res[j + 1] = 0;
  return (res);
}

int	get_redir(char	**cmd)
{
  int	i;
  int	j;
  int	fd;

  i = -1;
  while (my_strcmp(cmd[++i], ">") && my_strcmp(cmd[i], ">>") && cmd[i]);
  if (is_same(cmd[i], ">") && cmd[i + 1] != NULL)
    fd = open(cmd[i + 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
  else if (is_same(cmd[i], ">>") && cmd[i + 1] != NULL)
    fd = open(cmd[i + 1], O_RDWR | O_CREAT | O_APPEND, 0644);
  else
  close(1);
  dup2(fd, STDOUT_FILENO);
  close(fd);
}

void	redir_left(int fd, char **cmd, int i)
{
  if (fd > 0)
    {
      close(0);
      dup2(fd, STDIN_FILENO);
      close(fd);
    }
  else
    {
      my_printf("File %s does not exist\n", cmd[i + 1]);
      exit(-1);
    }
}

int	get_redir_left(char **cmd)
{
  int	i;
  int	fd;

  i = -1;
  while (my_strcmp(cmd[++i], "<") && my_strcmp(cmd[i], "<<") && cmd[i]);
  if (i > 0)
    {
      if (is_same(cmd[i], "<") && cmd[i + 1] != NULL)
	{
	  fd = open(cmd[i + 1], O_RDONLY);
	  redir_left(fd, cmd, i);
	}
      else
	{
	  my_printf("Missing name for redirect\n");
	  exit(-1);
	}
    }
  else
    my_printf("Missing name for redirect\n");
}
