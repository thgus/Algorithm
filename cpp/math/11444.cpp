#include<iostream>
#include<map>

#define ll long long
#define DIVISOR 1000000007

using namespace std;

map<ll, ll> mem;
ll n;

void initialize()
{
	cin >> n;
}

// Fm+n=Fm-1*Fn+Fm*Fn+1
ll docagne(ll num)
{
	if (num == 0)	return 0;
	else if (num == 1)	return 1;
	else if (num == 2)	return 1;
	else if (mem.count(num) > 0)	return mem[num];
	else
	{
		if (num % 2 == 0)	//Â¦¼ö
		{
			//Fn+n = Fn-1*Fn + Fn*Fn+1
			//	= Fn(Fn-1 + Fn+1)
			//	= Fn(Fn-1 + Fn + Fn-1 )
			//	= Fn(2*Fn-1 + Fn )
			ll a = docagne(num / 2 - 1) % DIVISOR;
			ll b = docagne(num / 2) % DIVISOR;

			mem[num] = (b * ((2 * a + b) % DIVISOR)) % DIVISOR;
		}
		else //È¦¼ö
		{
			//Fn+1+n = Fn*Fn + Fn+1*Fn+1
			//	= Fn^2+Fn+1^2

			ll a = docagne(num / 2) % DIVISOR;
			ll b = docagne(num / 2 + 1) % DIVISOR;

			mem[num] = ((a*a) % (DIVISOR)+(b*b) % (DIVISOR)) % DIVISOR;
		}

		return mem[num];
	}
}

void solve()
{
	ll result = docagne(n);
	cout << result % DIVISOR;
}

int main()
{
	initialize();
	solve();

	return 0;
}