#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int main(){
    FILE * fp = fopen("C:\\github\\database\\sample.txt", "r+");

    //개행문자는 2비트 ! (20 + 2)
    char buffer[20] = {0,};
    fseek(fp, 22, SEEK_SET);
    fread(buffer,20,1,fp);
    printf("%s\n", buffer);

    rewind(fp);
    char s1[20];
    strcpy(s1, "modify");

    fseek(fp,3,SEEK_SET);
    fwrite(s1,strlen(s1),1,fp);
    rewind(fp);
    fread(buffer,19,1,fp);

    printf("%s\n", buffer);
    fclose(fp);

    return 0;
}