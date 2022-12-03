#include <iostream>

using namespace std;

#pragma region Описание структуры

struct ORDER {
    char payersAccount[50];         //Расчётный счёт плательщика
    char beneficiarysAccount[50];   //Расчётный счёт получателя
    int transferAmount = 0;         //Сумма перевода
    void showTransfer() {           //Функция отображения суммы перевода
        cout << "С " << payersAccount << " было списано " << transferAmount << " рублей.";
    };
};

#pragma endregion

#pragma region Инициализация функций

void fillOrder(ORDER* orders, int n);
void showOrder(ORDER* orders, int n);
void sortOrder(ORDER* orders, int n);
void findOrder(ORDER* orders, int n);

#pragma endregion

#pragma region Главная функция

int main()
{
    setlocale(LC_ALL, "Russian");

    int countOrders = 3;        //Количество плательщиков
    ORDER* orders = new ORDER [countOrders];        //Создание массива структур
#pragma region Вызов функций
    fillOrder(orders, countOrders);
    sortOrder(orders, countOrders);
    showOrder(orders, countOrders);
    findOrder(orders, countOrders);
#pragma endregion

    return 0;
}

#pragma endregion

#pragma region Функции

#pragma region Заполнение структуры
void fillOrder(ORDER* orders, int n) {
    for (size_t i = 0; i < n; i++)
    {
        cout << "Введите расчётный счёт плательщика: ";
        cin >> orders[i].payersAccount;
        cout << "Введите расчётный счёт получатела: ";
        cin >> orders[i].beneficiarysAccount;
        cout << "Введите сумму перевода: ";
        cin >> orders[i].transferAmount;
    }
};
#pragma endregion

#pragma region Отображение структуры
void showOrder(ORDER* orders, int n) {
    for (size_t i = 0; i < n; i++)
    {
        cout << "\nРасчётный счёт плательщика номер " << i + 1 << " : " << orders[i].payersAccount;
        cout << "\nРасчётный счёт получателя номер " << i + 1 << " : " << orders[i].beneficiarysAccount;
        cout << "\nСумма перевода: " << orders[i].transferAmount;
    }
};
#pragma endregion

#pragma region Поиск структуры по полю
void findOrder(ORDER* orders, int n) {
    char orderBuff[50];             //Переменная для хранения искомого плательщика
    bool isOrderFind = false;       //Переменная для проверки нахождения плательщика
    cout << "\nВведите счёт плательщика, чтобы узнать сумму перевода: ";
    cin >> orderBuff;
    for (size_t i = 0; i < n; i++)
    {
        if (strcmp(orders[i].payersAccount, orderBuff) == 0)    //Если плательщик найден
        {
            orders[i].showTransfer();           //То выводим сумму перевода и расчётный счёт при помощи встроенной функции
            isOrderFind = true;                 //И говорим программе, что нужный плательщик найден
        }
    }
    if (!isOrderFind)           //Если плательщик не найден, выводим соответствующее сообщение
    {
        cout << "\nПлательщик с расчётным счётом " << orderBuff << " не найден.";
    }
};
#pragma endregion

#pragma region Сортировка структур
void sortOrder(ORDER*orders,int n) {
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n-i; j++)
        {
            if (strcmp(orders[j].payersAccount,orders[j+1].payersAccount) > 0)  //Если расчётный счёт первого выше по алфавиту, второго
            {
                swap(orders[j],orders[j+1]);        //То происходит обмен
            }
        }
    }
}
#pragma endregion

#pragma endregion