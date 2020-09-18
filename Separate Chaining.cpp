#include <iostream>

using namespace std;
class Node
{
private:
    string name;
    Node *next;
public:
    Node(string x)
    {
        name=x;
        next=NULL;

    }
    void Set_name(string x)
    {
        name=x;
    }
    string Get_name()
    {
        return name;
    }
    void Set_next(Node *p)
    {
        next=p;
    }
    Node* Get_next()
    {
        return next;
    }
    void Display()
    {
        cout<<name<<endl;
    }
};

class Link_list
{
private:
    Node *first;
public:
    Link_list()
    {
        first=NULL;
    }

    void Add_at_start(string x)
    {

        Node *temp=new Node(x);
        temp->Set_next(first);
        first=temp;

    }
    void Display()
    {
        Node *temp=first;
        if(first==NULL)
        {

            cout<<"nothing to display........."<<endl;
            return;
        }
        while(temp->Get_next()!=NULL)
        {

            cout<<temp->Get_name()<<" -> ";
            temp=temp->Get_next();


        }
        cout<<temp->Get_name()<<endl;

    }
    int Size_of_list()
    {
        int size=1;
        if (first==NULL)
        {
            size=0;
            return size;//cout<<size<<endl;
        }

        else
        {

            Node *temp=first;
            while(temp->Get_next()!=NULL)
            {

                temp=temp->Get_next();
                size++;
            }
            return size;//cout<<size<<endl;
        }
    }

    void Add_at_end(string x)
    {
        if(first==NULL)
        {
            Node *temp=new Node(x);
            temp->Set_next(first);
            first=temp;
            return;

        }

        Node *atend=new Node(x);
        Node *temp=first;
        while(true)
        {
            if(temp->Get_next()==NULL)
            {
                //cout<<"ok"<<endl;
                temp->Set_next(atend);
                return;
            }
            temp=temp->Get_next();
        }
    }
    void Remove_from_start()
    {
        if(first==NULL)
        {

            cout<<"No node to delete..."<<endl;
            return;
        }
        first=first->Get_next();

    }
    void Remove_from_end()
    {
        {
            if(first==NULL)
            {

                cout<<"Add node first  to delete..."<<endl;
                return;
            }
            if(first->Get_next()==NULL)
            {

                first=NULL;
                cout<<"Node deleted..."<<endl;

                return;
            }

            //Node *end=new Node(x);
            Node *temp=first;
            while(true)
            {
                if(temp->Get_next()->Get_next()==NULL)
                {
                    //cout<<"ok"<<endl;
                    temp->Set_next(NULL);//temp->Set_next(end);
                    return;
                }
                temp=temp->Get_next();
            }
        }
    }
    void Add_at_index(int index_no,string y)
    {
        if(first==NULL&&index_no>=1)
        {
            Node *temp=new Node(y);
            temp->Set_next(first);
            first=temp;
            cout<<"Node added at index no 1..."<<endl;
            return;
        }

        int size_l=Size_of_list();
        if(size_l<index_no)
        {
            Add_at_end(y);
            cout<<"Node added at end....."<<endl;
            return;
        }
        if(size_l==index_no)
        {
            Node *index=new Node(y);
            Node *temp=first->Get_next();
            Node *temp2=first;
            int z=2;
            while(z<index_no)
            {
                //temp=first;
                temp=temp->Get_next();
                temp2=temp2->Get_next();
                z++;
            }
            temp2->Set_next(index);
            index->Set_next(temp);

            //index->Set_next(temp->Get_next()->Get_next());
            //temp->Set_next(index);
            return;

        }
        int x=2;
        Node *index=new Node(y);
        Node *temp=first;
        while(x<index_no)
        {
            //temp=first;
            temp=temp->Get_next();
            x++;
        }

        index->Set_next(temp->Get_next());
        temp->Set_next(index);

    }
    void Search_name(string name)
    {
        if(first==NULL)
        {

            cout<<"No name found"<<endl;
            return;
        }
        Node *temp=first;
        int n=1;
        while(temp->Get_next()!=NULL)
        {
            if(temp->Get_name()==name)
            {

                {
                    cout<<name<<"  found at index_no:"<<n<<endl;
                    return;
                }
            }
            n++;
            temp=temp->Get_next();

        }
        if(temp->Get_name()==name)
        {
            cout<<name<<"   found at index_no:"<<n<<endl;
            return;
        }
        else
            cout<<"NOT found"<<endl;


    }
    void Delete_name_node(string name)
    {
        if(first==NULL)
        {

            cout<<"No Value to be deleted."<<endl;
            return;
        }
        if(first->Get_name()==name)
        {
            first=NULL;
            cout<<"Value Deleted."<<endl;
            return;
        }
        Node *temp=first;
        while(temp->Get_next()!=NULL)
        {
            if(temp->Get_next()->Get_name()==name)
            {
                temp->Set_next(temp->Get_next()->Get_next());
                return;
            }
            temp=temp->Get_next();
        }
        if(temp->Get_name()==name)
        {
            temp->Set_next(NULL);
            cout<<"Value Deleted."<<endl;
            return;
        }
        else
            cout<<"Name not found at any node.."<<endl;

    }




    int check()
    {
        return first==NULL ? 0:1;
    }
};
class SeparateChaining
{
private:
    int Array_size=20;
    Link_list Array[20];
public:
    int Hash(string word)
    {
        int sum = 0;
        for (int k = 0; k < word.length(); k++)
        {
            sum = 2^k*(sum + int(word[k]));
        }
        return  sum % Array_size ;
    }
    void Insert(string value)
    {
        int index=Hash(value);
        Array[index].Add_at_end(value);
    }
    void Search(string value)
    {
        cout<<"Search Result: ";
        int index=Hash(value);
        Array[index].Search_name(value);

    }
    void Display()
    {
        for(int i=0; i<Array_size; i++)
        {

            if(Array[i].check()==0)
                continue;//displaying only those lists where data is...
            cout<<i<<"=>";
            Array[i].Display();
        }
    }
    void Delete(string value)

    {
        cout<<"Delete Result:";
        int index=Hash(value);
        Array[index].Delete_name_node(value);
    }

};

int main()
{

    SeparateChaining obj;
    obj.Insert("Imran");
    obj.Insert("Imran");
    obj.Insert("Imran");
    obj.Insert("Imran");
    obj.Insert("Imran");
    obj.Insert("khan");
    obj.Insert("ali");
    obj.Insert("hassan");
   // obj.Delete("khan");
    obj.Search("khan");
    obj.Search("khan");
    obj.Display();
    return 0;
}
