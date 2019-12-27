#include <vector>
int solution(int number) 
{
  std::vector<int> nums;
  for (int i =1;i<number;i++){
    if (i%3==0){
      nums.push_back(i);
      continue;
    }
    if (i%5==0) nums.push_back(i);
  }
  int sum =0;
  for (const auto&c:nums) sum+=c;
  
  return sum;
}
