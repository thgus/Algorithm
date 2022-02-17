/*
20327번: 배열 돌리기 6
https://www.acmicpc.net/problem/20327
*/

#include <iostream>
#include <vector>
#include <cmath>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n, r;
int arr_len;
vector<vector<int>> arr;

void print_arr()
{
	for (int i = 0; i < arr_len; i++)
	{
		for (int j = 0; j < arr_len; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

void initialize()
{
	cin >> n >> r;
	arr_len = pow(2, n);

	arr.resize(arr_len, vector<int>(arr_len));
	for (int i = 0; i < arr_len; i++)    for (int j = 0; j < arr_len; j++)    cin >> arr[i][j];
}

void solve1(int sy, int sx, int len)
{
	int ey = sy + len - 1;
	int ex = sx + len - 1;

	for (int i = 0; i < len / 2; i++)
	{
		for (int j = 0; j < len ; j++)
		{
			int temp = arr[sy + i][sx + j];
			arr[sy + i][sx + j] = arr[ey - i][sx + j];
			arr[ey - i][sx + j] = temp;
		}
	}
}
void solve2(int sy, int sx, int len)
{
	int ey = sy + len - 1;
	int ex = sx + len - 1;

	for (int i = 0; i < len ; i++)
	{
		for (int j = 0; j < len/2; j++)
		{
			int temp = arr[sy + i][sx + j];
			arr[sy + i][sx + j] = arr[sy + i][ex - j];
			arr[sy + i][ex - j] = temp;
		}
	}
}
void solve3(int sy, int sx, int len)
{
	vector<vector<int>> temp(len, vector<int>(len));
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			temp[j][len-1-i] = arr[sy + i][sx + j];
		}
	}

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			arr[sy + i][sx + j] = temp[i][j];
		}
	}
}
void solve4(int sy, int sx, int len)
{
	vector<vector<int>> temp(len, vector<int>(len));
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			temp[len - 1 - j][i] = arr[sy + i][sx + j];
		}
	}

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			arr[sy + i][sx + j] = temp[i][j];
		}
	}
}
void solve5(int y, int len)
{
	int y1 = y * len;
	int y2 = arr_len - ((y+1) * len);

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < arr_len; j++)
		{
			int temp = arr[y1 + i][j];
			arr[y1 + i][j] = arr[y2 + i][j];
			arr[y2 + i][j] = temp;
		}
	}
}
void solve6(int x, int len)
{
	int x1 = x * len;
	int x2 = arr_len - ((x + 1) * len);

	for (int i = 0; i < arr_len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			int temp = arr[i][x1+j];
			arr[i][x1+j] = arr[i][x2+j];
			arr[i][x2+j] = temp;
		}
	}
}

int main()
{
	sync_off;

	initialize();

	vector<vector<int>> temp(arr_len, vector<int>(arr_len));
	int k, l;
	while (r--)
	{
		cin >> k >> l;

		l = pow(2, l);
		switch (k)
		{
		case 1:
			for (int i = 0; i < arr_len; i += l)
			{
				for (int j = 0; j < arr_len; j += l)
				{
					solve1(i, j, l);
				}
			}
			break;
		case 2:
			for (int i = 0; i < arr_len; i += l)
			{
				for (int j = 0; j < arr_len; j += l)
				{
					solve2(i, j, l);
				}
			}
			break;
		case 3:
			for (int i = 0; i < arr_len; i += l)
			{
				for (int j = 0; j < arr_len; j += l)
				{
					solve3(i, j, l);
				}
			}
			break;
		case 4:
			for (int i = 0; i < arr_len; i += l)
			{
				for (int j = 0; j < arr_len; j += l)
				{
					solve4(i, j, l);
				}
			}
			break;
		case 5:
			for (int i = 0; i < arr_len / (l * 2); i++)
			{
				solve5(i, l);
			}
			break;
		case 6:
			for (int i = 0; i < arr_len / (l * 2); i++)
			{
				solve6(i, l);
			}
			break;
		case 7:
			for (int i = 0; i < arr_len / l; i++)
			{
				for (int j = 0; j < arr_len / l; j++)
				{
					int sy = i * l;
					int sx = j * l;

					int ey = j * l;
					int ex = arr_len - (i + 1) * l;

					for (int y = 0; y < l; y++)
					{
						for (int x = 0; x < l; x++)
						{
							temp[ey + y][ex + x] = arr[sy + y][sx + x];
						}
					}
				}
			}
			arr = temp;
			break;
		case 8:
			for (int i = 0; i < arr_len / l; i++)
			{
				for (int j = 0; j < arr_len / l; j++)
				{
					int sy = i * l;
					int sx = j * l;

					int ey = arr_len - (j + 1) * l;
					int ex = i * l;

					for (int y = 0; y < l; y++)
					{
						for (int x = 0; x < l; x++)
						{
							temp[ey + y][ex + x] = arr[sy + y][sx + x];
						}
					}
					int d = 1;
				}
			}
			arr = temp;
			break;
		}

		//print_arr();
	}
	print_arr();

	return 0;
}