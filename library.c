#include <stdio.h>
#include <string.h>
typedef struct{
  int dia, mes, ano, id;
  int ddev, mdev, adev;
}emprestimo;

typedef struct{
	char titulo[100];
	char autor[100];
	char state;
	int id;
	emprestimo livro; //Dados sobre emprestimos//
	
}livros;

typedef struct{
  char nome[100];
  int dia,mes,ano;
  char state;
  
}clientes;


int addLivro(livros bib[],int n){
	printf("Digite o titulo do livro: \n");
	gets(bib[n].titulo);
	__fpurge(stdin);
	printf("Digite o nome do autor: \n");
	gets(bib[n].autor);
	__fpurge(stdin);
	bib[n].state = '1';
	bib[n].id = n;
	bib[n].livro.id = -1;
	n ++;
	return n;
}
void delLivro(livros bib[],int n){
  bib[n].state = '0';
}
int compara(char frase[], char palavra[]){ //Func p/ comparar 
  int i=0,aux=0;
  while(frase[i] != '\0'){
    if (frase[i] == palavra[aux]){
      aux ++;
      if(aux == strlen(palavra)){
        return 1;
      }
    }
    else{
      aux = 0;
    }
    i ++;
  }
  return 0;
}

int findLivro(livros bib[5],char palavra[]){ //Muda tamanho do vetor depois bib[] <- 
  int i;
  for (i=0;i<5; i++){
    if (compara(bib[i].titulo,palavra)){
      printf("%d ", i);
    }
  }
}

void emprestaLivro(livros bib[], int n, int id) {
  printf("Dia do emprestimo:\n");
  scanf("%d",&bib[n].livro.dia);
  __fpurge(stdin);
  printf("Mes atual:\n");
  scanf("%d", &bib[n].livro.mes);
  __fpurge(stdin);
  printf("Ano atual:\n");
  scanf("%d",&bib[n].livro.ano);
  __fpurge(stdin);
  bib[n].livro.ddev = bib[n].livro.dia + 4;
  bib[n].livro.mdev = bib[n].livro.mes;
  bib[n].livro.adev = bib[n].livro.ano;
  if (bib[n].livro.ddev > 30){
    bib[n].livro.mdev ++;
    bib[n].livro.ddev = bib[n].livro.ddev - 30;
    if (bib[n].livro.mdev > 12){
      bib[n].livro.mdev = 1;
      bib[n].livro.adev ++;
    }
  }
  bib[n].livro.id = id;
  printf("O livro deve ser devolvido\n");
  printf("ate %d/%d/%d \n",bib[n].livro.ddev,bib[n].livro.mdev,bib[n].livro.adev);
}
void devolveLivro(livros bib[], int n){
  bib[n].livro.id = -1;
}

int addCliente(clientes c[],int n){
  printf("Digite seu nome:\n");
  gets(c[n].nome);
  __fpurge(stdin);
  printf("Dia de nascimento: \n");
  scanf("%d",&c[n].dia);
  __fpurge(stdin);
  printf("Mes de nascimento: \n");
  scanf("%d",&c[n].mes);
  __fpurge(stdin);
  printf("Ano de nascimento: \n");
  scanf("%d",&c[n].ano);
  __fpurge(stdin);
  c[n].state = '1';
  n ++;
  return n;
}

void delCliente(clientes c[],int n){
  c[n].state = '0';
}

int findCliente(clientes c[5],char palavra[]){ //Muda tamanho do vetor depois c[] <- 
  int i;
  for (i=0;i<5; i++){
    if (compara(c[i].nome,palavra)){
      printf("%d ", i);
    }
  }
}


main(){
	livros x[5]; //Tamanho desse vetor tem q ser o msm na func findLivro //
	clientes y[5];
	int i = 0;
	while (i<2){
	i = addLivro(x,i);
	i --;
	i = addCliente(y,i);
}

printf("%s %s %c \n",x[0].titulo,x[0].autor,x[0].state);
printf("%s %s %c \n",x[1].titulo,x[1].autor,x[1].state);

printf("%s %d %c \n",y[0].nome,y[0].dia,y[0].state);
printf("%s %d %c \n",y[1].nome,y[1].dia,y[1].state);


findCliente(y,"Bernardo");

}
