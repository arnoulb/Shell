/*
** function.h for  in /home/daelomin/rendu/PSU/PSU_2015_minishell1
**
** Made by Arnould Jean-Michel
** Login   <daelomin@epitech.net>
**
** Started on  Thu Jan 21 20:39:17 2016 Arnould Jean-Michel
** Last update Tue Jun  7 17:27:26 2016 ARNOULD Jean-Michel
*/

#ifndef FUNCTION_H_
#define FUNCTION_H_

/*
** main.c
*/
int	gest_env(char **tab, char ***env);
int	gest_env2(char **tab, char ***env);
int	gestion2(char **tab, char ***env);
void	gestion(char **tab, char **env);

/*
** environ.c
*/
int	my_strlen2(char **str);
char	**env_copy(char **env, char *path);
char	*get_value(char *str, int nb);
char	*get_env_value(char **env, char *str, int nb);
void	aff_env(char **env);

/*
** setenv.c
*/
void	set_env(char ***env, char *param, char *value, int i);
int	get_env_nb(char ***env, char *str, char *value);
void	my_setenv(char ***env, char *param, char *value);

/*
** unsetenv.c
*/

int	is_value(char *env, char *value);
void	my_unsetenv2(char *env, char ***new, int *i, char *param);
void	my_unsetenv(char ***env, char *param);

/*
** tools.c
*/
int	is_same(char *str, char *str2);
int	replace(char *str1, char *str2);
int	is_valid(char *str);
void	my_exit(char **tab, char **env);
char	*concat(char *str, char *str2);

/*
** tools2.c
*/
int	my_chdir2(char **tab, char **env);
int	my_chd2(char **tab, char **env);
int	my_chdir(char **tab, char **env);
int	executer(char **str, char **env, int test);
char	*correctif(char *str);

/*
** errors.c
*/
int	is_good(char *str);
void	free_all(char **tab, char **env);
int	argument(char **tab, char ***env);
int	test_char(char *str);
void	display_prompt(char **env);

/*
** errors2.c
*/
void	error_seg(int child, char **tab);
int	is_exec(char *str);
int	argument2(char **tab, char ***env);
/*
** get_next_line.c
*/
char	*get_next_line(const int fd);

/*
** parser.c
*/
int	nb_pipe(char *cmd);
int	size_cmd(char *cmd);
char	*get_cmd(char *cmd, int nb);
char	***parser(char *cmd);

/*
** multipip.c
*/
void	my_pipe2(int *p, char ***cmd, int fd_in, char **env);
int	my_pipe(char ***cmd, char **env);
int	strlen_cmd(char ***cmd);
void	gestionaire(char *cmd, char ***env);
int	gestionaire2(char *, char ***);

/*
** separators.c
*/
int	size_sep(char *str);
void	main_boucle(char *s, char ***env);
char	*split_sep(char *str, int nb);

/*
** redirection.c
*/
int	is_redir(char **s);
void	redir_lol(char **s);
int	is_redir_left(char **s);
int	is_redir_right(char **s);
int	get_redir(char **s);
int	get_redir_left(char **s);
char	*space_maker(char *s);

/*
** epur_str
*/
char	*epur_str(char *, char);

/*
** my_str_to_wordtab2.c
*/
char	**my_str_to_wordtab2(char *, char);

/*
** compt.c
*/
char	*how_many(char *);

#endif
