//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "TFuncao.h"
#include "Defines.h"
#include "TVariavel.h"
#include "TEquipamento.h"
#include "TListaDeVariaveis.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

bool __fastcall TFuncao::ParentesesOk(TExpressao* expressao)
{
int i, saldo;
char *dados;

if(!expressao)
 return false;
if(!expressao->Texto.Length())
  return false;
if((dados=(char*)(expressao->Texto.data()))==NULL)
  return false;
saldo=0; // o saldo deve iniciar em zero e terminar assim também.
for(i=0;i<expressao->Texto.Length();i++)
   {
   if(dados[i]=='(')
     saldo ++;
   else
   if(dados[i]==')')
     saldo --;
   if(saldo<0) return false;
   }
if(saldo) return false;
return true; // saldo zero, os parenteses tao todos ok. Vamos processar contas!
}
bool __fastcall TFuncao::FGetValida()
{
// Olha se todas as expressoes da função sao válidas.
int i;
for(i=0;i<Numero;i++)
   if(!EValida(Expressoes[i]))
     return (FValida=false);
return (FValida=true);
}

bool __fastcall TFuncao::EValida(TExpressao* expressao)
{
int i;
int tamanho; // tamanho da expressao a avaliar, em bytes;
char *dados;
if(!expressao)
 return (false); // Não tem expressao, logico que nao é valida!
if(!ParentesesOk(expressao))
  return false;
dados=expressao->Texto.c_str();
tamanho=strlen(dados);
i=0;
if(!isalnum(dados[0]))
  {
  if(dados[0]!='+' && dados[0]!='-')
    if(dados[0]!='(')
      return false;
    else i=0;
  else i=1;
  }
for(;i<tamanho;i++)
   {
   if(IsOperator(dados[i]) && IsOperator(dados[i+1]))
     return false;
   if(i)
     {
     if((IsOperator(dados[i-1]) && IsOperator(dados[i])) ||\
        (IsBadOperator(dados[i]) && dados[i-1] == '(') ||\
        //(dados[i]=='(' && !IsOperator(dados[i-1])) ||
        (dados[i]==')' && IsOperator(dados[i-1])) ||\
        (dados[i]==')' && dados[i-1]=='('))
       return false;
     }
   }
if(IsOperator(dados[tamanho-1]))
  return false;
return true;
}

class TExpressao* __fastcall  TFuncao::GetExpressoes(int Indice)
{
TExpressao *texp;
texp=(TExpressao*)TLista::Objetos[Indice];
return texp;
}

int __fastcall TFuncao::FGetNumeroDeVariaveis(void)
{
if(FVars)
  return FVars->Numero;
return 0;
}

class TVariavel* __fastcall TFuncao::FGetVariaveis(int Indice)
{
if(FVars)
  return FVars->Variaveis[Indice];
return NULL;
}
class TListaDeVariaveis* __fastcall TFuncao::FGetListaDeVariaveis(void)
{
return FVars;
}

void __fastcall TFuncao::Init(void)
{
FValor = 0;
FValida = false;
FAutoCalculo = false;
FVars = new TListaDeVariaveis(this);
FStandAlone = false;
}

__fastcall TFuncao::TFuncao(void): TLista()
{
Init();
}
__fastcall TFuncao::TFuncao(class TObjeto *eDono): TLista(eDono)
{
Init();
}
__fastcall TFuncao::~TFuncao(void)
{
while(Numero)
  delete Remove(0);
SAFEDEL(FVars);
}

class TExpressao* __fastcall TFuncao::Expressao(AnsiString eNome)
{
TExpressao *texp;
texp=Expressoes[Indice(eNome)];
return texp;
}

void __fastcall TFuncao::Adiciona(class TExpressao* eExpressao)
{
double tlim;
bool text;
if(eExpressao->Limites[0]>eExpressao->Limites[1])
  {
  tlim=eExpressao->Limites[0];
  eExpressao->Limites[0]=eExpressao->Limites[1];
  eExpressao->Limites[1]=tlim;
  text=eExpressao->Extremos[0];
  eExpressao->Extremos[0]=eExpressao->Extremos[1];
  eExpressao->Extremos[1]=text;
  }
this->Insere((TObjeto*) eExpressao);
}

bool __fastcall TFuncao::Adiciona(AnsiString nova, double Limites[],\
                                  bool Extremos[])
{
TExpressao *novaexpressao;
int i;
try {
  i=0;
  while(Expressao(AnsiString("Exp")+AnsiString(i)))
       i++;
  novaexpressao=new TExpressao(this);
  novaexpressao->Nome=AnsiString("Exp")+AnsiString(i);
  novaexpressao->Texto=nova;
  if(Limites[0]<Limites[1])
    {
    novaexpressao->Limites[0]=Limites[0];
    novaexpressao->Limites[1]=Limites[1];
    novaexpressao->Extremos[0]=Extremos[0];
    novaexpressao->Extremos[1]=Extremos[1];
    }
  else
    {
    novaexpressao->Limites[1]=Limites[0];
    novaexpressao->Limites[0]=Limites[1];
    novaexpressao->Extremos[1]=Extremos[0];
    novaexpressao->Extremos[0]=Extremos[1];
    }
  this->Insere((TObjeto*)novaexpressao);
  return true;
  } catch (...)
      {
      return false;
      }
}
class TExpressao* __fastcall TFuncao::Remove(int Indice)
{
TExpressao *ret;
ret=Remove(TLista::Nomes[Indice]);
return ret;
}
class TExpressao* __fastcall TFuncao::Remove(AnsiString eNome)
{
TExpressao *ret;
ret=(TExpressao*)TLista::Remove(eNome);
return ret;
}
    // metodo que calcula valor da função, segundo parametros informados.
double __fastcall TFuncao::Calcula(double Parametros[])
{
TExpressao *exp;
int i,j;
// Em Parametros, temos o numero de parametros, mais os parametros. O parametro 1
// é o parametro principal da função, aquele que dita a expressão usada neste
// intervalo.
// A metodologia de solução de uma funcao cpp:
// 1. Descobre a expressao para o dado valor de parametro[1]
if(FVars)
  {
  if(Parametros[0]!=FVars->NumeroDeParametros)
    return 0; // Exception numero de parametros errado.
  for(i=0,j=1;i<FVars->Numero;i++)
     if(FVars->Variaveis[i]->DeEntrada)
       FVars->Variaveis[i]->Valor=Parametros[j++];
  }
else
  if(Parametros[0])
    return 0;
exp=NULL;
if(Numero==1 && !Parametros[0])
  exp=Expressoes[0];
else
for(i=0;i<Numero && !exp;i++)
  {
  if(Expressoes[i]->Extremos[0] && Expressoes[i]->Extremos[1])
    {
    if(Parametros[1]<=Expressoes[i]->Limites[1] &&\
       Parametros[1]>=Expressoes[i]->Limites[0])
      exp=Expressoes[i];
    }
  else
  if(Expressoes[i]->Extremos[0] && !Expressoes[i]->Extremos[1])
    {
    if(Parametros[1]<Expressoes[i]->Limites[1] &&\
       Parametros[1]>=Expressoes[i]->Limites[0])
      exp=Expressoes[i];
    }
  else
  if(!Expressoes[i]->Extremos[0] && Expressoes[i]->Extremos[1])
    {
    if(Parametros[1]<=Expressoes[i]->Limites[1] &&\
       Parametros[1]>Expressoes[i]->Limites[0])
      exp=Expressoes[i];
    }
  else
  if(!Expressoes[i]->Extremos[0] && !Expressoes[i]->Extremos[1])
    {
    if(Parametros[1]<Expressoes[i]->Limites[1] &&\
       Parametros[1]>Expressoes[i]->Limites[0])
      exp=Expressoes[i];
    }
  }
if(exp)
  return Resolve(exp->Texto);
return 0; // Exception Valor fora dos limites definidos para a função.
}

// Calcula uma expressão como gente!
// 1. Converte pra notação posfixa;
// 2. Calcula a expressão.
double __fastcall TFuncao::Resolve(AnsiString expr)
{
TList *saida;
TStack *pilha;
AnsiString *token;
char *dados;
int i,p;
double Ret;
struct COISAS {
unsigned char tipo;  // 0 = número; 1 = operador; 2 = operando; 6 = função
double numero;
AnsiString texto;
};
struct COISAS *coisas;
struct COISAS *op1, *op2;

dados=expr.c_str();
saida=new TList();
pilha=new TStack();
token=new AnsiString();
for(i=0;i<(int)strlen(dados);i++)
   if(dados[i]!=' ')
     *token+=dados[i];
if((dados=(char*)malloc(token->Length()+1))==NULL)
  return 0; // Jogar exception!...
strcpy(dados,token->c_str());
if(dados[0]=='-' || dados[0]=='+')
  {
  coisas=new struct COISAS;
  coisas->tipo=0;
  coisas->numero=0;
  saida->Add(coisas);
  }
  i=0;
while(i<(int)strlen(dados))
  {
  if(isalpha(dados[i]))
    {
    coisas = new struct COISAS;
    coisas->tipo=2;
    token=PegaToken(dados,i);

    if(dados[i]=='(')
      {
      coisas->tipo|=4;
      p=1;
      *token+=dados[i++];
      while(p)
        {
        if(dados[i]=='(')
          p++;
        if(dados[i]==')')
          p--;
        *token+=dados[i++];
        }
      }
    coisas->texto=(*token);
    saida->Add(coisas);
    delete token;
    continue;
    }
  if(isdigit(dados[i]))
    {
    coisas = new struct COISAS;
    coisas->tipo=0;
    coisas->numero=PegaNumero(dados,i);
    saida->Add(coisas);
    continue;
    }
  switch(dados[i])
    {
    case '+':
    case '-':
      if(pilha->Count())
      while(pilha->Count() &&\
            strcmp(((struct COISAS*)pilha->Peek())->texto.c_str(),"("))
          {
          saida->Add(pilha->Pop());
          }
      coisas = new struct COISAS;
      coisas->tipo=1;
      coisas->texto=AnsiString(dados[i]);
      pilha->Push(coisas);
      break;
    case '*':
    case '/':

      while(pilha->Count())
         if(!strcmp(((struct COISAS*)pilha->Peek())->texto.c_str(),"^") ||
            !strcmp(((struct COISAS*)pilha->Peek())->texto.c_str(),"*") ||
            !strcmp(((struct COISAS*)pilha->Peek())->texto.c_str(),"/"))
          saida->Add(pilha->Pop());
         else break;
      coisas = new struct COISAS;
      coisas->tipo=1;
      coisas->texto=AnsiString(dados[i]);
      pilha->Push(coisas);
      break;
    case '^':
      while(pilha->Count())
         if(!strcmp(((struct COISAS*)pilha->Peek())->texto.c_str(),"^"))
          saida->Add(pilha->Pop());
         else break;
      coisas = new struct COISAS;
      coisas->tipo=1;
      coisas->texto=AnsiString(dados[i]);
      pilha->Push(coisas);
      break;
    case '(':
      coisas = new struct COISAS;
      coisas->tipo=1;
      coisas->texto=AnsiString("(");
      pilha->Push(coisas);
      if(dados[i+1]=='-')
        {
        coisas = new struct COISAS;
        coisas->tipo=0;
        coisas->numero=0;
        saida->Add(coisas);
        }
      break;
    case ')':
      while(pilha->Count())
         if(strcmp(((struct COISAS*)pilha->Peek())->texto.c_str(),"("))
           saida->Add(pilha->Pop());
         else break;
      coisas=(struct COISAS*)pilha->Pop();
      delete coisas;
      break;
    }
  i++;
  }
while(pilha->Count())
   saida->Add(pilha->Pop());
// Aqui temos uma expressão na forma pos fixa distribuída na lista "saida".
while(saida->Count)
   {
   coisas=(struct COISAS*)saida->First();
   saida->Remove(coisas);
   if(!coisas->tipo || coisas->tipo&2)
     pilha->Push(coisas);
   else
     {
     op2=(struct COISAS*)pilha->Pop();
     if(op2->tipo!=0)
       {
       double *parms;
       AnsiString *token;
       switch(op2->tipo)
         {
         case 2:
           op2->numero=FVars->Valor(op2->texto);
           break;
         case 6:
           token=PegaToken(op2->texto.c_str(),i);
           parms=PegaParms(op2->texto.c_str(),i);
           op2->numero=Funcao(token,parms);
           delete token;
           delete[] parms;
           break;
         }
       op2->tipo=0;
       }
     op1=(struct COISAS*)pilha->Pop();
     if(op1->tipo!=0)
       {
       double *parms;
       AnsiString *token;
       switch(op1->tipo)
         {
         case 2:
           op1->numero=FVars->Valor(op1->texto);
           break;
         case 6:
           token=PegaToken(op1->texto.c_str(),i);
           parms=PegaParms(op1->texto.c_str(),i);
           op1->numero=Funcao(token,parms);
           delete token;
           delete[] parms;
           break;
         }
       op1->tipo=0;
       }
     switch((char)*(coisas->texto.c_str()))
       {
       case '+':
         op1->numero+=op2->numero;
         break;
       case '-':
         op1->numero-=op2->numero;
         break;
       case '*':
         op1->numero*=op2->numero;
         break;
       case '/':
         op1->numero/=op2->numero;
         break;
       case '^':
         op1->numero=pow(op1->numero,op2->numero);
         break;
       }
     delete op2;
     pilha->Push(op1);
     }
   }
op1=(struct COISAS*)pilha->Pop();
Ret=op1->numero;
delete op1;
return Ret;
}

double __fastcall TFuncao::Funcao(AnsiString *eToken, double parms[])
{
TFuncao *func;
if(*eToken=="sen")
  {
  if(parms[0]!=1)
    return 0; // Problema... Aqui tem que gerar uma exception
  return sin(parms[1]);
  }
else if(*eToken=="cos")
  {
  if(parms[0]!=1)
    return 0; // Problema... Aqui tem que gerar uma exception
  return cos(parms[1]);
  }
else if(*eToken=="tg")
  {
  if(parms[0]!=1)
    return 0; // Problema... Aqui tem que gerar uma exception
  return tan(parms[1]);
  }
else if(*eToken=="asen")
  {
  if(parms[0]!=1)
    return 0; // Problema... Aqui tem que gerar uma exception
  return asin(parms[1]);
  }
else if(*eToken=="acos")
  {
  if(parms[0]!=1)
    return 0; // Problema... Aqui tem que gerar uma exception
  return acos(parms[1]);
  }
else if(*eToken=="atg")
  {
  if(parms[0]!=1)
    return 0; // Problema... Aqui tem que gerar uma exception
  return atan(parms[1]);
  }
else if(*eToken=="senh")
  {
  if(parms[0]!=1)
    return 0; // Problema... Aqui tem que gerar uma exception
  return sinh(parms[1]);
  }
else if(*eToken=="cosh")
  {
  if(parms[0]!=1)
    return 0; // Problema... Aqui tem que gerar uma exception
  return cosh(parms[1]);
  }
else if(*eToken=="tgh")
  {
  if(parms[0]!=1)
    return 0; // Problema... Aqui tem que gerar uma exception
  return tanh(parms[1]);
  }
else if(*eToken=="exp")
  { // Exponencial como uma função exp(x)
  if(parms[0]!=1)
    return 0; // Problema... Aqui tem que gerar uma exception
  return exp(parms[1]);
  }
else if(*eToken=="ln")
  { // Logaritmo natural
  if(parms[0]!=1)
    return 0; // Problema... Aqui tem que gerar uma exception
  return log(parms[1]);
  }
else if(*eToken=="log")
  { // Logaritmo na base 10
  if(parms[0]!=1)
    return 0; // Problema... Aqui tem que gerar uma exception
  return log10(parms[1]);
  }
else if(*eToken=="logn")
  { // Logaritmo em uma base qualquer Parm 1 é o argumento, parm2 é a base.
  if(parms[0]!=2)
    return 0; // Problema... Aqui tem que gerar uma exception
  return (log(parms[1])/log(parms[2]));
  }
else if(*eToken=="int")
  { // inteiro
  if(parms[0]!=1)
    return 0; // Problema... Aqui tem que gerar uma exception
  return (double)(int(parms[1]));
  }
else
  {
  // Se nao foi nenhuma das acima, tem que estar na relação do seu dono...
  if(!Dono || (Dono->Tipo!=TP_EQUIPAMENTO && Dono->Tipo!=TP_USINA))
    return 0; // Gerar Exception de função desconhecida.
  if(Dono->Tipo==TP_EQUIPAMENTO)
    func=((TEquipamento*)Dono)->Funcao(*eToken);
  if(func)
      return func->Calcula(parms);
    else
      return 0; // Gerar Exception de função desconhecida.
  }
}

double __fastcall TFuncao::PegaNumero(char *str,int &pos)
{
int i; // Contador comum... algo contra o nome i?
char buffer[100]; // Buffer temporario para a montagem do numero;
AnsiString tmp;
double resultado;
if(!str)
 {
 pos=-1;   // sinalizar que deu algum pau aqui.
 return 0; // Não tem expressao, logico que nao esta Ok!
 }
i=0;
while(isdigit(str[pos])) // pega os primeiros digitos da lista.
  buffer[i++]=str[pos++]; // Vai parar quando aparecer qquer coisa que ñ e no.
// Vamos "parsear" o primeiro caractere que apareceu "estranho"
// "i" serve pro buffer, pos atualiza diretamente.
if(str[pos]==DecimalSeparator) // Se for separador decimal...
  {
  buffer[i++]=str[pos++]; // Coloca o ponto la pra ele ficar satisfeito!
  // pega um streamzinho de algarismos.
  while(isdigit(str[pos])) // pega os primeiros digitos depois da virgula.
     buffer[i++]=str[pos++]; // Vai parar quando aparecer qquer ñ digito.
  }
// Não era, nem numero, nem ponto. Agora so pode ser E ou e, para notação
   // científica (123213123,123123E+93483)
if(str[pos]=='e' || str[pos]=='E') // Possivel notação científica.
  {                                    // vamos conferir o digito seguinte.
  if(str[pos+1]=='+' || str[pos+1]=='-' || isdigit(str[pos+1]))
    {
    // Somente nos casos de e seguido de +, - ou digitos teremos not. cient.
    // Como confirmei a notação cinetifica, adicionar ao numero.
    buffer[i++]=str[pos++]; // inclui o E;
    buffer[i++]=str[pos++]; // inclui o +, -, ou o 1o. digito
    while(isdigit(str[pos])) //enquanto tivermos digitos da not. cientifica
      buffer[i++]=str[pos++]; // inclui digito a digito;
    }
  } // Aquí pos está no índice de uma letra, ponto, ou algo que nao me interessa
buffer[i]='\0';      // Que tal terminar a string, hein?
if(!strlen(buffer))
  {
  pos=-1;
  return 0;
  }
tmp=AnsiString(buffer); // Vamos usar o conversor do VCL por garantia...
if(tmp=="+INF" || tmp=="-INF")
  resultado=strtod(buffer,NULL);
else
  resultado=tmp.ToDouble(); // Converte.
return resultado; // retorna o valor do número.
}

AnsiString* __fastcall TFuncao::PegaAlphaNumero(char *str,int &pos)
{
int i; // Contador comum... algo contra o nome i?
char buffer[100]; // Buffer temporario para a montagem do numero;
AnsiString tmp;
AnsiString *resultado;
resultado=new AnsiString();
if(!str)
 {
 pos=-1;   // sinalizar que deu algum pau aqui.
 return resultado; // Não tem expressao, logico que nao esta Ok!
 }
i=0;
while(isdigit(str[pos])) // pega os primeiros digitos da lista.
  buffer[i++]=str[pos++]; // Vai parar quando aparecer qquer coisa que ñ e no.
// Vamos "parsear" o primeiro caractere que apareceu "estranho"
// "i" serve pro buffer, pos atualiza diretamente.
if(str[pos]==DecimalSeparator) // Se for separador decimal...
  {
  buffer[i++]=str[pos++]; // Coloca o ponto la pra ele ficar satisfeito!
  // pega um streamzinho de algarismos.
  while(isdigit(str[pos])) // pega os primeiros digitos depois da virgula.
     buffer[i++]=str[pos++]; // Vai parar quando aparecer qquer ñ digito.
  }
// Não era, nem numero, nem ponto. Agora so pode ser E ou e, para notação
   // científica (123213123,123123E+93483)
if(str[pos]=='e' || str[pos]=='E') // Possivel notação científica.
  {                                    // vamos conferir o digito seguinte.
  if(str[pos+1]=='+' || str[pos+1]=='-' || isdigit(str[pos+1]))
    {
    // Somente nos casos de e seguido de +, - ou digitos teremos not. cient.
    // Como confirmei a notação cinetifica, adicionar ao numero.
    buffer[i++]=str[pos++]; // inclui o E;
    buffer[i++]=str[pos++]; // inclui o +, -, ou o 1o. digito
    while(isdigit(str[pos])) //enquanto tivermos digitos da not. cientifica
      buffer[i++]=str[pos++]; // inclui digito a digito;
    }
  } // Aquí pos está no índice de uma letra, ponto, ou algo que nao me interessa
buffer[i]='\0';      // Que tal terminar a string, hein?
if(!strlen(buffer))
  {
  pos=-1;
  return resultado;
  }
*resultado=AnsiString(buffer); // Vamos usar o conversor do VCL por garantia...
return resultado; // retorna o valor do número.
}


AnsiString* __fastcall TFuncao::PegaToken(char *str,int &pos)
{
// busca um token na posição indicada.
AnsiString *ret;
ret=new AnsiString("");
if(!isalpha(str[pos]))
  return ret;
while(isalnum(str[pos]))
     (*ret)+=str[pos++];
return ret;
}

double* __fastcall TFuncao::PegaParms(char *str,int &pos)
{
int saldo;
int i;
double *args;
double valor;
TList *lista;
String tmp="";

if(str[pos]!='(')
  return NULL;
lista=new TList();
saldo=1;
for(i=pos+1;i<(int)strlen(str);i++)
  {
  if(saldo==1 && (str[i]==';' || str[i]==')'))
    {
    valor=Resolve(tmp);
    lista->Add(new double(valor));
    tmp="";
    if(str[i]==')')
      saldo--;
    continue;
    }
  if(str[i]=='(')
    saldo++;
  else
  if(str[i]==')')
    {
    saldo--;
    if(!saldo)
      break;
    }
  else
    tmp+=str[i];
  }
if(saldo)
 {
 while(lista->Count)
   delete (double *)lista->Extract(lista->First());
 delete lista;
 return NULL;
 }
args=new double[lista->Count+1];
args[0]=lista->Count;
pos=i;
for(i=0;i<lista->Count;i++)
  args[i+1]=*((double*)lista->Items[i]);
while(lista->Count)
  delete (double *)lista->Extract(lista->First());
delete lista;
return args;
}

void __fastcall TFuncao::IdentificaVars(void)
{
int i;
TListaDeVariaveis *NovaLista;
TVariavel *tvar;
NovaLista=new TListaDeVariaveis();
for(i=0;i<Numero;i++)
   IdentificaVarsExp(this->Expressoes[i], NovaLista);
for(i=0;i<FVars->Numero;i++)
   if(!(NovaLista->Variavel(FVars->Nomes[i])))
     FVars->Remove(FVars->Nomes[i]);
for(i=0;i<NovaLista->Numero;i++)
   if(!(FVars->Variavel(NovaLista->Nomes[i])))
     {
     tvar=new TVariavel();
     (*tvar)=*(NovaLista->Variaveis[i]);
     FVars->Insere(tvar);
     }
delete NovaLista;
}
void __fastcall TFuncao::IdentificaVarsExp(class TExpressao *expressao,\
                                           class TListaDeVariaveis *lista)
{
char *dados;
AnsiString *tmp;
class TVariavel *tvar;
int i;
if(!expressao || !lista)
  return;
dados=(char*)expressao->Texto.c_str();
for(i=0;i<(int)strlen(dados);i++)
   if(isalpha(dados[i]))
     {
     tmp=PegaToken(dados,i);
     if(dados[i]!='(')
       if(!(lista->Variavel(*tmp)))
         {
         tvar=new TVariavel();
         tvar->Nome=(*tmp);
         tvar->Valor=0;
         tvar->Dono=this; // Adiciona.
         lista->Insere(tvar);
         }
     delete tmp;
     }
}
void __fastcall TFuncao::RetiraParentese(char *expr, AnsiString *ret)
{
int saldo=0;
int i=0;//,j=0;
(*ret)=""; // Clear...
if(expr[i]=='(')
  saldo++, i++;
else return;

while(saldo) // Aqui somente importa matar o saldo!!! nada do que estava acima.
  if(expr[i]=='\0') // se chegar ao terminador antes do saldo zerar, a string
     return; // fazer um throw!
  else
  switch(expr[i])
   {
   case '(':
     saldo ++;
     (*ret)+=AnsiString(expr[i++]);
     break;
   case ')':
     if(saldo==1)
       {
       saldo=0;    // i++?
       continue;
       }
     saldo --;
     (*ret)+=AnsiString(expr[i++]);
     break;
   default:
     (*ret)+=AnsiString(expr[i++]);
   }
// Eliminei os parenteses requisitados...
return; // Tudo terminou OK...
}
bool __fastcall TFuncao::IntervaloOk(AnsiString eIntervalo, double limites[],
                                       bool extremos[])
{
char *dados;
int i;
AnsiString tmp;
dados=eIntervalo.c_str();
i=0;
tmp="";
while(dados[i]!='[' && dados[i]!='(' && dados[i]!='\0')
     i++;
if(dados[i]=='\0')
  return false;
if(dados[i]=='[')
  extremos[0]=true;
else
if(dados[i]=='(')
  extremos[0]=false;
else
  return false;
while(!isdigit(dados[i]) && dados[i]!='+' && dados[i]!='-' && dados[i]!='\0')
  i++;
if(dados[i]=='\0')
  return false;
while(dados[i]!=';' && dados[i]!='\0')
     tmp+=dados[i++];
if(dados[i]=='\0')
  return false;
try{
   limites[0]=tmp.ToDouble();
   } catch(EConvertError &Erro)
       {
       if(tmp=="+INF" || tmp=="-INF" || tmp=="INF")
         {
         limites[0]=strtod(tmp.c_str(),NULL);
         }
       else
       return false;
       }
tmp="";
while(!isdigit(dados[i]) && dados[i]!='+' && dados[i]!='-' && dados[i]!='\0')
  i++;
if(dados[i]=='\0')
  return false;
while(dados[i]!=']' && dados[i]!=')' && dados[i]!='\0')
     tmp+=dados[i++];
try{
   limites[1]=tmp.ToDouble();
   } catch(EConvertError &Erro)
       {
       if(tmp=="+INF" || tmp=="-INF" || tmp=="INF")
         {
         limites[1]=strtod(tmp.c_str(),NULL);
         }
       else
       return false;
       }
if(dados[i]=='\0')
  return false;
if(dados[i]==']')
  extremos[1]=true;
else
if(dados[i]==')')
  extremos[1]=false;
else
  return false;
return true;
}

bool __fastcall TFuncao::Salva(AnsiString arquivo)
{
int fHandle;
try {
    fHandle=FileCreate(arquivo);
    FStandAlone=true;
    Salva(fHandle);
    FStandAlone=false;
    FileClose(fHandle);
    } catch(...)
           {
           ShowMessage("Problemas no salvamento de uma equação.");
           return false;
           }
return true;
}

bool __fastcall TFuncao::Salva(int fHandle)
{
/* Tem que salvar:
   . Nome
   . AutoCalculo
   . Lista de Variaveis
   . Expressoes
     - Texto: AnsiString;
     - Limites: double[2];
     - Extremos: bool[2];
*/
int i;
int dado=ID_FUNCAO;
char *buffer;
try {
    FileWrite(fHandle,&dado,sizeof(dado));
    dado=Nome.Length()+1;
    FileWrite(fHandle,&dado,sizeof(dado));
    buffer=Nome.c_str();
    FileWrite(fHandle,buffer,dado);
    FileWrite(fHandle,&FAutoCalculo,sizeof(FAutoCalculo));
    FVars->Salva(fHandle);
    dado=Numero;
    FileWrite(fHandle,&dado,sizeof(dado));
    for(i=0;i<Numero;i++)
       {
       dado=Expressoes[i]->Texto.Length()+1;
       FileWrite(fHandle,&dado,sizeof(dado));
       buffer=Expressoes[i]->Texto.c_str();
       FileWrite(fHandle,buffer,dado);
       FileWrite(fHandle,Expressoes[i]->Limites,2*sizeof(double));
       FileWrite(fHandle,Expressoes[i]->Extremos,2*sizeof(bool));
       }
    dado=Ajuda.Length()+1;
    FileWrite(fHandle,&dado,sizeof(dado));
    buffer=Ajuda.c_str();
    FileWrite(fHandle,buffer,dado);
    } catch(...)
           {
           ShowMessage("Problemas no salvamento de uma equação.");
           return false;
           }
return true;
}
bool __fastcall TFuncao::Carrega(int fHandle)
{
/* Tem que carregar:
   . Nome
   . AutoCalculo
   . Lista de Variaveis
   . Expressoes
     - Texto: AnsiString;
     - Limites: double[2];
     - Extremos: bool[2];
*/
int i;
int dado,num;
char *buffer;
TExpressao *texp;
try {
    while(Numero)
      delete (TExpressao*)Remove(0);
    FileRead(fHandle,&dado,sizeof(dado));
    if(dado!=ID_FUNCAO)
      return false;
    FileRead(fHandle,&dado,sizeof(dado));
    buffer=new char[dado];
    FileRead(fHandle,buffer,dado);
    Nome=buffer;
    delete[] buffer;
    FileRead(fHandle,&FAutoCalculo,sizeof(FAutoCalculo));
    FVars->Carrega(fHandle);
    FileRead(fHandle,&num,sizeof(num));
    for(i=0;i<num;i++)
       {
       texp=new TExpressao();
       texp->Nome="Exp"+AnsiString(i);
       FileRead(fHandle,&dado,sizeof(dado));
       buffer=new char[dado];
       FileRead(fHandle,buffer,dado);
       texp->Texto=buffer;
       delete[] buffer;
       FileRead(fHandle,texp->Limites,2*sizeof(double));
       FileRead(fHandle,texp->Extremos,2*sizeof(bool));
       Adiciona(texp);
       }
    FileRead(fHandle,&dado,sizeof(dado));
    buffer=new char[dado];
    FileRead(fHandle,buffer,dado);
    Ajuda=buffer;
    delete[] buffer;
    } catch(...)
           {
           ShowMessage("Problemas no carregamento de uma equação.");
           return false;
           }
return true;
}
bool __fastcall TFuncao::Carrega(AnsiString arquivo)
{
int fHandle;
try {
    fHandle=FileOpen(arquivo, fmOpenRead);
    FStandAlone=true;
    Carrega(fHandle);
    FStandAlone=false;
    FileClose(fHandle);
    } catch(...)
           {
           ShowMessage("Problemas no carregamento de uma equação.");
           return false;
           }
return true;
}
TFuncao& TFuncao::operator = (TFuncao& src)
{
int i;
if(this==&src)
   return *this;
Nome=src.Nome;
FAutoCalculo=src.FAutoCalculo;
*FVars=*(src.FVars);
FStandAlone=src.FStandAlone;
FAjuda=src.FAjuda;
while(Numero)
  delete(this->Remove(0));
if(src.Numero)
  for(i=0;i<src.Numero;i++)
    this->Adiciona(new TExpressao(src.Expressoes[i]));
return *this;
}
