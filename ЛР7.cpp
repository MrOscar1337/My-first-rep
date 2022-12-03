#include <iostream>
#include <string>

using namespace std;

class Node         //������ ������
{
public:
	
	string end_point;                         //������
	int num_flight;
	string fio;
	int day;
	int month;
	int year;

	Node* next;                           //������ �� ��������� ������

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
	Node* head, * tail;                        //������ � ��������� ������� ������

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
	
	void pop_front()              //�������� �������� � ������ ������
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
	
	void push_front(string end_point, int num_flight, string fio, int day, int month, int year)   //���������� �������� � ������ ������
	{
		Node* node = new Node(end_point, num_flight, fio, day, month, year);
		node->next = head;
		head = node;
		if (tail == nullptr)
			tail = node;
	}

	void push_back(string end_point, int num_flight, string fio, int day, int month, int year)   //���������� �������� � ����� ������
	{
		Node* node = new Node(end_point, num_flight, fio, day, month, year);
		if (head == nullptr)
			head = node;
		if (tail != nullptr)
			tail->next = node;
		tail = node;
		
	}

	void pop_back()         //�������� �������� � ����� ������
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

	Node* getAt(int k)          //������ � ��������
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
	
	void show()              //����� ���� ���������
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
	
	string end_point;                      //���������� ��� �������� � �������
	int num_flight = 0;
	string fio;
	int day = 0;
	int month = 0;
	int year = 0;

	int c=0;

	OneLinkedList lst;

	while (c != 5)              
	{

		cout << "�������� �������� �������" << endl;
		cout << "1. �������� ����� ������ �� ����" << endl;
		cout << "2. ������� ��������� ������ �� ����" << endl;
		cout << "3. ������� ������ �� ������ �����" << endl;
		cout << "4. ������� ��� ������" << endl;
		cout << "5. ����� �� ���������" << endl;


		cin >> c;
		switch (c)                  //����� �������
		{
		case 1: lst.push_front(end_point, num_flight, fio, day, month, year);
			cout << "������� ����� ����������" << endl;
			cin >> end_point;
			cout << "������� ����� �����" << endl;
			cin >> num_flight;
			cout << "������� ������� � ��������" << endl;
			cin >> fio;
			cout << "������� ���� ����������� (�����/�����/���)" << endl;
			cin >> day >> month >> year;
			break;
		case 2: lst.pop_back();
			break;
		case 3: cout << "������� ����� �����" << endl;
			cin >> num_flight;
			lst.getAt(num_flight);
			break;
		case 4: lst.show();
			break;
		default: cout << "����� ������ ����� �� 1 �� 4!";
			break;
		}
	}
	return 0;
}