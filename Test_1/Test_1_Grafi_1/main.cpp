#include <iostream>
#include <vector>
#include <queue>
#include <string>

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
        visite[versh] = true;                           //Отмечаем город, как посещённый
    }

    cout << "Samiy desheviy do London: " << dist[6] << endl;    //Выводим дистанцию до Лондона

///////////////////////////////////////////////////Кратчайший путь:

    string way[10] = "", tower;

    for (int i = 0; i < 7; i++)
    {
        visite[i] = false;
        dist[i] = INT_MAX;
    }

    dist[0] = 0;
    visite[0] = true;

    q.push(0);
    way[0] = "Moscow->";

    while(!q.empty())
    {
        int versh = q.front();
        q.pop();

        for (int j = 0; j < graf[versh].size(); j++)
        {
            if (!visite[j] && (graf[versh][j] != 0) && (1 + dist[versh] < dist[j]))    //Если город не посещён и
            {                                   //дорога к городу есть и шаги до этого города меньше нынешных, то:
                dist[j] = 1 + dist[versh];         //Дистанции приравниваем шаги данного города + след.
                /*switch(j)                           //В какой город шагаем
                {
                    case 1: tower = "Novosib->";
                    case 2: tower = "Amsterdam->";
                    case 3: tower = "Paris->";
                    case 4: tower = "SPB->";        //swith почему-то работает не корректно
                    case 5: tower = "Berlin->";
                    case 6: tower = "London";
                }*/
                if (j == 1) tower = "Novosib->";
                if (j == 2) tower = "Amsterdam->";
                if (j == 3) tower = "Paris->";
                if (j == 4) tower = "SPB->";
                if (j == 5) tower = "Berlin->";
                if (j == 6) tower = "London;";
                way[j] = way[versh] + tower;
                q.push(j);
            }
            visite[versh] = true;                           //Отмечаем город, как посещённый
        }
    }

    cout << "Kratchayshiy put': " << way[6] << endl;

    return 0;
}
