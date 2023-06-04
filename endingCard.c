#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printCard(char (*names)[10][9]){
  int first = 1;
  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
      if(j%5==0){ 
        if(!first)
          printf("┃\n");
        printf("╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋\n");
        first = 0;
      }
      printf("┃%d-%d┃%-10s", i, j, names[i][j]);
    }
  } 
  printf("┃\n");
  printf("╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋\n");
}

void bet(char (*names)[10][9]){
  char num[3];
  char name[9];
  int row, col;
  do{
    printf("enter number combination: ");
    scanf("%2s", num);
    row = (num[0] - '1') + 1;
    col = (num[1] - '1') + 1;
  }while(strcmp(names[row][col],"") != 0);
  printf("enter name: ");
  scanf("%8s", name);
  strcpy(names[row][col], name);
  printf("%d - %d\n", row, col);
  printf("%s\n", names[row][col]);
}
void flush(){
  int c;
  while((c = getchar()) != '\n' && c != EOF);
}
int main(){
  char names[10][10][9] = {""};
  while(1){
    printf("\t\t\tGAME 2: NUGGETS VS HEAT\n\n");
    printCard(names);
    bet(names);
    flush();
    printCard(names);
    system("clear");
  }
}
