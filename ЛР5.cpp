/*
Номер и вид работы: Лабораторная работа №5
Название работы: 
Ф.И.О.: Тагиров Камиль Шамильевич
Группа: ИС-211
Вариант: №3
*/

#include <iostream> 
#include <string> 


using namespace std;

struct STUDENT                           //объявление полей структуры
{
	string fio;
	int group_num;
	int marks[5];
};

int compare(const void* x1, const void* x2)    //функция для сортировки
{
	return (*(int*)x1 - *(int*)x2);             
}

int main() {
	setlocale(LC_ALL, "Russian");

	const int SUM = 3, MARKS = 2;                 //объявление констант

	STUDENT student[SUM];                       //создание массива структур
	
	for (int i = 0; i < SUM; i++)                 //ввод данных в структуру
	{
		cout << "Введите фамилию и инициалы студента " << endl;
		cin.ignore();
		getline(cin, student[i].fio, '\n');

		cout << "Введите номер группы " << endl;
		cin >> student[i].group_num;

		cout << "Введите оценки студента " << endl;
		for (int j = 0; j < MARKS; j++)
		{
			cout << ' ' << j + 1 << "-я оценка ";
			cin >> student[i].marks[j];
		}
		cout << endl;
	}
	qsort(student,10,sizeof(student),compare);                      //Проблема в этой функции. Пробовал через неё писать, но у меня ничего не сработало. Лучшим решением будет написать свою функцию сортировки структуры, хоть тем же пузырьком.
	cout << "Список студентов по алфавиту: " << endl;
	for (int i = 0; i < SUM; i++)
	{
		cout <<"Фамилия и инициалы студента: " << student[i].fio << endl;
		cout <<"Номер группы: " << student[i].group_num << endl;
		cout << "Оценки: ";
		for (int j = 0; j < MARKS; j++)
		{
			cout << ' ' << j + 1 << "-я оценка: " << student->marks[j] << endl;             //Данное обращение всегда идёт к первому элементу структуры. Лучше использовать student[i].marks[j]
		}
		cout << endl;
	}
	
	cout << "Список студентов имеющих хотя бы одну оценку 2: " << endl;         //поиск студентов, имеющих хотя бы одну оценку 2
	int n = 0;
	for (int i = 0; i < SUM; i++)
	{
		for (int j = 0; j<MARKS; j++)
			if (student[i].marks[j]==2)
			{
				cout << "Фамилия и инициалы студента: " <<student[i].fio << endl;
				cout << "Номер группы: " << student[i].group_num << endl;
				n++;
			}
	}
	if (n==0)
	{
		cout << "Таких студентов нет" << endl;
	}

	return 0;
}