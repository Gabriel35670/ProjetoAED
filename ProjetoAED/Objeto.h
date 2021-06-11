#include <iostream>
#include <string>


using namespace std;

class Objeto{


    private:
        string nome;
    
    public:
        Objeto(string nome);
        ~Objeto();

        string getNome() const;
        void setNome(string nome);

        bool operator==(const Objeto &o)const;
};

