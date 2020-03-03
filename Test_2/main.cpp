#include <iostream>
#include <string>

using namespace std;

class Goods                                                         //Класс "Товары"
{
public:
    Goods(string nameShop, string location, string outlets);        //Объевляем контруктор в который передаётся адрес

    void add_new(string name, string parent);                       //Метод добавления нового товара
    void categor(string fname);                                     //Метод вывода на экран заданной категории
    void goods_from_cat(string fname);                              //Метод вывода товаров заданной категории
    int getSize(){return Size;}                                     //Метод, возвращающий кол-во товаров
    string getNameShop(){return nameShop;}                          //Возвращает имя магазина
    string getLocation(){return nameShop + "-" + location;}         //Возвращает "Формат торгового пути"
    string getOutlets(){return nameShop + "-" + location + " " + outlets;}      //Возвращает "Торговую точку"
    void available(string fname);                                   //Метод проверки наличия товара
private:

    class Node                                                      //Класс "Узел"
    {
    public:
        string parent;                                              //Хранит имя родителя товара
        string name;                                                //Имя товара
        Node *pNext;                                                //Указатель на след. элемент списка

        Node(string name, string parent = "", Node *pNext = nullptr)        //Конструктор "Узла"
        {
            this->name = name;                                      //Присваивает все полученные значения переменным класса
            this->parent = parent;
            this->pNext = pNext;
        }
    };
                                                                    //Переменные класса "Товары"
    string location, outlets, nameShop;                             //"Формат торг. пути", "Торг. точка" и имя магазина
    Node *head;                                                     //"Голова" первого элемента списка
    int Size;                                                       //Размер списка
};

Goods::Goods(string nameShop, string location, string outlets)      //Реализация конструктора класса
{
    head = new Node("Goods", "");                                   //"Голова"-первый элемент под именем "Товары" и без родителя
    Size = 0;                                                       //Размер пока нулевой
    this->location = location;                                      //Присваивает все полученные значения переменным класса
    this->outlets = outlets;
    this->nameShop = nameShop;
}

void Goods::add_new(string name, string parent)                     //Метод добавления нового товара
{
    Node *current = this->head;                                     //Временная переменная, в которую присв. знач. головы
    bool f = false;                                                 //Флаг

    if (current->name == parent)                                    //Проверяем верно ли введено имя родителя, если да:
    {
        f = true;                                                   //то поднимаем флаг (до цикла, потому что цикл может не идти)
    }
    while (current->pNext != nullptr)                               //Цикл, пока указатель не будет указывать на пустоту
    {
        current = current->pNext;                                   //Двигаемся по списку
        if (current->name == parent)                                //По-ходу проверяем имя родителя
        {
            f = true;
        }
    }

    if (f == false)                                                 //Если флаг опущен - имя родителя введено не правильно
    {
        cout << "Net takogo roditelya: " << parent << endl;
    }
    else                                                            //Иначе:
    {
        current->pNext = new Node(name, parent);                    //Указателю в пустоту присваиваем указ. на новый узел и созд.
        Size++;                                                     //новый узел. Размер списка +1
    }
}

void Goods::categor(string fname)                                   //Метод вывода заданной категории на экран
{
    Node *current = this->head;                                     //То же, что в прошлом методе
    bool f = false;

    if (current->name == fname)
    {
        f = true;
    }

    while ((current->name != fname) && (current->pNext != nullptr))     //Пока не встретим категорию или до конца списка
    {
        current = current->pNext;
        if (current->name == fname)
        {
            f = true;
        }
    }

    if (f == false)                                                 //Если товар так и не встретили, то:
    {
        cout << "Net takogo tovara: " << fname << endl;             //Выводим сообщение на экран
    }
    else                                                            //Иначе
    {
        string high = "Goods", low = current->parent;               //Две строковые переменные: самая верхняя категория
                                                                    //и имя родителя нашего товара
        cout << "Goods";                                            //Выводим "Товары" - они есть всегда

        if (low != "")                                              //Родителя нет только у "Товары", которые мы уже вывели
        {
            Node *higher = this->head;                              //Временный указатель со значением головы

            while (high != low)                                     //До тех пор, пока верхняя категория и родитель товара
            {                                                       //не будут равны
                while (higher->parent != high)                      //Пока имя родителя не будет равно верхней категории
                {                                                   //сделано для аккуратного отступа на один шаг каждый раз
                    higher = higher->pNext;
                }
                cout << " -> " << higher->name;                     //Выводим имя новой дочерней категории
                high = higher->name;                                //Верхней категории присваив. имя дочерней
            }
            cout << " -> " << fname << ": ";                        //Выводим имя категории, которую искали
            while (current->pNext != nullptr)                       //Проходим до конца списка
            {
                if (current->parent == fname)                       //Если имя родителя совпадает с заданным товаром
                {
                    cout << current->name << ", ";                  //Выводим на экран
                }
                current = current->pNext;                           //Двигаемся
            }
            if (current->parent == fname)                           //Проверяем самый последний товар
            {
                cout << current->name << ", ";
            }
            cout << ";" << endl;                                    //Завершение строчки для наглядности
        }
    }
}

void Goods::goods_from_cat(string fname)                            //Метод вывода товаров категории
{                                                                   //Такой же как предыдущий, только без печати род. категорий
    Node *current = this->head;
    bool f = false;

    if (current->name == fname)
    {
        f = true;
    }

    while ((current->name != fname) && (current->pNext != nullptr))
    {
        current = current->pNext;
        if (current->name == fname)
        {
            f = true;
        }
    }

    if (f == false)
    {
        cout << "Net takogo tovara: " << fname << endl;
    }
    else
    {
        cout << fname << ": ";
        while (current->pNext != nullptr)
        {
            if (current->parent == fname)
            {
                cout << current->name << ", ";
            }
            current = current->pNext;
        }
        if (current->parent == fname)
        {
            cout << current->name << ", ";
        }
        cout << ";" << endl;
    }
}

void Goods::available(string fname)                                         //Метод наличия заданного товара в магазине
{
    Node *current = this->head;                                             //Алгоритм описан в предыдущих методах
    bool f = false;

    if (current->name == fname)
    {
        f = true;
    }
    while (current->pNext != nullptr)
    {
        current = current->pNext;
        if (current->name == fname)
        {
            f = true;
        }
    }

    if (f == false)
    {
        cout << "V " << getNameShop() << "e net tovara: " << fname << endl;         //Если товара нет - выводим сообщение об этом
    }
    else
    {
        cout << "V " << getNameShop() << "e est' tovar: " << fname << endl;         //Если есть - говорим, что есть
    }
}

int main()
{
    Goods Ashan("Ashan", "700metrov", "Shosse Entuziastov 10");                     //Создание магазина и его адрес
    Ashan.add_new("Beverages", "Goods");                                            //Добавляем новые товары
    Ashan.add_new("Sweets", "Goods");
    Ashan.add_new("Soda","Beverages");
    Ashan.add_new("Snickers", "Sweets");
    Ashan.add_new("Energy drink", "Beverages");
    Ashan.add_new("Mineral water", "Beverages");
    Ashan.add_new("Juices", "Beverages");
    Ashan.add_new("Alcohol", "Beverages");
    Ashan.add_new("Wine", "Alcohol");
    Ashan.add_new("Strong alcohol", "Alcohol");
    Ashan.add_new("Beer", "Alcohol");
    Ashan.add_new("Sparkling wine", "Alcohol");

    cout << "Imya magazina: " << Ashan.getNameShop() << endl << endl;               //Выводим имя магазина и т.п.
    cout << "Format torgovoy seti: " << Ashan.getLocation() << endl << endl;
    cout << "Torgovaya tochka: " << Ashan.getOutlets() << endl << endl;

    cout << "Tovarov v " << Ashan.getNameShop() << "e: " << Ashan.getSize() << endl << endl;    //Кол-во товаров в магазине

    cout << "Kategoriya \"Alcohol\":" << endl;                      //Вызываем метод вывода заданной категории
    Ashan.categor("Alcohol");
    cout << endl;
    cout << "Tovari kategorii \"Alcohol\":" << endl;                //Метод вывода товаров заданной категории
    Ashan.goods_from_cat("Alcohol");
    cout << endl;
    cout << "Est' li v Ashane vino:" << endl;                       //Проверка наличия товара в магазине
    Ashan.available("Wine");
    cout << endl;
    cout << "Est' li v Ashane kotleti:" << endl;
    Ashan.available("Cutlets");

    return 0;
}
