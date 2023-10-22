#include <iostream>
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
        //unsigned int capacitty() {}
        //double percent_occupied() {}
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
        void empurra(int valor){
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
        void puxa(int valor){
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
        void coloca(unsigned int indice, int valor){
            if(indice > tamanho) return;
            if(indice == tamanho) empurra(valor);
            if(indice == 0) puxa(valor);

            nodeldl *este = new nodeldl;    
            este->valor = valor;

            if(indice <= tamanho/2){
                este = this->primeiro;
                for(unsigned int i = 0 ; i < indice ; i++){
                   este = este->proximo; 
                }
            }

            if(indice > tamanho/2){
                este = this->ultimo;
                for(unsigned int i = tamanho; i < indice ; i++){
                    este = este->anterior;
                }
            }

            este->proximo->anterior = este;
            este->anterior->proximo = este; 

        }
        bool tirar_comeco(){
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
        bool tirar_fim(){
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
        bool tirar_em(unsigned int indice){

            if(indice >= this->tamanho) return false;
            nodeldl *achar = this->primeiro;
            if(indice == 0){return tirar_comeco();}
            if(indice == tamanho-1){return tirar_fim();}
            
            for(unsigned int i = 0; i < indice; i++)
                achar = achar->proximo;


            achar->anterior->proximo = achar->proximo;
            achar->proximo->anterior = achar->anterior
            
        }
        int indice(unsigned int indice){
            if (indice > tamanho) return -1;
            nodeldl *este = new nodeldl;
            este = this->primeiro;
            if (indice >= tamanho/2){
                for(unsigned int i = 0 ; i < indice ; i++){
                    este = este->proximo;
                }
            }
            else{
                este = this->ultimo;
                for(unsigned int i = indice ; i < tamanho; i++){
                    este = este->anterior;
                }
            }
            return este->valor;
        }
        unsigned int tamanho(){
            return tamanho;
        }
        int inicio(){
            return this->primeiro->valor;
        }
        int final(){
            return this->ultimo->valor;
        }
        int achar_indice(int value){
            nodeldl *novono = this->primeiro;
            int count = 0;
            while(novono->proximo != nullptr){
                if(novono->valor = value) return count;
                count++;
                novono = novono->proximo;
            }
        }
        int contar(int value){
            nodeldl *novono = this->primeiro;
            int count = 0;
            while(novono->proximo != nullptr){
                if(novono->valor = value) count++;
                novono = novono->proximo;
            }
            return count;
        }
        int soma(){
            nodeldl *novono = this->primeiro;
            int count = 0;
            while(novono->proximo != nullptr){
                if(novono->valor = value) count+=novono->valor;
                novono = novono->proximo;
            }
            return count;
        }
        void limpar(){
            nodeldl novono = this->primeiro;
            
        }


};

int main(){
    LDL n;
    n.puxa(100);
    cout << n.indice(0) << endl;

}