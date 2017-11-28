/*
** my.h for  in /home/arnould_b/rendu/Piscine_C_J09
**
** Made by jean-michel arnould
** Login   <arnould_b@epitech.net>
**
** Started on  Thu Oct  8 13:25:26 2015 jean-michel arnould
** Last update Mon Jan 25 21:13:06 2016 Arnould Jean-Michel
*/

#ifndef MY_H_
#define MY_H_

int	is_it_a_number(char);
int	is_it_neg(char *);
void	my_putchar(char c);
int	my_isneg(int nb);
int	my_put_nbr(int nb);
int	my_swap(int *a, int *b);
void	my_putstr(unsigned char *str);
void	my_putstr2(unsigned char *);
int	my_strlen(char *str);
int	my_getnbr(char *str);
void	my_sort_int_tab(int *tab, int size);
int	my_power_rec(int nb, int power);
int	my_square_root(int nb);
int	my_is_prime(int nombre);
int	my_find_prime_sup(int nb);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int nb);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int nb);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
int	my_str_isalpha(char *str);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	my_str_isprintable(char *str);
int	my_showstr(char *str);
int	my_showmem(char *str, int size);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int nb);
int	my_strlcat(char *dest, char *src, int size);
void	base(char *, int, long int);
void	flags(char *, int *, long unsigned int);
char	*conv_bn(long int, int, int);
int	my_printf(char *, ...);
char	**my_str_to_wordtab(char *);
#endif
