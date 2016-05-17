/*
** write.c for  in /home/baptiste/project/generator_h
**
** Made by
** Login   <baptiste@epitech.net>
**
** Started on  Tue May 17 12:51:38 2016
** Last update Tue May 17 18:02:09 2016 
*/

#include "gen.h"

int	write_def_top(t_core *core)
{
  int	fdh;
  char	*tmp;
  int	i = -1;

  core->name_h_maj = header_format(core->name_h);
  if ((fdh = open(core->name_h, O_TRUNC | O_WRONLY)) == -1)
    {
      perror(core->name_prog);
      exit (0);
    }
  if (core->re_write != NULL)
    {
      while (++i < core->nb_write)
	{
	  write(fdh, core->re_write[i], strlen(core->re_write[i]));
	  write(fdh, "\n", strlen("\n"));
	}
      write(fdh, "\n", strlen("\n"));
    }
  else
    {
      write(fdh, "\n", strlen("\n"));
      if ((tmp = malloc(sizeof(char) * (11 + strlen(core->name_h_maj)))) == NULL)
	{
	  perror(core->name_prog);
	  exit (0);
	}
      memset(tmp, '\0', 13 + strlen(core->name_h_maj));
      sprintf(tmp, "#ifndef %s_H_\n", core->name_h_maj);
      write(fdh, tmp, strlen(tmp));
      memset(tmp, '\0', 13 + strlen(core->name_h_maj));
      sprintf(tmp, "#define %s_H_\n", core->name_h_maj);
      write(fdh, tmp, strlen(tmp));
    }
  close(fdh);
  return (1);
}

int	write_def_bottom(t_core *core)
{
  int	fdh;
  char	*tmp;

  if ((fdh = open(core->name_h, O_APPEND | O_WRONLY)) == -1)
    {
      perror(core->name_prog);
      exit (0);
    }
  if ((tmp = malloc(sizeof(char) * (18 + strlen(core->name_h_maj)))) == NULL)
    {
      perror(core->name_prog);
      exit (0);
    }
  memset(tmp, '\0', 18 + strlen(core->name_h_maj));
  sprintf(tmp, "#endif /* %s_H_ */\n", core->name_h_maj);
  write(fdh, tmp, strlen(tmp));
  return (1);
}
