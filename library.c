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
int delLivro(livros bib[],int n){
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

main(){
	livros x[5]; //Tamanho desse vetor tem q ser o msm na func findLivro //
	int y = 0;
	while (y<2){
	y = addLivro(x,y);
}

printf("%s %s %c \n",x[0].titulo,x[0].autor,x[0].state);
printf("%s %s %c \n",x[1].titulo,x[1].autor,x[1].state);

findLivro(x,"Teste");
delLivro(x,0);
delLivro(x,1);
printf("%s %s %c \n",x[0].titulo,x[0].autor,x[0].state);
printf("%s %s %c \n",x[1].titulo,x[1].autor,x[1].state);
}
