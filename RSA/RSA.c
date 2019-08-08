#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "linkedList/linkedList.h"
#include "useful/useful.h"

void fillUp(long long int *arrayList, int size, int count, node *list, int aux)
{
	if(count == size || list == NULL)
		return;
	arrayList[count] = list->item*arrayList[count-1]+aux;
	fillUp(arrayList, size, count+1, list->next, arrayList[count-1]);
}

int expModular(long long int n, long long int e, int M, node *list)
{	
	int size = 0;
	long long int mod = e%(n-1);
	long long int Mp = pow(M, mod);
	printf("%lld %lld\n", Mp, mod);
	printf("opa2\n");
	list = mdcAux(list, Mp, n, &size);
	printf("opa3\n");
	showList(list);
	long long int arrayList[size];
	arrayList[0] = list->item;
	fillUp(arrayList, size, 1, list->next, 1);
	long long int s = arrayList[size-2];
	if(size%2 == 0)
		s *= -1;
	return s;
}

void generateKey()
{
	FILE *file = fopen("publicKey.txt", "w");
	char pChar[19], qChar[19], eChar[19], nChar[19];

	printf("Insira os números primos p e q da chave pública: ");
	scanf(" %[^ ]", pChar);
	scanf(" %[^\n]", qChar);

	long long int p = atoi(pChar), q = atoi(qChar), e;

	if(isPrime(p, 2) && isPrime(q, 2))
	{
		sprintf(nChar, "%lld", p*q);

		printf("Insira um expoente e relativamente primo a (p-1)(q-1): ");
		scanf(" %[^\n]", eChar);

		e = atoi(eChar);

		if(mdcEuclides(((p-1)*(q-1)), e) == 1)
			fprintf(file, "%s %s", nChar, eChar);
		else
			printf("O expoente e não é relativamente primo a (p-1)(q-1)!\n");
		fclose(file);
	}
	else
		printf("Algum dos números não é primo!\n");
}

void cryptText()
{
	FILE *dFile = fopen("cryptedFile", "w");
	node *list = NULL;
	int i = 0;
	char msg[1000], nChar[19], eChar[19];

	printf("Digite a mensagem que deseja encriptografar:\n");
	scanf(" %[^\n]", msg);

	printf("Digite a chave pública que foi recebida previamente:\n");
	scanf(" %[^ ]", nChar);
	scanf(" %[^\n]", eChar);

	long long int n = atoi(nChar), e = atoi(eChar);
	

	while(msg[i++] != '\0')
	{
		printf("opa\n");
		int aux = msg[i]-97;
		if(aux < 0) aux = 26;
		int result = expModular(n, e, aux, list);
		//fprintf(dFile, "%c", result);
	}
}

int main()
{
	int check = 1;
	while(check)
	{
		int option;
		printf("[0] Sair.\n[1] Gerar chave pública.\n[2] Criptografar.\n[3] Descriptografar.\n");
		printf("Insira a operação a ser realizada: ");
		scanf("%d", &option);
		if(option == 0)
			check = 0;
		else if(option == 1)
			generateKey();
		else if(option == 2)
			cryptText();
		else if(option == 3)
		{

		}
		else
			printf("Opção inválida!");
	}
	return 0;
}