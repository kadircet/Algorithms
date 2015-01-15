#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
using namespace std;

class user
{
	public:
		unsigned long id, nm, nf;
		string name;
		bool active;
		
		bool follows[1000001];
		
		user()
		{
			name = "";
			id = 0;
			nm = 0;
			nf = 0;
			active = true;
			
			memset(follows, 0, sizeof(follows));
		}
};

vector<user> users;
string avaib;

string randName()
{
	string res="";
		
	int len = (rand()%10)+1;
	for(int i=0;i<len;i++)
		res += avaib[rand()%avaib.size()];
	
	for(int i=0;i<users.size();i++)
		if(res == users[i].name)
			return randName();
	return res;
}

int main()
{
	srand(time(NULL));
	avaib="";
	for(char a='0';a<='9';a++)
		avaib+=a;
	for(char a='A';a<='Z';a++)
		avaib+=a;
	for(char a='a';a<='z';a++)
		avaib+=a;
		
	long nm=0, nf=0;
	int nactive=0, ninactive=0;
	int n = (rand()%20000)+1;
	
	user nuser;
	int u1,u2;
	unsigned long k;
	for(int i=0;i<n;i++)
	{
		int m = rand()%7;
		k = 0;
		int l = users.size()+1;
		switch(m)
		{
			case 0: //ADD
				nuser.name = randName();
				nuser.id = users.size()+1;
				users.push_back(nuser);
				cout << "ADD " << nuser.name << endl;
				nactive++;
				break;
			case 1: //FOLLOW
				if(users.size()<2 || 2*nf>=users.size()*(users.size()-1) || nactive<2)
				{
					i--;
					break;
				}
				u1 = rand()%users.size();
				while(!users[u1].active || users[u1].nf == users.size()-1)
				{
					u1++;
					u1%=users.size();
					k++;
					if(k>=l)
					{
						i--;
						goto end;
					}
				}
				
				u2 = rand()%users.size();
				while(!users[u2].active || users[u1].follows[u2] || u1==u2)
				{
					u2++;
					u2%=users.size();
					k++;
					if(k>=l)
					{
						i--;
						goto end;
					}
				}
				
				users[u1].follows[u2] = true;
				users[u1].nf++;
				cout << "FOLLOW " << users[u1].name << " " << users[u2].name << endl;
				nf++;
				break;
			case 2: //SEND
				if(users.size()<1 || nactive<1)
				{
					i--;
					break;
				}
				u1 = rand()%users.size();
				while(!users[u1].active)
				{
					u1++;
					u1%=users.size();
					k++;
					if(k>=l)
					{
						i--;
						goto end;
					}
				}
					
				users[u1].nm++;
				for(int j=0;j<users.size();j++)
					if(users[j].follows[u1] && users[j].active)
						users[j].nm++;
				cout << "SEND " << users[u1].name << endl;
				nm++;
				break;
			case 3: //RESEND
				if(users.size()<1 || nm<1 || nactive<1)
				{
					i--;
					break;
				}
				u1 = rand()%users.size();
				while(!users[u1].active || users[u1].nm<1)
				{
					u1++;
					u1 %= users.size();
					k++;
					if(k>=l)
					{
						i--;
						goto end;
					}
				}
				k = (rand()%users[u1].nm)+1;
				
				users[u1].nm++;
				for(int j=0;j<users.size();j++)
					if(users[j].follows[u1] && users[j].active)
						users[j].nm++;
				
				cout << "RESEND " << users[u1].name << " " << k << endl;
				nm++;
				break;
			case 4: //INACTIVE
				if(users.size()<1 || nactive<1)
				{
					i--;
					break;
				}
				u1 = rand()%users.size();
				while(!users[u1].active)
				{
					u1++;
					u1 %= users.size();
					k++;
					if(k>=l)
					{
						i--;
						goto end;
					}
				}
				
				users[u1].active = false;
				cout << "INACTIVE " << users[u1].name << endl;
				ninactive++;
				nactive--;
				break;
			case 5: //ACTIVE
				if(users.size()<1 || ninactive<1)
				{
					i--;
					break;
				}
				u1 = rand()%users.size();
				while(users[u1].active)
				{
					u1++;
					u1 %= users.size();
					k++;
					if(k>=l)
					{
						i--;
						goto end;
					}
				}
				
				users[u1].active = true;
				cout << "ACTIVE " << users[u1].name << endl;
				nactive++;
				ninactive--;
				break;
			case 6: //UNFOLLOW
				if(users.size()<2 || nf<1 || nactive<2)
				{
					i--;
					break;
				}
				u1 = rand()%users.size();
				while(users[u1].nf==0 || !users[u1].active)
				{
					u1++;
					u1%=users.size();
					k++;
					if(k>=l)
					{
						i--;
						goto end;
					}
				}
				
				u2 = rand()%users.size();
				while(!users[u1].follows[u2] || !users[u2].active || u1==u2)
				{
					u2++;
					u2%=users.size();
					k++;
					if(k>=l)
					{
						i--;
						goto end;
					}
				}
				
				users[u1].follows[u2] = false;
				users[u1].nm = 0;
				cout << "UNFOLLOW " << users[u1].name << " " << users[u2].name << endl;
				nf--;
				break;
		}
		end:
		0;
	}
	
	return 0;
}

