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
        LDL(){
            this->primeiro = nullptr;
            this->ultimo = nullptr;
            tamanho = 0;
        }
        ~LDL(){
            if(primeiro != nullptr){
                nodeldl *este = new nodeldl;
                while(este->proximo != nullptr){
                    nodeldl *deletar = este->proximo;
                    delete [] deletar;
                }
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
                this->primeiro = novono;
                this->ultimo = novono;
            }
            tamanho++;
        }

        void coloca(unsigned int indice, int valor){
            if(indice > tamanho+1) return;
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

        void tirar_comeco(){
            if(this->primeiro == nullptr) return;
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
        }
        void tirar_fim(){
            if(this->primeiro == nullptr) return;
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
        }
        void tirar_em(unsigned int indice){
            if(this->primeiro == nullptr || indice > this->tamanho) return;
            nodeldl *achar = new nodeldl;
            
            if(this->primeiro == this->ultimo){
                this->primeiro = nullptr;
                this->ultimo = nullptr;
                achar = this->primeiro;
                delete achar;
                tamanho--;
                return;
            }

            if(indice == tamanho)tirar_fim();
            if(indice == 0   )tirar_comeco();

            if(indice <= tamanho/2){
                achar = this->primeiro;
                for(unsigned int i = 0 ; i < indice ; i++){
                    achar = achar->proximo;
                }

            }

            else if(indice > tamanho/2){
                achar = this->ultimo;
                for(unsigned int i = tamanho; i < indice ; i++){
                    achar = achar->anterior;
                }
            }
            
            achar->anterior->proximo = achar->proximo;
            achar->proximo->anterior = achar->anterior;
            tamanho--;
            delete achar;
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
};

int main(){
    LDL n;
    n.puxa(100);
    cout << n.indice(0) << " " << n.indice(1);
}