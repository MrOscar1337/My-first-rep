#include <iostream>
#include <math.h>

using namespace std;

class Circle                              //Класс для описания круга
{
private:
    double cx, cy, r;                     
public:                                   //Объявление функций
    void input_c();
    void output_c();
    void moving_c();
    void change_size_c();
};

class Square                                //Класс для описания квадрата
{
private:
    double ax, ay, cx, cy;
public:                                   //Объявление функций
    void input_s(); 
    void output_s();
    void moving_s();
    void change_size_s();
    void rotate_s();
};

class Rectangle                           //Класс для описания прямоугольника
{
private:
    double ax, ay, cx, cy;
public:                                   //Объявление функций
    void input_r();
    void output_r();
    void moving_r();
    void change_size_r();
    void rotate_r();
};

int menu();                              //Объявление функций меню
int menu_2();

int main()
{
    setlocale(LC_ALL, "Russian");
    Circle a;
    Square b;
    Rectangle c;
    bool work = true;         // Переменная для бесконечного цикла для проверки на выполнение
    bool work_2 = true;          //Вторая переменная для бесконечного цикла
    while (work)
    {
        cout << "Выберите фигуру, с которой хотите работать" << endl;
        switch (menu())
        {
        case 1: {                                      //Работа с кругом
            while (work_2)
            {
                switch (menu_2())
                {
                case 1: { a.input_c();                 //Ввод
                    break;
                }
                case 2: { a.output_c();                 //Вывод
                    break;
                }
                case 3: { a.moving_c();                    //Перемещение
                    break;
                }
                case 4: { a.change_size_c();                //Изменение размеров
                    break;
                }
                case 5: { cout << "Объясните, зачем вам вращать круг?" << endl;      //Небольшая шутка
                    break;
                }
                default: work_2 = false;                     //Выход из внутреннего меню
                    break;
                }
            }
        }
        case 2: {                         //Работа с квадратом
            while (work_2)
            {
                switch (menu_2())
                {
                case 1: b.input_s();               //Ввод
                    break;

                case 2: b.output_s();              //Вывод
                    break;

                case 3: b.moving_s();             //Перемещение
                    break;

                case 4: b.change_size_s();              //Изменение размера
                    break;

                case 5: b.rotate_s();                    //Вращение
                    break;
                default: work_2 = false;               //Выход из внутреннего меню
                    break;
                }
            }
        }
        case 3: {                        //Работа с прямоугольником
            while (work_2)
            {
                switch (menu_2())
                {
                case 1: c.input_r();         //Ввод
                    break;

                case 2: c.output_r();          //Вывод
                    break;

                case 3: c.moving_r();           //Перемещение
                    break;

                case 4: c.change_size_r();     //Изменение размера
                    break;

                case 5: c.rotate_r();              //Поворот
                    break;

                default: work_2 = false;            //Выход из внутреннего меню
                    break;
                }
            }
        case 0: work = false;              //Выход из программы
        }
        }
        
    };

    return 0;
}

int menu()        // Функция отображения меню выбора
{
    int in;
    cout << "Круг - 1" << endl;
    cout << "Квадрат - 2" << endl;
    cout << "Прямоугольник - 3" << endl;
    cout << "Для выхода введите - 0" << endl;
    cin >> in;
    return in;     // Возвращает выбранный пункт меню
};

int menu_2()            //Функция для отображения меню действий
{
    int in_2;
    cout << "Ввести параметры фигуры - 1" << endl;
    cout << "Вывести параметры фигуры - 2" << endl;
    cout << "Переместить фигуру - 3" << endl;
    cout << "Изменить размер фигуры - 4" << endl;
    cout << "Вращать фигуру - 5" << endl;
    cin >> in_2;
    return in_2;
}

void Circle::input_c()             //Функция для ввода параметров круга
{
    cout << endl;
    cout << "Введите параметры круга" << endl;
    cout << " cx=";
    cin >> cx;
    cout << " cy=";
    cin >> cy;
    cout << " r=";
    cin >> r;
    cout << endl;
}

void Square::input_s()                    //Функция для ввода параметров квадрата
{
    cout << endl;
    cout << "Введите параметры квадрата ";
    cout << endl;
    cout << "Координаты центра: cx=";
    cin >> cx;
    cout << " cy=";
    cin >> cy;
    cout << "Вектор от центра до вершины:" << endl;
    cout << " ax=";
    cin >> ax;
    cout << " ay=";
    cin >> ay;
}

void Rectangle::input_r()                //Функция для ввода параметров прямоугольника
{
    cout << endl;
    cout << "Введите параметры прямоугольника";
    cout << endl;
    cout << "Координаты центра: cx=";
    cin >> cx;
    cout << " cy=";
    cin >> cy;
    cout << "Вектор от центра до вершины:" << endl;
    cout << " ax=";
    cin >> ax;
    cout << " ay=";
    cin >> ay;
}

void Circle::output_c()                     //Функция для вывода параметров круга
{
    cout << "Параметры фигуры";
    cout << endl;
    cout << "cx=" << cx << " cy=" << cy << " r=" << r;
    cout << endl;
}

void Square::output_s()                            //Функция для вывода параметров квадрата
{
    cout << "Параметры фигуры";
    cout << endl;
    cout << "cx=" << cx << " cy=" << cy << " ax=" << ax << " ay=" << ay;
    cout << endl;
}

void Rectangle::output_r()                          //Функция для вывода параметров прямоугольника
{
    cout << "Параметры фигуры";
    cout << endl;
    cout << "cx=" << cx << " cy=" << cy << " ax=" << ax << " ay=" << ay;
    cout << endl;
}

void Circle::moving_c()                   //Функция для перемещения круга
{
    int sx, sy, ax = 0, ay = 0;
    cout << "Введите координаты смещения фигуры ";
    cout << endl;
    cout << "Смещение по X= ";
    cin >> sx;
    cout << "Смещение по Y= ";
    cin >> sy;
    cx = cx + sx;
    cy = cy + sy;
    ax = ax + sx;
    ay = ay + sy;
}

void Square::moving_s()                 //Функция для перемещения квадрата
{
    int sx, sy;
    cout << "Введите координаты смещения фигуры ";
    cout << endl;
    cout << "Смещение по X= ";
    cin >> sx;
    cout << "Смещение по Y= ";
    cin >> sy;
    cx = cx + sx;
    cy = cy + sy;
    ax = ax + sx;
    ay = ay + sy;
}

void Rectangle::moving_r()                    //Функция для перемещения прямоугольника
{
    int sx, sy;
    cout << "Введите координаты смещения фигуры ";
    cout << endl;
    cout << "Смещение по X= ";
    cin >> sx;
    cout << "Смещение по Y= ";
    cin >> sy;
    cx = cx + sx;
    cy = cy + sy;
    ax = ax + sx;
    ay = ay + sy;
}

void Circle::change_size_c()                     //Функция для изменения размеров круга
{
    double k;                                    //Переменная для изменения радиуса 
    cout << "Коэффициент изменения радиуса круга= ";
    cout << endl;
    cin >> k;
    r = r * k;                              //Увеличение радиуса в k раз
}

void Square::change_size_s()                    //Функция для изменения размеров квадрата
{
    double k;                                  //Переменная для изменения расстояния от центра до вершины квадрата
    cout << "Коэффициент изменения расстояния до вершины квадрата= ";
    cout << endl;
    cin >> k;
    ax = ax - cx;
    ay = ay - cy;
    ax = ax * k;
    ay = ay * k;
    ax = ax + cx;
    ay = ay + cy;
}

void Rectangle::change_size_r()                     //Функция для изменения размеров прямоугольника
{
    double k;
    cout << "Коэффициент изменения расстояния до вершины прямоугольника= ";
    cout << endl;
    cin >> k;
    ax = ax - cx;
    ay = ay - cy;
    ax = ax * k;
    ay = ay * k;
    ax = ax + cx;
    ay = ay + cy;
}

void Square::rotate_s()                 //Функция для вращения квадрата
{
    double f, co, si, axn1, axn2, ayn1, ayn2, axn, ayn;
    cout << "Угол поворота фигуры ";
    cin >> f;
    const double M_PI = 3.14;
    f = f * M_PI / 180;
    ax = ax - cx;
    ay = ay - cy;
    co = cos(f);
    si = sin(f);
    axn1 = ax * co;
    axn2 = ay * si;
    axn = axn1 - axn2;
    ayn1 = ax * si;
    ayn2 = ay * co;
    ayn = ayn1 + ayn2;
    ax = axn + cx;
    ay = ayn + cy;
};

void Rectangle::rotate_r()                         //Функция для вращения прямоугольника
{
    double f, co, si, axn1, axn2, ayn1, ayn2, axn, ayn;
    cout << "Угол поворота фигуры ";
    cin >> f;
    const double M_PI = 3.14;
    f = f * M_PI / 180;
    ax = ax - cx;
    ay = ay - cy;
    co = cos(f);
    si = sin(f);
    axn1 = ax * co;
    axn2 = ay * si;
    axn = axn1 - axn2;
    ayn1 = ax * si;
    ayn2 = ay * co;
    ayn = ayn1 + ayn2;
    ax = axn + cx;
    ay = ayn + cy;
}