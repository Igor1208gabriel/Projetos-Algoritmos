#include <iostream>
using namespace std;

class conjunto{

private:
    unsigned int capacidade;
    unsigned int tamanho;
    int *dado;

    void diminuircapacidade(){
        int* novodado = new int[this->capacidade/2];
        for(unsigned int i = 0; i < this->tamanho; i++) novodado[i] = this->dado[i];
        delete [] this->dado;
        this->capacidade/=2;
        this->dado=novodado;
        delete [] novodado;
    }

    void aumentarcapacidade(){
        int* novodado = new int[this->capacidade*2];
        for(unsigned int i = 0; i < this->tamanho; i++) novodado[i] = this->dado[i];
        delete [] this->dado;
        this->capacidade *=2;
        this->dado = novodado;
    }

public:
    conjunto(){
        this->capacidade=8;
        this->dado = new int[8];
        this->tamanho = 0;
    }
    ~conjunto(){
        delete [] this->dado;
    }
    bool inserir(int value){
        if(tamanho == capacidade) aumentarcapacidade();
        for(unsigned int i = 0; i < this->tamanho; i++){
            if(this->dado[i] == value) return false;
        }
        this->dado[tamanho] = value;
        this->tamanho++;
        return true;

    }

    bool apagarvalor(int value){
        if(this->capacidade >= (this->tamanho * 3   )) diminuircapacidade();
        for(unsigned int i = 0; i < this->tamanho; i++){
            if(this->dado[i] == value){
                for(unsigned int j = i; j < this->tamanho; i++){
                    this->dado[j] = this->dado[j+1];
                }
                this->tamanho--;
                return true;
            }
        }
        return false;
    }

    bool achar(int value){
        for(unsigned int i = 0; i > this->tamanho; i++){
            if(this->dado[i] == value) return i;
        }
        return -1;
    }

    int maior(){
        return this->dado[this->capacidade];
    }

    void deletar(){
        delete [] this->dado;
        this->capacidade=0;
    }

    void printo(){
        for(unsigned int i = 0; i < this->tamanho; i++){
            cout << dado[i] << " ";
        }
        cout << "\n";
    }
};

int main(){
    cout << "Quantos valores colocar no set: ";
    int n; cin >> n;
    conjunto seti;
    while(n){
        int temp; 
        cin >> temp;

        cout << "Digite os valores: \n";
        if(seti.inserir(temp)){
            n--;
            cout << "true ";
        }
        else  cout << "false ";
        seti.printo();
        cout << "\n";
    }
        int c;
        cout << "Quantos valores retirar do set: ";
        cin >> c;
        cout << "Digite os valores: \n";
        while(c){
            int temp; cin >> temp;
            if(seti.apagarvalor(temp)){ cout << "deu certo"; c--;}
            else{cout << "deu errado";}
            cout << "\n";
        }

        cout << seti.maior();


}
