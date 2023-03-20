#include <iostream>
#include "simd.h"
#include "Cripto.h"
using namespace std;

int main() {
	char ch;/*varíavel utilizada para leitura dos caracteres especiais na entrada de dados*/
	int val1, val2, val3, val4, val5, val6, val7, val8, oper1em32, oper2em32, somaem32, multem32; /*variáveis utilizadas para guardar a entrada de dados e o retorno de algumas funções ao redor do programa*/

	cin >> ch >> val1 >> ch >> val2 >> ch >> val3 >> ch >> val4 >> ch; 
	cin >> ch >> val5 >> ch >> val6 >> ch >> val7 >> ch >> val8 >> ch; /*entrada de dados obedecendo o exemplo dado pelo professor*/
	cout << endl;
	oper1em32 = armazenar(val1, val2, val3, val4);/*chama a função armazenar com os 4 valores de 8 bits*/
	cout << "Operandos em 32 bits = " << oper1em32 << endl; /*imprime o retorno da função armazenas com um número inteiro de 32 bits*/
	primeiro(oper1em32);/*retornando os 8 primeiros bits da vaiável selecionada*/
	segundo(oper1em32);/*retornando os 8 segundos bits da vaiável selecionada*/
	terceiro(oper1em32);/*retornando os 8 terceiros bits da vaiável selecionada*/
	quarto(oper1em32);/*retornando os 8 quartos bits da vaiável selecionada*/
	oper2em32 = armazenar(val5, val6, val7, val8);/*chama a função armazenar com os 4 primeiros valores de 8 bits*/
	cout << "Operandos em 32 bits = " << oper2em32 << endl;
	primeiro(oper2em32);
	segundo(oper2em32);
	terceiro(oper2em32);
	quarto(oper2em32);
	somaem32 = soma(oper1em32, oper2em32);/*Soma das duas variáveis do tipo inteiro*/
	cout << endl;
	cout << "Soma em 32 bits = " << somaem32 << endl;/*impressão das somas*/
	multem32 = mult(oper1em32, oper2em32);/*Mulriplicaão das duas variáveis de 32 bits*/
	cout << "Mult em 32 bits = " << multem32 << endl;/*impressão da multiplicações*/
	cout << endl;
	cout << "[";
	cout.width(3);
	cout.fill('0');/*configurãção feita para obedecer a impressão requisitada pelo professor*/
	cout << soma(primeiro(oper1em32),primeiro(oper2em32));/*soma dos dois primeiros valores inteiros inseridos*/
	cout << ",";
	cout.width(3);
	cout.fill('0');
	cout << soma(segundo(oper1em32), segundo(oper2em32));/*soma dos dois segundos valores inteiros inseridos*/
	cout << ",";
	cout.width(3);
	cout.fill('0');
	cout << soma(terceiro(oper1em32), terceiro(oper2em32));/*soma dos dois terceiros valores inteiros inseridos*/
	cout << ",";
	cout.width(3);
	cout.fill('0');
	cout << soma(quarto(oper1em32), quarto(oper2em32)) << "] = Somas" << endl;/*soma dos dois quartos valores inteiros inseridos*/
	cout << "[";
	cout.width(3);
	cout.fill('0');
	cout << mult(primeiro(oper1em32), primeiro(oper2em32));/*multiplicação dos dois primeiros valores inteiros inseridos*/
	cout << ",";
	cout.width(3);
	cout.fill('0');
	cout << mult(segundo(oper1em32), segundo(oper2em32));/*multiplicação dos dois segundos valores inteiros inseridos*/
	cout << ",";
	cout.width(3);
	cout.fill('0');
	cout << mult(terceiro(oper1em32), terceiro(oper2em32));/*multiplicação dos dois terceiros valores inteiros inseridos*/
	cout << ",";
	cout.width(3);
	cout.fill('0');
	cout << mult(quarto(oper1em32), quarto(oper2em32)) << "] = Multiplicações" << endl;/*multiplicação dos dois quartos valores inteiros inseridos*/
	cout << endl;
	unsigned long long soma64 = codificar(somaem32);/*chama e recebe a função da codificação o valor da soma das duas variáveis do tipo inteiro*/
	cout << "Soma Cripto 64 bits = " << soma64 << endl;
	unsigned long long mult64 = codificar(multem32);/*chama e recebe a função da codificação o valor da multiplicação das duas variáveis do tipo inteiro*/
	cout << "Mult Cripto 64 bits = " << mult64 << endl;

	unsigned int ultimos32soma = soma64 >> 32;  /*recupreando o valor da soma de maneira criptografada*/
	unsigned int primeiros32soma = (soma64 << 32) >> 32; /*recuperando os valores gerados de maneira aleatória*/
	unsigned int x1soma = primeiros32soma >> 27;
	unsigned int x2soma = (primeiros32soma << 5) >> 27;
	unsigned int x3soma = (primeiros32soma << 10) >> 27;
	unsigned int x4soma = (primeiros32soma << 15) >> 27;
	unsigned int x5soma = (primeiros32soma << 20) >> 27;
	unsigned int x6soma = (primeiros32soma << 25) >> 27;
	cout << endl;
	cout << "Valor Codificado = " << ultimos32soma << "(" << x1soma<< " " << x2soma << " " << x3soma << " " << x4soma<< " " << x5soma << " " << x6soma << ")" << endl; /*imprimindo o valor da soma criptografada e os valores aleatórios gerados*/
	unsigned int somadecodificada = decodificar(soma64);/*chamando e recebendo a função de descriptografia para a soma*/
	cout << "Soma Decodificada = " << somadecodificada << endl;
	cout << endl;

	unsigned int ultimos32mult = mult64 >> 32; /*recuperando o valor da multiplicação criptografada*/
	unsigned int primeiros32mult = (mult64 << 32) >> 32; /*recuperando os valores gerados de maneira aleatória*/
	unsigned int x1mult = (primeiros32mult >> 27);
	unsigned int x2mult = (primeiros32mult << 5) >> 27;
	unsigned int x3mult = (primeiros32mult << 10) >> 27;
	unsigned int x4mult = (primeiros32mult << 15) >> 27;
	unsigned int x5mult = (primeiros32mult << 20) >> 27;
	unsigned int x6mult = (primeiros32mult << 25) >> 27;

	cout << "Valor Codificado = " << ultimos32mult << "(" << x1mult << " " << x2mult << " " << x3mult << " " << x4mult << " " << x5mult << " " << x6mult << ")" << endl; /*imprimindo o valor da multiplicação criptografada e os valores aleatórios gerados*/
	unsigned int multdecodificada = decodificar(mult64);/*chamando e recebendo a função de descriptografia para a multiplicação*/
	cout << "Mult Decodificada = " << multdecodificada << endl;
}
