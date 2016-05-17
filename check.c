/*
1;2802;0c** read.c for  in /home/baptiste/project/generator_h
**
** Made by
** Login   <baptiste@epitech.net>
**
** Started on  Mon May 16 11:19:53 2016
** Last update Tue May 17 18:32:20 2016 
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
	{
	  if (check_not_key_word(str) == 0)
	    return (1);
	  else
	    return (-1);
	}
      else
	return (-1);
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

int	check_not_key_word(char *str)
{
  int	flag = 0;

  if (strstr(str,"while") != NULL)
    flag++;
  else if (strstr(str,"if(") != NULL)
    flag++;
  else if (strstr(str,"if (") != NULL)
    flag++;
  else if (strstr(str,"else(") != NULL)
    flag++;
  else if (strstr(str,"else (") != NULL)
    flag++;
  else if (strstr(str,"else if") != NULL)
    flag++;
  else if (strstr(str,"for(") != NULL)
    flag++;
  else if (strstr(str,"for (") != NULL)
    flag++;
  else
    flag = flag + 0;
  return (flag);
}

int     count_tab(char **tab)
{
  int   i = -1;

  if (tab == NULL)
    return (0);
  while (tab[++i] != NULL);
  return (i);
}

int	last_line_ok(char **tab)
{
  int	len = count_tab(tab);
  int	i = -1;

  if (len == 0)
    return (0);
  while (len - 1 > 0)
    {
      if (strstr(tab[len - 1], "endif") == NULL)
	{
	  while (tab[len - 1][++i] != '\0')
	    {
	      if (tab[len - 1][i] != ' ')
		return (len);
	    }
	}
      i = -1;
      len--;
    }
  return (0);
}

int	is_a_header_file(char *str)
{
  if (strstr(str, ".h") == NULL)
    return (-1);
  else
    return (1);
}

int     is_empty_elm2(char *str)
{
  int	i = -1;

  while (str[++i] != '\0')
    {
      if (str[i] != '\n' && str[i] != ' ')
	return (0);
    }
  return (1);
}

int	is_exist_already(t_core *core, char *str)
{
  t_header     *tmp;
  int		i;

  i = -1;
  tmp = core->header;
  while (tmp != NULL)
    {
      while(tmp->line[++i] != NULL)
	{
	  if (strcmp(str, tmp->line[i]) == 0)
	    {
	      return (1);
	    }
	}
      i = -1;
      tmp = tmp->nxt;
    }
  return (0);
}
