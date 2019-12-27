#include <string>
#include <vector>
using namespace std;

int score(string s){
  int sc=0;
  for (int i =0;i<s.size();i++){
    sc += (int)s[i] - 96;
  }
  return sc;
}
std::string highestScoringWord(const std::string &str)
{
  vector<string> v;
  string temp;
  for (int i=0;i<str.size();i++){
    if (str[i] == ' '){
      v.push_back(temp);
      temp.clear();
    }
    else if (i+1 == str.size()){
      temp+=str[i];
      v.push_back(temp);
      temp.clear();
    }
    else temp+=str[i];
  }
  
  int max_score= score(v[0]); string word = v[0];
  
  for (auto&c:v){
    if (score(c) > max_score){
      max_score = score(c);
      word = c;     
    }
  }
  return word;
}
