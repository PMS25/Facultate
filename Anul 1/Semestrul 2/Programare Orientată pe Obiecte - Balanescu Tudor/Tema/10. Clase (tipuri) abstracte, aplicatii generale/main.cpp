#include <iostream>
#include <cstring>
using namespace std;

class AbstractElem{
    public:
        virtual void process()=0;
};

class AbstractList{
    public:
        virtual void add(AbstractElem *e)=0;
        virtual AbstractElem* item()=0;
};

class Person: public AbstractElem{
    public:
        Person(char *m){
            nume=new char [strlen(m)+2];
            strcpy(nume,m);
        }
        void process() override{
            cout<<"Numele meu este: "<<nume<<endl;
        }
    private:
        char* nume;
};

class Queue: public AbstractList{
    public:
        void add(AbstractElem *e) override{
            AbstractElem **newlist = new AbstractElem*[n+1];
            for(int i=0; i<n; i++)
                newlist[i] = list[i];
            newlist[n++] = e;
            delete[] list;
            list = newlist;
        }
        AbstractElem* item() override{
            if(n==0)
                return nullptr;
            else{
                AbstractElem *p = list[n-1];
                AbstractElem **newlist = new AbstractElem*[n-1];
                for(int i=0; i<n-1; i++)
                    newlist[i] = list[i];

                delete[] list;
                list = newlist;
                n--;
                
                return p;
            }
        }
    private:
        AbstractElem **list;
        int n=0;
};

class Stack: public AbstractList{
    public:
        void add(AbstractElem *e) override{
            AbstractElem **newlist = new AbstractElem*[n+1];
            for(int i=0; i<n; i++)
                newlist[i] = list[i];
            newlist[n++] = e;

            delete[] list;
            list = newlist;
        }
        AbstractElem* item() override{
            if(n==0)
                return nullptr;
            else{
                AbstractElem *p = list[0];
                AbstractElem **newlist = new AbstractElem*[n-1];
                for(int i=0; i<n-1; i++)
                    newlist[i] = list[i+1];

                delete[] list;
                list = newlist;
                n--;
                
                return p;
            }
        }
    private:
        AbstractElem **list;
        int n=0;
};

int main(){
    cout<<"Aplicatie cu caracter general, care prelucreaza date anstracte"<<endl;
    int tip; cout<<"Tip (1:Stiva | 2:Coada): "; cin>>tip;

    AbstractList *pal;
    if(tip==1)
        pal=new Stack();
    else
        pal=new Queue();

    pal->add(new Person("Sara"));
    pal->add(new Person("Andrei"));
    (pal->item())->process();  
}