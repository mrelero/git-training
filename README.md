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


