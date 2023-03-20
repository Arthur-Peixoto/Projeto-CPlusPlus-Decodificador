
int armazenar(char a, char b, char c, char d) { /*recebe 4 valores do tipo char e retorna um int com os 4 valores agrupados*/
	unsigned int estado = 0;
	char variavel;
	variavel = a;
	estado = estado | (variavel << 24);
	variavel = b;
	estado = estado | (variavel << 16);
	variavel = c;
	estado = estado | (variavel << 8);
	variavel = d;
	estado = variavel | estado;

	return estado;
}
unsigned char primeiro (int a){ /*retornando os 8 primeiros bits da vai�vel selecionada*/
	unsigned char estado;
	estado = (a >> 24);
	return estado;
}

unsigned char segundo(int a) {/*retornando os 8 segundos bits da vai�vel selecionada*/
	unsigned char estado;
	estado = (a >> 16);
	return estado;
}
unsigned char terceiro(int a) { /*retornando os 8 terceiros bits da vai�vel selecionada*/
	unsigned char estado;
	estado = (a >> 8);
	return estado;
}

unsigned char quarto(int a) { /*retornando os 8 �ltimos bits da vai�vel selecionada*/
	unsigned char estado = a;
	return estado;
}

int soma(int a, int b) { /*recebe duas vari�veis int, cada uma � dividida em 4 partes de 8 bits e somadas aos bits respectivos da outra vari�vel*/
	int c, c1;
	char d, e;
	d = (a >> 24);
	e = (b >> 24);
	c = d + e;
	c = (c << 24);
	d = (a >> 16);
	e = (b >> 16);
	c1 = d + e;
	c = c | (c1 << 16);
	d = (a >> 8);
	e = (b >> 8);
	c1 = d + e;
	c = c | (c1 << 8);
	d = a;
	e = b;
	c1 = d + e;
	c = c | c1;
	
	return c;
}

int mult(int a, int b) { /*recebe duas vari�veis int, cada uma � dividida em 4 partes de 8 bits e multiplicadas aos bits respectivos da outra vari�vel*/
	int c, c1;
	char d, e;
	d = (a >> 24);
	e = (b >> 24);
	c = d * e;
	c = (c << 24);
	d = (a >> 16);
	e = (b >> 16);
	c1 = d * e;
	c = c | (c1 << 16);
	d = (a >> 8);
	e = (b >> 8);
	c1 = d * e;
	c = c | (c1 << 8);
	d = a;
	e = b;
	c1 = d * e;
	c = c | c1;

	return c;
}