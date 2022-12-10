#include <iostream>
#include <math.h>

using namespace std;

class Circle                              //����� ��� �������� �����
{
private:
    double cx, cy, r;                     
public:                                   //���������� �������
    void input_c();
    void output_c();
    void moving_c();
    void change_size_c();
};

class Square                                //����� ��� �������� ��������
{
private:
    double ax, ay, cx, cy;
public:                                   //���������� �������
    void input_s(); 
    void output_s();
    void moving_s();
    void change_size_s();
    void rotate_s();
};

class Rectangle                           //����� ��� �������� ��������������
{
private:
    double ax, ay, cx, cy;
public:                                   //���������� �������
    void input_r();
    void output_r();
    void moving_r();
    void change_size_r();
    void rotate_r();
};

int menu();                              //���������� ������� ����
int menu_2();

int main()
{
    setlocale(LC_ALL, "Russian");
    Circle a;
    Square b;
    Rectangle c;
    bool work = true;         // ���������� ��� ������������ ����� ��� �������� �� ����������
    bool work_2 = true;          //������ ���������� ��� ������������ �����
    while (work)
    {
        cout << "�������� ������, � ������� ������ ��������" << endl;
        switch (menu())
        {
        case 1: {                                      //������ � ������
            while (work_2)
            {
                switch (menu_2())
                {
                case 1: { a.input_c();                 //����
                    break;
                }
                case 2: { a.output_c();                 //�����
                    break;
                }
                case 3: { a.moving_c();                    //�����������
                    break;
                }
                case 4: { a.change_size_c();                //��������� ��������
                    break;
                }
                case 5: { cout << "���������, ����� ��� ������� ����?" << endl;      //��������� �����
                    break;
                }
                default: work_2 = false;                     //����� �� ����������� ����
                    break;
                }
            }
        }
        case 2: {                         //������ � ���������
            while (work_2)
            {
                switch (menu_2())
                {
                case 1: b.input_s();               //����
                    break;

                case 2: b.output_s();              //�����
                    break;

                case 3: b.moving_s();             //�����������
                    break;

                case 4: b.change_size_s();              //��������� �������
                    break;

                case 5: b.rotate_s();                    //��������
                    break;
                default: work_2 = false;               //����� �� ����������� ����
                    break;
                }
            }
        }
        case 3: {                        //������ � ���������������
            while (work_2)
            {
                switch (menu_2())
                {
                case 1: c.input_r();         //����
                    break;

                case 2: c.output_r();          //�����
                    break;

                case 3: c.moving_r();           //�����������
                    break;

                case 4: c.change_size_r();     //��������� �������
                    break;

                case 5: c.rotate_r();              //�������
                    break;

                default: work_2 = false;            //����� �� ����������� ����
                    break;
                }
            }
        case 0: work = false;              //����� �� ���������
        }
        }
        
    };

    return 0;
}

int menu()        // ������� ����������� ���� ������
{
    int in;
    cout << "���� - 1" << endl;
    cout << "������� - 2" << endl;
    cout << "������������� - 3" << endl;
    cout << "��� ������ ������� - 0" << endl;
    cin >> in;
    return in;     // ���������� ��������� ����� ����
};

int menu_2()            //������� ��� ����������� ���� ��������
{
    int in_2;
    cout << "������ ��������� ������ - 1" << endl;
    cout << "������� ��������� ������ - 2" << endl;
    cout << "����������� ������ - 3" << endl;
    cout << "�������� ������ ������ - 4" << endl;
    cout << "������� ������ - 5" << endl;
    cin >> in_2;
    return in_2;
}

void Circle::input_c()             //������� ��� ����� ���������� �����
{
    cout << endl;
    cout << "������� ��������� �����" << endl;
    cout << " cx=";
    cin >> cx;
    cout << " cy=";
    cin >> cy;
    cout << " r=";
    cin >> r;
    cout << endl;
}

void Square::input_s()                    //������� ��� ����� ���������� ��������
{
    cout << endl;
    cout << "������� ��������� �������� ";
    cout << endl;
    cout << "���������� ������: cx=";
    cin >> cx;
    cout << " cy=";
    cin >> cy;
    cout << "������ �� ������ �� �������:" << endl;
    cout << " ax=";
    cin >> ax;
    cout << " ay=";
    cin >> ay;
}

void Rectangle::input_r()                //������� ��� ����� ���������� ��������������
{
    cout << endl;
    cout << "������� ��������� ��������������";
    cout << endl;
    cout << "���������� ������: cx=";
    cin >> cx;
    cout << " cy=";
    cin >> cy;
    cout << "������ �� ������ �� �������:" << endl;
    cout << " ax=";
    cin >> ax;
    cout << " ay=";
    cin >> ay;
}

void Circle::output_c()                     //������� ��� ������ ���������� �����
{
    cout << "��������� ������";
    cout << endl;
    cout << "cx=" << cx << " cy=" << cy << " r=" << r;
    cout << endl;
}

void Square::output_s()                            //������� ��� ������ ���������� ��������
{
    cout << "��������� ������";
    cout << endl;
    cout << "cx=" << cx << " cy=" << cy << " ax=" << ax << " ay=" << ay;
    cout << endl;
}

void Rectangle::output_r()                          //������� ��� ������ ���������� ��������������
{
    cout << "��������� ������";
    cout << endl;
    cout << "cx=" << cx << " cy=" << cy << " ax=" << ax << " ay=" << ay;
    cout << endl;
}

void Circle::moving_c()                   //������� ��� ����������� �����
{
    int sx, sy, ax = 0, ay = 0;
    cout << "������� ���������� �������� ������ ";
    cout << endl;
    cout << "�������� �� X= ";
    cin >> sx;
    cout << "�������� �� Y= ";
    cin >> sy;
    cx = cx + sx;
    cy = cy + sy;
    ax = ax + sx;
    ay = ay + sy;
}

void Square::moving_s()                 //������� ��� ����������� ��������
{
    int sx, sy;
    cout << "������� ���������� �������� ������ ";
    cout << endl;
    cout << "�������� �� X= ";
    cin >> sx;
    cout << "�������� �� Y= ";
    cin >> sy;
    cx = cx + sx;
    cy = cy + sy;
    ax = ax + sx;
    ay = ay + sy;
}

void Rectangle::moving_r()                    //������� ��� ����������� ��������������
{
    int sx, sy;
    cout << "������� ���������� �������� ������ ";
    cout << endl;
    cout << "�������� �� X= ";
    cin >> sx;
    cout << "�������� �� Y= ";
    cin >> sy;
    cx = cx + sx;
    cy = cy + sy;
    ax = ax + sx;
    ay = ay + sy;
}

void Circle::change_size_c()                     //������� ��� ��������� �������� �����
{
    double k;                                    //���������� ��� ��������� ������� 
    cout << "����������� ��������� ������� �����= ";
    cout << endl;
    cin >> k;
    r = r * k;                              //���������� ������� � k ���
}

void Square::change_size_s()                    //������� ��� ��������� �������� ��������
{
    double k;                                  //���������� ��� ��������� ���������� �� ������ �� ������� ��������
    cout << "����������� ��������� ���������� �� ������� ��������= ";
    cout << endl;
    cin >> k;
    ax = ax - cx;
    ay = ay - cy;
    ax = ax * k;
    ay = ay * k;
    ax = ax + cx;
    ay = ay + cy;
}

void Rectangle::change_size_r()                     //������� ��� ��������� �������� ��������������
{
    double k;
    cout << "����������� ��������� ���������� �� ������� ��������������= ";
    cout << endl;
    cin >> k;
    ax = ax - cx;
    ay = ay - cy;
    ax = ax * k;
    ay = ay * k;
    ax = ax + cx;
    ay = ay + cy;
}

void Square::rotate_s()                 //������� ��� �������� ��������
{
    double f, co, si, axn1, axn2, ayn1, ayn2, axn, ayn;
    cout << "���� �������� ������ ";
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

void Rectangle::rotate_r()                         //������� ��� �������� ��������������
{
    double f, co, si, axn1, axn2, ayn1, ayn2, axn, ayn;
    cout << "���� �������� ������ ";
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