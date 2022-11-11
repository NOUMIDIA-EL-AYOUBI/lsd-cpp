#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define BUFFER_SIZE 15
static char s[99999];


void  strjoin(char* s1,char* s2)
{
    int n= strlen(s1);
    int m= strlen(s2);
    for(int i =0;i<m;i++)
        s1[n+i]=s2[i];
    return ;

}

/*int check(char* s, int i)
{
        if (s[i]=='\n')
            return 1;
        return 0;

}*/

int check(char* s)
{
	int i=0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return 1;
		i++;
	}
	return 0;
}


void	*Memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*str;

	str = (char*)b;
	i = 0;
	while (i < len)
	{
		str[i] = (char)c;
		i++;
	}
	return (str);
}

char * getline_return( )
{
    int i=0;
    while(s[i]!='\n'&& s[i]!='\0')
    {
        i++;
    }
    if(s[i]=='\n')
        i++;
    char* line= (char*)malloc( sizeof(char)*(i+1));
    for(int k=0;k<i;k++)
        line[k]=s[k];
    line[i]='\0';
    return line;

}

void read_file(int fd   )
{
   int k;

	char* buffer= (char*)malloc((BUFFER_SIZE+1) * sizeof(char));
	while(k=read(fd,buffer,BUFFER_SIZE) != 0)
	{
		if (k== -1)
		{
			free(buffer);
			exit(EXIT_FAILURE);
		}
        strjoin(s,buffer);
        if(check(s))
          break;
	   
	}
    return ;
}


char * extraread()
{
    int n =strlen(s);
    int i=0;
    while(s[i]!='\n')
    {
        i++;
    }
    int size=n-i;
    char * extraread = (char*)malloc((size) * sizeof(char));
    for(int k=0;k<size-1;k++)
        extraread[k]=s[i+k+1];
    extraread[size-1]='\0';
    return extraread;
    
}


	


char* get_line (int fd)
{
	// if fd or buffer_size non valid return null
	read_file (fd);
	if (s == NULL)
		exit(EXIT_FAILURE);
	char* line = getline_return();
	char* extra= extraread();
	
	int i=0;
	while ( line[i] !='\0')
	{
		printf("%c", line[i]);
		i++;
	}
	Memset(s,0,strlen(s));
	int j=0;
	while( extra [j]!= '\0')
	{
		s[j] = extra [j];
        j++;
	}
	return line;
	
}


int main()
{
    
    int fd = open("test.txt", O_RDONLY );
    for (int i=0; i<4; i++)
    {
    	get_line(fd);
    }
    return 0;
    int i=0;
    
}
