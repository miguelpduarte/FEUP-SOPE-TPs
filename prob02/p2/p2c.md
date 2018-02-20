Usando um ficheiro de input de 16MB, verifiquei os seguintes tempos:

Os tempos foram medidos usando o comando `time` de bash. O ficheiro de saída já se encontrava criado.

p2a (biblioteca de C):

* Real: 0m0.020s
* User: 0m0.004s
* System: 0m0.016s

p2b (chamadas ao sistema):

* Real: 0m0.074s
* User: 0m0.004s
* System: 0m0.071s

Apesar de parecer contra intuitivo, é verdade que as chamadas ao sistema demoram mais tempo que as funções da biblioteca de C a correr.

Isto ocorre pois as chamadas à biblioteca de C correm dentro do mesmo processo, usando os seus privelégios e memória, sem precisar de considerações de segurança/permissões.

Por outro lado, as *system calls*, por correrem no kernel (e terem, portanto, acesso a tudo do sistema), precisam de verificar o que o processo que as chama está a fazer. Para além disto, as *syscalls* exigem um *"context switch"* no CPU, operação bastante pesada em comparação com apenas chamar uma biblioteca.

Baseado em: https://unix.stackexchange.com/questions/57232/difference-between-system-calls-and-library-functions
