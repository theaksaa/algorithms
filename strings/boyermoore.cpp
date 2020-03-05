#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string text, pat;
	cin >> text >> pat;
	
	unordered_map<char, int> suffix;
	int n = text.length();
	int m = pat.length();
	
	for(int i = 0; i < m; i++) { 
		suffix[pat[i]] = m - 1 - i;
	}
	
	int i = m - 1;
	
	while(i < n) {
		if(text[i] == pat[m - 1]) {
			bool flag = true;
			for(int j = i, z = m - 1; z >= 0; j--, z--) {
				if(text[j] != pat[z]) {
					i += min(m - 1 - z, suffix[text[j]] == 0 ? m : suffix[text[j]]);
					flag = false;
					break;
				}
			}
			if(flag) {
				cout << i - (m - 1) << "\n";
				i++;
				//break;
			}
		}
		else i += suffix[text[i]] == 0 ? m : suffix[text[i]];
	}
	return 0; 
}
