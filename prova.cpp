#include <stdio.h>
#include <stdlib.h>

typedef struct nodoN{
	int data;
	struct nodoN *esq;
	struct nodoN *dir;	
}nodo;

int maior_valor(nodo *raiz){
	
	if(raiz!=NULL)
	{
		if(raiz->dir!=NULL)
		{
			if(raiz->dir->data>raiz->data)
			{
				return maior_valor(raiz->dir);
			}
		}
		else if(raiz->esq!=NULL)
		{
			if(raiz->esq->data>raiz->data)
			{
				return	maior_valor(raiz->esq);
				
			}
		}
		
		return raiz->data;
	
	}
	
	
}

	/*
        	40   	
		20       50   
	15     25  45   60    
						70 
	*/
int est_binaria(nodo *raiz){
	
	if(raiz==NULL)
		return 1;
	
	if((raiz->esq!=NULL)&&(raiz->dir!=NULL)){
		int i=est_binaria(raiz->esq);   					
		int j=est_binaria(raiz->dir);
		return j*i*1;
	}else if((raiz->dir!=NULL)||(raiz->dir!=NULL))
		return 0;
	
	
		

			
}

int altura(nodo * raiz){
	if(raiz ==NULL)
		return 0;
	
	int esq = altura(raiz->esq);          
	int dir = altura(raiz->dir);   
	    
	if (esq>dir)
		return esq+1;
	else
		return dir+1;	
}

void pre_ordem(nodo *raiz){
	if(raiz==NULL) return;
	
	printf("%d, ", raiz->data);		
	pre_ordem(raiz->esq);  
	pre_ordem(raiz->dir);

}

void pos_ordem(nodo *raiz){
	if(raiz==NULL) return;
	
	pre_ordem(raiz->esq);  
	pre_ordem(raiz->dir);
	printf("%d, ", raiz->data);		

}
void in_ordem(nodo *raiz){
	if(raiz==NULL) return;
	
	pre_ordem(raiz->esq);  
	printf("%d, ", raiz->data);		
	pre_ordem(raiz->dir);
	
}

void insercao(nodo **root, int v){
	nodo *ptr=*root;
	if(ptr==NULL){
		nodo *n = (nodo *)malloc(sizeof(nodo));
		n->data = v;
		n->dir = n->esq = NULL;
		*root = n;
	}else{
		if(ptr->data <v )
			insercao(&ptr->dir,v) ;
		else
			insercao(&ptr->esq, v);
	}
}

int main(){
	nodo *iArvore= NULL;
	
	insercao(&iArvore, 40);

	

	


	pre_ordem(iArvore);
	printf("\n\nAltura: %d", 	altura(iArvore));
	printf("\n\nEstritamente Binaria %d", 	est_binaria(iArvore));
	printf("\n\n %d", 	maior_valor(iArvore));

	return 0;
}
