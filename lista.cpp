#include "lista.h"

Lista::Lista(){
	this->cabeca = 0;
	this->qtd = 0;
}

Lista::~Lista(){
	this->libera();
	this->qtd = 0;
}

void Lista::insere_ordenado(int i){
	no_dado* novo = new no_dado();
	no_dado* ant = new no_dado(); 
	no_dado* p = this->cabeca;
	novo->info = i;
	
	if(p==0){// Lista vazia
		novo->prox = 0;
		novo->ant = 0;
		this->last = novo;
		this->cabeca = novo;
		this->qtd++;
		return;
	}
	
	if(p->ant==0 && p->prox==0){ // Apenas um nó dado
		if(p->info<=i){//insere fim por ser maior
			p->prox = novo;
			novo->prox = 0;
			novo->ant = p;
			this->last = novo;
		}else{	//insere inicio por ser menor
			novo->ant = 0;
			novo->prox = p;
			p->ant = novo;
			this->last = p;
			this->cabeca = novo;
		}
	}else{ // 2 ou + nós dado 
		for(;p!=NULL && i>p->info; (ant=p) && (p=p->prox));	
		
		if(p==0){//ultimo no a ser inserido
			ant->prox = novo;
			novo->ant = ant;
			novo->prox = 0;
			this->last = novo;
			this->qtd++;
			return;
		}
		
		if(p->ant==0 && i<p->info){//primeiro 
			novo->prox = p;
			p->ant = novo;
			this->cabeca = novo;
			this->qtd++;
			return;
		}
				
		novo->ant = p->ant;
		p->ant->prox = novo;
		novo->prox = p;
		p->ant = novo;
		if(novo->prox==0){
			this->last = novo;
		}
	}
	qtd++;
}

void Lista::libera(){
	no_dado* p = this->cabeca;
	 while (p != NULL) {
	 	no_dado* t = p->prox; 
		free(p); 
		this->qtd--; 
	 	p = t; 
	 }
	 this->cabeca = 0; 
	 this->last = 0;
}

void Lista::imprime_inic_fim(){
	if (this->cabeca!=0){
		no_dado* p; /* variável auxiliar para percorrer a lista */
		printf("\nInfo = ");
		for (p = this->cabeca; p != NULL; p = p->prox)
			printf("%d - ", p->info);
		printf("\n");	
	} else printf("\nLista está vazia!\n");
}

void Lista::remove_inicio(){
	no_dado* p = this->cabeca;
	if(p==0){
		cout<< "\nLista vazia\n" << endl;
		return;
	}
	
	if(p->ant==0 && p->prox==0){
		free(p);
		this->cabeca = 0;
		this->last = 0;
		this->qtd--;
		return;
	}
	
	p->prox->ant = 0;
	this->cabeca = p->prox;
	free(p);
}

void Lista::remove_fim(){
	no_dado* p = this->last;

	if(p==0){
		cout<< "Lista Vazia!"<< endl;
		return;	
	}
	
	if(p->ant==0 && p->prox==0){
		free(p);
		this->cabeca = 0;
		this->last = 0;
		this->qtd--;
		return;
	}
	
	no_dado* anter = p->ant;
	anter->prox = 0;
	free(p);
	this->last = anter;
}

void Lista::remove_elemento(int i){
	no_dado* p = this->cabeca;
	
	if(p==0){ 
		cout<< "Lista Vazia!"<< endl;
		return;	
	}
	
	for(;p->info!=i && p!=0; p=p->prox);
	
	if(p->info==i){
	
		if(p->ant==0 && p->prox==0){ // 1 elemento
			free(p);
			this->cabeca = 0;
			this->last = 0;
			this->qtd--;
			return;	
		}
		
		if(p->ant==0 && p->info==i){// 2 ou + elementos && primeiro elemento 
			p->prox->ant = 0;
			this->cabeca = p->prox;
			free(p);
			this->qtd--;
			return;
		}
		
		if(p->ant!=0 && p->prox!=0){// 2 ou + elementos && Entre 2 elementos 
			p->ant->prox = p->prox;
			p->prox->ant = p->ant;
			this->qtd--;
			free(p);
			return;
		}
		
		p->ant->prox = 0;
		this->last = p->ant;
		free(p);
		this->qtd--;
		
	}else
		cout<<"Elemento não presente na lista" <<endl;
}

void Lista::imprime_fim_inic(){
	no_dado* p = this->last;
	
	if(p==0){
		cout<<"Lista vazia! "<<endl;
		return;
	}
	cout<<"\nInfo: ";
	for(; p!=0; p=p->ant)
		cout<< p->info <<" - ";
	cout<<endl;
}

void Lista::buscar_elemento(int i){
	no_dado* p = this->cabeca;
	
	if(p==0){
		cout<<"Lista vazia! "<<endl;
		return;	
	}
	
	for(;p!=0; p=p->prox){
		if(p->info==i){
		cout<<"\nElemento encontrado na lista" <<endl;
		return;
		}
	}
	cout<<"\nElemento não encontrado na lista" <<endl;	
}
