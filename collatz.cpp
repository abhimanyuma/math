
#include <cstring>
#include <cstdio>

int main() {

  int n = 100000000;             //n is the total number for which collatz
                                 //sequence length is computed
  int mem_length = n;            //mem_length is the number till which it is memoized
  long long int current_num = 0;
  int seq_length = 0;

  int *val_map = new int[mem_length];
  memset(val_map, 0, sizeof(int) * mem_length);

  for(int i=1;i<=n; i++){

    seq_length = 0;
    current_num = i;

    while (current_num > 1) {

      //Yay!! We found a memoized value
      if ((current_num < mem_length) && val_map[current_num]) {
        seq_length = seq_length + val_map[current_num];
        break;
      }

      //Check if number is even using j & 1 rather than j%2 because
      //this is much faster
      else if ((current_num & 1) == 0) {
        current_num = current_num >> 1;   //Don't divide by 2, shift right
        seq_length++;
      }

      // If odd do two steps at once
      else {
        current_num = ((3 * current_num) + 1) >> 1; //Don't divide, shift right
        seq_length += 2;
      }
    }

    // If number within memoization limit memoize
    if (i < mem_length)
      val_map[i] = seq_length;

    //For debug purposes
    //printf("%d %d\n",i,seq_length);
  }
}
