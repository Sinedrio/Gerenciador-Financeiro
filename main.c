#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Registro {
  int mes;
  int ano;
  float valor;
  float moradia;
  float estudos;
  float trans;
  float ali;
  float poup;
};

struct Registro registro;
float meses_lucro[13];

char meses[12][0xFF] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro","Dezembro"};

//1- Cadastro de Receitas e Gastos
int cadrg(){//Cadastro receita e gasto
  printf("Digite o mês e o ano: ");
  scanf("%d",&registro.mes);
  scanf("%d",&registro.ano);
  printf("Insira o valor depositado: ");
  scanf("%f",&registro.valor);
  printf("gasto com moradia: ");
  scanf("%f",&registro.moradia);
  printf("gasto com estudos: ");
  scanf("%f",&registro.estudos);
  printf("gasto com transporte: ");
  scanf("%f",&registro.trans);
  printf("gasto com alimentação: ");
  scanf("%f",&registro.ali);
  puts("");

 meses_lucro[registro.mes] = registro.valor-(registro.moradia+registro.estudos+registro.trans+registro.ali);
  

  
  FILE *file;
  file=fopen("MYGF/index.html","a");
  
  if (file==NULL){
    printf("O arquivo não existe!");
    getchar();
    exit(0);
  }
  fprintf(file, "DATA: %d/%d\n",registro.mes,registro.ano);
  fprintf(file, "Valor: R$ %.2f\n",registro.valor);
  fprintf(file, "Moraida: R$ %.2f\n",registro.moradia);
  fprintf(file, "Estudos: R$ %.2f\n",registro.estudos);
  fprintf(file, "Transporte: R$ %.2f\n",registro.trans);
  fprintf(file, "Alimentação: R$ %.2f\n",registro.ali);
  fprintf(file, "Lucro do mês: R$ %.2f\n",meses_lucro[registro.mes]);
  fprintf(file,"---------------------------------\n");

  fclose(file);
  return 0;
}

//2-Relatório de Movimentação dos Ultimos 12 Meses
int anual(){//Registro anual dos gastos
  float lucro_anual;
   meses_lucro[registro.mes] = registro.valor-(registro.moradia+registro.estudos+registro.trans+registro.ali);
  for (int i = 1; i <= 12; i++) {
  lucro_anual += meses_lucro[i];
  printf("%s %s\t= R$ %.2f\n",meses[i-1], (i>=3 && i<=8) ? "\t" : ""  ,meses_lucro[i]);
  }

  printf("\nO seu lucro anual foi de: R$ %.2f\n",lucro_anual);
  return 0;
} 

//3-Relatório do ultimo mes
int ultmes(){//Registro anual dos gastos
  meses_lucro[registro.mes] = registro.valor-(registro.moradia+registro.estudos+registro.trans+registro.ali);

  FILE *file;
  file=fopen("MYGF/index.html","a");
  printf("MOVIMENTAÇÃO DO ÚLTIMO MÊS\n");
  puts("");
  printf("DATA: %d/%d\n",registro.mes,registro.ano);
  printf("Valor: R$ %.2f\n",registro.valor);
  printf("Moraida: R$ %.2f\n",registro.moradia);
  printf("Estudos: R$ %.2f\n",registro.estudos);
  printf("Transporte: R$ %.2f\n",registro.trans);
  printf("Alimentação: R$ %.2f\n",registro.ali);
  printf("Lucro do mês: R$ %.2f\n",meses_lucro[registro.mes]);
  fclose(file);
  return 0;
} 

//Investimento poupança
int poupanca(){
  float poup_total;

  printf("Bem vindo a sua poupança! \n");
  printf("---------------------------------\n");  
  
    printf("Digite o mês e o ano: ");
    scanf("%d",&registro.mes);
    scanf("%d",&registro.ano);
    printf("Qual valor deseja depositar? ");
    scanf("%f", &registro.poup);

    if(registro.mes == 1 || registro.mes == 2)
    {
      poup_total = registro.poup * 1.98;
    }
    else if(registro.mes == 3 || registro.mes == 4)
    {
      poup_total = registro.poup * 1.38;
    }
    else if(registro.mes == 5 || registro.mes == 6)
    {
      poup_total = registro.poup * 1.45;
    }
    else if(registro.mes == 7 || registro.mes == 8)
    {
      poup_total = registro.poup * 1.79;
    }
    else if(registro.mes == 9 || registro.mes == 10)
    {
      poup_total = registro.poup * 2.90;
    }
    else if(registro.mes == 11 || registro.mes == 12)
    {
      poup_total = registro.poup * 1.16;
    }
    

    FILE *file;
    file=fopen("MYGF/index.html","a");
    fprintf(file,"---------------------------------\n");
    printf("Valor rendido da poupança do mês: ");
    printf("%.2f\n",poup_total);
    return 0;
}

//chamando o menu de volta
void retorno();

int main(void){

  puts("--------------------------------------------------");
  puts("$$$\\    $$$ |\\$$\\   $$  |   $$  __$$\\ $$  _____| ");
  puts("$$$$\\  $$$$ | \\$$\\ $$  /    $$ /  \\__|$$ |       ");
  puts("$$\\$$\\$$ $$ |  \\$$$$  /     $$ |$$$$\\ $$$$$\\     ");
  puts("$$ \\$$$  $$ |   \\$$  /      $$ |\\_$$ |$$  __|    ");
  puts("$$ |\\$  /$$ |    $$ |       $$ |  $$ |$$ |       ");
  puts("$$ | \\_/ $$ |    $$ |       \\$$$$$$  |$$ |       ");
  puts("\\__|     \\__|    \\__|        \\______/ \\__|       " );
  
  printf("\n");
  puts("Ola, seja bem vindo M.Y.G.F!");
  puts("Seu Gerenciador Financeiro.");
  puts("Aproveite o nosso software!");
  puts("Por favor, escolha uma opção.");
  printf("--------------------------------------------------\n"
  "1-Cadastro de Receitas e Gastos\n"
  "2-Relatório de Movimentação dos Ultimos 12 Meses\n"
  "3-Relatório de Cada Categaoria (último mês)\n"
  "4-Poupança\n"
  "5-Integrantes\n"
  "--------------------------------------------------\n");
  
  int opc;
  printf("Digite a opção escolhida: ");
  scanf("%d",&opc);
  puts("\n");

  switch (opc){
    case 1:
    cadrg();
    
    break;
    case 2:
    anual();
    
    break;
    case 3:
    ultmes();
    break;
    case 4:
    poupanca();
    break;
    case 5:
    puts("Lucas Forge Freo - CEO");
    puts("RA: 22.121.081-8");
    puts("");
    puts("João Lucas Freitas de Almeida Rocha - CTO");
    puts("RA: 22.121.004-0");
    break;
  };
  retorno();
}

//Função de retorno p/ o menu.  
void retorno(){
  int confirm;
  puts("--------------------------------------------------\n");
  printf("Digite 0 para voltar ao menu: ");
  scanf("%d",&confirm);
  puts("");
  if(confirm==0){
    main();
  }
} 