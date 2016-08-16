//#include <cassert>
#include <cstring>
#include <map>
//using namespace std;
int main() {
  //printf("%d %d\n",sizeof(int), sizeof(long long int));
  int x = 10000000;
  long long int j = 0;
  int count = 0;
  std::map<long long int, int> val_map;
  //memset(array, 0, sizeof(int) * x);
  for(int i=1;i<=x;i++){
    count = 0;
    j = i;
    while (j>1) {
      if (val_map[j]) {
        count = count + val_map[j];
        break;
      } else if ((((j >> 1) << 1) -j) == 0) {
        j = j >> 1;
        count++;
      } else {
        j = ((3 * j) + 1) >> 1;
        count += 2;
      }
    }
    val_map[i] = count;
  }
}
