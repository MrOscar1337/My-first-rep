/*
����� � ��� ������: ������������ ������ �5
�������� ������: 
�.�.�.: ������� ������ ����������
������: ��-211
�������: �3
*/

#include <iostream> 
#include <string> 


using namespace std;

struct STUDENT                           //���������� ����� ���������
{
	string fio;
	int group_num;
	int marks[5];
};

int compare(const void* x1, const void* x2)    //������� ��� ����������
{
	return (*(int*)x1 - *(int*)x2);             
}

int main() {
	setlocale(LC_ALL, "Russian");

	const int SUM = 3, MARKS = 2;                 //���������� ��������

	STUDENT student[SUM];                       //�������� ������� ��������
	
	for (int i = 0; i < SUM; i++)                 //���� ������ � ���������
	{
		cout << "������� ������� � �������� �������� " << endl;
		cin.ignore();
		getline(cin, student[i].fio, '\n');

		cout << "������� ����� ������ " << endl;
		cin >> student[i].group_num;

		cout << "������� ������ �������� " << endl;
		for (int j = 0; j < MARKS; j++)
		{
			cout << ' ' << j + 1 << "-� ������ ";
			cin >> student[i].marks[j];
		}
		cout << endl;
	}
	qsort(student,10,sizeof(student),compare);                      //���������� �������� �� ��������
	cout << "������ ��������� �� ��������: " << endl;
	for (int i = 0; i < SUM; i++)
	{
		cout <<"������� � �������� ��������: " << student[i].fio << endl;
		cout <<"����� ������: " << student[i].group_num << endl;
		cout << "������: ";
		for (int j = 0; j < MARKS; j++)
		{
			cout << ' ' << j + 1 << "-� ������: " << student->marks[j] << endl;
		}
		cout << endl;
	}
	
	cout << "������ ��������� ������� ���� �� ���� ������ 2: " << endl;         //����� ���������, ������� ���� �� ���� ������ 2
	int n = 0;
	for (int i = 0; i < SUM; i++)
	{
		for (int j = 0; j<MARKS; j++)
			if (student[i].marks[j]==2)
			{
				cout << "������� � �������� ��������: " <<student[i].fio << endl;
				cout << "����� ������: " << student[i].group_num << endl;
				n++;
			}
	}
	if (n==0)
	{
		cout << "����� ��������� ���" << endl;
	}

	return 0;
}