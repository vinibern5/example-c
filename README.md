# example-c
//
#include <stdio.h>

typedef struct{
	char titulo[100];
	char autor[100];
	
	
}livros;

int adiciona(livros bib[5],int n){
	printf("Digite o titulo do livro: \n");
	gets(bib[n].titulo);
	fflush(stdin);
	printf("Digite o nome do autor: \n");
	gets(bib[n].autor);
	fflush(stdin);
	n ++;
	return n;
}

main(){
	livros x[5];
	int y = 0;
	while (y<2){
	y = adiciona(x,y);
}

printf("%s %s \n",x[0].titulo,x[0].autor);
printf("%s %s \n",x[1].titulo,x[1].autor);
}
