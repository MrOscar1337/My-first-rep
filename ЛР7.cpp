#include <iostream>

using namespace std;

#pragma region Описание структур

#pragma region Структура поезда

class trip {          // Структура для хранения информации о поезде
public:
    string end_ptr;
    int number;
    string fio;
    int day;
    int month;
    int year;
public:
    trip (int num, string end, string FIO, int den, int mesyat, int god) {            // Конструктор структуры с параметрами
        number = num;
        end_ptr = end;
        fio = FIO;
        day = den;
        month = mesyat;
        year = god;
    }
    trip() {                // Конструктор структуры по умолчанию
        
    }
    void printTrip() {     // Функция отображения структуры полностью
        cout << "Номер рейса: " << number << endl;
        cout << "Точка назначения: " << end_ptr << endl;
        cout << "Дата отправления: " << day << "." << month << "." << year << "." << endl;
        cout << "Фамилия и инициалы: " << fio << endl;
    }
};

#pragma endregion

#pragma region Структура узла

class Node {           // Структура узла дерева
public:
    int index;
    trip tr;
    Node* next;     // Указатели на будущие правые и левые ветви дерева
public:
    Node(trip tra) {           // Конструктор структуры с передачей в неё параметров
        index = tra.number;
        tr = tra;
        next = nullptr;
    }
};

#pragma endregion

#pragma endregion

#pragma region Объявление функций

bool exists(Node* head, trip ind);
bool exists(Node* head, int index, int day, int month, int year);
void insert(Node*& head, trip tr);
bool exists(Node* head, Node*prev, int number);
void printNode(Node* head);
int menu();
void deleteNode(Node* prev, Node* head);

#pragma endregion

#pragma region Главная функция

int main()
{
    setlocale(LC_ALL, "Rus");// Установка локали для всей программы для корректного отображения русского языка

    bool work = true;       // Переменна для бесконечного цикла для проверки на выполнение
    Node* head = nullptr;   // Создание корня дерева и присваивание ему нулевого значеиния

    cout << "Приветствую вас в моей программе по хранению сведений об отправляемых поездах. " << endl;  // Приветствие с пользователем
    while (work) {          // Бесконечный цикл опроса
        switch (menu()) {   //Вызов функции меню
        case 1:             // Ввод данных
        {
            int number = 0;
            string end_ptr = " ";
            string fio = " ";
            int day , month , year = 0;
            // Инициализация переменных для хранения вводимых данных
            cout << "Введите номер рейса (только цифры): ";
            cin >> number;
            cout << "Введите пункт назначения: ";
            cin >> end_ptr;
            cout << "Введите дату отправления  (формат ввода день.месяц.год): ";
            cin >> day >> month >> year;
            cout << "Введите фамилию и инициалы: ";
            cin >> fio;
            trip tr(number, end_ptr, fio, day, month, year);       // Создание структуры поезда по конструктору с параметрами
            insert(head, tr);                   // Создаём узел дерева передавая указатель на корень дерева и структуру поезда
            break;
        }
        case 2:                 // Вывод данных
        {
            cout << "Вывод всех заявок: " << endl;
            printNode(head);    // Вызываем функцию вывода значений
            cout << endl;
            break;
        }
        case 3:                 // Поиск по номеру поезда
        {
            int number, day, month, year;
            
            cout << "Введите номер рейса: ";
            cin >> number;
            cout << "Введите дату вылета: ";
            cin >> day >> month >> year;
            if (exists(head, number, day, month, year)) {  // Если поезд с таким номером существует (используется перегруженная функция)
                continue;               // То выходим из условия
            }
            else {                      // Иначе выводим сообщение
                cout << "Рейса с таким номером не существует" << endl;
            }
            break;
        }
        case 4:                 // Поиск всех поездов, относящихся к одной станции
        {
            int number;
            Node* prev = nullptr;
            
            cout << "Введите номер рейса: ";
            cin >> number;         
            if (exists(head, prev, number)) {    // Если есть поезда, относящиеся к данной станции
                cout << "Был удален рейс с номером: " << number << endl;
            }
            else
            {
                cout << "Рейса с номером " << number << " не существует" << endl;
            }
            break;
        }
        case 0: default:        // При нуле и отсутствии значения
        {
            delete head;        // Очищаем память выделенную для хранения дерева
            work = false;       // Меняем флаг выполнения на ложь
            break;              // И выходим из кейса
        }
        }
    }
    return 0;
}

#pragma endregion

#pragma region Функции

#pragma region Проверка существования узла

bool exists(Node* head, trip ind)        // Функция проверки, существует ли уже поезд вовсе
{
    if (head == nullptr) {      // Если узел пуст
        return false;       // Вернуть ложь
    }
    if (head->index == ind.number && head->tr.fio == ind.fio && head->tr.end_ptr == ind.end_ptr) {    // Если да 
        return true;        // Вернуть истину
    }
    return exists(head->next, ind);    //Иначе проверить в правой ветке
}

#pragma endregion

#pragma region Проверка существование поезда с введённым номером

bool exists(Node* head, int number, int day, int month, int year)         // Перегрузка функции проверки существует ли поезд с определённым номером
{
    if (head == nullptr) {      // Если узел пуст
        return false;           // Вернуть ложь
    }
    if (head->index == number && head->tr.day == day && head->tr.month == month && head->tr.year == year) { // Если да
        head->tr.printTrip();  // Отобразить информацию о поезде
        return true;            // И вернуть истину
    }
    return exists(head->next, number, day, month, year);      //Иначе проверить в правой ветке
}

#pragma endregion

#pragma region Проверка существования поездов с определённой станцией

bool exists(Node* head, Node * prev, int number)  // Перегрузка функции проверки для нахождения всех поездов, относящихся к одной станции
{
    if (head == nullptr) {      // Если узел пуст
        return false;           // Вернуть ложь
    }
    if (head->index == number && head->next == nullptr) {  // Если имена искомой станции и станции в узле совпадают
        delete head;   // То вывести истину
        prev->next = nullptr;
        return true;                    // И вернуть истину
    }
    
    if (head->index == number)
    {
        deleteNode(head, head->next);
        return true;
    }
    exists(head->next, prev = head, number);
}

#pragma endregion

void deleteNode (Node*prev, Node*head)
{
    prev->index = head->index;
    prev->tr = head->tr;
    prev->next = head->next;
    delete head;
}

#pragma region Создание узла дерева

void insert(Node*& head, trip tr)    // Фнкция добавления узлов, принемает двойной указатель на корень дерева и структуру поезда, которую надо хранить
{
    if (exists(head, tr)) {              // Проверяем, существует ли такой узел
        cout << "Такой рейс уже существует" << endl;
        return;                         // Если да, то выходим из функции
    }
    if (head == nullptr) {              // Если узла не существует
        head = new Node(tr);            // Tо создаём его
        return;                         // И выходим
    }
    insert(head->next, tr);
    return;                             // В ином случае выходим из функции
}

#pragma endregion

#pragma region Вывод всего дерева

void printNode(Node* head)             // Функция печати дерева в прямом порядке
{
    if (head == nullptr) {              // Если узел пуст
        return;                         // Выходим из функции 
    }
    head->tr.printTrip();
    printNode(head->next);
    return;
}

#pragma endregion

#pragma region Меню выбора

int menu()        // Функция отображения меню выбора
{
    int in;
    cout << "Для ввода новых данных введите - 1" << endl;
    cout << "Для отображения уже существующих данных в системе введите - 2" << endl;
    cout << "Для поиска рейса по номеру и дате вылета введите - 3" << endl;
    cout << "Для удаления по номеру рейса введите - 4" << endl;
    cout << "Для выхода введите - 0" << endl;
    cin >> in;
    return in;     // Возвращает выбранный пункт меню
}

#pragma endregion

