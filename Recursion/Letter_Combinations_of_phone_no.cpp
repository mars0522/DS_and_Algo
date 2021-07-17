class Solution {
public:


	vector<string>fun(string digits, unordered_map<char, vector<string>>& m)
	{
		if (digits.size() == 0)
		{
			vector<string> v;
			return v;
		}
		else if (digits.size() == 1)
		{
			return m[digits[0]];
		}

		else
		{
			char ch = digits[0];
			string str = digits.substr(1);

			vector<string> v = fun(str, m);

			vector<string>res;

			for (auto i : v)
			{
				for (auto j : m[ch])
				{

					res.push_back(j + i);
				}
			}

			return res;

		}

	}

	vector<string> letterCombinations(string digits) {

		unordered_map<char, vector<string>>m;
		vector<string>v1 = {"a", "b", "c"};
		vector<string>v2 = {"d", "e", "f"};
		vector<string>v3 = {"g", "h", "i"};
		vector<string>v4 = {"j", "k", "l"};
		vector<string>v5 = {"m", "n", "o"};
		vector<string>v6 = {"p", "q", "r", "s"};
		vector<string>v7 = {"t", "u", "v"};
		vector<string>v8 = {"w", "x", "y", "z"};

		m['2'] = v1;
		m['3'] = v2;
		m['4'] = v3;
		m['5'] = v4;
		m['6'] = v5;
		m['7'] = v6;
		m['8'] = v7;
		m['9'] = v8;

		return fun(digits, m);

	}
};