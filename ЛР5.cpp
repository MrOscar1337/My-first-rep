#include <iostream>
#include <string>

using namespace std;
struct STUDENT
{
	string fio;
	int group_number;
	int marks[5];
};

int main() {

setlocale(LC_ALL, "Russian");

STUDENT student[10];

for (int i = 0; i < 10; i++)
{
	cout << "¬ведите фамилию и инициалы студента " << endl;
	cin.getline(student[i].fio);
}

   return 0;
}
