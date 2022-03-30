#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<string>
#include<cmath>

using namespace std;

long long a;
long long b, c;

struct Destination
{
	string name;
	long long y, x;

	bool isGasSatation = false;
	long long cost;
};

struct Passenger
{
	string dist;
	long long len;
};

struct Taxi
{
	string cur = "Taxi Garage";
	long long y, x;
	//long long fuel;
	long double can_go;
	long long money = 0;

	queue<Passenger> passenger;
};

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

Destination parsing_dis_xy(string str)
{
	str += " ";

	string dist;
	string sy, sx;

	int index = 0;
	dist = token_str(str, index);
	sy = token_str(str, index);
	sx = token_str(str, index);

	while (1)
	{
		string temp = token_str(str, index);
		if (temp == "-1")	break;

		dist += " ";
		dist += sy;

		sy = sx, sx = temp;
	}

	Destination result;
	result.name = dist;
	result.y = stoi(sy);
	result.x = stoi(sx);

	return result;
}

pair<string, long long> parsing(string str)
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

Taxi taxi;
map<string, Destination> m;

bool go_to_x(string dist_str)
{
	auto dist = m[dist_str];
	long long len = abs(taxi.y - dist.y) + abs(taxi.x - dist.x);

	// ÀÌµ¿Áß ¿¬·á ¶³¾îÁü
	if ((long long)taxi.can_go < len)
	{
		return false;
	}
	taxi.can_go -= len;

	queue<Passenger> temp;
	while (!taxi.passenger.empty())
	{
		Passenger p = taxi.passenger.front();
		taxi.passenger.pop();

		p.len += abs(dist.y - taxi.y) + abs(dist.x - taxi.x);
		if (p.dist == dist_str)
		{
			taxi.money += p.len * b;
		}
		else
		{
			temp.push(p);
		}
	}
	taxi.passenger = temp;

	if (dist.isGasSatation)
	{
		long double left_len = (long double)(a * c) - taxi.can_go;
		left_len += 1e-12;

		long double cost = ((long double)left_len / (long double)c);
		cost = cost + 1e-12;

		long long need_cost = dist.cost * cost;

		if (need_cost <= taxi.money)
		{
			taxi.money -= need_cost;
			taxi.can_go = a * c;
		}
		else
		{
			taxi.can_go += (long double)(taxi.money) / (dist.cost);
			taxi.can_go += 1e-12;
			taxi.money = 0;
		}
	}

	taxi.cur = dist_str;
	taxi.y = dist.y;
	taxi.x = dist.x;

	return true;
}

bool pickup(string dist_str)
{
	if (taxi.passenger.size() >= 3)	return false;

	taxi.passenger.push({ dist_str,0 });

	return true;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> a >> b >> c;

	taxi.can_go = a * c;

	long long n;
	cin >> n;
	getchar();

	string str;
	while (n--)
	{
		getline(cin, str);
		//cin >> str;
		Destination temp = parsing_dis_xy(str);
		m.insert({ temp.name, temp });

		if (temp.name == "Taxi Garage")
		{
			taxi.y = temp.y;
			taxi.x = temp.x;
		}
	}

	for (long long i = 0; i < 3; i++)
	{
		getline(cin, str);
		//cin >> str;
		pair<string, long long> p = parsing(str);
		auto it = m.find(p.first);
		it->second.isGasSatation = true;
		it->second.cost = p.second;
	}

	cin >> n;
	getchar();

	string order[2] = { "Go to" ,"Pickup a passenger going to" };

	while (n--)
	{
		getline(cin, str);

		bool flag[2] = { false,false };
		string dist_str;
		for (long long i = 0; i < 2; i++)
		{
			int index = str.find(order[i], 0);
			if (index != -1)
			{
				dist_str = str.substr(order[i].size() + 1, str.size() - order[i].size() - 1);
				flag[i] = true;
			}
		}
		dist_str.pop_back();

		if (flag[0])
		{
			if (!go_to_x(dist_str)) {
				cout << "OUT OF GAS";
				return 0;
			};
			flag[0] = false;
		}
		else if (flag[1])
		{
			if (!pickup(dist_str)) {
				cout << "CAPACITY FULL";
				return 0;
			};
			flag[0] = false;
		}
	}

	if (taxi.cur != "Taxi Garage")
	{
		cout << "NOT IN GARAGE";
	}
	else if (!taxi.passenger.empty())
	{
		cout << "REMAINING PASSENGER";
	}
	else
	{
		cout << taxi.money;
	}

	return 0;
}
