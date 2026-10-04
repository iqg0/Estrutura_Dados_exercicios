typedef struct ponto Ponto;


//Cria um novo ponto
Ponto* pto_cria (float x, float y); // Equivalente ao nosso fopen() (Devolve um ponteiro para p)

//Libera um ponto
void pto_libera (Ponto* p); //Equivalente ao fclose() (Libeira o ponteiro de p/ Libera o ponto) 

//Acessa os valores "x" e "y" de um ponto
void pto_acessa (Ponto *p, float* x, float* y); // Retorna a parte x e y por referencia do nosso ponto

//Atribui os valores "x" e "y" a um ponto
void pto_atribui(Ponto* p, float x, float y); // Pega o valor x e y passa para a nossa funcao e coloca em nosso ponto

//Calcula a distancia entre dois pontos
float pto_distancia (Ponto* p1, Ponto* p2); // Calcula a distancia entre dois pontos