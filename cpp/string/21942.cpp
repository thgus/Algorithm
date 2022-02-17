/*
21942번: 부품 대여장
https://www.acmicpc.net/problem/21942
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
int dday, dh, dm;
int f;

void initialize()
{

	cin >> n;

    // ex) 8 014/00:00 5
	string str;
	cin >> str;

	dday = stoi(str.substr(0, 3));
	dh = stoi(str.substr(4, 2));
	dm = stoi(str.substr(7, 2));

	cin >> f;
}

struct Rent {
	int month, day, hour, minute;
};

map<string, long long> member;
map<pair<string, string>, Rent> rent;

int rmonth(int month){
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
        return 31;
    }
    else if(month==2){
        return 28;
    }
    else{
        return 30;
    }
}

long long cal_cost(Rent r){
    long long num=0;
    num+=r.minute;
    num+=r.hour*60;
    num+=r.day*24*60;
    for(int i=1;i<r.month;i++){
        num+=rmonth(i)*24*60;
    }

    return num;
}

void print_result(){
    bool allClear=false;
    for(auto it=member.begin();it!=member.end();it++){
        if(it->second!=0){
            allClear=true;
            cout<<it->first<<" "<<(it->second)*(long long)f<<"\n";
        }
    }

    if(!allClear){
        cout<<"-1";
    }
}

void solve()
{
	while (n--) {
        //ex) 2021-01-01 09:12 arduino tony9402
		string yhm, time, part, mem;
		cin >> yhm >> time >> part >> mem;

		Rent r;
		r.month = stoi(yhm.substr(5, 2));
		r.day = stoi(yhm.substr(8, 2));
		r.hour = stoi(time.substr(0, 2));
		r.minute = stoi(time.substr(3, 2));

        auto it=rent.find({part,mem});

        if(it==rent.end()){ // 렌트 목록에 없음 => 부품 빌림
            rent.insert({{part,mem},r});

            //신규 회원이면 새로 저장
            if(member.find(mem)==member.end()){
                member.insert({mem,0});
            }
        }
        else{   // 렌트 목록에 있음 = > 부품 반납
            it->second.day+=dday;
            it->second.hour+=dh;
            it->second.minute+=dm;

            //시간을 정수로 변환
            long long rent_day=cal_cost(it->second);
            long long return_day=cal_cost(r);

            //렌트 시간이 지났으면 초과 시간만큼 저장
            if(return_day-rent_day>0){
                member.find(mem)->second+=return_day-rent_day;
            }

            rent.erase(it);
        }
	}
}

int main()
{
	sync_off;
	initialize();
    solve();
    print_result(); 

	return 0;
}