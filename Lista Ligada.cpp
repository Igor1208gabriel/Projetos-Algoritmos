using namespace std;

class LL{
    private:
        struct no_LL{
            int valor;
            no_LL *proximo;
        }
        no_LL *primeiro, *ultimo;
    public:
        LL(){
            primeiro = nullptr;
            ultimo = nullptr;
        }
        ~LL(){
        }
        empurra(int valor){
            no_LL *novono = new no_LL;
            novono->valor = this->valor;
            novono->proximo = nullptr;

            if(this->primeiro == nullptr){
                this->primeiro = novono;
            }
            this->ultimo->proximo = novono;
            this->ultimo = novono;
        }
        puxa(int valor){
            no_LL *novono = new no_LL;
            novono->valor = this->valor;
            novono->proximo = primeiro;
            this->primeiro = novono;

            if(this->ultimo == nullptr){
                this->ultimo = novono;
            }
        }

        remover_comeco(){
            no_LL *deletar = new no_LL;
            deletar= this->primeiro;
            
            if(this->primeiro == nullptrl) return;

            if(this->primeiro == this->ultimo){
                this->primeiro == nullptr;
                this->ultimo = nullptr;
            }

            else this->primeiro = this->primeiro->proximo;  
            delete deletar;
        }

        remover_final(){

        }

};