#include <stdio.h>

typedef struct{
	int dia,mes,ano;
}tData;
typedef struct{
	char nome[40];
	tData dataCadastro;
	int qtdEstoque;
	float valorUnitario;
}tProd;
int val=0;

void cadastra(tProd p[]){
	printf("Cadastro de produto\n");
	printf("Nome:");
	fflush(stdin);
	gets(p[val].nome);
	printf("Data do Cadastro: dia/mes/ano:");
	scanf("%d",&p[val].dataCadastro.dia);scanf("%d",&p[val].dataCadastro.mes);scanf("%d",&p[val].dataCadastro.ano);
	printf("Quantidade no Estoque:");
	scanf("%d",&p[val].qtdEstoque);
	printf("Valor Unitario:");
	scanf("%f",&p[val].valorUnitario);
	val++;
}
void lista(tProd p[]){
	int i;
		for(i=0;i<val;i++){
		printf("Produtos %d\n",i+1);
		printf("Nome:%s\n",p[i].nome);
		printf("Data do Cadastro :%d/%d/%d\n",p[i].dataCadastro.dia,p[i].dataCadastro.mes,p[i].dataCadastro.ano);
		printf("Quantidade em estoque:%d\n",p[i].qtdEstoque);
		printf("Valor Unitario:R$%.2f\n\n",p[i].valorUnitario); 	      
	}
}
void realizaVenda(tProd p[],char nomeBusca []){

int i,num,num2,existe=0;
	for(i=0;i<val;i++){
		if(strcmp (p[i].nome,nomeBusca)==0){
			
				printf("Lista de produtos encontrados %d\n",i+1);
				printf("Nome:%s\n",p[i].nome);
				printf("Data de Cadastro :%d/%d/%d\n",p[i].dataCadastro.dia,p[i].dataCadastro.mes,p[i].dataCadastro.ano);
				printf("Quantidade em estoque:%d\n",p[i].qtdEstoque);
				printf("Valor Unitario:R$%.2f\n\n",p[i].valorUnitario); 
				existe=1;
				break;
			}
		
		}
	if(existe==0){
	printf("Produto solicitado nao existe");
				}
		printf("\nInforme quantas unidade foram vendidas (remover quantidade)");
		scanf("%d",&num);
		
		num2=p[i].qtdEstoque-num;
		
		if(num2<0){
				printf("\nEstoque nao pode ser negativo (menor que 0)");
		}
		else{
			p[i].qtdEstoque=num2;
			printf("\nNova quantidade em estoque %d",p[i].qtdEstoque);
		}
		
}

void adicionaEstoque(tProd p[],char nomeBusca []){
int i,num,num2,existe=0;
	for(i=0;i<val;i++){
		if(strcmp (p[i].nome,nomeBusca)==0){
			
					printf("Produtos %d\n",i+1);
				printf("Nome:%s\n",p[i].nome);
				printf("Data de Cadastro :%d/%d/%d\n",p[i].dataCadastro.dia,p[i].dataCadastro.mes,p[i].dataCadastro.ano);
				printf("Quantidade em estoque:%d\n",p[i].qtdEstoque);
				printf("Valor Unitario:R$%.2f\n\n",p[i].valorUnitario); 
				existe=1;
				break;
			}
		
		}
	if(existe==0){
	printf("Produto solicitado nao existe");
		}
		printf("\nInforme a quantidade de entrada (adicionar quantidade)?");
		scanf("%d",&num);
		
		num2=p[i].qtdEstoque+num;
			p[i].qtdEstoque=num2;
			printf("\nNova quantidade em estoque %d",p[i].qtdEstoque);
		

}
void produtosAno(tProd p[]){
	int i, anoB;
			printf("Informe o ano: ");
			scanf("%d",&anoB);
			for(i=0; i<val;i++){
			 if(p[i].dataCadastro.ano >= anoB){
			printf("Produtos %d\n",i+1);
			printf("Nome:%s\n",p[i].nome);
			printf("Data de Cadastro :%d/%d/%d\n",p[i].dataCadastro.dia,p[i].dataCadastro.mes,p[i].dataCadastro.ano);
			printf("Quantidade em estoque:%d\n",p[i].qtdEstoque);
			printf("Valor Unitario:R$%.2f\n\n",p[i].valorUnitario);
				}
			}

}
void buscar(tProd p[],char nomeBusca []){
	int i,existe=0;
	for(i=0;i<val;i++){
		if(strcmp (p[i].nome,nomeBusca)==0){
			
				printf("Produtos %d\n",i+1);
				printf("Nome:%s\n",p[i].nome);
				printf("Data de Cadastro :%d/%d/%d\n",p[i].dataCadastro.dia,p[i].dataCadastro.mes,p[i].dataCadastro.ano);
				printf("Quantidade em estoque:%d\n",p[i].qtdEstoque);
				printf("Valor Unitario:R$%.2f\n\n",p[i].valorUnitario); 
				existe=1;
				break;
		}
		
	}
	if(existe==0)
	printf("Produto solicitado nao existe");
	
}

void valotTotalEstoque(tProd p[]){
	int i;
	float soma = 0;
		for(i=0;i<val;i++){
			    soma = (p[i].qtdEstoque * p[i].valorUnitario)+soma;
			    
	}
	printf("\nA Quantidade total de estoque:%.2f ",soma);

}
void valcb(tProd p[]){
	int i;
	float caro=0, barato=0;
	caro = (p[i].valorUnitario)*caro;
	barato = (p[i].valorUnitario)*barato;
	
	for(i=0;i<val;i++){
	if(p[i].valorUnitario>caro){
	barato = p[i].valorUnitario;
	} 
	for(i=0;i<val;i++){
	if(p[i].valorUnitario<barato);
	caro = p[i].valorUnitario;
	}
	printf("Valor mais caro: %.2f \n", caro);
	printf("Valor mais barato: %.2f \n", barato);
	}
}

int menu(){
	int opcao;
	printf("-----------------\n1-Cadastrar\n");
	printf("-----------------\n2-Listar\n");
	printf("-----------------\n3-Buscar por nome do produto\n");
	printf("-----------------\n4-Realizar venda\n");
	printf("-----------------\n5-Adicionar quantidade ao estoque\n");
	printf("-----------------\n6-Produtos cadastrados a partir de um ano\n");
	printf("-----------------\n7-Valor total do estoque\n");
	printf("-----------------\n8-Valor mais Caro e mais Barato\n");
	printf("-----------------\n0-Sair\n-----------------");
	scanf("%d",&opcao);
	return opcao;
}
int main(){
	tProd produtos[100];
	char nome[40];
    int opcao;
	tData data;
    do{
    	opcao=menu();
    	switch(opcao){
    		case 1: cadastra(produtos);
    		break;
    		case 2: lista(produtos);
    		break;
    		case 3: 
			printf("\nInforme o nome do Produto:");
    		fflush(stdin);
    		gets(nome);
    		buscar(produtos,nome);
    		break;
    		case 4: 
			printf("\nInforme o nome do Produto:");
			fflush(stdin);
    		gets(nome);
			realizaVenda(produtos,nome);
    		break;
    		case 5: 
			printf("\nInforme o nome do Produto:");
			fflush(stdin);
    		gets(nome);
			adicionaEstoque(produtos,nome);
    		break;
    		
    		case 6: produtosAno(produtos);
			break;
			
			case 7: valotTotalEstoque(produtos);
			break;
			
			case 8: valcb(produtos);
			break;
    		
    		case 0: printf("Aperte enter para fechar o sistema");
    		break;
		}
		getch();
		system("cls");
	}while(opcao!=0);
	return 0;
} //

