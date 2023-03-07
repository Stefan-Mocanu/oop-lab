#include <iostream>
#include <cstring>

using namespace std;

class Avioane{
    char *inmatriculare, *model;
    int capacitate_zbor, consum100;
public:
    Avioane(char *n=nullptr, char *m=nullptr, int cap=0, int comb=0) {
        if (n != nullptr) {
            int len1 = strlen(n) + 1;
            inmatriculare = new char[len1];
            strcpy(inmatriculare, n);
        }
        if (m != nullptr){
            int len2 = strlen(m) + 1;
            model = new char[len2];
            strcpy(model, m);
        }
        capacitate_zbor = cap;
        consum100 = comb;
    }
    Avioane(const Avioane &av){
        int len1 = strlen(av.model) + 1;
        inmatriculare = new char[1];
        model = new char[len1];
        strcpy(inmatriculare, "\0");
        strcpy(model, av.model);
        capacitate_zbor = av.capacitate_zbor;
        consum100 = av.consum100;
    }
    char *getInmatriculare() const{
        return inmatriculare;
    }
    char *getModel() const{
        return model;
    }
    int getCapacitate() const{
        return capacitate_zbor;
    }
    int getConsum100() const{
        return consum100;
    }
    void setInmatriculare(char *i){
        delete[] inmatriculare;
        int len1 = strlen(i)+1;
        inmatriculare = new char[len1];
        strcpy(inmatriculare, i);
    }
    void setModel(char *i){
        delete[] model;
        int len1 = strlen(i)+1;
        model = new char[len1];
        strcpy(model, i);
    }
    void setCapacitate(int i){
        capacitate_zbor = i;
    }
    void setConsum100(int i){
        consum100 = i;
    }
    Avioane operator=(const Avioane &av){
        setModel(av.model);
        capacitate_zbor = av.capacitate_zbor;
        consum100 = av.consum100;
        return *this;
    }


    ~Avioane(){
        delete[] inmatriculare;
        delete[] model;
    }
    friend ostream& operator<<(ostream& os, const Avioane &rhs);
    friend istream& operator>>(istream& is, Avioane &rhs);
};
bool operator==(const Avioane lhs, const Avioane rhs){
    return strcmp(lhs.getModel(),rhs.getModel())==0 && lhs.getCapacitate() == rhs.getCapacitate() && lhs.getConsum100() == rhs.getConsum100();
}
bool operator!=(const Avioane lhs, const Avioane rhs){
    return strcmp(lhs.getModel(),rhs.getModel())!=0 || lhs.getCapacitate() != rhs.getCapacitate() || lhs.getConsum100() != rhs.getConsum100();
}
ostream& operator<<(ostream& os, const Avioane &rhs) {
    os << rhs.inmatriculare << ' ' << rhs.model << ' ' << rhs.capacitate_zbor << ' ' << rhs.consum100;
    return os;
}
istream& operator>>(istream& is, Avioane &rhs){
    char aux[255];
    cout << "Inmatriculare: ";
    is >> aux;
    strcpy(rhs.inmatriculare,aux);
    cout << "Model: ";
    is >> aux;
    strcpy(rhs.model,aux);
    cout << "Capacitate zbor(km): ";

    is >> aux;
    rhs.setCapacitate(atoi(aux));
    cout << "Consum100: ";
    is >> aux;
    rhs.setConsum100(atoi(aux));
    return is;

}
class Zboruri{
    char *plecare, *destinatie;
    int distanta;
public:
    Zboruri(const char *plec = nullptr, const char *dest = nullptr, const int dist=0){
        if(plec = nullptr){
            int len1 = strlen(plec) + 1;
            plecare = new char[len1];
            strcpy(plecare, plec);
        }
        if(dest = nullptr) {
            int len2 = strlen(dest) + 1;
            destinatie = new char[len2];
            strcpy(destinatie, dest);
        }
        distanta = dist;
    }

    Zboruri(const Zboruri &zb){
        int len1 = strlen(zb.plecare) + 1;
        int len2 = strlen(zb.destinatie)  +1;

        plecare = new char[len1];
        strcpy(plecare, zb.plecare);

        destinatie = new char[len2];
        strcpy(destinatie, zb.destinatie);

        distanta = zb.distanta;
    }

    char *getPlecare(){
        return plecare;
    }
    char *getDestinatie(){
        return destinatie;
    }
    int getDistanta(){
        return distanta;
    }
    void setPlecare(const char *plec){
        delete[] plecare;
        int len = strlen(plec) + 1;
        plecare = new char[len];
        strcpy(plecare, plec);
    }
    void setDestinatie(const char *dest){
        delete[] destinatie;
        int len = strlen(dest) + 1;
        destinatie = new char[len];
        strcpy(destinatie, dest);
    }
    void setDistanta(const int dist){
        distanta = dist;
    }
    Zboruri operator=(const Zboruri &zb){
        setDestinatie(zb.destinatie);
        setPlecare(zb.plecare);
        distanta = zb.distanta;
        return *this;
    }

    ~Zboruri(){
        delete[] destinatie;
        delete[] plecare;
    }
    friend ostream& operator<<(ostream& os, const Zboruri &rhs);
};
bool operator==(Zboruri &st, Zboruri &dr){
    return strcmp(st.getDestinatie(),dr.getDestinatie())==0 && strcmp(st.getPlecare(),dr.getPlecare())==0 && st.getDistanta() == dr.getDistanta();
}
bool operator!=(Zboruri &st, Zboruri &dr){
    return strcmp(st.getDestinatie(),dr.getDestinatie())!=0 || strcmp(st.getPlecare(),dr.getPlecare())!=0 || st.getDistanta() != dr.getDistanta();
}
ostream& operator<<(ostream& os, const Zboruri &rhs) {
    os << rhs.plecare << ' ' << rhs.destinatie << ' ' << rhs.distanta;
    return os;
}


void init(Avioane *av,Zboruri *zb){
    av[0].setInmatriculare("YR-MIZ");
    av[1].setInmatriculare("YR-MIR");
    av[2].setInmatriculare("YR-MIV");
    av[3].setInmatriculare("YR-MIB");

    av[0].setModel("Boeing737");
    av[1].setModel("Boeing737");
    av[2].setModel("Boeing737MAX");
    av[3].setModel("Boeing737MAX");

    av[0].setCapacitate(3000);
    av[1].setCapacitate(3000);
    av[2].setCapacitate(4000);
    av[3].setCapacitate(4000);

    av[0].setConsum100(20);
    av[1].setConsum100(20);
    av[2].setConsum100(18);
    av[3].setConsum100(18);

    zb[0].setPlecare("OTP");
    zb[1].setPlecare("OTP");
    zb[2].setPlecare("BCN");
    zb[3].setPlecare("FCO");
    zb[4].setPlecare("FCO");

    zb[0].setDestinatie("BCN");
    zb[1].setDestinatie("FCO");
    zb[2].setDestinatie("LTN");
    zb[3].setDestinatie("BCN");
    zb[4].setDestinatie("BGY");

    zb[0].setDistanta(1975);
    zb[1].setDistanta(1141);
    zb[2].setDistanta(1183);
    zb[3].setDistanta(951);
    zb[4].setDistanta(500);
}
int main(){
    Avioane *avi = new Avioane[4];
    Zboruri *zbo = new Zboruri[6];
    init(avi, zbo);
    cout<<avi[0]<<endl;
    cout<<zbo[1]<<endl;
    return 0;
}