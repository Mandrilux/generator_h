/*
1;2802;0c** read.c for  in /home/baptiste/project/generator_h
**
** Made by
** Login   <baptiste@epitech.net>
**
** Started on  Mon May 16 11:19:53 2016
** Last update Mon May 16 12:59:29 2016 
*/

#include "gen.h"

int	check_is_proto(char *str)
{
  int	nb;
  if ((nb = check_parenthesis(str)) != 2)
    return (-1);
  if (str[strlen(str) - 1] == ')')
    {
      if (is_no_op(str) != -1)
	return (1);
    }
  else
    return (-1);
}

int     check_parenthesis(char *str)
{
  int   i;
  int   nb_o;
  int   nb_c;

  nb_o = 0;
  nb_c = 0;
  i = -1;
  while (str[++i] != '\0')
    {
      if (str[i] == '(')
	nb_o++;
      if (str[i] == ')')
	nb_c++;
    }
  if (nb_o != nb_c)
    return (-1);
  else
    return (nb_o + nb_c);
}

int	is_no_op(char *str)
{
  int	i = -1;

  while (str[++i] != '\0')
    {
      if (str[i] == '=')
	return (-1);
    }
  return (1);
}
