# Finanças Pessoais


## **Ferramentas**

Esse projeto utiliza as seguintes linguagem, ferramentas e bibliotecas:

* Linguagem: [C++11](https://cplusplus.com/doc/)
* Compilação: [Make](https://www.gnu.org/software/make/)
* Documentação: [Doxygen](https://doxygen.nl/)
* Testes Unitários: [Doctest](https://github.com/doctest/doctest)
* Cobertura: [gcovr](https://gcovr.com/)

## **Compilação**

```bash
$ make
```

## **Execução**

```bash
$ make run
```

## **Compilação Testes**

```bash
$ make tests
```

## **Execução Testes**

```bash
$ make run_tests
```

## **Relatório de Cobertura**

Para imprimir o relatório simplificado no próprio Terminal, utilizar:
```bash
$ make coverage
```

Para gerar o relatório em HTML, utilizar:
```bash
$ make html_coverage
```

## **Documentação**

É necessário ter na raiz do projeto um arquivo _Doxyfile_. Um arquivo padrão pode ser gerado pelo comando:
```bash
$ doxygen -g
```

Para gerar a documentação, utilizar:

```bash
$ doxygen Doxyfile
```
ou
```bash
$ make doc
```

## **Remover arquivos auxiliares**
```bash
$ make clean
```