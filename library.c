#include <stdio.h>
#include <string.h>
typedef struct{
  int dia, mes, ano;
  int ddev, mdev, adev;
  char status;
}emprestimo;

typedef struct{
  char titulo[100];
  char autor[100];
  char state;
  int id;
  char editora[20];
  int year;
  int ed;
  char area[20];
  emprestimo livro; //Dados sobre emprestimos//

}livros;

typedef struct{
  char nome[100];
  int dia,mes,ano,id;
  char state;
  char endereco[40];
  char telefone[15];


}clientes;


int addLivro(livros bib[],int n){
  printf("Digite o titulo do livro: \n");
  gets(bib[n].titulo);
  fflush(stdin);
  printf("Digite o nome do autor: \n");
  gets(bib[n].autor);
  fflush(stdin);
  printf("Digite o nome da editora: \n");
  gets(bib[n].editora);
  fflush(stdin);
  printf("Digite a area do livro: \n");
  gets(bib[n].area);
  fflush(stdin);
  printf("Digite o ano do livro: \n");
  scanf("%d",&bib[n].year);
  fflush(stdin);
  printf("Digite a edicao do livro: \n");
  scanf("%d",&bib[n].ed);
  fflush(stdin);
  bib[n].state = '1';
  bib[n].id = n;
  bib[n].livro.status = '1';
  n ++;
  return n;
}
int delLivro(livros bib[]){
  int n;
  printf("Digite o id do livro que deseja excluir: \n");
  scanf("%d",&n);
  fflush(stdin);
  bib[n].state = '0';
  return n;
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

int findLivro(livros bib[20]){ //Muda tamanho do vetor depois bib[] <-
  int i;
  char palavra[20];
  printf("Digite a palavra-chave da pesquisa\n");
  gets(palavra);
  fflush(stdin);
  for (i=0;i<20; i++){ //Muda tamanho aqui tbm bib[]
    if (compara(bib[i].titulo,palavra)){
      return i;
    }
  }
  return -1;
}

void emprestaLivro(livros bib[]) {
  int n;
  printf("Digite o id do livro: \n");
  scanf("%d",&n);
  fflush(stdin);
  printf("Dia do emprestimo:\n");
  scanf("%d",&bib[n].livro.dia);
  fflush(stdin);
  printf("Mes atual:\n");
  scanf("%d", &bib[n].livro.mes);
  fflush(stdin);
  printf("Ano atual:\n");
  scanf("%d",&bib[n].livro.ano);
  fflush(stdin);
  bib[n].livro.status = '0';
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
  printf("O livro deve ser devolvido\n");
  printf("ate %d/%d/%d \n",bib[n].livro.ddev,bib[n].livro.mdev,bib[n].livro.adev);
}
void devolveLivro(livros bib[]){
  int n;
  printf("Digite o id do livro que deseja devolver\n");
  scanf("%d",&n);
  bib[n].livro.status = '1';
}

int addCliente(clientes c[],int n){
  printf("Digite seu nome:\n");
  gets(c[n].nome);
  fflush(stdin);
  printf("Dia de nascimento: \n");
  scanf("%d",&c[n].dia);
  fflush(stdin);
  printf("Mes de nascimento: \n");
  scanf("%d",&c[n].mes);
  fflush(stdin);
  printf("Ano de nascimento: \n");
  scanf("%d",&c[n].ano);
  fflush(stdin);
  printf("Digite seu endereco\n");
  gets(c[n].endereco);
  fflush(stdin);
  printf("Digite o seu telefone\n");
  gets(c[n].telefone);
  fflush(stdin);
  c[n].state = '1';
  c[n].id = n;
  n ++;
  return n;
}

void delCliente(clientes c[]){
  int n;
  printf("Digite o id do cliente que deseja excluir\n");
  scanf("%d",&n);
  fflush(stdin);
  c[n].state = '0';
}

int findCliente(clientes c[20]){ //Muda tamanho do vetor depois c[] <-
  char palavra[20];
  printf("Digite a palavra-chave da busca: \n");
  gets(palavra);
  fflush(stdin);
  int i;
  for (i=0;i<20; i++){
    if (compara(c[i].nome,palavra)){
      return i;
    }
  }
  return -1;
}

int mostraLivros(livros bib[],int contl){
  int i;
  for(i=0;i<contl;i++){
    if(bib[i].state == '1'){
      printf("ID: %d Nome: %s \n",bib[i].id,bib[i].titulo);
    }
  }
}

int mostraLivrosEmp(livros bib[],int demp){
  int i;
  for(i=0;i<demp;i++){
    if(bib[i].state == '1' && bib[i].livro.status == '1')
    {
      printf("ID: %d Nome: %s \n",bib[i].id,bib[i].titulo);
    }
  }
}
int mostraLivrosEmprestados(livros bib[],int emp){
  int i;
  for(i=0;i<emp;i++){
    if(bib[i].state == '1' && bib[i].livro.status == '0')
    {
      printf("ID: %d Nome: %s \n",bib[i].id,bib[i].titulo);
    }
  }
}

int mostraCliente(clientes c[],int contc){
  int i;
  for(i=0;i<contc;i++){
    if(c[i].state == '1'){
      printf("ID: %d Nome: %s \n",c[i].id,c[i].nome);
    }
  }
}



main(){ //Na hora dos arquivos else p/ contl contc //
  livros x[20]; //Tamanho desse vetor tem q ser o msm na func findLivro //
  clientes y[20];//Msm da findCliente
  int contc=0, contl=0,clivro=0,ccont=0, opc, achado,achadoc, demp=0, emp=0, i; //contc = contador de clientes ~~ contl = contador de livros
  FILE *fp;

  fp=fopen("biblioteca.bin","rb");
  if(fp != NULL){
    fread(&contl, sizeof(int),1,fp);
    fread(&contc, sizeof(int),1,fp);
    fread(&demp, sizeof(int),1,fp);
    fread(&emp, sizeof(int),1,fp);
	  
    for(i=0;i<contl;i++){
      fread(&x[i],sizeof(livros),1,fp);
    }
    for(i=0;i<contc;i++){
      fread(&y[i],sizeof(clientes),1,fp);
    }
  }

  for(i=0;i<contl;i++){
    x[i].id = i;
  }

  for(i=0;i<contc;i++){
    y[i].id = i;
  }
  clivro = contl;
  ccont = contc;
  fclose(fp);


  while(1){
    system("cls");
    printf("Cardapio: \n");
    printf("1: Adicionar Livro \n2: Excluir Livro \n3: Procurar Livro\n4: Emprestar Livro \n5: Devolver Livro \n");
    printf("6: Inserir Cliente \n7: Excluir Cliente \n8: Procurar Cliente\n9: Sair\n");
    scanf("%d",&opc);
    fflush(stdin);
    if(opc == 9){
        break;
    }
    switch(opc){
      case 1:
        system("cls");
        clivro = addLivro(x,clivro);
        contl ++;
        demp ++;
        break;
      case 2:
	system("cls");
        if(contl > 0){
          printf("Os livros disponiveis sao: \n");
          mostraLivros(x,clivro);
          if(x[delLivro(x)].livro.status == '0'){
            emp --;
          }
          contl --;
          demp --;
          }
        else{
          printf("Nao ha livros disponiveis. \n");
       }
        break;
      case 3:
        system("cls");
        if(contl > 0){
          achado = findLivro(x);
          if (achado >= 0){
            printf("Livro achado! Informacoes do livro:\n");
            printf("Nome do livro: %s \nAutor: %s \nID: %d \n",x[achado].titulo,x[achado].autor,x[achado].id);
          }
          else{
            printf("As palavras-chave nao batem com nenhum livro!\n");
          }
        }
        else{
          printf("Nao ha livros disponiveis para busca.\n");
        }
        break;
      case 4:
        system("cls");
        if(demp > 0){
          printf("Livros disponiveis pra emprestimo: \n");
          mostraLivrosEmp(x,clivro);
          emprestaLivro(x);
          demp --;
          emp ++;
        }
        else{
          printf("A biblioteca nao possui livros disponiveis para emprestimo. \n");
        }
        break;
      case 5:
        system("cls");
        if(emp>0 && contl>0){
          printf("Livros emprestados: \n");
          mostraLivrosEmprestados(x,clivro);
          devolveLivro(x);
          emp --;
          demp ++;
        }
        else{
          printf("Nao ha livros emprestados. \n");
        }
        break;
      case 6:
        system("cls");
        ccont = addCliente(y,ccont);
        contc++;

        break;
      case 7:
        system("cls");
        if(contc>0){
          printf("Lista de clientes disponiveis\n");
          mostraCliente(y,ccont);
          delCliente(y);
          contc --;
        }
        else{
          printf("Nao ha clientes disponiveis\n");
        }
        break;
      case 8:
        system("cls");
        if(contc > 0){
            achadoc = findCliente(y);
            if (achadoc >= 0){
              printf("Cliente achado! Informacoes do cliente:\n");
              printf("Nome do cliente: %s\nID: %d \n",y[achadoc].nome,y[achadoc].id);
            }
            else{
              printf("As palavras-chave nao batem com nenhum cliente!\n");
            }
          }
          else{
            printf("Nao ha clientes disponiveis para busca.\n");
          }
          break;
      default:
        printf("Opcao invalida.\n");


    }

  }
  //contl > contc > livros > clientes


  fopen("biblioteca.bin","wb");
  fwrite(&contl, sizeof(int),1,fp);
  fwrite(&contc, sizeof(int),1,fp);
  fwrite(&demp, sizeof(int),1,fp);
  fwrite(&emp, sizeof(int),1,fp);

  for(i=0;i<clivro;i++){
    if (x[i].state == '1'){
      fwrite(&x[i],sizeof(livros),1,fp);
    }
  }
  for(i=0;i<ccont;i++){
    if(y[i].state == '1'){
      fwrite(&y[i],sizeof(clientes),1,fp);
    }
  }
}
