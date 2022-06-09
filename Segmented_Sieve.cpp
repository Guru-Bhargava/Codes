#include <bits/stdc++.h>
using namespace std;
int N=1000000;
bool sieve[1000001];
void createsieve()
{
    memset(sieve,true,sizeof(sieve));
    for(int i=2;i*i<=N;++i)
    {
        if(sieve[i])
        {
            for(int j=i*i;j<=N;j+=i)
            {
                sieve[j]=false;
            }
        }
    }
}

vector<int>generatesieve(int N){
    vector<int>ds;
    for(int i=2;i<=N;++i)
    {
        if(sieve[i])
        {
            ds.push_back(i);
        }
    }
    return(ds);
}

int main() {
	createsieve();
	int t;
	cin>>t;
	while(t--)
	{
	    int l,r;
	    cin>>l>>r;
	    vector<int>primes=generatesieve(sqrt(r));
	    int dummy[r-l+1];
	    memset(dummy,1,sizeof(dummy));
	    for(auto pr:primes)
	    {
	        int firstmultiple=(l/pr)*pr;
	        if(firstmultiple<l) firstmultiple+=pr;
	        for(int j=max(firstmultiple,pr*pr);j<=r;j+=pr)
	        {
	            dummy[j-l]=0;
	        }
	    }
	    for(int i=l;i<=r;++i)
	    {
	        if(dummy[i-l] and i!=1){
	            cout<<i<<endl;
	        }
	    }
	    cout<<endl;
	}
}
