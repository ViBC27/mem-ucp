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

* TODO: Gráficos com os resultados das medições das seguintes métricas utilizadas para avaliar o comportamento do **processo filho**:
*  **UCP(%)**:

![Uso intenso da UCP](https://github.com/ViBC27/ucp-mem/blob/master/src/cpu.jpeg)
	
*  **UCP-MEM(kB)**: 

![Uso intenso da UCP](https://github.com/ViBC27/ucp-mem/blob/master/src/cpu-mem.jpeg) 

## Discussão

### Utilização intensa da UCP

O gráfico de utilização intensa da UCP traz de maneira clara o resultado obtido no comando ./bin ucp, possuindo uma curva de acordo com o esperado, visto que, durante os 10 segundos (período que foi realizado o monitoramento), a UCP estava demonstrando total intensidade durante a execução do comando, apresentando poucas variações durante o processo.

Uma UCP quando está em funcionamento ocioso ou com tarefas leves em execução, o seu desempenho gira em torna de 10% à 20% em um ou até mesmo em dois núcleos de maneira simultânea (levando em consideração uma máquina com quatro núcleos), para assim ocorrer um bom desempenho da tarefa sem causar uma sobrecarga em um dos núcleos. E, conseguimos monitorar os núcleos através do Monitor de Sistemas do Linux que a mesma situação ocorria quando a UCP estava sendo utilizada intensamente pelo comando ./bin ucp, apenas dois dos quatro núcleos chegavam a se sobrecarregar em 100%, enquanto que, os outros dois trabalhavam abaixo de 50%. Por meio desse acompanhamento da UCP, conseguimos também chegar na conclusão que, mesmo que a Unidade Central de Processamento receba uma “ordem” de utilização intensa ela não prioriza apenas a tarefa que está sendo executada, como também, deixa de “reserva” dois núcleos para não causar uma paralisação geral no sistema operacional do usuário.

### Utilização intensa da UCP e memória

O gráfico da utilização intensa da UCP – MEM mostra os resultados obtidos pelo comando (./bin ucp-mem). Através dele foi possível realizar sucessivas alocações na memória e usar a UCP de modo intenso. Durante os dez segundos, a memória RAM (física) recebeu toda a alocação de memória feita no código e ao extrapolar seu limite essa sobrecarga é transferida para a memória SWAP (virtual). Quando essas duas memórias estão completamente sobrecarregadas o sistema operacional trava por completo retornado apenas momentos depois do processo ser finalizado. Isso geralmente ocorre quando o valor alocado na memória é maior que a memória disponível.

Enquanto que a UCP está em utilização intensa junto a MEM seu comportamento é o semelhante em relação a sua utilização intensa sem haver alocação de memória. Ao realizarmos o monitoramento da memória (física e virtual) podemos observar que sua taxa de variação por segundo é muito pequena ou quase nula (levando em consideração o seu modo ocioso), porém as variações se mantêm entre 20% e 30% em ambas, considerando um computador de 4Gb de RAM. 

O código fonte criado (./bin ucp-mem) e o gráfico obtido nesse trabalho prático foram essenciais para demonstrar o quanto é perigoso trabalhar com UCP e MEM em utilização máxima (independente de suas configurações de Hardware) , pois há o risco de superaquecimento (mais comum), danificação do hardware (Memória e/ou Unidade Central de Processamento, por exemplo).

