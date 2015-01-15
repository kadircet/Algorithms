#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> numbers;

string rev(const string& str)
{
	string res="";
	for(int i=0;i<str.size();i++)
		res+=str[str.size()-1-i];
	return res;
}

string square(string str)
{
	str = rev(str);
	vector<string> toSum(str.size());
	for(int i=0;i<str.size();i++)
	{
		int carry=0;
		for(int j=0;j<i;j++)
			toSum[i]+='0';
		for(int j=0;j<str.size();j++)
		{
			int x = (str[i]-'0')*(str[j]-'0')+carry;
			carry = x/10;
			toSum[i] += (char)(x%10+'0');
		}
		while(carry)
		{
			toSum[i] += (char)(carry%10+'0');
			carry/=10;
		}
	}
	
	int carry=0;
	string res="";
	for(int i=0;i<toSum.back().size();i++)
	{
		int ds=0;
		for(int j=0;j<toSum.size();j++)
		{
			if(i>=toSum[j].size())
				continue;
			ds += toSum[j][i]-'0';
		}
		ds += carry;
		carry = ds/10;
		res += (char)(ds%10+'0');
	}
	while(carry)
	{
		res += (char)(carry%10+'0');
		carry/=10;
	}
	
	return res;
}

void generate(string cur, int rest, int d)
{
	if(cur.size()==(d+1)/2)
	{
		numbers.push_back(cur+rev(cur.substr(0, cur.size()-d%2)));
		return;
	}
	
	for(int i=0+cur.size()==0;i<4;i++)
		if((d+1)/2-1==cur.size() && d%2)
		{
			if(i*i<=rest)
				generate(cur+(char)(i+'0'), rest-i*i, d);
		}
		else if(2*i*i<=rest)
			generate(cur+(char)(i+'0'), rest-i*i*2, d);
}

bool bignumcomp(const string& a, const string& b)
{
	if(a.size()==b.size())
		return a<b;
	return a.size()<b.size();
}

int main()
{
	for(int i=1;i<51;i++)
		generate("", 9, i);
	for(int i=0;i<numbers.size();i++)
		numbers[i] = square(numbers[i]);
	sort(numbers.begin(), numbers.end(), bignumcomp);
	return 0;
	
	string A,B;
	int T,t=0;
	cin >> T;
	
	while(T--)
	{
		t++;
		cin >> A >> B;
		int s=lower_bound(numbers.begin(), numbers.end(), A, bignumcomp)-numbers.begin();
		int e=upper_bound(numbers.begin(), numbers.end(), B, bignumcomp)-numbers.begin();
		cout << "Case #" << t << ": " << e-s << endl;
	}
	
	return 0;
}
