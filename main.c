#include <stdio.h>
#include <string.h>

int main(){
char massiv[1024];
char massivnew[1024];
char massiv1[1024];
char massiv1new[1024];
char* znaki;
FILE *text =fopen("input.txt", "r");
FILE *neww =fopen("inputnew.txt", "a");
FILE *dict =fopen("dict.txt", "r");
FILE *opaa =fopen("output.txt","a");

fgets(massivnew, 1024, text);
char* mass = massivnew;
while(znaki = strtok_r(mass," .,-",&mass))
{
    fprintf(neww, "%s\n", znaki);
}
/*Переписали файл input в файл inputnew без знаков препинания*/
fclose(neww);
FILE *neww2 =fopen("inputnew.txt", "r");

while (!feof(neww2)){
fscanf(neww2, "%s", massiv);
int k = 0;
while (!feof(dict))
{
fscanf(dict, "%s", massiv1);
if (strcmp(massiv, massiv1) == 0){
k = 0;
break;
}
else {
k++;
}
}
if(k!=0) {
fprintf (opaa,"%s\n", massiv);
}
dict =fopen("dict.txt", "r");
}
/*Сравнили файл inputnew и dict и переписали лишние слова в файл output*/
fclose(text);
fclose(neww2);
fclose(dict);
fclose(opaa);
FILE *opaa2 =fopen("output.txt","r");
fgets(massiv1new, 1024, opaa2);
memset(massiv1new,'_',4);
if (strlen(massiv1new) == 4){printf("%s","Ok");}else{printf("%s","Warning");}
fclose(opaa2);
/*Задали условия для выходных данных*/
return 0;
}


