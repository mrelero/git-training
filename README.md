# git-trainning-private
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



## Referências

https://git-scm.com/docs/git-rebase

https://www.youtube.com/watch?v=RGOj5yH7evk&t=2267s&ab_channel=freeCodeCamp.org

https://www.youtube.com/watch?v=Uszj_k0DGsg&ab_channel=freeCodeCamp.org

https://www.youtube.com/watch?v=qsTthZi23VE&t=903s&ab_channel=freeCodeCamp.org
