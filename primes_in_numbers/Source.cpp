#include <vector>
#include <string>
using namespace std;
  int count(std::vector<int>&v,int f){
    int c = 0;
	  for (int i = 0; i < v.size(); i++) {
		  if (v[i] == f) {
			  c++;
			  v.erase(v.begin() + i);
			  i--;
			  if (i < 0) i = -1;
		  }
	  }
  return c;
}
class PrimeDecomp
{
public:

    static std::string factors(int lst){
      std::vector<int> primes;
	int k = 2;
	while (lst) {
		while (lst % k == 0) {
			primes.push_back(k);
			lst /= k;
		}
		if (lst % k != 0) k++;
		if (k > lst) break;
	}
	std::string res;
	for (int i = 0; i < primes.size(); i++) {
		std::string temp;
		temp += '(';
		int temp_numb = primes[i];
		int co = count(primes, primes[i]);
		i--;
		if (co != 1) {
			temp += to_string(temp_numb);
			temp += "**" + to_string(co) + ")";
		}
		else
		{
			temp += to_string(temp_numb) + ")";
		}
		res += temp;
	}

	return res;
    }

};
