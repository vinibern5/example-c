#include <stdio.h>
#include <string.h>

typedef struct{
	char titulo[100];
	char autor[100];
	char state;
	int id;
	
	
}livros;

int addLivro(livros bib[5],int n){
	printf("Digite o titulo do livro: \n");
	gets(bib[n].titulo);
	fflush(stdin);
	printf("Digite o nome do autor: \n");
	gets(bib[n].autor);
	fflush(stdin);
	bib[n].state = '1';
	bib[n].id = n;
	n ++;
	return n;
}
int delLivro(livros bib[5],int n){
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

}
