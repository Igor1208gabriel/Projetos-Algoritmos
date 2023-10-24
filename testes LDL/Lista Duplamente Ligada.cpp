#include <iostream>
#include <chrono>
using namespace std;


struct LDL{
    private:
        struct nodeldl{
            int valor;
            nodeldl *anterior, *proximo;
        };
        nodeldl *primeiro, *ultimo;
        unsigned int tamanho;
    public:
        unsigned int capacitty() {return tamanho;}
        double percent_occupied() {return 1.00;}
        LDL(){
            this->primeiro = nullptr;
            this->ultimo = nullptr;
            tamanho = 0;
        }
        ~LDL(){
            nodeldl *este = this->primeiro;
            while(este != nullptr){
                nodeldl* deletar = este;
                este = este->proximo;
                delete deletar;
            }            
        }
        void push_back(int valor){
            nodeldl *novono = new nodeldl;
            novono->valor = valor;
            novono->proximo = nullptr;
            novono->anterior = this->ultimo;

            if(primeiro == nullptr){
                this->primeiro = novono;
                this->ultimo = novono;
            }
            else{
                this->ultimo->proximo = novono;
                this->ultimo = novono;
            }
            tamanho++;
        }
        void push_front(int valor){
            nodeldl *novono = new nodeldl;
            novono->valor = valor;
            novono->proximo = this->primeiro;
            novono->anterior = nullptr;
            
            if(primeiro == nullptr){
                this->ultimo = novono;
            }
            else    
                this->primeiro->anterior = novono;
            this->primeiro = novono;

            tamanho++;
        }
        bool insert_at(unsigned int indice, int valor){
            if(indice > tamanho) return false;
            if(indice == tamanho){
            push_back(valor);
            return true;
            }
            if(indice == 0){
            push_front(valor);
            return true;
            }
            

            nodeldl *este = new nodeldl;
            este = this->primeiro;

            for(unsigned int i = 0 ; i < indice ; i++){
               este = este->proximo; 
            }
            nodeldl *novono = new nodeldl;
            novono->valor = valor;
            novono->proximo = este;
            novono->anterior = este->anterior;
            novono->anterior->proximo = novono;
            novono->proximo->anterior = novono;
            tamanho++;
            
            return true;

        }
        bool pop_front(){
            if(this->primeiro == nullptr) return false;
            nodeldl *deletar = new nodeldl;
            deletar = this->primeiro;
            this->primeiro->anterior = nullptr;

            if(this->primeiro == this->ultimo){
                this->primeiro = nullptr;
                this->ultimo = nullptr;
            }else 
                this->primeiro = this->primeiro->proximo;
            delete deletar;
            tamanho--;
            return true;
        }
        bool pop_back(){
            if(this->primeiro == nullptr) return false;
            nodeldl *deletar = new nodeldl;
            deletar = this->ultimo;
            if(this->primeiro == this->ultimo){
                this->primeiro = nullptr;
                this->ultimo = nullptr;
            }else{
                 this->ultimo = this->ultimo->anterior;   
                 this->ultimo->proximo = nullptr;
            }
            delete deletar;
            tamanho--;
            return true;
        }
        bool remove_at(unsigned int indice){

            if(indice >= this->tamanho) return false;
            nodeldl *achar = this->primeiro;
            if(indice == 0){return pop_front();}
            if(indice == tamanho-1){return pop_back();}
            
            for(unsigned int i = 0; i < indice; i++)
                achar = achar->proximo;

            achar->anterior->proximo = achar->proximo;
            achar->proximo->anterior = achar->anterior;
            return true;
            
        }
        int get_at(unsigned int indice){
            if (indice > tamanho) return -1;
            nodeldl *este = new nodeldl;
            este = this->primeiro;
            for(unsigned int i = 0 ; i < indice; i++){
                este = este->proximo;
            }
            return este->valor;
        }
        unsigned int size(){
            return this->tamanho;
        }
        int front(){
            return this->primeiro->valor;
        }
        int back(){
            return this->ultimo->valor;
        }
        int find_index(int value){
            nodeldl *novono = this->primeiro;
            int count = 0;
            while(novono->proximo != nullptr){
                if(novono->valor == value) return count;
                count++;
                novono = novono->proximo;
            }
            return -1;
        }
        int count(int value){
            nodeldl *novono = this->primeiro;
            int count = 0;
            while(novono->proximo != nullptr){
                if(novono->valor == value) count++;
                novono = novono->proximo;
            }
            return count;
        }
        int sum(){
            nodeldl *novono = this->primeiro;
            int count = 0;
            while(novono->proximo != nullptr){
                count+=novono->valor;
                novono = novono->proximo;
            }
            return count;
        }
        void clear(){
            int x = tamanho;
            while(x--){
                pop_back();
                }
        }
        bool remove(int valor){
            int indice = find_index(valor);
            if(indice != -1){
                remove_at(indice);
                return true;
            }
            else{
                return false;
            }
        }
        string tostring(){
            nodeldl *este = this->primeiro;
            string str =  "[";
            str += to_string(este->valor);
            este = este->proximo;
            while(este != nullptr){
                str+=", ";
                str += to_string(este-> valor);
                este = este->proximo;
            }
            str += "]";
            return str;
        }

};

int main(){
    LDL listica;
    int n; cin >> n;


    auto comeco = chrono::high_resolution_clock::now();
    while(n--){
        int temp, temp2; cin >> temp >> temp2;
        listica.push_back(temp);
    }
    auto fim = chrono::high_resolution_clock::now();
    auto duracao = fim-comeco;

    cerr << duracao.count() << "\n";

}