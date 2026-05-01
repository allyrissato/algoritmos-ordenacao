# 📊 Algoritmos de Ordenação em C

![C](https://img.shields.io/badge/language-C-blue.svg)
![Status](https://img.shields.io/badge/status-completed-green.svg)
![Algorithms](https://img.shields.io/badge/algorithms-sorting-orange.svg)

---

## 📌 Sobre o Projeto

Este projeto implementa e compara algoritmos clássicos de ordenação em linguagem C, analisando seu desempenho com diferentes tipos de entrada de dados.

O objetivo é entender o comportamento prático dos algoritmos e suas diferenças de eficiência em cenários reais.

---

## 🎯 Objetivos

- Implementar algoritmos clássicos de ordenação
- Comparar desempenho em diferentes tipos de dados
- Analisar custo computacional real (comparações, trocas e memória)
- Estudar complexidade em pior, médio e melhor caso

---

## ⚙️ Algoritmos Implementados

- QuickSort  
- MergeSort  
- HeapSort  
- BubbleSort  
- SelectionSort  
- InsertionSort  

---

## 📂 Tipos de Entrada Testados

- Ordem crescente  
- Ordem decrescente  
- Dados aleatórios  
- Padrão côncavo  
- Padrão convexo  

---

## 📈 Métricas Avaliadas

O programa mede automaticamente:

- Número de comparações  
- Número de trocas  
- Número de inserções  
- Profundidade da recursão (QuickSort)  
- Uso de memória (MergeSort)  
- Número de passagens (BubbleSort)  

---

## 🧠 Complexidade dos Algoritmos

| Algoritmo     | Melhor Caso | Caso Médio | Pior Caso |
|---------------|-------------|------------|-----------|
| QuickSort     | O(n log n)  | O(n log n) | O(n²)     |
| MergeSort     | O(n log n)  | O(n log n) | O(n log n)|
| HeapSort      | O(n log n)  | O(n log n) | O(n log n)|
| BubbleSort    | O(n)        | O(n²)      | O(n²)     |
| SelectionSort | O(n²)       | O(n²)      | O(n²)     |
| InsertionSort | O(n)        | O(n²)      | O(n²)     |

---

## 📊 Resultados

O programa gera comparações completas entre os algoritmos, permitindo análise de:

- Eficiência por tipo de entrada
- Custo computacional real
- Impacto da organização dos dados
- Comportamento em diferentes cenários

---

## 🛠️ Tecnologias Utilizadas

- Linguagem C  
- GCC Compiler  
- Manipulação de arquivos  
- Estruturas de dados  
- Alocação dinâmica de memória  

---

## 💼 Aprendizados

Este projeto reforça conhecimentos em:

- Análise de algoritmos  
- Complexidade assintótica (Big-O)  
- Estruturas de dados  
- Programação em C  
- Otimização de código  
- Manipulação de memória  

---

## 👩‍💻 Autor

Alianny Rissato

---

## 🚀 Como Executar

```bash
gcc main.c -o main
./main



