#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main (){
    FILE *fin = fopen("A.txt","r");
    int count;
    char cmd[128];
    while (!feof(fin)){
        fscanf(fin,"%[^\n]%*c",&cmd);
        count++;
        printf("\n\ncmd: %s\n",cmd);
        char id[20] = "";
        char toy[20] = "";
        int lastid, lasttoy = strlen(cmd);
        int i;
        for (i = 0; i < strlen(cmd); i++)
        {
			if (isdigit(cmd[i])){
				//printf("i = %d\n",i);
				lastid = i;
			}
        	if ((cmd[i] > 'a' && cmd[i] <'z') || (cmd[i] > 'A' && cmd[i] < 'Z'))
        	{
        		//printf("k = %d\n",i);
        		if (lasttoy > i)
        			lasttoy = i;
			}
    	}
    	strcpy(id, cmd);
    	id[lastid+1] = '\0';
    	int resultid = atoi(id);
    	
    	//printf("lasttoy= %d\n",lasttoy);
    	strcpy(toy, &cmd[lasttoy]);
    	
    	printf("id (char) = %s\n",id);
    	printf("id (int) = %d\n",resultid);
    	printf("toy (char) = %s\n",toy);
    	printf("len(toy) = %d\n",strlen(toy));
    	
    }
    printf("\n count = %d",count);
}
