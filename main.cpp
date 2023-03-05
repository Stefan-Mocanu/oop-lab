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
    }


    ~Avioane(){
        delete[] inmatriculare;
        delete[] model;
    }
    friend ostream& operator<<(ostream& os, const Avioane &rhs);
    //friend istream& operator>>(istream& is, const Avioane &rhs);
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
/*istream& operator>>(istream& is, Avioane &rhs){
    cout << "Inmatriculare: ";
    is >> rhs.inmatriculare>>"\n";
    cout << "Model: ";
    is >> rhs.model>>"\n";
    cout << "Capacitate zbor(km): ";
    char aux[255];
    is >> aux >> "\n";
    rhs.setCapacitate(atoi(aux));
    cout << "Consum100: ";
    is >> aux >> "\n";
    rhs.setConsum100(atoi(aux));
    return is;

}*/
class Zboruri{
    char *plecare, *destinatie;
    int distanta;
public:
    Zboruri(const char *plec, const char *dest, const int dist){
        int len1 = strlen(plec) + 1;
        int len2 = strlen(dest)  +1;

        plecare = new char[len1];
        strcpy(plecare, plec);

        destinatie = new char[len2];
        strcpy(destinatie, dest);

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
struct Avion{
    Avioane av;
    Avion *next;
};
struct Zbor{
    Zboruri zb;
    Zbor *next;
};
void init(Avioane &av){
    av.setCapacitate(2000);
    av.setConsum100(10);

}
int main(){
    Avion *Flota = new Avion;
    Avioane av;
    //cin>>av;
    cout<<(av);
    return 0;
}