#include <iostream>

using namespace std;
int table_size=10;
//Hashing through Linear probing.....
class Hashing
{
private:
    char hash_table[10]= {0};
    int load_facter=0;
public:
    int Hashfunction(char value)
    {
        return int(value)%table_size;
    }
    void insert_value(char value)
    {

        if (load_facter>=table_size)
        {
            cout<<"Hash Table is Full"<<endl;
            return;
        }
        int index=Hashfunction(value);
       // cout<<index<<"->"<<value<<endl;
        if(hash_table[index]==0)
        {
            hash_table[index]=value;
        }
        else
        {
            while(hash_table[index%table_size]!=0)
            {
                index++;
            }
            hash_table[index%table_size]=value;

        }
        load_facter++;


    }
    void Delete_value(int value)
    {
        int index=Hashfunction(value);
        hash_table[index]=0;
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
        double n=100*load_facter/10;
        cout<<"LOAD FACTER: "<<n<<"%"<<endl;
    }


};/*
int main()
{
    Hashing h;
    h.insert_value('A');
    h.insert_value('B');
    h.insert_value('C');
    h.insert_value('D');
    h.insert_value('E');
    h.insert_value('F');
    //h.insert_value('a');
    //h.insert_value('b');
    h.insert_value('c');
    h.insert_value('-');
    h.Display();
    h.loadfacter();
    return 0;
}
