#include <string>
#include <vector>

std::string range_extraction(std::vector<int> args) {
  std::string res;
	for (int i = 0; i < args.size(); i++) {
		if (abs(args[i] - args[i + 1]) == 1) {
			int j = i + 1, count = 1;
			while (abs(args[j] - args[j + 1]) == 1) {
				j++; count++;
				if (j == args.size() - 1) break;
			}
			if (count + 1 > 2) {
				res += std::to_string(args[i]) + "-" + std::to_string(args[j]) + ",";
				i += count;
			}
			else
			{
				res += std::to_string(args[i]) + ",";
			}
		}
		else
		{
			res += std::to_string(args[i]) + ",";
		}
	}
	res.erase(res.size() - 1);
	return res;
}
