#include "grupo2.h" // header local com todas as bibliotecas
void menu()//fun��o mostra menu
{
	printf("|--------------------------------------------------|\n");
	printf("|========= ENCONTRA A PALAVRA ESCONDIDA ===========|\n");
	printf("|=================== CIDADES ======================|\n");
	printf("|================ 5 TENTATIVAS ====================|\n");
	printf("|--------------------------------------------------|\n");
}
char transformaNome(char* maiusculas) //fun��o para mudar as letras para maiusculas
{
	for (int i = 0; i < strlen(maiusculas); i++) {
		if (maiusculas[i] >= 'a' && maiusculas[i] <= 'z')
			maiusculas[i] = maiusculas[i] - 32;
	}
}
void jogo(char nomeutilizador[]) // fun��o jogo
{
	char arrayCidades[100][20] = { "lisboa","bragan�a","coimbra","santarem","evora", "alcoba�a","aveiro", "fatima", "guimaraes", "portimao",
	"leiria","funchal", "estremoz", "matosinhos", "albufeira", "setubal", "portalegre", "sintra", "barcelos", "mirandela" };
	char palavras2[20];
	char tentaAcertar[20];
	char tentapalavra[20];
	char letrasInseridas[6];
	char letra;
	int num, opcao, tentativas = 0, acertou = 0, nPalavras = 20, tentaOutra = 0;
	int adicionarP = 1;
	//================== INICIO PROGRAMA ============================
	srand(time(NULL));
	//DECIDIR SE O USER QUER MAIS PALAVRAS NO ARRAY
	printf("Quer adicionar quantas palavras? ");
	scanf(" %d", &adicionarP); //recebe numero inteiro para se o utilizador quer adicionar palavras
	printf("===============================\n");
	for (int i = 0; i < adicionarP; i++) // Ciclo for at� ao adicionar palavras(se for 0 da skip neste passo)
	{
		printf("%d Insira a palavra novas: ", i + 1); //insere a palavra, [i+1 � o numero da posi��o FOR]
		scanf(" %s", arrayCidades[nPalavras]); //guarda a palavra no arraycidades[posi��o nPalavras]
		printf("===============================\n");
		nPalavras++;//adiciona +1 ao nPalavras para guardar a palavra na pr�xima posi��o [nPalavras]
	}
	//FIM PALAVRAS DO USER NO ARRAY
	num = rand() % nPalavras; //gera palavra aleatoria com base na variavel nPalavras
	//printf("PALAVRA RANDOM : %s \n", arrayCidades[num]); //para efeitos de teste
	strcpy(palavras2, arrayCidades[num]); //copia a palavra na posi��o [num] para a variavel palavras2
	strcpy(tentapalavra, arrayCidades[num]); //copia a palavra na posi��o [num] para a variavel tentapalavra
	for (int i = 0; i < strlen(tentapalavra); i++) //define os carateres m�ximos da palavra
		tentapalavra[i] = '_'; //mete os underscores do tamanho da palavra
	memset(letrasInseridas, 0, 6); //Limpa os valores da variavel letrasInseridas -> Google
	do //FAZER
	{
		printf("%d� tentativa. \nInsira uma letra: \n->", tentativas + 1);//mostra as tentativas no %d
		scanf(" %c", &letra);//guarda o carat�r na vari�vel letra
		printf("===============================\n");
		if (letra >= 'A' && letra <= 'Z')//se letras maiusculas entre 'A' e 'Z'
			letra = letra + 32;//passa para letras min�sculas
			//===========INICIO LETRAS NO SITIO CERTO====================
		for (int i = 0; i < strlen(palavras2); i++) //ciclo para ver os valores no array da variavel palavras2
			if (letra == palavras2[i]) //se tiver uma letra = � palavra na posi��o [i] do
				tentapalavra[i] = letra; //a variavel tentapalavra [posi��o i] guarda a letra no s�tio certo da palavra
		letrasInseridas[strlen(letrasInseridas)] = letra; //guarda as letras j� escritas na variavel lentrasInserias
		printf("Jogo: %s\n", tentapalavra); // letras corretas e underscores que faltam para adivinhar a palavra
		printf("===============================\n");
		printf("Letras ja inseridas: %s \n", letrasInseridas); //letras ja inseridas
		printf("===============================\n");
		//====================INICIO VERIFICA��O LETRAS==========================
		//VARIAVEL "tentapalavra" tem as letras guardadas na posi��o certa, e o que falta tem underscores
		if (strcmp(tentapalavra, palavras2) == 0) { //se as letras tentadas forem iguais � variavel palavras 2 (palavra escondida) retorna 0
			printf("PARABENS %s GANHOU!!\n", nomeutilizador); //ganhou
			printf("===============================\n");
			acertou = 1; //passa o acertou para 1 (est� a 0 no in�cio das variaveis)
		}
		printf("Quer adivinhar a palavra completa?\n");
		printf("1- Sim | 2 - Nao\n->");
		scanf(" %d", &opcao);//guarda op��o variavel int
		printf("===============================\n");
		//=====================FIM VERIFICA��O LETRAS=========================
		//====================INICIO VERIFICA��O PALAVRA COMPLETA
		if (opcao == 1) {//Se opcao for 1
			printf("Introduza o nome da cidade completo: ");
			scanf(" %s", &tentaAcertar); //guarda string na variavel "tentaAcertar"
			for (int i = 0; i < strlen(tentaAcertar); i++) { //ciclo para ver o tamanho da palavra tentaAcertar
				if (tentaAcertar[i] >= 'A' && tentaAcertar[i] <= 'Z') //se letras maiusculas entre 'A' e 'Z'
					tentaAcertar[i] = tentaAcertar[i] + 32; //passa para letras min�sculas
			}
			printf("%s\n", tentaAcertar); //imprime a variavel tentaAcertar com letras min�sculas
			if (strcmp(tentaAcertar, palavras2) == 0) //se a palavra tentada for igual � variavel palavras 2 (palavra escondida) retorna 0
			{
				printf("PARAB�NS %s GANHOU!!!\n", nomeutilizador); //imprime nome utilizador a dizer que ganhou
				printf("===============================\n");
				acertou = 1; //variavel acertou passa a 1 (esta a 0 na declara��o de vari�veis
			}
			//====================FIM VERIFICA��O PALAVRA COMPLETA
		}
		tentativas++; //conta sempre mais um nas tentativas caso a palavra seja tentada ou uma letra seja inserida
		if (tentativas >= 5 && acertou == 0) //SE tentativas forem maiores ou iguais que 5 (tentativas � iniciada a 1 na declara��o de vari�veis) E a variavel acertou for igual a 0
			printf("%s gastou as 5 tentativas PERDEU...\n", nomeutilizador); //gastou o numero de tentativas e perdeu, imprime nome utilizador
	} while (tentativas < 5 && acertou == 0); //fazer isto tudo enquanto a variavel tentativas forem menores que 5 e a variavel acertou for = 0
	//======================FIM PROGRAMA JOGO==================================
}
void main()
{
	int opcao;
	setlocale(LC_ALL, "Portuguese");
	char nome[30];
	menu();
	printf("Nome do jogador: "); //pede nome utilizador
	scanf("%29[^\n]s", nome); //guarda nome utilizador (array nome tem 30 carat�res dispon�veis, da� o %29 e guarda em nome
	transformaNome(&nome); //chama a fun��o transformaNome(envia o endere�o do nome para a fun��o transformaNome) para mudar as letras para maiusculas
	printf("Vamos come�ar a jogar %s\n", nome); //imprime nome de utilizador
	printf("===============================\n");
	jogo(nome); //chama fun��o jogo e manda para l� o nome j� transformado em MAI�SCULAS
	do
	{
		printf("Quer jogar novamente? 1-Sim | 2-N�o: ");
		scanf(" %d", &opcao); //Guarda numero inteiro
		system("cls");
		if (opcao != 1) //Se op��o for diferente de 1
		{
			printf("===============================\n");
			printf("AT� � PR�XIMA %s\n", nome); //imprime at� � proxima e o nome
			printf("===============================\n");
		}
		else //Se a op��o for igual a 1
		{
			jogo(nome); //chama a fun��o jogo e o jogo recome�a
		}
	} while (opcao == 1); //fazer isto tudo enquanto a op��o for igual a 1
	getch();
}