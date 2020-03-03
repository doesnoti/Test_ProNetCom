#include <iostream>
#include <string>

using namespace std;

class Goods                                                         //����� "������"
{
public:
    Goods(string nameShop, string location, string outlets);        //��������� ���������� � ������� ��������� �����

    void add_new(string name, string parent);                       //����� ���������� ������ ������
    void categor(string fname);                                     //����� ������ �� ����� �������� ���������
    void goods_from_cat(string fname);                              //����� ������ ������� �������� ���������
    int getSize(){return Size;}                                     //�����, ������������ ���-�� �������
    string getNameShop(){return nameShop;}                          //���������� ��� ��������
    string getLocation(){return nameShop + "-" + location;}         //���������� "������ ��������� ����"
    string getOutlets(){return nameShop + "-" + location + " " + outlets;}      //���������� "�������� �����"
    void available(string fname);                                   //����� �������� ������� ������
private:

    class Node                                                      //����� "����"
    {
    public:
        string parent;                                              //������ ��� �������� ������
        string name;                                                //��� ������
        Node *pNext;                                                //��������� �� ����. ������� ������

        Node(string name, string parent = "", Node *pNext = nullptr)        //����������� "����"
        {
            this->name = name;                                      //����������� ��� ���������� �������� ���������� ������
            this->parent = parent;
            this->pNext = pNext;
        }
    };
                                                                    //���������� ������ "������"
    string location, outlets, nameShop;                             //"������ ����. ����", "����. �����" � ��� ��������
    Node *head;                                                     //"������" ������� �������� ������
    int Size;                                                       //������ ������
};

Goods::Goods(string nameShop, string location, string outlets)      //���������� ������������ ������
{
    head = new Node("Goods", "");                                   //"������"-������ ������� ��� ������ "������" � ��� ��������
    Size = 0;                                                       //������ ���� �������
    this->location = location;                                      //����������� ��� ���������� �������� ���������� ������
    this->outlets = outlets;
    this->nameShop = nameShop;
}

void Goods::add_new(string name, string parent)                     //����� ���������� ������ ������
{
    Node *current = this->head;                                     //��������� ����������, � ������� �����. ����. ������
    bool f = false;                                                 //����

    if (current->name == parent)                                    //��������� ����� �� ������� ��� ��������, ���� ��:
    {
        f = true;                                                   //�� ��������� ���� (�� �����, ������ ��� ���� ����� �� ����)
    }
    while (current->pNext != nullptr)                               //����, ���� ��������� �� ����� ��������� �� �������
    {
        current = current->pNext;                                   //��������� �� ������
        if (current->name == parent)                                //��-���� ��������� ��� ��������
        {
            f = true;
        }
    }

    if (f == false)                                                 //���� ���� ������ - ��� �������� ������� �� ���������
    {
        cout << "Net takogo roditelya: " << parent << endl;
    }
    else                                                            //�����:
    {
        current->pNext = new Node(name, parent);                    //��������� � ������� ����������� ����. �� ����� ���� � ����.
        Size++;                                                     //����� ����. ������ ������ +1
    }
}

void Goods::categor(string fname)                                   //����� ������ �������� ��������� �� �����
{
    Node *current = this->head;                                     //�� ��, ��� � ������� ������
    bool f = false;

    if (current->name == fname)
    {
        f = true;
    }

    while ((current->name != fname) && (current->pNext != nullptr))     //���� �� �������� ��������� ��� �� ����� ������
    {
        current = current->pNext;
        if (current->name == fname)
        {
            f = true;
        }
    }

    if (f == false)                                                 //���� ����� ��� � �� ���������, ��:
    {
        cout << "Net takogo tovara: " << fname << endl;             //������� ��������� �� �����
    }
    else                                                            //�����
    {
        string high = "Goods", low = current->parent;               //��� ��������� ����������: ����� ������� ���������
                                                                    //� ��� �������� ������ ������
        cout << "Goods";                                            //������� "������" - ��� ���� ������

        if (low != "")                                              //�������� ��� ������ � "������", ������� �� ��� ������
        {
            Node *higher = this->head;                              //��������� ��������� �� ��������� ������

            while (high != low)                                     //�� ��� ���, ���� ������� ��������� � �������� ������
            {                                                       //�� ����� �����
                while (higher->parent != high)                      //���� ��� �������� �� ����� ����� ������� ���������
                {                                                   //������� ��� ����������� ������� �� ���� ��� ������ ���
                    higher = higher->pNext;
                }
                cout << " -> " << higher->name;                     //������� ��� ����� �������� ���������
                high = higher->name;                                //������� ��������� ��������. ��� ��������
            }
            cout << " -> " << fname << ": ";                        //������� ��� ���������, ������� ������
            while (current->pNext != nullptr)                       //�������� �� ����� ������
            {
                if (current->parent == fname)                       //���� ��� �������� ��������� � �������� �������
                {
                    cout << current->name << ", ";                  //������� �� �����
                }
                current = current->pNext;                           //���������
            }
            if (current->parent == fname)                           //��������� ����� ��������� �����
            {
                cout << current->name << ", ";
            }
            cout << ";" << endl;                                    //���������� ������� ��� �����������
        }
    }
}

void Goods::goods_from_cat(string fname)                            //����� ������ ������� ���������
{                                                                   //����� �� ��� ����������, ������ ��� ������ ���. ���������
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

void Goods::available(string fname)                                         //����� ������� ��������� ������ � ��������
{
    Node *current = this->head;                                             //�������� ������ � ���������� �������
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
        cout << "V " << getNameShop() << "e net tovara: " << fname << endl;         //���� ������ ��� - ������� ��������� �� ����
    }
    else
    {
        cout << "V " << getNameShop() << "e est' tovar: " << fname << endl;         //���� ���� - �������, ��� ����
    }
}

int main()
{
    Goods Ashan("Ashan", "700metrov", "Shosse Entuziastov 10");                     //�������� �������� � ��� �����
    Ashan.add_new("Beverages", "Goods");                                            //��������� ����� ������
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

    cout << "Imya magazina: " << Ashan.getNameShop() << endl << endl;               //������� ��� �������� � �.�.
    cout << "Format torgovoy seti: " << Ashan.getLocation() << endl << endl;
    cout << "Torgovaya tochka: " << Ashan.getOutlets() << endl << endl;

    cout << "Tovarov v " << Ashan.getNameShop() << "e: " << Ashan.getSize() << endl << endl;    //���-�� ������� � ��������

    cout << "Kategoriya \"Alcohol\":" << endl;                      //�������� ����� ������ �������� ���������
    Ashan.categor("Alcohol");
    cout << endl;
    cout << "Tovari kategorii \"Alcohol\":" << endl;                //����� ������ ������� �������� ���������
    Ashan.goods_from_cat("Alcohol");
    cout << endl;
    cout << "Est' li v Ashane vino:" << endl;                       //�������� ������� ������ � ��������
    Ashan.available("Wine");
    cout << endl;
    cout << "Est' li v Ashane kotleti:" << endl;
    Ashan.available("Cutlets");

    return 0;
}
