#include <iostream>
#include <string>

using namespace std;

class Node         //Объект списка
{
public:
	
	string end_point;                         //Данные
	int num_flight;
	string fio;
	int day;
	int month;
	int year;

	Node* next;                           //Ссылка на следующий объект

public:
	Node(string end_point, int num_flight, string fio, int day, int month, int year)
	{
		this->end_point = end_point;
		this->num_flight = num_flight;
		this->fio = fio;
		this->day = day;
		this->month = month;
		this->year = year;
		this->next = nullptr;
	}
};

class OneLinkedList 
{
public:
	Node* head, * tail;                        //Первый и последний элемент списка

public:
	OneLinkedList()
	{
		this->head = this->tail = nullptr;
	}
	~OneLinkedList()
	{
		while (head != nullptr)
			pop_front();
	}
	
	void pop_front()              //Удаление элемента в начале списка
	{
		if (head == nullptr)
			return;
		if (head == tail)
		{
			delete tail;
			head = tail = nullptr;
			return;
		}
		Node* node = head;
		head = node->next;
		delete node;
	}
	
	void push_front(string end_point, int num_flight, string fio, int day, int month, int year)   //Добавление элемента в начало списка
	{
		Node* node = new Node(end_point, num_flight, fio, day, month, year);
		node->next = head;
		head = node;
		if (tail == nullptr)
			tail = node;
	}

	void push_back(string end_point, int num_flight, string fio, int day, int month, int year)   //Добавление элемента в конец списка
	{
		Node* node = new Node(end_point, num_flight, fio, day, month, year);
		if (head == nullptr)
			head = node;
		if (tail != nullptr)
			tail->next = node;
		tail = node;
		
	}

	void pop_back()         //Удаление элемента в конце списка
	{
		if (tail == nullptr)
			return;
		if (head == tail)
		{
			delete tail;
			head = tail = nullptr;
			return;
		}
		Node* node = head;
		for (; node->next != tail; node = node->next);
		node->next = nullptr;
		delete tail;
		tail = node;
	}

	Node* getAt(int k)          //Доступ к элементу
	{
		if (k < 0)
			return nullptr;

		Node* node = head;
		int n = 0;
		while (node && n != k && node->next)
		{
			node = node->next;
			n++;
		}
		return (n == k) ? node : nullptr;
	}
	
	void show()              //Вывод всех элементов
	{
		Node* node = head;
		for (; node->next != tail; node = node->next);
		node->next = nullptr;
		tail = node;
		cout << node << endl;
	}
};

int main ()
{
	setlocale(LC_ALL, "Russian");
	
	string end_point;                      //Переменные для передачи в функцию
	int num_flight = 0;
	string fio;
	int day = 0;
	int month = 0;
	int year = 0;

	int c=0;

	OneLinkedList lst;

	while (c != 5)              
	{

		cout << "Выберите желаемую функцию" << endl;
		cout << "1. Добавить новую заявку на рейс" << endl;
		cout << "2. Удалить последнюю заявку на рейс" << endl;
		cout << "3. Вывести заявку по номеру рейса" << endl;
		cout << "4. Вывести все заявки" << endl;
		cout << "5. Выйти из программы" << endl;


		cin >> c;
		switch (c)                  //Выбор функции
		{
		case 1: lst.push_front(end_point, num_flight, fio, day, month, year);
			cout << "Введите пункт назначения" << endl;
			cin >> end_point;
			cout << "Введите номер рейса" << endl;
			cin >> num_flight;
			cout << "Введите фамилию и инициалы" << endl;
			cin >> fio;
			cout << "Введите дату отправления (число/месяц/год)" << endl;
			cin >> day >> month >> year;
			break;
		case 2: lst.pop_back();
			break;
		case 3: cout << "Введите номер рейса" << endl;
			cin >> num_flight;
			lst.getAt(num_flight);
			break;
		case 4: lst.show();
			break;
		default: cout << "Нужно ввести число от 1 до 4!";
			break;
		}
	}
	return 0;
}