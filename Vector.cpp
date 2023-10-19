using namespace std;

struct vetor{

    private:
    unsigned int tamanho;
    unsigned int capacidade;
    int *dado;

    void aumentarcapacidade(){
        vetor *novovetor = new vetor;
        novovetor->capacidade = 2 * this->capacidade;
        for(unsigned int i = 0; i < this->tamanho; i++){
            novovetor->dado[i] = this->dado[i];
        }
        delete [] this->dado;
        this->dado = novovetor->dado;
        this->capacidade *=2; 
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