# Programare Orientata Pe Obiecte - Laborator 02 - Teme

- [Programare Orientata Pe Obiecte - Laborator 02 - Teme](#programare-orientata-pe-obiecte---laborator-02---teme)
  - [Complex - CPP Class](#complex---cpp-class)
  - [Vector - OOP Class](#vector---oop-class)
  - [MyString - CPP Class](#mystring---cpp-class)

## Complex - CPP Class

```cpp
#include <iostream>
#include <cmath>
using namespace std;
//Sa se implementeze o clasa C++ pentru operatii cu numere complexe.

class Complex{
    private:
        double *_re, *_im;
    public:
        //Constructori
        Complex();
        Complex(double, double);
        Complex(const Complex&);
        //Getters and Setters
        double GetRe();
        void SetRe(double);
        double GetIm();
        void SetIm(double);
        //Metode
        void Display();
        void Read();
        double Modul();
        Complex Suma(const Complex&);
        Complex Suma(double);
        Complex Diferenta(const Complex&);
        Complex Diferenta(double);
        Complex Produs(const Complex&);
        Complex Produs(double);
        //Destructor
        ~Complex();
};

//Constructori
Complex::Complex(){
    _re = new double(0);
    _im = new double(0);
}
Complex::Complex(double re, double im){
    _re = new double(re);
    _im = new double(im);
}
Complex::Complex(const Complex& nr){
    _re = new double(*nr._re);
    _im = new double(*nr._im);
}

//Getters and Setters
double Complex::GetRe(){ return *_re; }
double Complex::GetIm(){ return *_im; }
void Complex::SetRe(double re){ *_re=re; }
void Complex::SetIm(double im){ *_im=im; }

//Metode
void Complex::Display(){
    cout<<*_re;
    if(*_im != 0){
        if(abs(*_im) != 1)
            cout<<(*_im >=0 ? " + ":" - ")<<abs(*_im);
        cout<<"i";
    }
    cout<<endl;
}
void Complex::Read(){
    cout<<"Numar (a + b[i]): "; cin>>*_re>>*_im;
}
double Complex::Modul(){
    return sqrt((*_re)*(*_re) + (*_im)*(*_im));
}
Complex Complex::Suma(const Complex& nr){
    *_re += *nr._re;
    *_im += *nr._im;
    return *this;
}
Complex Complex::Suma(double nr){
    *_re += nr;
    return *this;
}
Complex Complex::Diferenta(const Complex& nr){
    *_re -= *nr._re;
    *_im -= *nr._im;
    return *this;
}
Complex Complex::Diferenta(double nr){
    *_re -= nr;
    return *this;
}
Complex Complex::Produs(const Complex& nr){
    double re = (*_re)*(*nr._re) - (*_im)*(*nr._im);
    double im = (*_re)*(*nr._im) + (*_im)*(*nr._re);
    *_re = re; *_im = im;
    return *this;
}
Complex Complex::Produs(double nr){
    *_re *= nr;
    *_im *= nr;
    return *this;
}

//Destructor
Complex::~Complex(){
    delete[] _im, _re;
}

int main(){
    Complex d(1,2);
    Complex dd(3,4);
    Complex ddd;
    d.Display();
    dd.Display();
    ddd.Read();
    ddd.Display();
    d.Produs(3).Display();
    d.Produs(dd).Display();
} 
```

## Vector - OOP Class

```cpp
#include <iostream>
using namespace std;
// Sa se implementeze o clasa C++ pentru operatii cu vectori.
// Exemplu: x = (a1,a2,...an) si y = (b1,b2,...,bn)
// Suma(x): a1+a2+...+an ; Produs(x): a1*a2*...*an
// Suma Vectori: x+y = (a1+b1, a2+b2, ..., an+bn)
// Produsul Scalar: x*y = a1*b1 + a2*b2 +...+ an*bn

class Vector{
    private:
        double* _elem;
        int _size;
    public:
        //Constructori
        Vector();
        Vector(int);
        Vector(double*, int);
        Vector(const Vector&);
        //Metode
        void Read();
        void Display();
        double Suma();
        Vector Suma(const Vector&);
        double Produs();
        double ScalarProd(const Vector&);
        //Destructor
        ~Vector();
};

//Constructori
Vector::Vector(){
    _size = 0;
    _elem = new double[_size];
}
Vector::Vector(int size){
    _size = size;
    _elem = new double[_size];
    for(int i=0; i<_size; i++)
        _elem[i] = 0;
}
Vector::Vector(double* elem, int size){
    _size = size;
    _elem = new double[_size];
    for(int i=0; i<_size; i++)
        _elem[i] = elem[i];
}
Vector::Vector(const Vector& vect){
    _size = vect._size;
    _elem = new double[_size];
    for(int i=0; i<_size; i++)
        _elem[i] = vect._elem[i];
}

//Metode
void Vector::Read(){
    delete[] _elem;
    cout<<"Size: "; cin>>_size;
    cout<<"Elements: ";
    _elem = new double[_size];
    for(int i=0; i<_size; i++)
        cin>>_elem[i];
}
void Vector::Display(){
    cout<<"["<<_size<<"] : ( ";
    for(int i=0; i<_size; i++)
        cout<<_elem[i]<<",";
    cout<<"\b )"<<endl;
}
double Vector::Suma(){
    double s = 0;
    for(int i=0; i<_size; i++)
        s += _elem[i];
    return s;
}
Vector Vector::Suma(const Vector& vect){
    int n = min(_size,vect._size);
    for(int i=0; i<n; i++)
        _elem[i] += vect._elem[i];
    return *this;
}
double Vector::Produs(){
    double p = 1;
    for(int i=0; i<_size; i++)
        p *= _elem[i];
    return p;
}
double Vector::ScalarProd(const Vector& vect){
    double s = 0;
    int n = min(_size,vect._size);
    for(int i=0; i<=n; i++)
        s += _elem[i] * vect._elem[i];
    return s;
}

//Destructor
Vector::~Vector(){
    delete[] _elem;
}

int main(){
    Vector v, vv;
    v.Read(); v.Display();
    vv.Read(); vv.Display();
    cout<<v.Suma()<<endl;
    cout<<vv.Produs()<<endl;
    v.Suma(vv).Display();
    cout<<v.ScalarProd(vv)<<endl;
}
```

 ## MyString - CPP Class

```cpp
#include <iostream>
#include <cstring>
using namespace std;
//Sa se implementeze o clasa C++ pentru operatii cu siruri de caractere.

class MyString{
    private:
        char* _text;
        int _len;
    public:
        //Constructori
        MyString();
        MyString(char*);
        MyString(const MyString&);

        //Getters and Setters
        int GetLen();
        char* GetText();
        char GetAt(int);
        void SetAt(int, char);

        //Metode
        void Display();
        MyString Concat(int);
        MyString Concat(char);
        MyString Concat(char*);
        MyString Concat(const MyString&);
        MyString& ToUpper();
        MyString& ToLower();
        MyString& Trim();
        MyString& Trim(char);
        bool Equals(const MyString&);

        //Destructor
        ~MyString();
};

//Constructori
MyString::MyString(){
    _len = 0;
    _text = new char[0];
}
MyString::MyString(char *text){
    for(_len=0; text[_len]!='\0'; _len++);
    _text = new char[_len+1];
    strcpy(_text,text);
}
MyString::MyString(const MyString& str){
    _len=str._len;
    _text=new char[_len+1];
    strcpy(_text,str._text);
}

//Getters and Setters
int MyString::GetLen(){ return _len; }
char* MyString::GetText(){
    char* aux = new char[_len+1];
    strcpy(aux,_text);
    return aux;
}
char MyString::GetAt(int p){ return (p>=0 && p<_len ? _text[p]:0); }
void MyString::SetAt(int p, char c){ _text[p] = (p>=0 && p<_len ? c:_text[p]); }

//Metode
void MyString::Display(){
    cout<<"["<<_len<<"] : "<<_text<<endl;
}
MyString MyString::Concat(int c){
    char *text = new char[6]; int len = 0;
    do{
        text[len++] = '0' + c%10;
        c/=10;
    }while(c);
    for(int i=0; i<len/2; i++)
        swap(text[i],text[len-i-1]);
    text[len] = '\0';
    this->Concat(text);
    delete[] text;
    return *this;
}
MyString MyString::Concat(char c){
    char *text = new char(2);
    text[0] = c; text[1] = '\0';
    this->Concat(text);
    delete[] text;
    return *this;
}
MyString MyString::Concat(char *text){
    MyString str(text);
    return this->Concat(str);
}
MyString MyString::Concat(const MyString& str){
    char *aux = new char[_len+str._len+1];
    strcpy(aux,_text);
    strcat(aux,str._text);
    delete[] _text;
    _text = aux;
    _len += str._len;
    return *this;
}

MyString& MyString::ToUpper(){
    for(int i=0; i<_len; i++)
        _text[i] = toupper(_text[i]);
    return *this;
}
MyString& MyString::ToLower(){
    for(int i=0; i<_len; i++)
        _text[i] = tolower(_text[i]);
    return *this;
}
MyString& MyString::Trim(){
    return Trim(' ');
}
MyString& MyString::Trim(char c){
    for(int i=0; i<_len; i++)
        if(_text[i] == c){
            strcpy(_text+i,_text+i+1);
            _len--; i--;
        }
    char* aux = new char[_len+1];
    strcpy(aux,_text);
    delete[] _text;
    _text = aux;
    return *this;
}
bool MyString::Equals(const MyString& str){
    if(_len != str._len)
        return false;
    for(int i=0; i<_len; i++)
        if(_text[i] != str._text[i])
            return false;
    return true;
}

//Destructor
MyString::~MyString(){
    delete[] _text;
}

int main(){
    char t[] = "test";
    MyString str1;
    MyString str2(t);
    MyString str3(str2);
    str1.Display();
    str2.Display();
    str3.Display();
    cout<<str2.Equals(str3)<<endl;
    str3.SetAt(2,'A');
    cout<<str3.GetText()<<endl;
    str1.Concat(12).Display();
    str1.Concat('c').Display();
    str1.Concat(t).Display();
    str3.ToUpper().Display();
    str2.Trim('t').Display();
    cout<<str2.Equals(str3)<<endl;
}
```

