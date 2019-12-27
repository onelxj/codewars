#include <vector>
class RGBToHex
{
  public:
  static std::string rgb(int r, int g, int b){
	std::vector<std::string> oct;
	std::vector<int> data = { r,g,b };
	for (int i = 0; i < data.size(); i++) {
		std::string oc;
		if (data[i] > 255) data[i] = 255;
		if (data[i] < 0) data[i] = 0;
		char res[32] = "0";
		static const char* digits = "0123456789ABCDEF";
		int j = data[i] ? 0 : 1;
		while (data[i])
		{
			res[j++] = digits[data[i] % 16];
			data[i] /= 16;
		}
		while (j--)
		{
			oc += res[j];
		}
		if (oc.size() == 1) {//fixing problem with 1 digit on little values
			std::string temp = "0";
			temp += oc;
			oc = temp;
		}
		oct.push_back(oc);
		
	}
	std::string res = oct[0] + oct[1] + oct[2];
	return res;
  }
};
