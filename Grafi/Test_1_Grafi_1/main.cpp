#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{                   //Объевляем граф:
    vector < vector <int> > graf = {{0, 500, 100, 300, 0, 0, 0},  //Moscow
                                    {0, 0, 0, 0, 200, 0, 0},      //Novosib
                                    {0, 0, 0, 50, 500, 70, 0},    //Amsterdam
                                    {0, 0, 0, 0, 0, 0, 300},      //Paris
                                    {100, 0, 0, 0, 0, 0, 0},      //SPB
                                    {0, 0, 0, 0, 0, 0, 200},      //Berlin
                                    {0, 0, 0, 0, 500, 0, 0}};     //London

    bool visite[10];                    //Посещен ли город
    int dist[10];                       //Дистанция до города

    for (int i = 0; i < 7; i++)         //Устанавливаем, что все города не посещены, а дистанция максимальная
    {
        visite[i] = false;
        dist[i] = INT_MAX;
    }

    dist[0] = 0;                        //Начальный город (Москва) посещён
    visite[0] = true;                   //Дистанция до Москвы = 0

    queue<int> q;                       //Создаём очередь
    q.push(0);                          //Устанавливаем Москву в очередь

    while(!q.empty())                   //Пока очередь не закончится - цикл:
    {
        int versh = q.front();          //Получаем город из очереди
        q.pop();                        //Удаляем город из очереди

        for (int j = 0; j < graf[versh].size(); j++)            //Циклом проходим по всем городам от данного города
        {
            if (!visite[j] && (graf[versh][j] != 0) && (graf[versh][j] + dist[versh] < dist[j]))    //Если город не посещён и
            {                                   //дорога к городу есть и дистанция до этого города меньше нынешней, то:
                dist[j] = graf[versh][j] + dist[versh];         //Дистанции приравниваем дистанцию данного города + след.
                q.push(j);                                      //Добавляем след. город в очередь
            }
        }
    }

    cout << "Samiy desheviy do London: " << dist[6] << endl;    //Выводим дистанцию до Лондона


    return 0;
}
