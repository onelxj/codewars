#include <string>
#include <vector>
#include <math.h>

using namespace std;
string get_binary(int n) {
	string temp;
	if (!n) return "0";
	while (n) {
		temp += to_string(n % 2);
		n /= 2;
	}
	reverse(temp.begin(), temp.end());
	return temp;
}
int from_bin(string s) {
	int num = 0, p = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] == '1') num += pow(2, p);
		p++;
	}
	return num;
}

namespace coding
{
    std::string code(const std::string &strng)
    {
      vector<int> data;
      for (int i = 0; i < strng.size(); i++) {
    		string temp;
    		temp += strng[i];
    		data.push_back(stoi(temp));
    	}
  	  string full;
	    for (int i = 0; i < data.size(); i++) {
		    string fpart;
		    string bin = get_binary(data[i]);
		    int k = bin.size();
		    for (int i = 0; i < k - 1; i++) {
			    fpart += '0';
		    }
		  fpart += '1';
		  full += fpart + bin;
	    }   
      
      return full;
    }
    
    
    std::string decode(const std::string &str1)
    {
        string str = str1;
        string decoded = "";
      	string temp;
      	for (int i = 0; i < str.size(); i++) {
      		if (str[i] == '1' && str[i+1] == '1') {
      			temp += "1";
      			decoded += temp;
      			str.erase(str.begin() + i, str.begin() + 2 + i);
      			temp.clear();
      			i--;
      		}
      		else if (str[i] == '1' && str[i + 1] == '0') {
      			temp += "0";
      			decoded += temp;
      			str.erase(str.begin() + i, str.begin() + 2 + i);
      			temp.clear();
      			i--;
      		}
      		else
      		{
      			if (str[i] == '0') {
      				string nulls;
      				for (int j = i; j < str.size(); j++) {
      					if (str[j] == '0') nulls += str[i];
      					if (str[j] != '0') break;
      				}
      				for (int j = i + nulls.size() + 1; j < i + 2 * nulls.size() + 2; j++) {
      					temp += str[j];
      				}
      				str.erase(str.begin() + i, str.begin() + i + 2 * nulls.size() + 2);
      				decoded += to_string(from_bin(temp));
      				temp.clear();
      			}
      			i--;
      		}
      	}
      return decoded;
    }
}
