# git-trainning
Repositório criado para treinar comandos do Git. 

## O que é ?
- Criado por Linus Torvalds em 2005;
- Permite o gerenciamento de versões; 
- Registro de modificações;

## Getting a Repository
Para "baixar" um repositório remoto para o local:
```
$git clone URL
```

Para iniciar um Repositório Local sem o Clone:
```
$git init
$git add ...
```

## Comandos Básicos
Adicionar Arquivos:
```
$git add --all (Adiciona Todos)
$git add *.c (Adiciona Todos os Arquivos .c)
$git add Arquivo.arq (Adiciona um único Arquivo)
```
Salvar mudanças realizadas (Commit):
```
$git commit -m "Mensagem...." (Salva os arquivos Adicionados)
$git commit -a -m "Mensagem...." (Adiciona todos os arquivos e Salva)
```
Subir Mudanças para o Repositório Remoto:
```
$git push -m origin NomedaBranch (Origin significa o Repo Remoto)
$git push --set-upstream origin NomedaBranch (--set-upstream utilizado para rastrear o branch remoto, geralmente é usado pela 1ªvez, depois só usar Push) 
```
Baixar Mudanças do Repositório Remoto:
```
$git pull
```
Buscar tags e branchs remotas, assim como sincronizar mudanças no repositório remoto:
```
$git fetch
```

## Branchs

Lista de todas as Branchs do Repositório:
```
$git branch (A Branch que você está ficara destacada)
```
Criar uma nova Branch
```
$git branch NomeDaBranch
```
Mudar de Branch
```
$git checkout NomeDaBranch
```
Uma forma Automatica de criar e já mudar de Branch
```
$git checkout -b NomeDaNovaBranch (Já cria e da Checkout na nova Branch)
```
Merge entre duas Branchs

>* Suponha que você tem duas Branchs: Main e Feature, e você quer mesclar a feature na Main.
```
$git checkout Main
$git merge Feature
```
>* Suponha que você tem duas Branchs: Main e Feature, e você quer mesclar a Main na Feature.
>> Esta parte é relevante, pois suponha que você esteja trabalhando na Feature, e enquanto isso uma Hotfix foi realizada na Main. Assim, você pode mesclar a Mestre na Feature, para ter uma versão mais atualizada, e quando o Merge da FFeature for realizada na Main, o código vai estar atualizado. 
```
$git checkout Feature
$git merge Main
```

## Rebase
>🚧 Importante! Evitar usar Rebases em Commits que já tenha sido enviados para o repositório remoto. 

O Git Rebase tem como objetivo de reaplicar os commits realizados em outra base. Por exemplo:

- Suponha que você está na Branch Topic. E Ocorreram dois commits 

```
          A---B---C topic
         /
    D---E---F---G master
```
- Caso deseja aplicar os commits F e G ao topic, é possível realizar um Rebase da Branch. 
```
git rebase master
git rebase master topic
```
- O resultado é F e G.
```
                  A'--B'--C' topic
                 /
    D---E---F---G master
```

O Rebase também pode funcionar para editar e manipular commits já ralizados:
```
git rebase -i HEAD~3
```

> No Windows, quando o comando for executado, ira abrir um novo arquivo. Para salvar, deve-se apertar ESC e depois escrever :wq. 

> O número "3" em HEAD~**3**, significa que será buscado 3 Commits desde o último. 

Para editar, existem alguns comandos: 
- Reword: Edita a mensagem do Commit;
- Squash: Combina Commits

## Reflog

O Comando Reflog apresenta de forma detalhada todas as últimas ações executadas. Cada ação tem um Hash que pode ser usado para outras ações de correção de erro. 
```
632744c HEAD@{2}: commit: Oi Mundo em Turco
54d918b (HEAD -> main) HEAD@{3}: commit: Alemao na Main
7bbf312 (origin/main, origin/HEAD) HEAD@{4}: commit: Readme
ce5577e HEAD@{6}: rebase (pick): Novo Update de GIT
5355cec HEAD@{7}: rebase (reword): Atualização do Arquivo README com dados do Rebase.
218429b HEAD@{8}: rebase: fast-forward
468e783 (origin/hotfix-language, hotfix-language) HEAD@{9}: rebase (start): checkout HEAD~3
c13cb85 HEAD@{10}: rebase (abort): updating HEAD
c13cb85 HEAD@{11}: rebase (abort): updating HEAD
c13cb85 HEAD@{12}: rebase (abort): updating HEAD
c13cb85 HEAD@{13}: rebase (abort): updating HEAD
c13cb85 HEAD@{14}: rebase (abort): updating HEAD
c13cb85 HEAD@{15}: rebase (abort): updating HEAD
c13cb85 HEAD@{16}: rebase (abort): updating HEAD
```

Suponha que um commit 632744c tenha sido excluído, e você percebe que foi um erro e decide restaurar. Para isso, pode-se utilizar um truque simples: 
```
git branch correcao-turco 632744c
```
Você cria uma Nova Branch a partir do Hash excluído. Tudo será recuperado. 

Como o Reflog também é possível recuperar branchs excluídas seguidno mesmo processo. 
```
e34dfe9 (HEAD -> main, origin/main, origin/correcao-turco, origin/HEAD, correcao-turco) HEAD@{0}: checkout: moving from nova-feature to main
c0e1e67 (origin/nova-feature) HEAD@{1}: checkout: moving from main to nova-feature
e34dfe9 (HEAD -> main, origin/main, origin/correcao-turco, origin/HEAD, correcao-turco) HEAD@{4}: checkout: moving from main to nova-feature
e34dfe9 (HEAD -> main, origin/main, origin/correcao-turco, origin/HEAD, correcao-turco) HEAD@{5}: merge correcao-turco: Fast-forward
54d918b HEAD@{6}: checkout: moving from correcao-turco to main
e34dfe9 (HEAD -> main, origin/main, origin/correcao-turco, origin/HEAD, correcao-turco) HEAD@{7}: commit: Commit recuperado e Readme Reflog
632744c HEAD@{8}: checkout: moving from main to correcao-turco
```
- e34dfe9: Foi movido da Feature nova-feature para main (No caso, a Branch foi excluída, tanto no local quanto no remoto)

Para recuperar, foi utilizado o comando git branch, e indicando o mesmo nome da branch, e o HASH de quando foi realizado o checkout para a Branch deletada.

```
git branch nova-feature c0e1e67
```

## Submodule
Trabalhar com Submodule pode ajudar a importar bibliotecas e arquivos de outros repositórios. A função é muito simples:

```
git submodule add URL
```
Ao executar o comando, o repositório e seus arquivos são clonados diretamente para o seu repositório. 

>❗️ Importante! Em caso de clonar um repositório que já tenha outros submódulos, as pastas de cada um deles vem vazia. Para isso, alguns comandos de update podem ser utilizados:
```
git submodule update --init --recursive

ou

git clone --recurse-submodules URL
```


### Atualizando Submodulos
É provável que ao utilizar sub-módulos tenha interesse em atualizar os fontes do sub-módulo e ao mesmo tempo puxar atualizações. Vejamos a seguinte situação:

- Atualização do Sub-Módulo(SM) e Depois executar o comando de update:

> Aqui ocorre o seguinte, ao aplicar o comando submodule update, todas as modificações realizadas pelo desenvolvedor no sub-módulo serão perdidas, pois substituirão as modificações.  

Uma forma de contornar essa situação é aplicar o seguinte comando: 

```
git submodule update --remote --merge
```

Ou seja, as atualizações serão mescladas no repositório do projeto. 

>❗️ Atenção! Para que as modificações sejam mescladas, o Sub-Repositório precisa estar em uma branch diferente da **detached HEAD**. Para isso, basta entrar na pasta do sub-repositório e usar o comando ``` git checkout branchname```, comitar as mudanças e depois usar o comando  ```git submodule update --remote --merge``` .


## Sub-tree

Sub-tree é uma estratégia alternativa ao submodule. Para esse caso existem algumas vantagens:
- Gerenciar um fluxo simples;
- Projeto e arquivos disponíveis logo depois de aplicar git clone, sem a necessidade de usar o comando de atualização;
- Usuários não precisam aprender nada novo de git para usar. 

Para usar, basta aplicar o seguinte comando: 
```
git subtree add --prefix {local directory being pulled into} {remote repo URL} {remote branch} --squash
```
>```--squash``` é um comando para suprimir todo o histórico antes do subtree adicionado. 

Para atualizar o fonte da Subtree:

```
git subtree pull --prefix {local directory being pulled into} {remote repo URL} {remote branch} --squash
```
>❗️ Cuidado com os conflitos ao utilizar o pull. 

Para enviar atulizações:
```
git subtree push --prefix {local directory being pulled into} {remote repo URL} {remote branch}
```

Apesar de possuir comandos simples, como pull e push, existem algumas desvantagens de utilizar subtrees:

- A checagem de atualizações não é simples. Ou seja, diferente do Submodule, que ao usar ```git Status``` as modificações ficam mais evidentes; 
- Utilizar subtrees com multiplos sub-repos pode ser um problema. 


## Sub-Repos
De acordo com autor (@ingydotnet) o Sub-Repo é uma melhoria das outras duas alternativas, sub-tree e sub-module. São listados alguns benefícios: 
- Execução por linha de comando simples e intuitivas; 
- Usuarios clonam o repositório e sub-repositórios de forma direta;
- Existe o arquivo .gitrepo para rastreio e identificação;
- Branchs diferentes podem ter diferentes subrepos em diferentes estados;
- ...

Para clonar um subrepo, basta utilizar o comando:

```
git subrepo clone <repository> [<subdir>] [-b <branch>]
```

Obs. Existem outros comandos que podem ser utilizados, como: ```git subrepo clone <repository> [<subdir>] [-b <branch>] [-f] [-m <msg>] [-e] [--method <merge|rebase>]```. 

Também é possível tornar um subdiretório em um subrepo:

```
git subrepo init <subdir> [-r <remote>] [-b <branch>] [--method <merge|rebase>]
```

Para puxar as novas atualizações do repositório remoto:

```
git subrepo pull <subdir>|--all [-M|-R|-f] [-m <msg>] [-e] [-b <branch>] [-r <remote>] [-u]
```

Enviar atualizações:

```
git subrepo push <subdir>|--all [<branch>] [-r <remote>] [-b <branch>] [-M|-R] [-u] [-f] [-s] [-N]
```

Adicionar a branch do subrepo como um único commit na história principal:

```
git subrepo commit <subdir> [<subrepo-ref>] [-m <msg>] [-e] [-f] [-F]
```
>❗️ A função commit não é tão trivial quanto ao modo convencional. Neste caso, a branch do subrepo é adicionado ao fluxo de história principal. Para comitar mudanças, basta utilizar o commit normalmente. 

### Exemplo de Comandos

1. Push (Enviando atualizações para o repositório remoto originário do subrepo)
```
git subrepo clone.....)
git subrepo pull --force repotest 
git commit -a -m "msg"
git subrepo push repotest
```
2. Pull e Merge (Mesclando atualizações próprias do projeto, com desenvolvimento remoto)

Suponha que ao clonar um subrepo par ao seu projeto, você precisa edita-lo para customizar algumas opções. Portanto, é interessante e necessário que atualizações internas e externas(repositório original) sejam mescladas, para não perder ou prejudicar o andamento do projeto. Nesta situação, ao aplicar a função ```pull```, deve-se utilizar a opção ```-M --merge```. 
```
git subrepo pull -M --merge repotest
```
Quando ocorre o Merge, o fluxo é semelhante ao mostrado abaixo:
```
          A---B---C  subrepo
         /         \ (git subrepo pull <subdir> -M --merge)     
    D---E---F---G---H Repositório Remoto
```
>O Repositório Remoto (origem do subrepo) não sofre alteração com o Pull, ou seja

Abaixo um exemplo real retirado de um repositório de teste:

```
*   commit 45b74374d280b7477d92abed199aa8837c4dbd20 (refs/subrepo/repotest/commit, refs/subrepo/repotest/branch, subrepo/repotest)
|\  Merge: cacbb10 b50d992
| | 
| | 
| |
| |     Merge commit 'refs/subrepo/repotest/fetch' into subrepo/repotest
| |
| * commit b50d992cd50a222654d112a74a1dfac2eaf47212 (refs/subrepo/repotest/fetch)
| | 
| | 
| |
| |     fun11
| |
* | commit cacbb106533ebd9aaf555ff8b38bb40ed479ca40
|/  
|   
|
|       
|
* commit b4df05c88ac3ed1cfce563357ddf7aee3129613a
```
O Rebase segue a mesma lógica do convencional. Ao realizar o comando, o fluxo de commits é reposicionado conforme o diagrama abaixo:

                  A'--B'--C' Sub Repo
                 / (git subrepo pull <subdir> --method --rebase)
    D---E---F---G Repositório Remoto

>Sempre importante relembrar que é preciso ter cuidado ao aplicar o Rebase com atualizações já enviadas para o upstream. 


3. Branch Remoto (Puxar e enviar desenvolvimento de Branchs diferentes)

Ao trabalhar com subrepo, pode ser necessário a puxar do repositório remoto, outras branchs da principal. Para isso, basta usar o comando ```-b <branch>``` . 
```
git subrepo pull --force repotest -b NomeDaBranch
git commit -a -m "Atualizações"
git subrepo push repotest
```
O comando push pega a branch do último pull e envia, portanto não é necessário especificar qual branch será enviado o desenvolvimento. Caso seja necessário mudar a branch, basta especificar o nome da branch no push ```-b <branch>```. 



>❗️ Apesar de promissor, o subrepo tem pouco conteúdo e informação na internet.

## Quando usar Merge e Rebase
Suponha que temos a seguinte situação:

```
          A---B---C topic
         /
    D---E---F---G master
```

1) Usando o Merge

Podemos aplicar o Merge do **topic** na **master**, assim ambos os desenvolvimentos serão mesclados. 
```
>>Mergeq
          A---B---C  topic
         /         \     
    D---E---F---G---H master
```
Em H, o projeto irá conter os desenvolvimentos de topic e master mesclados, e em caso de conflitos, os mesmos devem ser resolvidos na hora do merge. No entanto, perceba que os commits A, B e C da Branch **topic** não consideram os commits F e G da **master**, o que pode ser um problema, pois as branchs desincronizada podem ocasionar problemas no funcionamento geral. 

Neste caso, o ideal é realizar testes com os códigos mesclados antes de enviar para a master. Uma estrutura é utilizar o merge em uma branch **dev** intermediária a master, que pode ser utilizada para testes, e manipulações antes de ser mesclada na master. 

```
>>Merge
          A---B---C  topic
         /         \     
    D---E---F---G---H dev
    |   |   |   |    \*Testes
    D---E---F---G-----H  master
```

2) Usando Rebase

Com o Rebase, os commits aplicados na Branch **topic** serão considerados após a o último commit G da master. Este processo "Sincroniza" a branch topic com a master, levando todas as atualizações da branch master para a **topic**. Com isso, é possível realizar o desenvolvimento na branch **topic** considerando todas as atualizações feitas na master, e trabalhar nas possíveis implicações que os commits F e G comprometeriam na branch **topic**.  

```
>>Rebase
                  A'--B'--C' topic
                 /
    D---E---F---G master
```
Depois, o comando merge pode ser aplicado para levar o desenvolvimento da branch **topic** na **master**.
```
>>Merge
                  A'--B'--C' topic
                 /         \
    D---E---F---G-----------H' master
```

Como G = A' e C'=H', o resultado final fica:

```
>>Merge
    D---E---F---G/A'--B'--H'/c' master
```
Dessa forma, a linha do tempo no Git fica mais limpa e clara, considerando apenas os commits essenciais. 

## Referências

https://git-scm.com/docs/git-rebase

https://www.youtube.com/watch?v=RGOj5yH7evk&t=2267s&ab_channel=freeCodeCamp.org

https://www.youtube.com/watch?v=Uszj_k0DGsg&ab_channel=freeCodeCamp.org

https://www.youtube.com/watch?v=qsTthZi23VE&t=903s&ab_channel=freeCodeCamp.org

https://www.treinaweb.com.br/blog/git-merge-e-git-rebase-quando-usa-los

https://gist.github.com/SKempin/b7857a6ff6bddb05717cc17a44091202

https://gist.github.com/SKempin/b7857a6ff6bddb05717cc17a44091202 

https://github.com/ingydotnet/git-subrepo

