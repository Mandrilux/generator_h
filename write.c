/*
** write.c for  in /home/baptiste/project/generator_h
**
** Made by
** Login   <baptiste@epitech.net>
**
** Started on  Tue May 17 12:51:38 2016
** Last update Tue May 17 12:56:38 2016 
*/

#include "gen.h"

int	write_def_top(t_core *core)
{
  int	fdh;
  char	*tmp;

  if ((fdh = open(core->name_h, O_TRUNC | O_WRONLY)) == -1)
    {
      perror(core->name_prog);
      printf("ok\n");
      exit (0);
    }
  if (core->re_write != NULL)
    {
      printf("ok\n");
    }
  else
    {
      write(fdh, "\n", strlen("\n"));
      if ((tmp = malloc(sizeof(char) * (11 + strlen(core->name_h)))) == NULL)
	{
	  perror(core->name_prog);
	  exit (0);
	}
      memset(tmp, '\0', 13 + strlen(core->name_h));
      sprintf(tmp, "#ifndef %s_H_\n", core->name_h);
      write(fdh, tmp, strlen(tmp));
      memset(tmp, '\0', 13 + strlen(core->name_h));
      sprintf(tmp, "#define %s_H_\n", core->name_h);
      write(fdh, tmp, strlen(tmp));
      /* #ifndef GEN_H_ */
      /* #define GEN_H_ */
    }
  close(fdh);
  return (1);
}
