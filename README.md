# Orion Airlines

Projeto A3 da UC Estrutura de dados e Análise de Algoritmos.

## Tecnologias

* C++ - Linguagem de programação
* FTXUI - Frontend
* SQLITE3 - Banco de dados

## Como compilar

**Instalando as dependências:**

### Linux

```bash
sudo apt install build-essential libssl-dev libfl-dev libsqlite3-dev make cmake
```

### MacOS

```zsh
xcode-select --install
brew install openssh make cmake 
```

**Compilando:**
O executável da aplicação estará disponível no seguinte caminho: ./buid/orion_airlines

```console
make build
```

## Como executar

**Modo manual:**

```console
./build/orion_airlines
```

**Usando o makefile:**

```console
make run
```
