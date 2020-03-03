#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool f = false;                             //���� ����� �� �� �������
string strBest = "";                        //������ �������
int countBest = 100;                        //���-�� ����� ������� ��������

string short_way(vector < vector <int> >& graf, const int city, int count)    //����������� ������� ������ ��������� ��������. �������
{                                                                       //��� ����; ����� ������, � ������� ���������; ���
    string str[5] = "", tower;                  //������ ����� ���������; �����, � ������� ���
    int i;                                      //������� ��� for

    if ((city == 6) && (count < countBest))     //���� ����� �� ������� � ������ ���������, ��:
    {
        countBest = count;                      //������ ��� ������������ �������� ����
        f = true;                               //���������� ����
        count--;                                //��� �������� ����� ��������� ���
        return ";";                             //���������� ��������� ��������
    }

    for (i = city + 1; i < 7; i++)              //���� �� �������� ������ +1 �� �������
    {
        if (city == 0) count = 0;               //�� ������ ������ ��������
        if (graf[city][i] != 0)                 //���� ���� ����, ��:
        {
            count++;                            //��� +1
            /*switch(i)                           //� ����� ����� ������
            {
                case 1: tower = "Novosib->";
                case 2: tower = "Amsterdam->";
                case 3: tower = "Paris->";
                case 4: tower = "SPB->";
                case 5: tower = "Berlin->";
                case 6: tower = "London";
            }*/
            if (i == 1) tower = "Novosib->";
            if (i == 2) tower = "Amsterdam->";
            if (i == 3) tower = "Paris->";
            if (i == 4) tower = "SPB->";
            if (i == 5) tower = "Berlin->";
            if (i == 6) tower = "London;";
            str[city] = tower + short_way(graf, i, count);      //� ������ �������� ������ - ����. ����� + ��, ���
        }                                                       //����� �������� ����. ������
        if (f == true)                          //����� �������� ���������� ��������� ����, ���� ������, ��:
        {
            if (city == 0)                      //��������� ��������� �� � ������ (��������� ������), ���� ��:
            {
                strBest = str[city];            //������ ������� = ������� �������
                f = false;                      //���������� ���� � �������� ���������
                //cout << count << endl;
            }
            else                                //���� �� � ������:
            {
                count--;
                return str[city];               //���������� ������ �������� ������ � ����������
            }
        }
        //cout << city << endl;
    }
    count--;
    return str[city];
}

int main()
{                           //����� ������� ���������: 0 - ���� ���, ����� - ���� (���������� ���������� � ����� �����
                            //������������� ��� ������)
    vector < vector <int> > graf = {{0, 500, 100, 300, 0, 0, 0},  //Moscow
                                    {0, 0, 0, 0, 200, 0, 0},      //Novosib
                                    {0, 0, 0, 50, 500, 70, 0},    //Amsterdam
                                    {0, 0, 0, 0, 0, 0, 300},      //Paris
                                    {100, 0, 0, 0, 0, 0, 0},      //SPB
                                    {0, 0, 0, 0, 0, 0, 200},      //Berlin
                                    {0, 0, 0, 0, 500, 0, 0}};     //London

    string way;                                 //����������, ���� ������������ ������� ������� ������
    int city = 0, count = 0;                    //��������� ����� � ��������� ���

    way = short_way(graf, city, count);         //�������� ������� ������
    //cout << way << "!!!!" << endl;
    //cout << strBest << "????" << endl;
    cout << "Iteracii: " << countBest << endl;  //������ ���
    cout << "Moscow->" << strBest << endl;      //������� ������ ������� �� �����

    return 0;
}
