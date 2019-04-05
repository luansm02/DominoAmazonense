/*
	@Luan Souza Marques
	lsm@icomp.ufam.edu.br
*/
#include <iostream>

using namespace std;

typedef struct tno{
	int dado;
	struct tno *prox;
}no;

typedef struct tpc{
	int super;
	int infer;
}Peca;

class Pilha{
	no *topo;
	public:
		Pilha(){
			topo = NULL;
		}
		void esvazia(){
			while(!vazio()){
				pop();
			}
		}
		~Pilha(){
			esvazia(); 
		}
		int vazio(){
			return topo==NULL?1:0;
		}
		no* pegaTopo(){
			return topo;
		}
		void push(int val){
			no* aux = new no;
			aux->dado = val;
			aux->prox = topo;
			topo = aux;
		}
		int top(){
			if(!vazio()){
				return topo->dado;
			}else{
				return -1;
			}
		}
		int pop(){
			if(!vazio()){
				int val = topo->dado;
				no* aux = topo;
				topo = topo->prox;
				delete aux;
				return val;
			}else{return -1;}
		}
		int popN(int indice){
			int cont=1;
			if(!vazio()){
				no *aux = topo,*ant;
				if(indice==0){
					return pop();
				}else{
					ant = aux;
					aux = aux->prox;
					while(cont != indice && aux!=NULL){
						ant = aux;
						aux = aux->prox;
						cont++;
					}
					if(aux == NULL){
						return -1;
					}else{
						cont = aux->dado;
						ant->prox = aux->prox;
						delete aux;
					}
				}
			}else{return -1;}
			return cont;
		}
		int tamanho(){
			int tam=0;
			no* aux;
			for(aux = topo;aux != NULL;aux = aux->prox)
				tam++;
			return tam;
		}
		void imprime(){
			no* aux;
			for(aux = topo;aux != NULL;aux = aux->prox)
				if(aux->dado == 0)cout<<"  ";
				else cout<<aux->dado<<" ";
			cout<<endl;
		}
		void imprimeLado(){
			no* aux;
			Pilha temp;
			for(aux = topo;aux != NULL;aux = aux->prox)
				temp.push(aux->dado);
			temp.ipmTemp();
			//delete temp;
		}

		void ipmTemp(){
			no* aux;
			int cont=0;
			for(aux = topo;aux != NULL;aux = aux->prox){
				if(cont==0){
					if(aux->dado == 0){
						cout<<" |";cont++;	
					}else{
						cout<<aux->dado<<"|";cont++;
					}
				}else{
					if(cont==1){
						if(aux->dado == 0){
							cout<<"  ";cont=0;	
						}else{
							cout<<aux->dado<<" ";cont=0;
						}
					}
				}
			}
			cout<<endl;
		}
		int busca(int val){
			no* aux;
			int indice = 0;
			for(aux = topo;aux != NULL;aux = aux->prox){
				indice++;
				if(aux->dado == val)return indice;
			}
			return -1;
		}
		int buscaPorIndice(int indice){
			int cont=0;
			no* aux;
			for(aux = topo;aux!=NULL && cont != indice;aux = aux->prox){cont++;}
			if(aux == NULL){
				return -1;
			}else{
				return aux->dado;
			}
		}
};

void preenchePecas(Peca vet[]){
	vet[0].super = 0;vet[0].infer = 0;
	vet[1].super = 1;vet[1].infer = 0;
	vet[2].super = 1;vet[2].infer = 1;
	vet[3].super = 2;vet[3].infer = 0;
	vet[4].super = 2;vet[4].infer = 1;
	vet[5].super = 2;vet[5].infer = 2;
	vet[6].super = 3;vet[6].infer = 0;
	vet[7].super = 3;vet[7].infer = 1;
	vet[8].super = 3;vet[8].infer = 2;
	vet[9].super = 3;vet[9].infer = 3;
	vet[10].super = 4;vet[10].infer = 0;
	vet[11].super = 4;vet[11].infer = 1;
	vet[12].super = 4;vet[12].infer = 2;
	vet[13].super = 4;vet[13].infer = 3;
	vet[14].super = 4;vet[14].infer = 4;
	vet[15].super = 5;vet[15].infer = 0;
	vet[16].super = 5;vet[16].infer = 1;
	vet[17].super = 5;vet[17].infer = 2;
	vet[18].super = 5;vet[18].infer = 3;
	vet[19].super = 5;vet[19].infer = 4;
	vet[20].super = 5;vet[20].infer = 5;
	vet[21].super = 6;vet[21].infer = 0;
	vet[22].super = 6;vet[22].infer = 1;
	vet[23].super = 6;vet[23].infer = 2;
	vet[24].super = 6;vet[24].infer = 3;
	vet[25].super = 6;vet[25].infer = 4;
	vet[26].super = 6;vet[26].infer = 5;
	vet[27].super = 6;vet[27].infer = 6;	
}

typedef struct tjgs{
	Pilha super;
	Pilha infer;
	int nPeca;
	int pts;
}Jogadores;

void mao(Jogadores *jg){
	char letra=97;
	cout<<"***Voce tem "<<jg->nPeca<<" pecas"<<endl;
	cout<<"____________________________________________"<<endl;
	jg->super.imprime();
	for(int i=0;i<jg->nPeca;i++){cout<<"- ";}cout<<endl;
	jg->infer.imprime();
	for(int i=0;i<jg->nPeca;i++){cout<<letra++<<" ";}
	cout<<endl<<"____________________________________________"<<endl;
}

void mesa(Pilha *lado1,Pilha *lado2,Pilha *lado3,Pilha *lado4){
	
	cout<<"____________________________________________"<<endl;
	cout<<"Carroca: 6|6"<<endl;
	cout<<"Lado 1: "; lado1->imprimeLado(); 
	cout<<"Lado 2: "; lado2->imprimeLado(); 
	cout<<"Lado 3: "; lado3->imprimeLado(); 
	cout<<"Lado 4: "; lado4->imprimeLado(); 
	cout<<"____________________________________________"<<endl;
}

int coloca(int peca,Pilha *l,Jogadores *jg){
	if(!l->vazio()){
		if(jg->super.buscaPorIndice(peca) == l->top()){
			l->push(jg->super.buscaPorIndice(peca));
			l->push(jg->infer.buscaPorIndice(peca));
			jg->super.popN(peca);
			jg->infer.popN(peca);
			jg->nPeca --;;
			return 0;
		}else{
			if(jg->infer.buscaPorIndice(peca) == l->top()){
				l->push(jg->infer.buscaPorIndice(peca));
				l->push(jg->super.buscaPorIndice(peca));
				jg->infer.popN(peca);
				jg->super.popN(peca);
				jg->nPeca --;
				return 0;
			}
		}
	}else{
		if(jg->super.buscaPorIndice(peca) == 6){
			l->push(jg->super.buscaPorIndice(peca));
			l->push(jg->infer.buscaPorIndice(peca));
			jg->super.popN(peca);
			jg->infer.popN(peca);
			jg->nPeca --;
			return 0;
		}else{
			if(jg->infer.buscaPorIndice(peca) == 6){
				l->push(jg->infer.buscaPorIndice(peca));
				l->push(jg->super.buscaPorIndice(peca));
				jg->infer.popN(peca);
				jg->super.popN(peca);
				jg->nPeca --;
				return 0;
			}
		}
	}
	return 1;
}

void contaPontos(Jogadores *jg,Pilha *lado1,Pilha *lado2,Pilha *lado3,Pilha *lado4){
	int soma=0,cont=0;
	no* aux;
	if(!lado1->vazio()){
		cont++;
		aux = lado1->pegaTopo();
		soma = soma + aux->dado;
		if(aux->prox->dado == aux->dado){
			if(aux->prox->prox != NULL){
				soma = soma + aux->prox->dado;
			}
		}
	}
	if(!lado2->vazio()){
		cont++;
		aux = lado2->pegaTopo();
		soma = soma + aux->dado;
		if(aux->prox->dado == aux->dado){
			if(aux->prox->prox != NULL){
				soma = soma + aux->prox->dado;
			}
		}
	}
	if(!lado3->vazio()){
		cont++;
		aux = lado3->pegaTopo();
		soma = soma + aux->dado;
		if(aux->prox->dado == aux->dado){
			if(aux->prox->prox != NULL){
				soma = soma + aux->prox->dado;
			}
		}
	}
	if(!lado4->vazio()){
		cont++;
		aux = lado4->pegaTopo();
		soma = soma + aux->dado;
		if(aux->prox->dado == aux->dado){
			if(aux->prox->prox != NULL){
				soma = soma + aux->prox->dado;
			}
		}
	}
	if(cont == 1){
		soma = soma + 12;
	}
	if(soma%5 == 0){
		jg->pts = soma + jg->pts;
	}
}

int jogaPeca(int vez,Jogadores *jg,Pilha *lado1,Pilha *lado2,Pilha *lado3,Pilha *lado4){
	
	int topo,valido = 0,invalido=0,numero;
	char letra;
	if(!lado1->vazio()){
		topo = lado1->top();
		if(jg->super.busca(topo) == -1){
			if(jg->infer.busca(topo) == -1){
				invalido = 1;
			}else{
				valido = 1;
			}
		}else{
			valido = 1;
		}
	}else{
		if(jg->super.busca(6) == -1){
			if(jg->infer.busca(6) == -1){
				invalido = 1;
			}else{
				valido = 1;
			}
		}else{
			valido = 1;
		}
	}
	if(!lado2->vazio()){
		topo = lado2->top();
		if(jg->super.busca(topo) == -1){
			if(jg->infer.busca(topo) == -1){
				invalido = 1;
			}else{
				valido = 1;
			}
		}else{
			valido = 1;
		}
	}else{
		if(jg->super.busca(6) == -1){
			if(jg->infer.busca(6) == -1){
				invalido = 1;
			}else{
				valido = 1;
			}
		}else{
			valido = 1;
		}
	}
	if(!lado3->vazio()){
		topo = lado3->top();
		if(jg->super.busca(topo) == -1){
			if(jg->infer.busca(topo) == -1){
				invalido = 1;
			}else{
				valido = 1;
			}
		}else{
			valido = 1;
		}
	}else{
		if(jg->super.busca(6) == -1){
			if(jg->infer.busca(6) == -1){
				invalido = 1;
			}else{
				valido = 1;
			}
		}else{
			valido = 1;
		}
	}
	if(!lado4->vazio()){
		topo = lado4->top();
		if(jg->super.busca(topo) == -1){
			if(jg->infer.busca(topo) == -1){
				invalido = 1;
			}else{
				valido = 1;
			}
		}else{
			valido = 1;
		}
	}else{
		if(jg->super.busca(6) == -1){
			if(jg->infer.busca(6) == -1){
				invalido = 1;
			}else{
				valido = 1;
			}
		}else{
			valido = 1;
		}
	}
	if(valido == 0){
		cout<<"Desculpa, voce nao tem nenhuma peca valida"<<endl<<endl;
		cout<<"JOGADOR "<<vez<<" PASSOU"<<endl<<endl;
		return 1;
	}else{
		cout<<endl<<"Uma peca (letra):";
		cin>>letra;
		cout<<"Um lado (numero):";
		cin>>numero;
		if(letra == 'a'){
			if(numero == 1)valido = coloca(0,lado1,jg);
			if(numero == 2)valido = coloca(0,lado2,jg);
			if(numero == 3)valido = coloca(0,lado3,jg);
			if(numero == 4)valido = coloca(0,lado4,jg);
		}
		if(letra == 'b'){
			if(numero == 1)valido = coloca(1,lado1,jg);
			if(numero == 2)valido = coloca(1,lado2,jg);
			if(numero == 3)valido = coloca(1,lado3,jg);
			if(numero == 4)valido = coloca(1,lado4,jg);
		}
		if(letra == 'c'){
			if(numero == 1)valido = coloca(2,lado1,jg);
			if(numero == 2)valido = coloca(2,lado2,jg);
			if(numero == 3)valido = coloca(2,lado3,jg);
			if(numero == 4)valido = coloca(2,lado4,jg);
		}
		if(letra == 'd'){
			if(numero == 1)valido = coloca(3,lado1,jg);
			if(numero == 2)valido = coloca(3,lado2,jg);
			if(numero == 3)valido = coloca(3,lado3,jg);
			if(numero == 4)valido = coloca(3,lado4,jg);
		}
		if(letra == 'e'){
			if(numero == 1)valido = coloca(4,lado1,jg);
			if(numero == 2)valido = coloca(4,lado2,jg);
			if(numero == 3)valido = coloca(4,lado3,jg);
			if(numero == 4)valido = coloca(4,lado4,jg);
		}
		if(letra == 'f'){
			if(numero == 1)valido = coloca(5,lado1,jg);
			if(numero == 2)valido = coloca(5,lado2,jg);
			if(numero == 3)valido = coloca(5,lado3,jg);
			if(numero == 4)valido = coloca(5,lado4,jg);
		}
		if(letra == 'g'){
			if(numero == 1)valido = coloca(6,lado1,jg);
			if(numero == 2)valido = coloca(6,lado2,jg);
			if(numero == 3)valido = coloca(6,lado3,jg);
			if(numero == 4)valido = coloca(6,lado4,jg);
		}
		if(valido == 1){
			cout<<"JOGADA INVALIDA"<<endl<<endl;
			return 0;
		}else{
			contaPontos(jg,lado1,lado2,lado3,lado4);
			return 1;
		}
	}
}

void jogaOrd(int comeca,Jogadores jg1,Jogadores jg2,Jogadores jg3,Jogadores jg4){
	Pilha lado1,lado2,lado3,lado4;
	int indice,atencao=0,quemJoga,botao;
	cout<<"O jogador "<<comeca<<" ira comecar com a carroca"<<endl;

	if(comeca==1){
		indice = jg1.infer.busca(6) - 1;
		jg1.super.popN(indice);
		jg1.infer.popN(indice);
		jg1.nPeca = jg1.nPeca - 1;
		comeca++;
	}else{
		if(comeca == 2){
			indice = jg2.infer.busca(6) - 1;
			jg2.super.popN(indice);
			jg2.infer.popN(indice);
			jg2.nPeca = jg1.nPeca - 1;
			comeca++;
		}else{
			if(comeca == 3){
				indice = jg3.infer.busca(6) - 1;
				jg3.super.popN(indice);
				jg3.infer.popN(indice);
				jg3.nPeca = jg1.nPeca - 1;
				comeca++;
			}else{
				indice = jg4.infer.busca(6) - 1;
				jg4.super.popN(indice);
				jg4.infer.popN(indice);
				jg4.nPeca = jg1.nPeca - 1;
				comeca = 1;
			}
		}
	}
	mesa(&lado1,&lado2,&lado3,&lado4);
	while(atencao == 0){
		cout<<"Vez do Jogador "<<comeca<<endl<<"Aperte '1' para ver sua mao:";
		cin>>botao;
	
		if(botao == 1){
			if(comeca==1){
				mao(&jg1);
				if(jogaPeca(1,&jg1,&lado1,&lado2,&lado3,&lado4) == 1){
					comeca++;
				}
				if(jg1.super.vazio()){
					atencao = 1;
				}
			}else{
				if(comeca == 2){
					mao(&jg2);
					if(jogaPeca(2,&jg2,&lado1,&lado2,&lado3,&lado4) == 1){
						comeca++;
					}
					if(jg2.super.vazio()){
						atencao = 2;
					}
				}else{
					if(comeca == 3){
						mao(&jg3);
						if(jogaPeca(3,&jg3,&lado1,&lado2,&lado3,&lado4) == 1){
							comeca++;
						}
						if(jg3.super.vazio()){
							atencao = 3;
						}
					}else{
						mao(&jg4);
						if(jogaPeca(4,&jg4,&lado1,&lado2,&lado3,&lado4) == 1){
							comeca = 1;
						}
						if(jg4.super.vazio()){
							atencao = 4;
						}
					}
				}
			}
		}else{
			cout<<"ERRO"<<endl;
		}

		cout<<"--------------PUNTUACAO PARCIAL---------------"<<endl;
		cout<<"           ********Dupla 1********"<<endl;
		cout<<"              Pontos jogador 1: "<<jg1.pts<<endl;
		cout<<"              Pontos jogador 3: "<<jg3.pts<<endl;
		cout<<"              Total: "<<jg1.pts + jg3.pts<<endl<<endl;
		cout<<"           ********Dupla 2********"<<endl;
		cout<<"              Pontos jogador 2: "<<jg2.pts<<endl;
		cout<<"              Pontos jogador 4: "<<jg4.pts<<endl;
		cout<<"              Total: "<<jg2.pts + jg4.pts<<endl;
			

		mesa(&lado1,&lado2,&lado3,&lado4);
	}

	if(atencao == 1){
		cout<<"JOGADOR 1 BATEU!!!!!!!!!"<<endl;
		cout<<"VITORIA DA DUPLA 1!!!!!!!!!"<<endl;
	}
	if(atencao == 2){
		cout<<"JOGADOR 2 BATEU!!!!!!!!!"<<endl;
		cout<<"VITORIA DA DUPLA 2!!!!!!!!!"<<endl;
	}
	if(atencao == 3){
		cout<<"JOGADOR 3 BATEU!!!!!!!!!"<<endl;
		cout<<"VITORIA DA DUPLA 1!!!!!!!!!"<<endl;
	}
	if(atencao == 4){
		cout<<"JOGADOR 4 BATEU!!!!!!!!!"<<endl;
		cout<<"VITORIA DA DUPLA 2!!!!!!!!!"<<endl;
	}
	
	cout<<"--------------PUNTUACAO FINAL---------------"<<endl;
	cout<<"           ********Dupla 1********"<<endl;
	cout<<"              Pontos jogador 1: "<<jg1.pts<<endl;
	cout<<"              Pontos jogador 3: "<<jg3.pts<<endl;
	cout<<"              Total: "<<jg1.pts + jg3.pts<<endl<<endl;
	cout<<"           ********Dupla 2********"<<endl;
	cout<<"              Pontos jogador 2: "<<jg2.pts<<endl;
	cout<<"              Pontos jogador 4: "<<jg4.pts<<endl;
	cout<<"              Total: "<<jg2.pts + jg4.pts<<endl;
			
}

void iniciaJogo(){
	Jogadores jg1,jg2,jg3,jg4;	
	
	Peca vet[29];//observe********************************* pode ser 28
	int cont=0,rd,valido=0,primeirojogar=0;
	preenchePecas(vet);
	while(cont<28){
		while(valido == 0){
			rd = rand()%28;
			cout<<"rd:"<<rd<<endl;
			if(vet[rd].super != 100){
				
				if(cont>=0 && cont<7){
					jg1.super.push(vet[rd].super);jg1.infer.push(vet[rd].infer);
					cout<<"jg 1: "<<jg1.super.top()<<" "<<jg1.infer.top()<<endl;
					if(rd == 27){primeirojogar = 1;}
				}
				if(cont>=7 && cont<14){
					jg2.super.push(vet[rd].super);jg2.infer.push(vet[rd].infer);
					cout<<"jg 2: "<<jg2.super.top()<<" "<<jg2.infer.top()<<endl;
					if(rd == 27){primeirojogar = 2;}
				}
				if(cont>=14 && cont<21){
					jg3.super.push(vet[rd].super);jg3.infer.push(vet[rd].infer);					
					cout<<"jg 3: "<<jg3.super.top()<<" "<<jg3.infer.top()<<endl;
					if(rd == 27){primeirojogar = 3;}
				}
				if(cont>=21 && cont<28){
					jg4.super.push(vet[rd].super);jg4.infer.push(vet[rd].infer);					
					cout<<"jg 4: "<<jg4.super.top()<<" "<<jg4.infer.top()<<endl;
					if(rd == 27){primeirojogar = 4;}
				}
				vet[rd].super = 100;
				valido = 1;
			}else{
				valido = 0;
			}
		}
		valido=0;
		cont++;
	}
	//inicializa numero de pecas
	jg1.nPeca = jg2.nPeca = jg3.nPeca = jg4.nPeca = 7;
	//inicializa pontos
	jg1.pts = jg2.pts = jg3.pts = jg4.pts = 0;

	cout<<"***************DOMINO AMAZONENSE**************"<<endl<<endl;
	cout<<"AS PECAS JA FORAM EMBARALHADAS E DISTRIBUIDAS"<<endl<<endl;
	if(primeirojogar == 1){
		jogaOrd(1,jg1,jg2,jg3,jg4);
	}else{
		if(primeirojogar == 2){
			jogaOrd(2,jg1,jg2,jg3,jg4);
		}else{
			if(primeirojogar = 3){
				jogaOrd(3,jg1,jg2,jg3,jg4);
			}else{
				if(primeirojogar == 4){
					jogaOrd(4,jg1,jg2,jg3,jg4);
				}	
			}
		}
	}
}

int main(){
	iniciaJogo();
	cout<<"Etapa :Mislestone 1:"<<endl;
	cout<<"Concluido!!!!!!!!!"<<endl;
}
