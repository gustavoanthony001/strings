#include <Arduino.h>

void textoTipoC();
void textoTipoString();

void setup()
{
  Serial.begin(9600);
  Serial.println();
  textoTipoC();
  textoTipoString();
}

void loop()
{
}

void textoTipoC()
{
  // texto literal
  // use const char* quando o texto não será alterado
  const char *cidade = "Sao Paulo";
  const char outraCidade[] = "Sao Caetano";

  Serial.println(cidade);
  Serial.println(outraCidade);

  // descobrindo o tamanho do texto
  // strlen conta quantos caracteres vem antes do '/0'
  int tamanhoCidade = strlen(cidade);
  int tamanhoOutraCidade = strlen(outraCidade);

  Serial.print("comprimento do texto em caracteres: ");
  Serial.println(outraCidade);

  Serial.print("tamanho do conteudo do ponteiro: ");
  Serial.println(cidade);

  // descobrindo o tamanho ocupado

  int tamanhoVar = sizeof(outraCidade);
  int tamanhoPonteiro = sizeof(cidade);

  // quando usa o sizeof em uma string sempre retornará um
  // byte a mais que a quantidade de caracteres por causa do
  //'/0' que finaliza do texto
  Serial.print("tamanho da variavel em bytes: ");
  Serial.println(tamanhoVar);

  // quando usamos o sizeof em ponteiros retorna sempre 4byets
  // pois o conteudo dele é um endereço de memoria como 0xFF00C245
  Serial.print("tamanho do ponteiro: ");
  Serial.println(tamanhoPonteiro);

  // o caractere '/0' é colocado automatimente quando escrevemos
  // um texto entre aspas duplas
  const char vetorTexto[10] = 
  {
      'G',
      'u',
      's',
      't',
      'a',
      'v',
      'o',
  };
  Serial.print(vetorTexto);

  const char *cidade1 = "porto Alegre";
  const char *cidade2 = "Porto Alegre";


  if (strcmp(cidade1, cidade2) == 0)
    Serial.println("As Strings são iguais");

  else
    Serial.println("As Strings são diferentes");

  // strcmp analize a ordem léxica das palavras, se a primeira palavra vem antes da segunda o valor retornado será menor que 0
  // se a primeira palavra vem após a segunda o retorno será maior que 0.

  //*=======================
  //*TEXTO EDITÁVEL COM CHAR
  //*=======================

  char nomeAluno[7] = "Thiagp";

  nomeAluno[5] = 'o';

  Serial.println(nomeAluno);

  // copiando outro texto para dentro do vetor
  //! Cuidado: o vetor precisa ter espaço o suficiente

  strcpy(nomeAluno, "Tadeu");
  Serial.println(nomeAluno);

  // concatenado texto ao final
  char frase[40] = "ola ";
  strcat(frase, "Mundo cruel!");
  Serial.print(frase);

  // procurando um caractere no texto

  char *posicaoLetra = strchr(frase, 'M');
  if (posicaoLetra != NULL)
  {
    Serial.println("Letra encontrada");
    Serial.print(posicaoLetra);
  }
  else
  {
    Serial.println("letra não encontrada");
  }

  // convertendo texto numerico para inteiro
  char idadeTexto[] = "39";
  int idade = atoi(idadeTexto);

  // montando texto
  char buffer[100];
  char *local = "sala de aula";
  float temperatura = 26.4;
  int umidade = 72;

  snprintf(buffer, sizeof(buffer), "%s | Temp: %f C | Umid: %d %% \n", local, temperatura, umidade);

  Serial.print(buffer);

  // sniprintf monta o texto dentro de um vetor de char
  // isso e muito util quando depois voce quer:
  //  - enviar por MQTT
  //  - salvar e variavel
  //  - mandar para o display
  // imprimir na serial

  // ESPECIFICADORES

  //%d ou %i  -int
  //%u        -unsigned int
  //%ld       -long
  //%lu       -unsigned long
  //%f        -float
  //%e        -notacao cientifica
  //%g        -float em formato amis curto
  //%c        -char
  //%s          -char*
  //%x ou %X    -hexadecimal maiusculo ou minusculo
  //%o          -octal
  //%p          -ponteiro
  //%%          -o proprio %

  // Flags, largura e precisao

  //%5d         -imprime com largura minima de 5, alinhado ou a direita
  //%-2d        -imprime com largura minima de 2, alinhado ou a esquerda
  //%04d        -complata com zeros
  //%+d         -mostra sempre o sinal da operacao
  //%.2f        -2 casas decimais
  //%4.2f       -largura de 4 com 2 casas
  //%02X        -Hexadecimal com 2 digitos
  //%#x         -prefixo 0x
  //%.3s        -so os primeiros 3 caracteres da string
  //%*d         -largura passada" como argumento
  //%
}

void textoTipoString()
{
  String nome = " Gustavo Anthony";
  String curso = "Lógica de programação";
  String mensagem = "Ola";

  mensagem = mensagem + "," + nome + "! Bem vindo ao curso de " + curso + ".";

  Serial.println(mensagem);
  
  //* Tamanho da String
  int tamanhoMensagem = mensagem.length();
  Serial.printf("Tamanho da String em letra: %u\n\r", tamanhoMensagem);

  //* Acessando um caractere em uma posição especifica
  char primeiraLetra = mensagem.charAt(0);
  Serial.printf("Primeira letra : %c\n\r", primeiraLetra);

  //* Tambem é possivel acessar com colchetes 
  char ultimaLetra =  mensagem[tamanhoMensagem - 1];
  Serial.printf("Ultima letra: %c\n\r", ultimaLetra);

  //* Procurando um texto dentro da String
  int posicaoTextoProcurado = mensagem.indexOf("curso");
  Serial.printf("A palavra procurada está na posição: %d\n\r", posicaoTextoProcurado);

  int inicioNomeCurso = posicaoTextoProcurado + 9; //*posição da palavra curso + 9 posições a frente

  String nomeDoCursoDoTexto = mensagem.substring(inicioNomeCurso, tamanhoMensagem - 1);
  Serial.printf("Nome do curso: %s\n\r", nomeDoCursoDoTexto.c_str());

  //* Substituindo um trexo dentro da String
  mensagem.replace("Ola, ", "Boa Tarde! ");
  Serial.println(mensagem);
  
  //* Convertendo tudo em maiusculas
  mensagem.toUpperCase();
  Serial.println(mensagem);

  //*convertendo tudo em minúsculas
  mensagem.toLowerCase();
  Serial.println(mensagem);

  //* Verificando se uma string esta vazia
  String textoVazio = "";
  if(textoVazio.length() == 0) Serial.println("O texto está vazio");

  //* Convertendo texto numérico para inteiro
  String textoNumero = "725";
  int numero = textoNumero.toInt();
  Serial.println(numero / 5);

  //* Convertendo String para const char* (texto tipo c)
  //* Isso é útil quando alguma biblioteca espera texto estilo C
  const char* textoComoChar = mensagem.c_str();
  Serial.println(textoComoChar);
}