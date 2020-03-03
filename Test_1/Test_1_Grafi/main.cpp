#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool f = false;                             //Флаг дошли ли до Лондона
string strBest = "";                        //Лучший маршрут
int countBest = 100;                        //Кол-во шагов лучшего маршрута

string short_way(vector < vector <int> >& graf, const int city, int count)    //Рекурсивная функция поиска короткого маршрута. Передаём
{                                                                       //сам граф; номер города, в котором находимся; шаг
    string str[5] = "", tower;                  //Массив строк маршрутов; город, в который идём
    int i;                                      //Счётчик для for

    if ((city == 6) && (count < countBest))     //Если дошли до Лондона и лучшим маршрутом, то:
    {
        countBest = count;                      //Лучший шаг приравниваем текущему шагу
        f = true;                               //Выставляем флаг
        count--;                                //При возврате назад уменьшаем шаг
        return ";";                             //Возвращаем окончание маршрута
    }

    for (i = city + 1; i < 7; i++)              //Цикл от текущего города +1 до Лондона
    {
        if (city == 0) count = 0;               //На всякий случай обнуляем
        if (graf[city][i] != 0)                 //Если путь есть, то:
        {
            count++;                            //Шаг +1
            /*switch(i)                           //В какой город шагаем
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
            str[city] = tower + short_way(graf, i, count);      //В строку текущего города - след. город + то, что
        }                                                       //вернёт рекурсия след. города
        if (f == true)                          //Когда рекурсии отработали проверяем флаг, если истина, то:
        {
            if (city == 0)                      //Проверяем находимся ли в Москве (начальном городе), если да:
            {
                strBest = str[city];            //Лучший маршрут = текущий маршрут
                f = false;                      //Возвращаем флаг в исходное положение
                //cout << count << endl;
            }
            else                                //Если не в Москве:
            {
                count--;
                return str[city];               //Возвращаем строку текущего города в предыдущий
            }
        }
        //cout << city << endl;
    }
    count--;
    return str[city];
}

int main()
{                           //Задаём матрицу смежности: 0 - пути нет, иначе - цена (планировал изначально в одной проге
                            //реализовывать оба пункта)
    vector < vector <int> > graf = {{0, 500, 100, 300, 0, 0, 0},  //Moscow
                                    {0, 0, 0, 0, 200, 0, 0},      //Novosib
                                    {0, 0, 0, 50, 500, 70, 0},    //Amsterdam
                                    {0, 0, 0, 0, 0, 0, 300},      //Paris
                                    {100, 0, 0, 0, 0, 0, 0},      //SPB
                                    {0, 0, 0, 0, 0, 0, 200},      //Berlin
                                    {0, 0, 0, 0, 500, 0, 0}};     //London

    string way;                                 //Переменная, куда записывается возврат функции поиска
    int city = 0, count = 0;                    //Начальный город и начальный шаг

    way = short_way(graf, city, count);         //Вызывает функцию поиска
    //cout << way << "!!!!" << endl;
    //cout << strBest << "????" << endl;
    cout << "Iteracii: " << countBest << endl;  //Лучший шаг
    cout << "Moscow->" << strBest << endl;      //Выводим лучший маршрут на экран

    return 0;
}
