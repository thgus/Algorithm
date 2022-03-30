#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<cmath>
#include<list>
#include<queue>

using namespace std;

#define ll long long

ll a, b, c;

struct Station
{
	string name;
	ll y;
	ll x;

	bool isGasStation;
	ll gasPrice;

	Station()
	{
		isGasStation = false;
	}

	Station(string name, ll y, ll x)
	{
		this->name = name;
		this->y = y;
		this->x = x;
		isGasStation = false;
	}
};

map<string, Station> stations;

inline string token_str(string str, int& index)
{
	string result;
	int nindex;

	nindex = str.find(" ", index);
	if (nindex == -1)	return "-1";

	result = str.substr(index, nindex - index);
	index = nindex + 1;

	return result;
}

Station parsing_dis_xy(string str)
{
	str += " ";

	string dist;
	string sy, sx;

	int index = 0;
	dist = token_str(str, index);
	sx = token_str(str, index);
	sy = token_str(str, index);

	while (1)
	{
		string temp = token_str(str, index);
		if (temp == "-1")	break;

		dist += " ";
		dist += sx;

		sx = sy, sy = temp;
	}

	Station result;
	result.name = dist;
	result.y = stoi(sy);
	result.x = stoi(sx);

	return result;
}

pair<string, ll> parsing_gas_station(string str)
{
	str += " ";

	string dist;
	string cost;

	int index = 0;
	dist = token_str(str, index);
	cost = token_str(str, index);

	while (1)
	{
		string temp = token_str(str, index);
		if (temp == "-1")	break;

		dist += " ";
		dist += cost;

		cost = temp;
	}

	return { dist,stoi(cost) };
}

void initialize()
{
	ll n;

	cin >> a >> b >> c;
	cin >> n;

	getchar();
	string str;
	while (n--)
	{
		getline(cin, str);

		Station s = parsing_dis_xy(str);
		stations.insert({ s.name,s });
	}

	n = 3;
	while (n--)
	{
		getline(cin, str);

		pair<string, ll> p = parsing_gas_station(str);
		auto it = stations.find(p.first);
		it->second.isGasStation = true;
		it->second.gasPrice = p.second;
	}
}

struct Passenger
{
	string destination;
	ll move_distance;

	bool operator==(Passenger p)
	{
		if (p.destination == destination)	return true;
		return false;
	}
};

ll money = 0;
list<Passenger> passengers;
string cur;

pair<ll, ll> left_gas;
bool isEnd = false;

// https://mk28.tistory.com/193
ll gcd3(ll a, ll b) { return (a % b == 0 ? b : gcd3(b, a % b)); }

pair<ll, ll> fraction_sum(pair<ll, ll> p1, pair<ll, ll>p2)
{
	ll num = p1.first*p2.second + p2.first*p1.second;
	ll den = p1.second*p2.second;

	ll gcd = gcd3(num, den);

	return{ num / gcd,den / gcd };
}

pair<ll, ll> fraction_sub(pair<ll, ll> p1, pair<ll, ll> p2)
{
	ll num = p1.first*p2.second - p2.first*p1.second;
	ll den = p1.second*p2.second;

	if (num < 0)	return{ -1,1 };
	else if (num == 0)	return { 0,1 };

	ll gcd = gcd3(num, den);

	return{ num / gcd,den / gcd };
}

pair<ll, ll> fraction_mul(pair<ll, ll> p1, pair<ll, ll> p2)
{
	ll num = p1.first*p2.first;
	ll den = p1.second*p2.second;

	ll gcd = gcd3(num, den);

	return{ num / gcd,den / gcd };
}

pair<ll, ll> fraction_div(pair<ll, ll> p1, pair<ll, ll> p2)
{
	ll num = p1.first*p2.second;
	ll den = p1.second*p2.first;

	ll gcd = gcd3(num, den);

	return{ num / gcd,den / gcd };
}

void order1(string x)
{
	auto start = stations[cur];
	auto end = stations[x];

	// 출발지와 도착지의 거리 차
	ll diff = abs(start.y - end.y) + abs(start.x - end.x);
	// 도착지까지 갔을 때 남은 연료
	left_gas = fraction_sub(left_gas, { diff,c });

	// 연료가 모자랄 때
	if (left_gas.first < 0)
	{
		cout << "OUT OF GAS";
		isEnd = true;
		return;
	}

	// 내릴 손님 찾기
	queue<Passenger> out;
	for (auto it = passengers.begin(); it != passengers.end(); it++)
	{
		it->move_distance += diff;

		if (it->destination == x)
		{
			out.push(*it);
		}
	}

	// 손님 내려요~
	while (!out.empty())
	{
		Passenger it = out.front();
		out.pop();

		money += it.move_distance*b;
		passengers.remove(it);
	}

	// 여기가 주유소면 가스 충전하기
	auto curStation = stations[x];
	if (curStation.isGasStation)
	{
		ll gp = curStation.gasPrice;
		pair<ll, ll> need_gas = fraction_sub({ a,1 }, left_gas);
		pair<ll, ll> need_cost = fraction_mul(need_gas, { gp,1 });
		ll need_cost_ll = (long double)need_cost.first / (long double)need_cost.second;

		if (money >= need_cost_ll)
		{
			money -= need_cost_ll;
			left_gas = { a,1 };
		}
		else
		{
			left_gas = fraction_sum({ money,gp }, left_gas);
			money = 0;
		}
	}

	cur = x;
}

void order2(string x)
{
	if (passengers.size() >= 3)
	{
		cout << "CAPACITY FULL";
		isEnd = true;
		
		return;
	}
	passengers.push_back({ x,0 });
}

void solve()
{
	ll k;
	cin >> k;

	left_gas = { a,1 };

	vector<string> order;
	order.push_back("Go to");
	order.push_back("Pickup a passenger going to");

	cur = "Taxi Garage";
	string str;
	getchar();
	while (k--)
	{
		if (isEnd)	return;
		getline(cin, str);

		if (str.find(order[0]) != -1)
		{
			order1(str.substr(order[0].length() + 1, str.length() - order[0].length() - 2));
		}
		else if (str.find(order[1]) != -1)
		{
			order2(str.substr(order[1].length() + 1, str.length() - order[1].length() - 2));
		}

		//double cal_gas = (double)left_gas.first / (double)left_gas.second + 1e-9;
		//int f = 1;
	}

	if (cur != "Taxi Garage")
	{
		cout << "NOT IN GARAGE";
	}
	else if (passengers.size() != 0)
	{
		cout << "REMAINING PASSENGER";
	}
	else
	{
		cout << money;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	initialize();
	solve();

	return 0;
}