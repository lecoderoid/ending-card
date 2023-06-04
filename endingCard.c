#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void saveToFile(char (*names)[10][9]){
  FILE *file = fopen("data.txt", "w");
  if(file == NULL){
    printf("Error opening file.\n");
    return;
  }
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++)
      fprintf(file, "%s\n", names[i][j]);
  }
  fclose(file);
}
void readFromFile(char (*names)[10][9]){
  FILE *file = fopen("data.txt", "r");
  if(file == NULL) {
    printf("Error opening file.\n");
    return;
  }

  for(int i = 0; i < 10; i++){
    for(int j=0; j < 10; j++){
      if(fgets(names[i][j], 8, file) == NULL){
        printf("Error reading from file.\n");
        fclose(file);
        return;
      }
      if(strcmp(names[i][j], "\n") == 0){
        strcpy(names[i][j], "");
      }
      size_t len = strlen(names[i][j]);
      if(len > 0 && names[i][j][len-1] == '\n') 
        names[i][j][len-1] = '\0';
    }
  }
  fclose(file);
}
void flush(){
  int c;
  while((c = getchar()) != '\n' && c != EOF);
}
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
  flush();
  printf("enter name: ");
  scanf("%8s", name);
  strcpy(names[row][col], name);
  printf("%d - %d\n", row, col);
  printf("%s\n", names[row][col]);
}
void printArray(const char (*names)[10][9]){
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++)
      printf("%d-%d: %s\n", i, j, names[i][j]);
  }
}
int main(){
  char names[10][10][9] = {""};
  while(1){
    printf("\t\t\tGAME 2: NUGGETS VS HEAT\n\n");
    readFromFile(names);
    // printArray(names);
    printCard(names);
    bet(names);
    flush();
    saveToFile(names);
    // printArray(names);
    // printCard(names);
    // system("clear");
  }
}
