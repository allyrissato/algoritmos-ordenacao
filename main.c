#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ARQUIVOS 5
#define NUM_COPIAS 6

#define BOLD "\033[1m"
#define RESET "\033[0m"

// ===================== PROTÓTIPOS =====================
int* lerArquivo(const char* caminho, int* size);
void carregarDados(int*** v, int* tamanho);
int* copiarArray(const int* original, int size);

void verificarAlocacao(void* ptr);
void liberarMemoria(int** vetores, int tamanho);

void printArray(int arr[], int size);
void printNegrito(char* texto);
void printDivisor1();
void printDivisor2();

// Algoritmos
void QuickSort(int* v, int low, int high, int* profundidade, int* trocas, int* comparacoes);
void InsertionSort(int* v, int tam, int* insercoes, int* comparacoes);
void SelectionSort(int* v, int tam, int* trocas, int* comparacoes);
void BubbleSort(int* v, int tam, int* passagens, int* trocas, int* comparacoes);
void PercorreArvore(int* v, int raiz, int fim, int* trocas, int* comparacoes);
void HeapSort(int* v, int tam, int* trocas, int* comparacoes);
void MergeSort(int* v, int inicio, int fim, int* comp, int* mov, int* merges, size_t* mem);

// ===================== UTIL =====================
void verificarAlocacao(void* ptr) {
    if (!ptr) {
        fprintf(stderr, "Erro de alocação de memória\n");
        exit(EXIT_FAILURE);
    }
}

// ===================== LEITURA =====================
int* lerArquivo(const char* caminho, int* size) {
    FILE *file = fopen(caminho, "r");
    if (!file) {
        fprintf(stderr, "Erro ao abrir arquivo: %s\n", caminho);
        return NULL;
    }

    int *v = NULL;
    *size = 0, int num;

    while (fscanf(file, "%d", &num) == 1) {
        int* temp = realloc(v, (*size + 1) * sizeof(int));
        verificarAlocacao(temp);
        v = temp;
        v[*size] = num;
        (*size)++;
    }

    fclose(file);
    return v;
}

int* copiarArray(const int* original, int size) {
    int* copia = malloc(size * sizeof(int));
    verificarAlocacao(copia);
    memcpy(copia, original, size * sizeof(int));
    return copia;
}

// ===================== CARREGAMENTO =====================
void carregarDados(int*** v, int* tamanho) {

    const char* arquivos[NUM_ARQUIVOS] = {
        "DadosAps/1000/SemDuplicidade/Decrescente/dtdecre1kuni0.txt",
        "DadosAps/1000/SemDuplicidade/Aleatorio/dtaleat1kuni0.txt",
        "DadosAps/1000/SemDuplicidade/Crescente/dtcresc1kuni0.txt",
        "DadosAps/1000/SemDuplicidade/ConcavoDecresceCresce/dtconcv1kuni0.txt",
        "DadosAps/1000/SemDuplicidade/ConvexoCresceDecresce/dtconvx1kuni0.txt"
    };

    int tamLocal = 0;
    int* base = lerArquivo(arquivos[0], &tamLocal);
    verificarAlocacao(base);

    *tamanho = tamLocal;

    *v = malloc(NUM_ARQUIVOS * NUM_COPIAS * sizeof(int*));
    verificarAlocacao(*v);

    for (int i = 0; i < NUM_ARQUIVOS; i++) {

        int localTam = 0;
        int* array = lerArquivo(arquivos[i], &localTam);
        verificarAlocacao(array);

        for (int j = 0; j < NUM_COPIAS; j++) {
            (*v)[i * NUM_COPIAS + j] = copiarArray(array, localTam);
        }

        free(array);
    }

    free(base);
}

// ===================== QUICK SORT =====================
void QuickSort(int* v, int low, int high, int* profundidade, int* trocas, int* comparacoes) {
    if (low >= high) return;

    int pivot = v[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        (*comparacoes)++;
        if (v[j] <= pivot) {
            i++;
            int tmp = v[i];
            v[i] = v[j];
            v[j] = tmp;
            (*trocas)++;
        }
    }

    int tmp = v[i + 1];
    v[i + 1] = v[high];
    v[high] = tmp;
    (*trocas)++;

    int p = i + 1;

    int prof = *profundidade + 1;

    QuickSort(v, low, p - 1, &prof, trocas, comparacoes);
    QuickSort(v, p + 1, high, &prof, trocas, comparacoes);

    if (prof > *profundidade)
        *profundidade = prof;
}

// ===================== INSERTION SORT =====================
void InsertionSort(int* v, int tam, int* ins, int* comp) {
    for (int i = 1; i < tam; i++) {
        int chave = v[i];
        int j = i - 1;

        while (j >= 0 && (++(*comp) && v[j] > chave)) {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = chave;
        (*ins)++;
    }
}

// ===================== SELECTION SORT =====================
void SelectionSort(int* v, int tam, int* trocas, int* comp) {
    for (int i = 0; i < tam - 1; i++) {
        int min = i;

        for (int j = i + 1; j < tam; j++) {
            (*comp)++;
            if (v[j] < v[min])
                min = j;
        }

        if (min != i) {
            int tmp = v[i];
            v[i] = v[min];
            v[min] = tmp;
            (*trocas)++;
        }
    }
}

// ===================== BUBBLE SORT =====================
void BubbleSort(int* v, int tam, int* pass, int* trocas, int* comp) {
    int trocou;

    do {
        trocou = 0;
        (*pass)++;

        for (int i = 0; i < tam - 1; i++) {
            (*comp)++;
            if (v[i] > v[i + 1]) {
                int tmp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = tmp;
                (*trocas)++;
                trocou = 1;
            }
        }

        tam--;

    } while (trocou);
}

// ===================== HEAP SORT =====================
void PercorreArvore(int* v, int raiz, int fim, int* trocas, int* comp) {
    while (2 * raiz + 1 <= fim) {
        int filho = 2 * raiz + 1;

        if (filho + 1 <= fim && (++(*comp) && v[filho] < v[filho + 1]))
            filho++;

        if (++(*comp) && v[raiz] < v[filho]) {
            int tmp = v[raiz];
            v[raiz] = v[filho];
            v[filho] = tmp;
            (*trocas)++;
            raiz = filho;
        } else break;
    }
}

void HeapSort(int* v, int tam, int* trocas, int* comp) {
    for (int i = tam / 2 - 1; i >= 0; i--)
        PercorreArvore(v, i, tam - 1, trocas, comp);

    for (int i = tam - 1; i > 0; i--) {
        int tmp = v[0];
        v[0] = v[i];
        v[i] = tmp;
        (*trocas)++;

        PercorreArvore(v, 0, i - 1, trocas, comp);
    }
}

// ===================== MERGE SORT =====================
void MergeSort(int* v, int ini, int fim, int* comp, int* mov, int* merges, size_t* mem) {
    if (ini >= fim) return;

    int meio = (ini + fim) / 2;

    MergeSort(v, ini, meio, comp, mov, merges, mem);
    MergeSort(v, meio + 1, fim, comp, mov, merges, mem);

    int n = fim - ini + 1;
    int* temp = malloc(n * sizeof(int));
    verificarAlocacao(temp);

    *mem += n * sizeof(int);

    int i = ini, j = meio + 1, k = 0;

    while (i <= meio && j <= fim) {
        (*comp)++;
        temp[k++] = (v[i] < v[j]) ? v[i++] : v[j++];
        (*mov)++;
    }

    while (i <= meio) temp[k++] = v[i++], (*mov)++;
    while (j <= fim) temp[k++] = v[j++], (*mov)++;

    for (i = ini, k = 0; i <= fim; i++, k++) {
        v[i] = temp[k];
        (*merges)++;
    }

    free(temp);
}

// ===================== MAIN =====================
int main() {

    int tamanho;
    int** v;

    carregarDados(&v, &tamanho);

    int comp = 0, trocas = 0, prof = 0;

    QuickSort(v[0], 0, tamanho - 1, &prof, &trocas, &comp);

    printf("QuickSort OK\n");

    liberarMemoria(v, NUM_ARQUIVOS * NUM_COPIAS);
    free(v);

    return 0;
}