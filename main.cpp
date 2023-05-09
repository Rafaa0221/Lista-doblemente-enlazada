#include <iostream>

using namespace std;

class SocioClub{
    private:
        int NumeroSocio;
        string NombreSocio;
        string Domicilio;
        int AnioIngreso;
    public:
        SocioClub(){};
        friend std::ostream & operator<<(std::ostream &O, SocioClub &x){
            O<<"\n Numero de socio: "<<x.NumeroSocio;
            O<<"\n Nombre de socio: "<<x.NombreSocio;
            O<<"\n Domicilio de socio: "<<x.Domicilio;
            O<<"\n Anio de ingreso: "<<x.AnioIngreso;
            return O;
        }
        friend std::istream & operator>>(std::istream &O, SocioClub &x){
            std::cout<<"\n Numero de socio: ";
            O>>x.NumeroSocio;
            std::cout<<" Nombre de socio: ";
            O>>x.NombreSocio;
            std::cout<<" Domicilio de socio: ";
            O>>x.Domicilio;
            std::cout<<" Anio de ingreso: ";
            O>>x.AnioIngreso;
            return O;
        }
        bool operator==(SocioClub &x){
        return (NumeroSocio==x.NumeroSocio && NombreSocio==x.NombreSocio && Domicilio==x.Domicilio && AnioIngreso==x.AnioIngreso);
        }
        bool operator!=(SocioClub &x){
        return (NumeroSocio!=x.NumeroSocio && NombreSocio!=x.NombreSocio && Domicilio!=x.Domicilio && AnioIngreso!=x.AnioIngreso);
        }
        bool operator<(SocioClub &x){
            return (NumeroSocio<x.NumeroSocio);
        }
        bool operator>(SocioClub &x){
            return (NumeroSocio>x.NumeroSocio);
        }
        bool operator<=(SocioClub &x){
            return (NumeroSocio<=x.NumeroSocio);
        }
        bool operator>=(SocioClub &x){
            return (NumeroSocio>=x.NumeroSocio);
        }
        void setNombre(string);
        void setDomicilio(string);
};

template<class T>
class LDLLSE;

template<class T>
class nodo{
private:
    T data;
    nodo<T>* sig;
    nodo<T>* ant;
public:
    nodo():sig(nullptr), ant(nullptr){};
    friend class LDLLSE<T>;
};

template<class T>
class LDLLSE{
private:
    nodo<T>* ancla;
public:
    LDLLSE(): ancla(nullptr){};
    bool vacia()const;
    nodo<T>* primero()const;
    nodo<T>* ultimo()const;
    nodo<T>* anterior(nodo<T>*)const;
    nodo<T>* siguiente(nodo<T>* )const;
    nodo<T>* localiza(T)const;
    T recupera(nodo<T>* )const;
    void imprime()const;
    void anula();
    void inserta(nodo<T>* pos, SocioClub elem);
    bool elimina(nodo<T>* pos);
    void contador();
};

void SocioClub::setNombre(string n){
    NombreSocio=n;
}

void SocioClub::setDomicilio(string d){
    Domicilio=d;
}

template<class T>
void LDLLSE<T>::inserta(nodo<T>* pos, SocioClub elem){
    nodo<T>* aux= new nodo<T>;
    aux->data=elem;
    if(pos==nullptr){
        aux->ant=nullptr;
        aux->sig=ancla;
        if(ancla!=nullptr){
            ancla->ant=aux;
        }
        ancla=aux;
    }
    else{
        aux->ant=pos;
        aux->sig=pos->sig;
        if(pos->sig!=nullptr){
            pos->sig->ant=aux;
        }
        pos->sig=aux;
    }
}

template<class T>
bool LDLLSE<T>::elimina(nodo<T>* pos){
    if(vacia() || pos==nullptr){
        cout<<"\nSocio proporcionado no existe. . .\n\n";
        return false;
    }
    if(pos->ant!=nullptr){
        pos->ant->sig=pos->sig;
    }
    if(pos->sig!=nullptr){
        pos->sig->ant=pos->ant;
    }
    if(pos==ancla){
        ancla=ancla->sig;
    }
    delete pos;
    cout<<"\nSocio eliminado correctamente. . .\n\n";
    return true;
}

template<class T>
nodo<T>* LDLLSE<T>::primero()const{
    return ancla;
}

template<class T>
nodo<T>* LDLLSE<T>::ultimo()const{
    if(vacia()){
        return ancla;
    }
    else{
        nodo<T>* aux=ancla;
        while(aux->sig!=nullptr){
            aux=aux->sig;
        }
        return aux;
    }
}

template<class T>
nodo<T>* LDLLSE<T>::anterior(nodo<T>* pos)const{
    if(vacia()|| pos==nullptr){
        return nullptr;
    }
    else{
        return pos->ant;
    }
}

template<class T>
nodo<T>* LDLLSE<T>::siguiente(nodo<T>* pos)const{
    if(vacia()|| pos==nullptr){
        return nullptr;
    }
    else{
        return pos->sig;
    }
}

template<class T>
nodo<T>* LDLLSE<T>::localiza(T elem)const{
    nodo<T>* aux=ancla;
    if(vacia()){
        return nullptr;
    }
    else{
        while(aux->sig!=nullptr && aux->data!=elem){
            aux=aux->sig;
        }
        if(aux->data!=elem){
            return nullptr;
        }
    }
    return aux;
}

template<class T>
T LDLLSE<T>::recupera(nodo<T>* pos)const{
    if(vacia()|| pos==nullptr){
    }
    else{
        return pos->data;
    }
}

template<class T>
bool LDLLSE<T>::vacia()const{
    if(ancla==nullptr){
        return true;
    }
    return false;
}

template<class T>
void LDLLSE<T>::imprime()const{
    if(!vacia()){
        nodo<T>* aux=ancla;
        while(aux!=nullptr){
            std::cout<<aux->data<<std::endl;
            aux=aux->sig;
        }
    }
}

template<class T>
void LDLLSE<T>::anula(){
    nodo<T>* aux;
    while(ancla!=nullptr){
        aux=ancla;
        ancla=aux->sig;
        delete aux;
    }
}

template<class T>
void LDLLSE<T>::contador(){
    int i=1;
    if(ancla==nullptr){
        cout<<"\nLa lista se encuentra vacia. . .\n"<<endl;
    }
    else{
    nodo<T>* aux=ancla;
    while(aux->sig!=nullptr){
        aux=aux->sig;
        i++;
    }
    cout<<"\nNumero de socios registrados: "<<i<<endl<<endl;
    }
}

void menu(){
    std::cout<<"------Menu Socios------"<<std::endl;
    std::cout<<"1. Registrar nuevo socio"<<std::endl;
    std::cout<<"2. Dar de baja socio"<<std::endl;
    std::cout<<"3. Reporte de datos de socios"<<std::endl;
    std::cout<<"4. Busqueda de socio"<<std::endl;
    std::cout<<"5. Total socios registrados"<<std::endl;
    std::cout<<"6. Salir"<<std::endl;
    std::cout<<"Opcion: ";
}

int main()
{
    LDLLSE<SocioClub> milista;
    SocioClub socio,elem,elem1;
    int opc;
    do{
        system("cls");
        menu();
        string temp;
        cin>>opc;
        switch(opc){
             case 1:
                cout<<"\nRegistrar datos de nuevo socio: \n";
                cin>>socio;
                milista.inserta(milista.ultimo(), socio);
                cout<<"\nSocio agregado correctamente. . .\n\n";
                system("pause");
                break;
            case 2:
                if(milista.vacia()){
                    cout<<"\nLa lista se encuentra vacia. . .\n\n";
                }
                else{
                cout<<"\nDatos de socio a dar de baja: \n";
                cin>>socio;
                milista.elimina(milista.localiza(socio));
                }
                system("pause");
                break;
            case 3:
                cout<<"\nDatos de socios registrados: "<<endl;
                milista.imprime();
                cout<<"\n";
                system("pause");
                break;
            case 4:
                if(!milista.vacia()){
                    std::cout<<"\nProporcione los datos de socio a buscar\n"<<std::endl;
                    std::cout<<" Nombre de socio: ";
                    std::cin>>temp;
                    elem.setNombre(temp);
                    std::cout<<" Domicilio de socio: ";
                    std::cin>>temp;
                    elem.setDomicilio(temp);
                    if(milista.localiza(elem)){
                        elem1=milista.recupera(milista.localiza(elem));
                        std::cout<<"\nSocio encontrado\n"<<elem1<<std::endl<<std::endl;
                    }
                    else{
                        std::cout<<"\nSocio no encontrado\n"<<std::endl;
                    }
                }else{
                    std::cout<<"\nLa lista se encuentra vacia. . .\n"<<std::endl;
                }
                system("pause");
                break;

            case 5:
                milista.contador();
                system("pause");
                break;
            default:
                cout<<"\nSaliendo . . .\n";



        }



    }
    while(opc!=6);
    return 0;
}
