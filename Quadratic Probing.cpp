#include <iostream>

using namespace std;
int table_size=5;
//Hashing through Linear probing.....
class Hashing
{
private:
    char hash_table[5]= {0};
    int load_facter=0;

public:
    Hashing()
    {

    }
    int Hashfunction(char value)
    {
        int n=int(value)%table_size;
        return n;
    }
    void insert_value(char value)
    {

        if (load_facter>=table_size)
        {
            cout<<"Hash Table is Full"<<endl;
            return;
        }
        int index=Hashfunction(value);
        int Quadratic_value=1;
        if(hash_table[index]==0)
        {
            hash_table[index]=value;
        }
        else
        {
            while(hash_table[(index)%table_size]!=0)
            {
                Quadratic_value=Quadratic_value*2;
                index=(index)+Quadratic_value;
            }

            hash_table[index%table_size]=value;

        }
        load_facter++;
    }
    void Delete_value(char value)
    {
        int index=Hashfunction(value);
        int Quadratic_value=1;
        if(hash_table[index]==value)
        {
            hash_table[index]=0;
        }
        else
        {
            while(hash_table[(index)%table_size]!=value)
            {
                Quadratic_value=Quadratic_value*2;
                index=(index)+Quadratic_value;
            }

            hash_table[index%table_size]=0;

        }
        load_facter--;
    }
    void Search_value(int value)
    {
        for(int i=0; i<table_size; i++)
        {
            if(hash_table[i]==value)
            {
                cout<<"Value Found AT Index:"<<i<<endl;
                return;
            }
        }
        cout<<"Value Not Found.."<<endl;
    }
    void Display()
    {
        for(int i=0; i<table_size; i++)
        {
            cout<<i<<" => "<<hash_table[i]<<endl;
        }
    }
    void loadfacter()
    {
        double n=5*load_facter/table_size;
        cout<<"load facter: "<<n<<"%"<<endl;
    }


};
int main()
{
    Hashing h;
    h.insert_value('A');
    h.insert_value('F');
    h.insert_value('K');
    h.insert_value('U');

    h.Display();
    h.loadfacter();
    return 0;
}
