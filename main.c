/* K&R exercise 8.5 */
/* recurcive print files and directories */
int main(int argc, char **argv) {
  void show_dir(char*, int);

  if(argc < 2)
    show_dir("./", 0);
  else
    show_dir(argv[1], 0);

  return 0;
}

#include"head.h"
#include"macro.h"

void show_dir(char *dir_name, int g) {
  DIR *cur_dir;		/* the stream to the current directory 		*/
  struct dirent *p;	/* pointer to the object inside directory 	*/

  /* try to open current directory */
  if((cur_dir = opendir(dir_name)) == NULL)
    err(1, "%s", "Can't open directory");

/* if the directory was open, explore inner elements */
  while((p = readdir(cur_dir)) != NULL) {
    struct stat st_buf;
    char *path;

    /* skip current and parents directories and hidden files too */
    if(*p->d_name == '.') continue;

    /* prepare the path */
    if((path = malloc(_POSIX_PATH_MAX)) == NULL)
      err(1, "%s", "Malloc error");

    MAKE_PATH(path);

    /* DEBUG may be here */
    /* try to see what is the current element */
    if(stat(path, &st_buf) != EOF) {
      static char head;

        if(!head++) /* print the initial directory (only once) */
          fprintf(stdout, "%s[%s]%s\n", COLOR_GREEN, dir_name, COLOR_RESET);

        /*** choise mode ***/
        /* if a file, just print it and it's size */
        if(S_ISREG(st_buf.st_mode)) {
          GASP(g);
          POINT;
          fprintf(stdout, "%s %s(%lu k)%s\n", p->d_name, COLOR_RED, st_buf.st_size, COLOR_RESET);
        }

        /* directory */
        else if(S_ISDIR(st_buf.st_mode)) {
          GASP(g);
          POINT;
          fprintf(stdout, "%s[%s]%s\n", COLOR_GREEN, p->d_name, COLOR_RESET);
          show_dir(path, g+4);
        }

        else
          err(1, "%s", "Unknow file type");
    }
    
    else
      err(1, "%s", "Stat error");

    free(path);
  }

  closedir(cur_dir);
}
