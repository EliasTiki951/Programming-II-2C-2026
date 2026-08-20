#include <iostream>
#include <string>
using namespace std;

class Persona{  //class = clase
    private:  //privado
        //ATRIBUTOS
        //Los Atributos(Tiene 3 tipos de estado: el estado privado, el estado publico y protegido)
        string nombre;
        string apellido;
        int edad;

        void Privada(){
            cout<<"Esto es una función privada"<<endl;
        }

    public: //público

    //CONSTRUCTOR
        Persona(string nombre, string apellido, int edad){
            this->nombre=nombre;
            this->apellido=apellido;
            this->edad=edad;
        }
        Persona()=default;

	//SETTERS (Es para establecer)
        void setNombre(string n){nombre=n;}
        void setApellido(string a){apellido=a;}
        void setEdad(int e){edad=e;}

	//GETTERS (Es uno de los atributos)
        string getNombre(){return nombre;}
        string getApellido(){return apellido;}
        int getEdad(){return edad;}

	//Métodos
        void Presentar(){
            cout<<"Me llamo "<<nombre<<" "<<apellido<<" y tengo "<<edad<<" años."<<endl;
        }

        void Mostrar_Privada(){
            Privada();
        }
};

class Alumno : public Persona{ //Hereda los atributos
private:
    int legajo;

public:
    Alumno(string n, string a, int e, int legajo) : Persona(n,a,e){
        this->legajo=legajo;
    }
    Alumno()=default;

    void setLegajo(int l){this->legajo=l;}
};

/*
clase nombre{
    ATRIBUTOS (Privado, Publico, Protegido)
    CONSTRUCTOR
    SETTERS
    GETTERS
    MÉTODOS
    DESTRUCTOR
}
*/

/*
    ABSTRACCIÓN
    ENCAPSULACIÓN
    HERENCIA
    POLIMORFISMO
*/

int main() {
	/*
	string nombre, apellido;
	int edad;

	cout<<"Ingrese nombre: ";
	cin>>nombre;
	cout<<"Ingrese apellido: ";
	cin>>apellido;
	cout<<"Ingrese edad: ";
	cin>>edad;

	cout<<"Me llamo "<<nombre<<" "<<apellido<<" y tengo "<<edad<<" años."<<endl;
	*/

	// Persona p1;

    /*
	p1.nombre="Marcos";
	p1.apellido="Senesi";
	p1.edad=38;
    */

    /*
    p1.setNombre("Elias");
    p1.setApellido("Tiquicala");
    p1.setEdad(23);

    p1.Presentar();

    cout<<p1.getNombre()<<endl;
    cout<<p1.getApellido()<<endl;
    cout<<p1.getEdad()<<endl;
    */

	// p1.Mostrar_Privada();

	Persona p1("Elias", "Tiquicala", 23);
    Persona p2("Kevin", "Mamani", 40);
    Persona p3("Jose", "Palacios", 20);
    p1.Presentar();
    p2.Presentar();
    p3.Presentar();

	return 0;
}
