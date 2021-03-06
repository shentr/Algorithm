// CodeForces412E
//http://codeforces.com/problemset/problem/412E


#include <iostream>
#include <string>

using namespace std;

bool isnumber(char x)
{
	return  (x >= '0' && x <= '9');
}

bool isletter(char x)
{
	return (x >= 'a' && x <= 'z');
}

int main()
{
	string str;
	int i, j, k;
	long long ans = 0,lt,rt;
	while (cin >> str)
	{
		ans = 0ll;
		for (i = 0; i < str.length();)
		{
			lt = rt = 0ll;
			if (str[i] == '@')
			{
				for (j = i - 1; j >= 0 && (isnumber(str[j]) || isletter(str[j]) || str[j]=='_'); j--)
				{
					if (isletter(str[j]))
						lt ++;
				}
				for (j = i + 1; j < str.length() && (isnumber(str[j]) || isletter(str[j])); j++);
				if (j < str.length() && str[j] == '.' && j>i+1)
				{
					for (k = j + 1; k < str.length() && isletter(str[k]); k++)
						rt++;
					ans += lt*rt;
					i = k;
				}
				else
					i = j;
			}
			else
				i++;
		}
		cout << ans << endl;
	}
}