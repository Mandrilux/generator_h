/*
** str.c for  in /home/baptiste/project/generator_h
**
** Made by
** Login   <baptiste@epitech.net>
**
** Started on  Tue May 17 13:22:04 2016
** Last update Tue May 17 19:20:56 2016 
*/

#include "gen.h"

char	*format_str(char *str)
{
  char	*tmp;
  char	**cut;
  int	i = -1, len_tmp = 0, nb_elm, len;

  len  = strlen(str);
  if ((tmp = malloc(sizeof(char) * (len + 4))) == NULL)
    return (NULL);
  memset(tmp, '\0', len + 4);
  if ((cut = strtowordtab(str, '(')) == NULL)
    return (NULL);
  if ((cut = strtowordtab(cut[0], ' ')) == NULL)
    return (NULL);
  nb_elm = count_tab(cut);
  while (++i < nb_elm)
    {
      if (i + 1 != nb_elm)
	  len_tmp += strlen(cut[i]) + 1;
    }
  len_tmp -= 1;
  strncat(tmp, str, len_tmp);
  strcat(tmp, "\t\t");
  strcat(tmp, &(str[len_tmp]));
  strcat(tmp, ";");
  free(str);
  return (tmp);
}

char	*get_name_file(char *name)
{
  char	*tmp;
  int	len;

  len = strlen(name);
  if ((tmp = malloc(sizeof(char) * (len + 10))) == NULL)
    return (NULL);
  memset(tmp, '\0', len + 10);
  strcat(tmp, "\t\t");
  strcat(tmp, "/* ");
  strcat(tmp, name);
  strcat(tmp, " */");
  return (tmp);
}

char	**alloc(char **re_write, char *name)
{
  int   i;
  char  **tmp;

  i = -1;
  if (re_write == NULL)
    {
      if ((tmp = malloc(sizeof(char *) * 2)) == NULL)
	return (NULL);
      tmp[0] = strdup(name);
      tmp[1] = NULL;
    }
  else
    {
      if ((tmp = malloc(sizeof(char *) *
			(count_tab(re_write) + 2))) == NULL)
	return (NULL);
      while (re_write[++i] != NULL)
	tmp[i] = re_write[i];
      tmp[i] = strdup(name);
      tmp[i + 1] = NULL;
    }
  return (tmp);
}

char	*add_include(char *str)
{
  char	*tmp;

  if (strstr(str, "include") != NULL)
    return (str);
  if ((tmp = malloc(sizeof(char) * (strlen(str) + strlen("include/") + 1))) == NULL)
    return (NULL);
  memset(tmp, '\0', strlen(str) + strlen("include/") + 1);
  strcat(tmp, "include/");
  strcat(tmp, str);
  return (tmp);
}

char	*header_format(char *name)
{
  char	**cut;
  int	count;

  if ((cut = strtowordtab(name, '/')) == NULL)
    return (NULL);
  count = count_tab(cut);
  if ((cut = strtowordtab(cut[count - 1], '.')) == NULL)
    return (NULL);
  majuscule(cut[0]);
  return (cut[0]);
}

void majuscule(char *chaine)
{
  int i = 0;

  while (chaine[i] != '\0')
    {
      if (chaine[i]  >= 97 && chaine[i] <= 122)
	chaine[i] = chaine[i] - 32;
      i++;
    }
}
