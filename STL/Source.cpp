#include<iostream>
#include<vector>
#include<string.h>
#include<fstream>

using namespace std;
struct student {
	int id;
	string name;
	float score;
};
student input();
bool checkscore(student st);
void output(vector<student>list);
void save(vector<student>list);
void load(vector<student>list);
student input() {
	student st;
	cout << "id :";
	cin >> st.id;
	cout << "name : ";
	cin >> st.name;
	cout << "score :";
	cin >> st.score;
	return st;
}
bool checkscore(student st) {
	if (st.score < 0 || st.score>10) {
		return false;
	}
	else return true;
}
void output(vector<student>list) {
	
	for (int i = 0; i < list.size(); i++) {
		cout << list[i].id << "|" << list[i].name << "|" << list[i].score << endl;
	}
}
void save(vector<student>list) {
	ofstream fo;
	fo.open("test.txt");
	for (int i = 0; i < list.size(); i++) {
		fo << list[i].id << endl;
		fo << list[i].name << endl;
		fo << list[i].score;
		if (i != list.size() - 1) {
			fo << endl;
		}
	}
	fo.close();
}

void load(vector<student>list) {
	ifstream fi;
	fi.open("test.txt");
	for (int i = 0; i < list.size(); i++) {
		fi >> list[i].id;
		fi >> list[i].name;
		fi >> list[i].score;
	}
	for (int i = 0; i < list.size(); i++) {
		cout << list[i].id << "|" << list[i].name << "|" << list[i].score << endl;
	}
	fi.close();

}
int main() {
	int choose;
	vector<student> list;
	

	do {
		
		cout << " 1. Input\n";
		cout << " 2. Display\n";
		cout << " 3. Save to file\n";
		cout << " 4. Load from file\n";
		cout << " 0. Exit\n\n";
	
		cout << " please choose : ";
		cin >> choose;
		switch (choose) {
		case 1:
		{
			student st;
			st = input();
			if (checkscore(st)) {
				list.push_back(st);
			}
			break;
		}

		case 2:
		{
			
			output(list);
			break;
		}
		case 3:
		{
			save(list);
			break;
		}
		case 4:
		{
			load(list);
			break;
		}
		case 0:
		{
			exit(0);
			break;
		}
		default:
		{
			cout<< "choose again!" << endl;
			break;
		}
		}
		
	} while (choose!= 0);
}

