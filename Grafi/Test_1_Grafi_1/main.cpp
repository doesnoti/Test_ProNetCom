#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{                   //��������� ����:
    vector < vector <int> > graf = {{0, 500, 100, 300, 0, 0, 0},  //Moscow
                                    {0, 0, 0, 0, 200, 0, 0},      //Novosib
                                    {0, 0, 0, 50, 500, 70, 0},    //Amsterdam
                                    {0, 0, 0, 0, 0, 0, 300},      //Paris
                                    {100, 0, 0, 0, 0, 0, 0},      //SPB
                                    {0, 0, 0, 0, 0, 0, 200},      //Berlin
                                    {0, 0, 0, 0, 500, 0, 0}};     //London

    bool visite[10];                    //������� �� �����
    int dist[10];                       //��������� �� ������

    for (int i = 0; i < 7; i++)         //�������������, ��� ��� ������ �� ��������, � ��������� ������������
    {
        visite[i] = false;
        dist[i] = INT_MAX;
    }

    dist[0] = 0;                        //��������� ����� (������) �������
    visite[0] = true;                   //��������� �� ������ = 0

    queue<int> q;                       //������ �������
    q.push(0);                          //������������� ������ � �������

    while(!q.empty())                   //���� ������� �� ���������� - ����:
    {
        int versh = q.front();          //�������� ����� �� �������
        q.pop();                        //������� ����� �� �������

        for (int j = 0; j < graf[versh].size(); j++)            //������ �������� �� ���� ������� �� ������� ������
        {
            if (!visite[j] && (graf[versh][j] != 0) && (graf[versh][j] + dist[versh] < dist[j]))    //���� ����� �� ������� �
            {                                   //������ � ������ ���� � ��������� �� ����� ������ ������ ��������, ��:
                dist[j] = graf[versh][j] + dist[versh];         //��������� ������������ ��������� ������� ������ + ����.
                q.push(j);                                      //��������� ����. ����� � �������
            }
        }
    }

    cout << "Samiy desheviy do London: " << dist[6] << endl;    //������� ��������� �� �������


    return 0;
}
