#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 4
#define NUM_COLS 4
#define SECTOR_HEIGHT 2
#define SECTOR_WIDTH 2

#define NUM_THREADS 4

int array[NUM_ROWS][NUM_COLS] = { 0 } ;

void secureAccess(int threadID){
  int row_offset = (threadID/SECTOR_HEIGHT)*SECTOR_HEIGHT;
  int column_offset = (threadID%SECTOR_WIDTH)*SECTOR_WIDTH;
  
  for (int row = 0+row_offset; row < row_offset+SECTOR_HEIGHT; row++){
    for (int column = 0+column_offset; column < column_offset+SECTOR_WIDTH; column++){
      array[row][column] = row*NUM_ROWS+column;  //threadID;
      printf("array value: %d, row: %d, col: %d, ThreadID: %d\n" , 
	     array[row][column] , row, column,threadID);
    }
  }
}

int main(int argc, char *argv[]){

  omp_set_num_threads(NUM_THREADS);
#pragma shared(array)
#pragma omp parallel for

  for (int i = 0; i < 4; ++i)
    {
      secureAccess(i);
    }
  
  return 0;
}
