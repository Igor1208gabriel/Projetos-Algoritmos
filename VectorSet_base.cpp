using namespace std;

struct vetor{

    private:
    unsigned int tamanho;
    unsigned int capacidade;
    int *dado;

    void aumentarcapacidade(){
        int* novodado = new int[this->capacidade *2];
        for(unsigned int i = 0; i < this->tamanho; i++){
            novodado->dado[i] = this->dado[i];
        }
        delete [] this->dado;
        this->dado = novodado;
        this->capacidade *=2; 
    }

    void diminuircapacidade(){
        int* novodado = new int[this->capacidade /2];
        for(unsigned int i = 0; i < this->capacidade){
            novodado->dado[i] = this->dado[i];
        }
        delete [] this->dado;
        this->dado = novodado;
        this->capacidade /=2;
    }

    public:
    vetor(){
        this->tamanho = 0;
        this->capacidade = 8;
        this->dado = new int[8];
    }
    ~vetor(){
        this->tamanho = 0;
        this->capacidade = 0;
        delete [] this->dado;
    }

};

int main(){
    vetor n;
}