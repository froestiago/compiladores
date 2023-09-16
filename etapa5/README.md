# 👁👄👁
- todos as variáveis são **int** ou seja, todas as variáveis terão tamanho 4bytes, isso facilitara o calculo dos deslocamentos
- não precisa implementar chamada de função
- professor falou que todas as entradas estarão corretas, então não precisamos das verificaçøes de erro.
# to-do
## campos
- [x] uma struct chamada *instrução* que contem quatro campos (quatro strings) uma contendo a operação a ser executada e as outras três contendo os operandos
- [x] uma struct chamada *código* que contem dois campos
	- [x] "instrução" (do tipo instrução descrita acima) para armazenar a instrução RI daquele nodo
	- [x] "próxima instrução" (do tipo código) que apontara para a próxima instrução (assim nosso código sera uma lista simplesmente encadeada)
- [x] na struct ValorLexico, *que é um campo da struct Nodo*, teremos um novo campo chamado "codigo" (do tipo código, descrito acima) que armazenara o código daquele nodo
- [x] ainda na struct ValorLexico é necessário dois novos campos, deslocamento e temporario.
- [x] na struct "List" teremos um novo campo chamado "endereço atual"
	- ainda não investiguei a fundo esse campo mas acredito que seja um endereço base para calcular o deslocamento das variaveis daquele escopo
	- já temos um campo chamado index, que indica o index daquela lista, seria interessante usarmos esse index para não ficar tão similar ao trabalho referencia

## variáveis globais
- [x] uma para especificar o tamanho máximo da string do nome de uma instrução
	- hardcode(parameter_x[16];) na struct Instruction
- [x] uma para especificar o tamanho máximo da string do nome de um operando
	- hardcode(oper[16];) na struct Instruction
- [ ] NOME_REGISTRADOR_GLOBAL "rbss" (?)
- [ ] NOME_REGISTRADOR_LOCAL "rfp" (?)
- [ ] podemos pensar em adicionar uma variavel global para ser a lista total de instruções
## funções
isso aqui vai ser só uma leitura e descrição das funções novas encontradas no trabalho referencia. podemos modificar algumas para deixar do nosso jeit.
a ideia é verificar quais funcionalidades elas exercem.
- ### funções para criação de funções
	- *perceber o **tipo** de cada parâmetro em cada função*
	
	- [ ] Instrucao\* criaInstrucaoAritmeticaLogica (char \*operacao, int operando1, int operando2, int operando3)
		- char \*operacao -> soma, multiplicação, etc
		- pelo que entendi o parametro *oprecao* é uma string equivalente a instrução do ILOC
		- exemplo -> criaInstrucaoAritmeticaLogica("div",\$1->info->temporario,\$3->info->temporario,\$$->info->temporario)
	- [ ] Instrucao\* criaInstrucao_loadI (char \*operando1, int operando2)
		- consultar documentação ILOC para saber o que loadI faz
		- dentro da função passa "loadI" direto como para o campo intrucao->operacao
		- strcpy(instrucao->operacao, "loadI"); //refencia a linha acima
		- **só possui 2 operandos** (dentro da função *strcpy(instrucao->operando3, "");*)
	- [ ] Instrucao\* criaInstrucao_loadAI (int operando1, char \*operando2, int operando3)
		- o que faz loadAI?
		- idea parecida com **criaInstrucao_loadI**
		- passa *loadAI* direto como operando
		- essa contem três operandos
	- [ ] Instrucao\* criaInstrucao_storeAI (int operando1, char \*operando2, int operando3)
		- o que faz *storeAI*?
		- mesma ideia das anteriores...

- [ ] void insereInstrucao(Codigo \*\*inicio_codigo, Instrucao \*instrucao)
	- pelo que entendi insere uma instrução a lista encadeada
- [ ] void atualizaNomeRegistrador(Lista_tabelas \*lista_tabelas, char \*registrador)
- [ ] void imprimeInstrucaoPadrao (Instrucao \*instrucao)
- [ ] void imprimeInstrucoesNodo(Nodo \*nodo)
	- imprime o que esta no campo nodo->valor_lexico->codigo
- [ ] Codigo* concatenaCodigo (Codigo \*codigo1, Codigo \*codigo2)
	- essa é uma função que percorre a lista encadeada de Codigo (pelo campo proxima_instrução) e vai concatenando os códigos
- [ ] int achaDeslocamento(Lista_tabelas \*lista_tabelas, char \*valor_token)
- [ ] int achaEscopo(Lista_tabelas \*lista_tabelas, char \*valor_token)
- [ ] void atualizaRegistradorEscopo(Lista_tabelas \*lista_tabelas, char \*registrador_escopo, char \*valor_token)
- [ ] void atualizaRegistradorGeral(char \*str, int N)