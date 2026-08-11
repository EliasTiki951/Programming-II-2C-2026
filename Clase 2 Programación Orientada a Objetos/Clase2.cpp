#include <iostream> //Libreria por Defecto
#include <cstdlib>  //Funciones generales como gestión de memoria, conversión de tipos y números aleatorios.
#include <conio.h>  //Para el CMD de Windons
using namespace std;

/*

class Persona{
private: //PRIVADO, SOLO ACCESIBLES POR LA CLASE
    //ATRIBUTOS
    string nombre;
    string apellido;
    int edad;

public:
    //CONSTRUCTOR
    Persona(string n, string a, int e){
        nombre=n;
        apellido=a;
        edad=e;
    }
    //CONSTRUCTOR
    //Persona()=default;


    //SETTERS
    void setNombre(string nombre){
        this->nombre=nombre;
    }

    void setApellido(string apellido){
        this->apellido=apellido;
    }

    void setEdad(int edad){
        this->edad=edad;
    }

    //GETTERS
    //string getNombre(string nombre){return nombre};

    //METODOS
    void Presentar(){
        cout<<"Hola me llamo "<<nombre<<" "<<apellido<<" y tengo "<<edad<<" años."<<endl;
    }

    string NombreComleto(){
        return nombre+" "+apellido;
    }
};

class Alumno : Persona{
private:
    int legajo;
    string carrera;
public:
    Alumno(string n, string a, int e, int l, string c) Persona(n,a,e){
        legajo=l;
        carrera=c;
    }

    void Presentar(){
        cout<<"Hola, me llamo "<<nombre<<" "<<apellido<<", tengo "<<edad<<" años"<<endl;
        cout<<"Estoy estudiando"<<carrera<<" y mi legajo es "<<legajo<<endl;
    }

};

int main(){

    //Persona p1;

    /*
    p1.nombre="Jorge";
    p1.apellido="Gonzales";
    p1.edad=35;

    cout<<p1.nombre<<endl;
    cout<<p1.apellido<<endl;
    cout<<p1.edad<<endl;

    cout<<p1.NombreComleto()<<endl;
    */

    /*
    p1.setNombre("Carlos");
    p1.setApellido("Tevez");
    p1.setEdad(42);

    cout<<p1.setNombre()<<endl;
    cout<<p1.setApellido()<<endl;
    cout<<p1.setEdad()<<endl;
    */

/*
    Persona p1("Elias", "Tiki", 23);
    p1.Presentar();

    getch();
    return 0;
}

*/


class Persona{
private: ///PRIVADOS, SOLO ACCESIBLES POR LA CLASE
    string nombre;
    string apellido;
    int edad;

    void Privado(){
        cout<<"Este es un metodo privado"<<endl;
    }

protected: ///PROTEGIDOS, SOLO ACCESIBLES POR LA CLASE BASE Y LA CLASE DERIVADA



public: ///INFORMACION ACCESIBLE MEDIANTE EL MAIN


    ///CONSTRUCTOR
    Persona(string n, string a, int e){
        nombre=n;
        apellido=a;
        edad=e;
    }
    ///CONSTRUCTOR DEFAULT
    Persona()=default;

    ///SETTERS
    void setNombre(string nombre){this->nombre=nombre;}
    void setApellido(string a){apellido=a;}
    void setEdad(int e){edad=e;}


    ///GETTERS
    string getNombre(){return nombre;}
    string getApellido(){return apellido;}
    int getEdad(){return edad;}


    ///METODOS
    void Presentar(){
        cout<<"Hola, me llamo "<<nombre<<" "<<apellido<<" y tengo "<<edad<<" años"<<endl;
    }

    void CargarDatos(){
        string n, a;
        int e;

        cout<<"Ingrese Nombre: ";
        cin>>n;
        cout<<"Ingrese Apellido: ";
        cin>>a;
        cout<<"Ingrese Edad: ";
        cin>>e;

        nombre=n;
        apellido=a;
        edad=e;
    }

    string NombreCompleto(){
        return nombre+" "+apellido;
    }

    void Puente(){
        Privado();
    }

};

class Alumno : public Persona{
private:
    int legajo;
    string carrera;
public:
    Alumno(string n, string a, int e,int l ,string c) : Persona(n,a,e){
        legajo=l;
        carrera=c;
    }

    void Presentar(){
        cout<<"Hola, me llamo "<<getNombre()<<" "<<getApellido()<<", tengo "<<getEdad()<<" años"<<endl;
        cout<<"Estoy estudiando "<<carrera<<" y mi legajo es "<<legajo<<endl;
    }
};

int main(){
Persona p1("Jorge","Rodriguez",23);
p1.Presentar();

cout<<endl;

Alumno a1("Carlos","Sanchez",22,12334,"Programacion");
a1.Presentar();
cout<<endl;

cout<<a1.NombreCompleto();

cout<<"-------------------"<<endl;

p1.Puente();

    return 0;
}
