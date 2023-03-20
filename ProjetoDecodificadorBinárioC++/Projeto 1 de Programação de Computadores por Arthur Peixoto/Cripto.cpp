#include <random>
using namespace std;

unsigned int ligarbit(unsigned int a, int b) /*recebe um valor de 32 bits e retorna o mesmo valor com uma posição ligada*/
{

	unsigned int mascara = 1 << b;

	unsigned int estado = a;
	estado = estado | mascara;
	return estado;
}

unsigned int Desligarbits(unsigned int a, int b) /*recebe um valor de 32 bits e retorna o mesmo valor com uma posição desligada*/
{
	unsigned int mascara = 1 << b;

	unsigned int estado = a;
	estado = estado & ~(mascara);
	return estado;
}


bool Testarbits(unsigned int a, int b)/*verificação para saber se o bit será desligado ou ligado*/
{
	bool controle;
	unsigned int mascara = (1 << b);

	unsigned int estado = a;
	if (estado & mascara)
		controle = true;
	else
		controle = false;

	return controle;
}

unsigned long long codificar(unsigned int a) {
	int P1, P2, P3, P4, P5, P6;/*gerando números aleatórios*/
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(0, 31);
	P1 = dist(mt);
	P2 = dist(mt);
	P3 = dist(mt);
	P4 = dist(mt);
	P5 = dist(mt);
	P6 = dist(mt);

	bool x = (Testarbits(a, P1)); /*criptografando o número da soma,verificando a situação do bits em determinada situação e modificando o valor do seus bits, ligando ou desligando em respectivas posições*/
	if (x == true) {
		a = Desligarbits(a, P1);
	}
	else {
		a = ligarbit(a, P1);
	}
	x = (Testarbits(a, P2));
	if (x == true) {
		a = Desligarbits(a, P2);
	}
	else {
		a = ligarbit(a, P2);
	}
	x = (Testarbits(a, P3));
	if (x == true) {
		a = Desligarbits(a, P3);
	}
	else {
		a = ligarbit(a, P3);
	}
	x = (Testarbits(a, P4));
	if (x == true) {
		a = Desligarbits(a, P4);
	}
	else {
		a = ligarbit(a, P4);
	}
	x = (Testarbits(a, P5));
	if (x == true) {
		a = Desligarbits(a, P5);
	}
	else {
		a = ligarbit(a, P5);
	}
	x = (Testarbits(a, P6));
	if (x == true) {
		a = Desligarbits(a, P6);
	}
	else {
		a = ligarbit(a, P6);
	}
	unsigned long long mascara = 0;/*imprimindo o valor de maneira criptografada com a utilização da máscara com os números gerados aleatoriamente*/
	mascara = mascara | unsigned long long(a) << 32;
	mascara = mascara | unsigned long long(P1) << 27;
	mascara = mascara | unsigned long long(P2) << 22;
	mascara = mascara | unsigned long long(P3) << 17;
	mascara = mascara | unsigned long long(P4) << 12;
	mascara = mascara | unsigned long long(P5) << 7;
	mascara = mascara | unsigned long long(P6) << 2;
	return mascara;

}

unsigned int decodificar(unsigned long long a)
{
	unsigned int ultimos32 = (a >> 32);/*recuperando o valor de maneira descriptografada, pelo passo a passo inverso seguido na criptografado*/
	unsigned int primeiros32 = (a << 32) >> 32;
	unsigned int x1 = (primeiros32 >> 27);
	unsigned int x2 = (primeiros32 << 5) >> 27;
	unsigned int x3 = (primeiros32 << 10) >> 27;
	unsigned int x4 = (primeiros32 << 15) >> 27;
	unsigned int x5 = (primeiros32 << 20) >> 27;
	unsigned int x6 = (primeiros32 << 25) >> 27;
	

	bool x = (Testarbits(ultimos32, x1));/*processo inverso da criptografia, desligando as posições que foram ligadas e ligando as que foram desligadas*/
	if (x == true) {
		ultimos32 = Desligarbits(ultimos32, x1);
	}
	else {
		ultimos32 = ligarbit(ultimos32, x1);
	}
	x = (Testarbits(ultimos32, x2));
	if (x == true) {
		ultimos32 = Desligarbits(ultimos32, x2);
	}
	else {
		ultimos32 = ligarbit(ultimos32, x2);
	}
	x = (Testarbits(ultimos32, x3));
	if (x == true) {
		ultimos32 = Desligarbits(ultimos32, x3);
	}
	else {
		ultimos32 = ligarbit(ultimos32, x3);
	}
	x = (Testarbits(ultimos32, x4));
	if (x == true) {
		ultimos32 = Desligarbits(ultimos32, x4);
	}
	else {
		ultimos32 = ligarbit(ultimos32, x4);	
	}
	x = (Testarbits(ultimos32, x5));
	if (x == true) 
	{
		ultimos32 = Desligarbits(ultimos32, x5);
	}
	else {
		ultimos32 = ligarbit(ultimos32, x5);
	}
	x = (Testarbits(ultimos32, x6));
	if (x == true) {
		ultimos32 = Desligarbits(ultimos32, x6);
	}
	else {
		ultimos32 = ligarbit(ultimos32, x6);
	}
	return ultimos32;/*recupera o valor da soma, pelo processo inverso feito na criptagrafia*/
}

