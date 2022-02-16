#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main()
{
    FILE *inputfile,*outputfile;
    char input[256],output[256],key[15],replace[15],read[256],ch;
    printf("enter .txt file name to read text- ");
    scanf("%s",&input);
    strcat(input,".txt");
    printf("enter .txt file name to write text- ");
    scanf("%s",&output);
    strcat(output,".txt");
    inputfile=fopen(input,"r");
    outputfile=fopen(output,"w+");
    if(inputfile==NULL || outputfile==NULL)
    {
        printf("Can't open file.");
        exit(0);
    }

    printf("\nEnter the word to find");
    fflush(stdin);
    fgets(key,100,stdin);
    key[strlen(key) - 1] = key[strlen(key)];
    printf("\nEnter the word to replace");
    fgets(replace,100,stdin);
    replace[strlen(replace) - 1] = replace[strlen(replace)];
    printf("\n\n");
    rewind(inputfile);
    while (!feof(inputfile))
    {

        fscanf(inputfile, "%s", read);

        if (strcmp(read, key) == 0) {

            strcpy(read, replace);
        }

        fprintf(outputfile, "%s ", read);
    }

    fclose(inputfile);
    fclose(outputfile);




}
