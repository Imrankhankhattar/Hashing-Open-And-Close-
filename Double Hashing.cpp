#include <iostream>

using namespace std;
int table_size=10;
//Double Hashing ....
class Hashing
{
private:
    char hash_table[10]= {0};
    int load_facter=0;
    int Prime=7;
public:
    int Hashfunction(char value)
    {
        return int(value)%table_size;
    }
     int Hashfunction2(char value)
    {
        return Prime-(int(value)%Prime);
    }
    void insert_value(char value)
    {

        if (load_facter>=table_size)
        {
            cout<<"Hash Table is Full"<<endl;
            return;
        }
        int index_1=Hashfunction(value);

        if(hash_table[index_1]==0)
        {
            hash_table[index_1]=value;
                    load_facter++;

        }
        else
        {
            int index_2=Hashfunction2(value);
            int i = 1;
            while (true)
            {
                int newIndex = (index_1 + i * index_2) % table_size;
                if (hash_table[newIndex] == 0)
                {
                    hash_table[newIndex] = value;
                            load_facter++;
                    return;
                }
                i++;
            }
        }
    }
    void Delete_value(char value)
    {
       int index=Search(value);
       if(index==-1)
       {
           cout<<"DELETION  RESULT::" <<"Not Found."<<endl;
           return;
       }
       else
        {
            cout<<"DELETION RESULT:: " <<value<<" Deleted"<<endl;
            hash_table[index]=0;
       return;
        }
    }
    int Search(char key)
    {
        int index1 = Hashfunction(key);
        int index2 = Hashfunction2(key);
        int i = 0;
        while (hash_table[(index1 + i * index2) % table_size] != key) {
            if (hash_table[(index1 + i * index2) % table_size] == 0) {
                cout << "SEARCH RESULT::" << key << " does not exist" << endl;
                return -1;
            }
            i++;
        }
        cout << "SEARCH RESULT::" << key  << " found" << endl;
        return (index1 + i * index2) % table_size;
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
        double n=10*load_facter/table_size;
        cout<<"load facter: "<<n<<"%"<<endl;
    }


};
int main()
{
    Hashing h;
    h.insert_value('A');
    h.insert_value('K');
    h.insert_value('U');


    h.Display();
    h.loadfacter();
    return 0;
}
