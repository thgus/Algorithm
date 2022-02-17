/*
20451번: 앨범정리
https://www.acmicpc.net/problem/20541
*/

#include <iostream>
#include <vector>
#include <map>
#include <set>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

struct Album {
	Album* parent = NULL;
	string name;
	map<string, Album*> m;
	set<string> s;
};

void mkalb(Album *album, string name) {
	if (album->m.find(name)==album->m.end()) {
		Album* temp = new Album;
		temp->parent = album;
		temp->name = name;
		album->m.insert({ name, temp });
	}
	else {
		cout << "duplicated album name\n";
	}
}

pair<int,int> count_album(Album& album) {
	int album_num, photo_num;
	album_num = 1;
	photo_num = album.s.size();

	if (!album.m.empty()) {
		for (auto it = album.m.begin(); it != album.m.end(); it++) {
			pair<int, int> temp = count_album(*(it->second));
			album_num += temp.first;
			photo_num += temp.second;
		}
	}
	
	return{ album_num,photo_num };
}

void rmalb(Album *album, string s) {
	pair<int, int> num;

	if (s == "-1") {
		if (!album->m.empty()) {
			auto it = album->m.begin();
			num = count_album(*(it->second));
			album->m.erase(it);
		}
	}
	else if (s == "0") {
		if (!album->m.empty()) {
			num.first = 0;	num.second = 0;
			pair<int, int> temp;
			for (auto it = album->m.begin(); it != album->m.end();) {
				temp = count_album(*(it->second));
				num.first += temp.first;
				num.second += temp.second;
				it = album->m.erase(it);
			}
		}
	}
	else if (s == "1") {
		if (!album->m.empty()) {
			auto it = album->m.end();
			it--;
			num = count_album(*(it->second));
			album->m.erase(it);
		}
	}
	else {
		auto it = album->m.find(s);
		if (it != album->m.end()) {
			num = count_album(*(it->second));
			album->m.erase(it);
		}
	}

	cout << num.first << " " << num.second << "\n";
}

void photo_insert(Album* album, string name) {
	if (album->s.find(name)==album->s.end()) {
		album->s.insert(name);
	}
	else {
		cout << "duplicated photo name\n";
	}
}

void photo_delete(Album* album, string s) {
	int photo_num = 0;
	if (s == "-1") {
		if (!album->s.empty()) {
			album->s.erase(album->s.begin());
			photo_num++;
		}
	}
	else if (s == "0") {
		photo_num = album->s.size();
		if (!album->s.empty()) {
			for (auto it = album->s.begin(); it != album->s.end();) {
				it = album->s.erase(it);
			}
		}
	}
	else if (s == "1") {
		if (!album->s.empty()) {
			album->s.erase(--album->s.end());
			photo_num++;
		}
	}
	else {
		auto it = album->s.find(s);
		if (it != album->s.end()) {
			album->s.erase(it);
			photo_num++;
		}
	}

	cout << photo_num << "\n";
}

Album* ca(Album* album, Album* top, string s) {
	if (s == "..") {
		if (album->parent != NULL) {
			album = album->parent;
		}
	}
	else if (s == "/") {
		album = top;
	}
	else {
		auto it = album->m.find(s);
		if (it != album->m.end()) {
			album = (it->second);
		}
	}

	cout << album->name << "\n";
	return album;
}

void solve()
{
	int n;
	cin >> n;

	string str1, str2;

	Album top;
	top.name = "album";
	Album *cur = &top;

	while (n--) {
		cin >> str1 >> str2;
		if (str1 == "mkalb") {
			mkalb(cur, str2);
		}
		else if (str1 == "rmalb") {
			rmalb(cur, str2);
		}
		else if (str1 == "insert") {
			photo_insert(cur, str2);
		}
		else if (str1 == "delete") {
			photo_delete(cur, str2);
		}
		else if (str1 == "ca") {
			cur=ca(cur, &top, str2);
		}

	}
}

int main()
{
	sync_off;
	solve();

	return 0;
}