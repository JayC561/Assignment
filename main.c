#include <stdio.h>

int main() {
  int i,j,count=1,temp[4];char notExec[5],temp_index;
  int need_res[5][4] = {{0,0,0,0},{0,7,5,0},{1,0,0,2},{0,0,2,0},{0,6,4,2}};
  int alloc_res[5][4] = {{0,0,1,2},{1,0,0,0},{1,3,5,4},{0,6,3,2},{0,0,1,4}};
  int max_res[5][4] = {{0,0,1,2},{1,7,5,0},{2,3,5,6},{0,6,5,2},{0,6,5,6}};
  int avail[4] = {1,5,2,0};
  int index=0,notExec_index=0;

  printf("Safe Sequence is:\n");
  for(i=0;i<5;i++)
  {
    count=0;
    for(j=0;j<4;j++){
      if(need_res[i][j]==0){
        temp[j]=avail[j]+alloc_res[i][j];
        count++;
      }
      else if(need_res[i][j]>avail[j])
      {
        notExec[index++]=i + '0';
        notExec[index]='\0';
        break;  
      }
      else if(need_res[i][j]<=avail[j])
      {
        temp[j]=avail[j]+alloc_res[i][j];
        count++;
      }
      if(count==4)
      {
        for(j=0;j<4;j++){
        avail[j]=temp[j];
        }
        printf("Process P%d\n",i);
      }
    }
  }
  notExec_index=index++;
  index=0;
  while(notExec[index]!='\0'){
    printf("Process P%c not executed\nGiving resources again\n",notExec[index]);
    notExec_index=notExec[index] - '0';
    count=0;
    for(i=0;i<4;i++){
      if(avail[i]>=need_res[notExec_index][i]){
        temp[j]=avail[j]+alloc_res[i][j];
        count++;
      }
      else if(avail[i]<need_res[notExec_index][i]){
        break;
      }
    }
    if(count==4){
      printf("Process P%c is executed",notExec[index]);
    }
    index++;
  }
}

