#include <iostream>
#include <chrono>
using namespace std;

struct vetor{

    private:
    unsigned int tamanho;
    unsigned int capacidade;
    int *dado;

    void aumentarcapacidade(){
        int* novodado = new int[this->capacidade *2];
        for(unsigned int i = 0; i < this->tamanho; i++){
            novodado[i] = this->dado[i];
        }
        delete [] this->dado;
        this->dado = novodado;
        this->capacidade *=2; 
    }

    void diminuircapacidade(){
        int* novodado = new int[this->capacidade /2];
        for(unsigned int i = 0; i < this->capacidade; i++){
            novodado[i] = this->dado[i];
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
    unsigned int size(){return tamanho;}
    unsigned int capacity(){return capacidade;}
    double percent_occupied(){ return (tamanho*1.0)/(capacidade);}
    bool insert_at(unsigned int index, int value){
        if (index > tamanho) return false;
        if (tamanho >= capacidade) aumentarcapacidade();
            for(unsigned int i = tamanho; i > index; i--)
                dado[i] = dado[i-1];
            dado[index] = value;
            tamanho++;
            return true;
    }
    bool remove_at(unsigned int index){
        if (index >= tamanho) return false;
        else{
            for(unsigned int i = index; i < tamanho-1 ; i++){
                dado[i] = dado[i+1];
            }
            tamanho--;
            return true;
        }
    }
    int get_at(unsigned int index){
        if (index <= tamanho) return dado[index]; 
        else return -1; 
    }
    void clear(){
        this->tamanho = 0;
        this->capacidade = 0;
        delete [] this->dado;
        this-> dado = new int[8];
    }
    void push_back(int value){
        insert_at(tamanho, value);
    }
    void push_front(int value){
        insert_at(0, value);
    }
    bool pop_back(){return remove_at(tamanho);}
    bool pop_front(){return remove_at(0);}
    int back(){return dado[tamanho-1];}
    int front(){return dado[0];}
    bool remove(int value){
        return(remove_at(find_index(value)));
    }
    int find_index(int value){
        for(unsigned int i = 0; i < tamanho; i++){
            if(dado[i] == value) return i;
        }
        return -1;
    }
    int count(int value){
        int ans = 0;
        for(unsigned int i = 0; i < tamanho; i++){
            if(dado[i] == value) ans++;
        }
        return ans;
    }
    int sum(){
        int ans = 0;
        for(unsigned int i = 0; i < tamanho; i++){
            ans+=dado[i];
        }
        return ans;
    }
    string tostring(){
        string ans = "[";
        ans += to_string(dado[0]);
        for(unsigned int i = 1; i < tamanho; i++){
            ans += ", ";
            ans += to_string(dado[i]) ;
        }
        ans += "]";
        return ans;
    }

};
