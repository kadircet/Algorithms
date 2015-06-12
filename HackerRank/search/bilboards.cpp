#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main()
{
    int N,K;
    cin >> N >> K;
    
    long long sum=0;
    vector<long long> c(N+1), dp(N+1);
    deque<long long> dpQ;
    
    for(int i=0;i<N;i++)
    	cin >> c[i], sum+=c[i];
    	
    if(K==N)
    {
    	cout << sum << endl;
    	return 0;
    }
    
    for(int i=0;i<K+1;i++)
    {
    	dp[i] = c[i];
    	while(!dpQ.empty() && dp[i]<=dp[dpQ.back()])
    		dpQ.pop_back();
    	dpQ.push_back(i);
    }
    
    for(int i=K+1;i<N;i++)
    {
    	dp[i] = c[i] + dp[dpQ.front()];
    	while(!dpQ.empty() && dp[i]<=dp[dpQ.back()])
    		dpQ.pop_back();
    	while(!dpQ.empty() && dpQ.front() < i-K)
    		dpQ.pop_front();
    	dpQ.push_back(i);
    }
    
    cout << sum-dp[dpQ.front()] << endl;
    return 0;
}
