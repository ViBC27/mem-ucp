## Identificação

* Página do repositório do trabalho (https://github.com/ViBC27/ucp-mem)

* Discente 1
	* Nome: Vitor Barcelos de Cerqueira
	* Matrícula: 18110271 
	* Distribuição da nota (%): 33.50
* Discente 2
	* Nome: José Rubens da Silva Brito
	* Matrícula: 18110471
	* Distribuição da nota (%): 33.00
* Discente 3
	* Nome: Ramon Basto Callado Lima Lopes
	* Matrícula: 18110502
	* Distribuição da nota (%): 33.50		
	
## Resultados

Gráficos com os resultados das medições das seguintes métricas utilizadas para avaliar o comportamento do **processo filho**:

**UCP(%)**:

![Uso intenso da UCP](https://github.com/ViBC27/ucp-mem/blob/master/src/cpu.jpeg)
	
**UCP-MEM(kB)**: 

![Uso intenso da UCP](https://github.com/ViBC27/ucp-mem/blob/master/src/cpu-mem.jpeg) 

## Discussão

### Utilização de bibliotecas e funções

A biblioteca string.h foi utilizada para a declaração de strings com o intuito de armazenar os comandos a serem executados no terminal. A função strcmp foi utilizada para verificar se as entradas digitadas pelo usuário são válidas.

A biblioteca stdio.h foi empregada para a utilização da função sprintf que tem a mesma funcionalidade da função printf, mas a saída após a execução é colocada em uma variável. A vantagem dessa função é poder formatar uma string. Além disso, foi usada a função printf para mostrar as mensagens “Error!, Sucess! e Invalid command!”.

A biblioteca stdlib.h foi usada para manipular a função system que executa um comando específico no terminal. Com isso, ela foi aplicada para  executar o comando solicitado pelo o usuário. Esses, podem ser:  (./bin ucp ou ./bin ucp-mem). Ainda nessa função utilizamos o comando que denominamos como kill_command para finalizar a execução do processo. Essa biblioteca também é responsável pela função malloc que aloca espaço para um bloco de bytes consecutivos na memória RAM do computador.  O número de bytes é especificado no argumento da função.

Após as declarações das bibliotecas, realizamos a utilização de algumas funções e variáveis que são essenciais para a desenvoltura do código. Ao inciar o código realizamos a declaração de uma variável do tipo pid_t, esse tipo de variável armazena os ID’s do processo pai e do filho criado pela função fork. A Função fork foi de grande importância para o trabalho, pois foi através dela que conseguimos criar uma cópia do processo pai, que é denominado como processo filho e aloca espaço da memória separadamente para realizar a execução desse novo processo. Pode-se notar que trata de dois processos distintos no momento que solicitamos o ID de cada um. A função fork tem retorno inteiro (< 0 , 0, > 0)  e dependendo dele, o código irá realizar processos distintos.  

Outra função que auxiliou na manipulação do código foi a clock. A função clock contribui para realizar mensuração do uso da UCP e da UCP-MEM a cada 1 segundo durante um total de 10 segundos (como o solicitado), sem realizar a “interrupção” dos processos. 


### Utilização intensa da UCP

O gráfico de utilização intensa da UCP traz de maneira clara o resultado obtido no comando ./bin ucp, possuindo uma curva de acordo com o esperado, visto que, durante os 10 segundos (período que foi realizado o monitoramento), a UCP estava demonstrando total intensidade durante a execução do comando, apresentando poucas variações durante o processo.

Uma UCP quando está em funcionamento ocioso ou com tarefas leves em execução, o seu desempenho gira em torna de 10% à 20% em um ou até mesmo em dois núcleos de maneira simultânea (levando em consideração uma máquina com quatro núcleos), para assim ocorrer um bom desempenho da tarefa sem causar uma sobrecarga em um dos núcleos. E, conseguimos monitorar os núcleos através do Monitor de Sistemas do Linux que a mesma situação ocorria quando a UCP estava sendo utilizada intensamente pelo comando ./bin ucp, apenas dois dos quatro núcleos chegavam a se sobrecarregar em 100%, enquanto que, os outros dois trabalhavam abaixo de 50%. Por meio desse acompanhamento da UCP, conseguimos também chegar na conclusão que, mesmo que a Unidade Central de Processamento receba uma “ordem” de utilização intensa ela não prioriza apenas a tarefa que está sendo executada, como também, deixa de “reserva” dois núcleos para não causar uma paralisação geral no sistema operacional do usuário.

### Utilização intensa da UCP e memória

O gráfico da utilização intensa da UCP – MEM mostra os resultados obtidos pelo comando (./bin ucp-mem). Através dele foi possível realizar sucessivas alocações na memória e usar a UCP de modo intenso. Durante os dez segundos, a memória RAM (física) recebeu toda a alocação de memória feita no código e ao extrapolar seu limite essa sobrecarga é transferida para a memória SWAP (virtual). Quando essas duas memórias estão completamente sobrecarregadas o sistema operacional trava por completo retornado apenas momentos depois do processo ser finalizado. Isso geralmente ocorre quando o valor alocado na memória é maior que a memória disponível.

Enquanto que a UCP está em utilização intensa junto a MEM seu comportamento é o semelhante em relação a sua utilização intensa sem haver alocação de memória. Ao realizarmos o monitoramento da memória (física e virtual) podemos observar que sua taxa de variação por segundo é muito pequena ou quase nula (levando em consideração o seu modo ocioso), porém as variações se mantêm entre 20% e 30% em ambas, considerando um computador de 4Gb de RAM. 

O código fonte criado (./bin ucp-mem) e o gráfico obtido nesse trabalho prático foram essenciais para demonstrar o quanto é perigoso trabalhar com UCP e MEM em utilização máxima (independente de suas configurações de Hardware) , pois há o risco de superaquecimento (mais comum), danificação do hardware (Memória e/ou Unidade Central de Processamento, por exemplo).

