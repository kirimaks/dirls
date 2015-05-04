#define GASP(n) register int i;				\
		if(g) putchar('\''); 			\
                for(i = 0; i < n; i++)			\
                  if( i != 0 && !(i % 4))		\
                    putchar('\'');			\
                  else					\
                    putchar(' ')
                    

#define POINT fprintf(stdout, "%s", "'-> ")

#define MAKE_PATH(path) strcpy(path, dir_name); 			\
    		    	if(*(dir_name + strlen(dir_name) - 1) != '/')	\
      			  strcat(path, "/");				\
    		        strcat(path, p->d_name)
