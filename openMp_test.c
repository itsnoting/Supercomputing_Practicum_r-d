#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define ROW 2
#define COL 2
#define SECTOR_HEIGHT 2
#define SECTOR_WIDTH 2

int array[ROW][COL] = {
  {0, 1},
  {2, 3}
};

// given row r and column c and thread ID t_id, you can map thread ID into region of array using following formula                         
// array(r,c) = array[r+m*t_id][c+m*t_id]                                                                                                  
// in this case, m and n are sector height/width                                                                                           
void secureAccess(int threadID){

  for (int row = 0; row < SECTOR_HEIGHT; row++)
    {

      for (int column = 0; column < SECTOR_WIDTH; column++)
        {
          printf("array value: %d, row: %d, col: %d, ThreadID: %d\n" , array[row+SECTOR_HEIGHT*threadID][column+SECTOR_WIDTH*threadID],thr\
eadID);
        }

    }


  // 2. Modify array based on this mapping                                                                                                 
  //printf("array value: %d, row: %d, col: %d, ThreadID: %d\n" , array[row][col], row, col, threadID);                                     

}

int main(int argc, char *argv[]){

  int threads = 4;
  int id = 4;

  omp_set_num_threads(4); // Use 4 threads for all consecutive parallel regions                                                            
#pragma omp parallel
  {

    threads = omp_get_num_threads();
    id = omp_get_thread_num()

    secureAccess(id);
  }
  return 0;
}
