#include <vector>
unsigned int countBits(unsigned long long n){
 std::vector<int> bin;
 while(n){
  bin.push_back(n%2);
  n/=2;
 }
 int number = 0;
 for (int i=0;i<bin.size();i++){
  if(bin[i]) number++;
 }
 return number;
}
