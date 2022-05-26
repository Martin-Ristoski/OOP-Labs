    #include <iostream>
    #include <cstring>
    #include <cmath>
    using namespace std;
    /*Потребно е да конструирате абстракна класа Shape со само еден параметар:

    страна (int)
    Конструктори:

    Shape()
    Shape(int a)
    И виртуелните методи:

    double plostina()
    void pecati()
    int getType()
    Од таа класа вие треба да конструирате 3 изведени класи:

    Square
    Circle
    Triangle
    Изведените класи немаат дополнителни парамтери, туку ја наследуваат страната од Shape

    Конструктори:

    Конструкторот на изведените класи ќе зема еден аругмент, страната на фигурата.

    При пишување на конструкторот на изведените класи да се искористи констукторот на родител класата

    Методи:

    Секоја од класите си има своја формула за plostina() соодветна за нивната геометриска фигура

    Формула за плоштина на квадрат а * a
    Формула за плоштина на круг 3.14 * a * a
    Формула за плоштина на триаголник (sqrt(3)/4) * side * side
    За pecati() методот упатете се кон outputot за тест случајите.

    getType() методот треба да враќа:

    1 за Square
    2 за Circle
    3 за Triangle
    Поени: 5

    --

    Дефинирајте го методот void checkNumTypes(Shape** niza, int n) така што ќе испечати во три реда колку квадрати, кругови и триаголници има во низата.

    Поени: 2

    --

    Покрај тоа треба да ја допишете Main класата така што ќе алоцирате динамичка низа од покажувачи кон класата Shape.

    Потоа кај секој покажувач од низата зависно од дадениот input да алоцирате објект од една од трите изведени класи.

    Input:

    Прво се добива n - големината на динамичката низа. Потоа n пати се добиваат пар цели броеви t i a, каде што t е типот на објектот и а е страната на објектот.

    Пример:

    3

    1 3 //квадрат со страна со должина 3

    2 2 //круг со страна со должина 2

    3 1 //триаголник со страна со должина 1

    Поени: 3*/


    class Shape{
    protected:
        int a;
    public:
        Shape(int a=0){
            this->a=a;
        }
        virtual double plostina(){}
        virtual void pecati(){}
        virtual int getType(){}
    };
    class Kvadrat: public Shape{
    public:
        Kvadrat(int a): Shape(a){}
        double plostina(){
            return a*a;
        }
        void pecati(){
            cout<<"Kvadrat so plostina = "<<plostina()<<endl;
        }
        int getType(){
            return 1;
        }
    };

    class Krug: public Shape{
    public:
        Krug(int a): Shape(a){}
        double plostina(){
            return 3.14*a*a;
        }
        void pecati(){
            cout<<"Krug so plostina = "<<plostina()<<endl;
        }
        int getType(){
            return 2;
        }
    };

    class Triagolnik: public Shape{
    public:
        Triagolnik(int a): Shape(a){}
        double plostina(){
            return (sqrt(3)/4)*a*a;
        }
        void pecati(){
            cout<<"Triagolnik so plostina = "<<plostina()<<endl;
        }
        int getType(){
            return 3;
        }
    };

    void checkNumTypes(Shape** niza, int n){
        int s=0,c=0,t=0;
        for(int i=0;i<n;i++){
            if(niza[i]->getType()==1)
                s++;
            else if(niza[i]->getType()==2)
                c++;
            else
                t++;
        }
        cout<<"Broj na kvadrati vo nizata = "<<s<<endl;
        cout<<"Broj na krugovi vo nizata = "<<c<<endl;
        cout<<"Broj na triagolnici vo nizata = "<<t<<endl;
    }

    int main(){
        int n;
        cin >> n;
        Shape** niza;
        niza=new Shape*[n];
        int classType;
        int side;
        for(int i = 0; i < n; ++i){
            cin >> classType;
            cin >> side;
            if(classType==1){
                niza[i]=new Kvadrat(side);
            }
            else if(classType==2){
                niza[i]=new Krug(side);
            }
            else niza[i]=new Triagolnik(side);
        }
        for(int i = 0; i < n; ++i){
            niza[i]->pecati();
        }
        checkNumTypes(niza, n);
        return 0;
    }
