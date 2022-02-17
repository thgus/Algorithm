/*
14718번: 용감한 용사 진수
https://www.acmicpc.net/problem/14718

*/

#include <iostream>
#include <algorithm>
#include <vector>

#define SOLMAX 100 //병사 최대 수
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

// 병사 수
int n;
//용사 진수가 이겨야 할 k명의 병사 수
int k;

vector<int[3]> soldier(SOLMAX);
void initialize()
{
    cin >> n >> k;
    //힘 민첩 지능
    int power, agility, intellct;
    for (int i = 0; i < n; i++)
    {
        cin >> power >> agility >> intellct;
        soldier[i][0] = power;
        soldier[i][1] = agility;
        soldier[i][2] = intellct;
    }
}

int minStat = 3000001;

void solv()
{
    //힘 민첩 지능
    int power, agility, intellct;

    //처음에 한 스탯을 정렬하고 시작하면 반복문 하나를 없앨 수 있음.
    //힘 스탯을 오름차순으로 정렬한다고 생각해보자.
    //그리고 민첩, 지능을 임의의 값(반복문으로 돌림)으로 설정하고 몇명의 용사를 이겼는지는 용사 0번부터 n-1번까지 확인한다.
    //만약 i번째의 용사를 이겼다면 힘 스탯은 i번 용사의 스탯만큼만 가지면 된다. 
    //  => 힘 스탯 값을 찾는 것을 2~3번째 줄에서 확인하고 있으므로 힘 스탯을 위해 따로 반복문을 돌릴 필요 없다. 

    // 힘
    for (int p = 0; p < n; p++)
    {   //민첩
        for (int a = 0; a < n; a++)
        {   //지능
            for (int i = 0; i < n; i++)
            { //지능
                //진수가 필요한 스탯 포인트는 선택된 용사들 중
                //힘이 가장 큰 용사의 힘 스탯, 민첩이 가장 큰 용사의 민첩 스탯, 지능이 가장 큰 용사의 지능 스탯을 더한 값
                //n명의 용사들 중 3명(인덱스가 같으면 1명, 2명)의 힘, 민첩, 지능 스탯을 확인해 보고 조건을 만족하는지 확인
                power = soldier[p][0];    //힘 스탯포인트로 선정된 i번 용사
                agility = soldier[a][1];  //민첩 스탯포인트로 선정된 j번 용사
                intellct = soldier[i][2]; //지능 스탯포인트로 선정된 k번 용사

                //위의 스탯포인트를 가지고 이길 수 있는 용사의 수
                int win = 0;
                //현재 힘, 민첩, 지능이 k명의 용사를 이길 수 있는 조건을 만족하는지 확인
                for (int l = 0; l < n; l++)
                {
                    //현재의 힘, 민첩, 지능이 l번째 용사를 이긴다면
                    if (soldier[l][0] <= power && soldier[l][1] <= agility && soldier[l][2] <= intellct)
                    {
                        win++; //이긴 용사의 수 증가
                    }
                }
                //만약 이긴 용사의 수가 조건에서 요구하는 k명의 용사보다 같거나 크면
                if (win >= k && minStat > power + agility + intellct)
                {
                    minStat = power + agility + intellct;
                }
            }
        }
    }

    cout << minStat;
}

int main()
{
    sync_off;
    initialize();
    solv();

    return 0;
}