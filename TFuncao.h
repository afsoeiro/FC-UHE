//---------------------------------------------------------------------------
#include "TLista.h"
#ifndef TFuncaoH
#define TFuncaoH
//---------------------------------------------------------------------------
class TExpressao : public TObjeto
{
public:
AnsiString Texto;  // A expressao propriamente dita;
double Limites[2]; // Os limites de validade da expressao;
bool Extremos[2]; // Os extremos
__fastcall TExpressao(void): TObjeto()
{
Limites[0]=strtod("-INF",NULL);
Limites[1]=strtod("+INF",NULL);
Extremos[0]=false;
Extremos[1]=false;
Texto="";
}
__fastcall TExpressao(TObjeto *eDono): TObjeto(eDono)
{
Limites[0]=strtod("-INF",NULL);
Limites[1]=strtod("+INF",NULL);
Extremos[0]=false;
Extremos[1]=false;
Texto="";
}
__fastcall TExpressao(TExpressao *eExp): TObjeto()
{
Limites[0]=eExp->Limites[0];
Limites[1]=eExp->Limites[1];
Extremos[0]=eExp->Extremos[0];
Extremos[1]=eExp->Extremos[1];
Texto=eExp->Texto;
Nome=eExp->Nome;
}
__fastcall ~TExpressao()
{
}
};
//---------------------------------------------------------------------------
class TFuncao : public TLista
{
private:
double FValor;      // Guarda o valor da função atual
bool FValida;  // Armazena estado de validade da equação atual
bool FAutoCalculo; // Manda calcular automaticamente o valor no caso de valida
class TListaDeVariaveis* FVars;
bool FStandAlone; // Se for gravar equação a partir de arquivo...
AnsiString FAjuda;

protected:
    // Testa os parenteses pra ver se ok
    bool __fastcall ParentesesOk(TExpressao* expressao);
    bool __fastcall FGetValida();  // diz se a expressão em expressao é válida
    class TExpressao* __fastcall GetExpressoes(int Indice);
    int __fastcall FGetNumeroDeVariaveis(void);
    class TVariavel* __fastcall FGetVariaveis(int Indice);
    class TListaDeVariaveis* __fastcall FGetListaDeVariaveis(void);
public:
    void __fastcall Init(void);
    __fastcall TFuncao(void);
    __fastcall TFuncao(class TObjeto *eDono);
    __fastcall ~TFuncao(void);

    __property class TExpressao* Expressoes[int Indice] = {read=GetExpressoes};
    // Inicializa uma nova expressao (única) com seus limites.
    void __fastcall Adiciona(class TExpressao* eExpressao);
    bool __fastcall Adiciona(AnsiString nova, double Limites[],bool Extremos[]);
    class TExpressao* __fastcall Remove(int Indice);
    class TExpressao* __fastcall Remove(AnsiString eNome);
    class TExpressao* __fastcall Expressao(AnsiString eNome);
    // metodo que calcula valor da função, segundo parametros informados.
    double __fastcall Calcula(double Parametros[]);
    double __fastcall Calcula(char Argumentos[]);
    double __fastcall Resolve(AnsiString expr); // Calcula uma expressao sem ()s
    bool __fastcall EValida(TExpressao* expressao);
    __property bool Valida = {read=FGetValida};

    double __fastcall PegaNumero(char *str,int &pos);
    AnsiString* __fastcall PegaAlphaNumero(char *str,int &pos);
    // busca um token na posição indicada. O token pode ser qualquer identifica-
    // dor que começa com uma letra diferente de "e", e das palavras reservadas.
    AnsiString* __fastcall PegaToken(char *str,int &pos);
    // Faz um parse dos parâmetros de uma função, que aparecem entre colchetes,
    // separados por ponto e vírgula.
    double* __fastcall PegaParms(char *str,int &pos);
    double __fastcall Funcao(AnsiString *eToken, double parms[]);
    bool __fastcall ColchetesOk(char *dados);
    void __fastcall IdentificaVars(void);
    void __fastcall IdentificaVarsExp(class TExpressao *expressao,\
                                      class TListaDeVariaveis *lista);

    __property bool AutoCalculo= {read=FAutoCalculo, write=FAutoCalculo};
    __property AnsiString Ajuda= {read=FAjuda, write=FAjuda};
    __property int NumeroDeVariaveis={read=FGetNumeroDeVariaveis};
    __property class TVariavel* Variaveis[int Indice]={read=FGetVariaveis};
    __property class TListaDeVariaveis* ListaDeVariaveis=\
                                        {read=FGetListaDeVariaveis};
    // voltar so la pra cima depois do teste!
    void __fastcall RetiraParentese(char *expr, AnsiString *ret);
    bool __fastcall IntervaloOk(AnsiString eIntervalo, double limites[],\
                                                               bool extremos[]);
    bool __fastcall Salva(int fHandle);
    bool __fastcall Salva(AnsiString arquivo);
    bool __fastcall Carrega(int fHandle);
    bool __fastcall Carrega(AnsiString arquivo);
    TFuncao& operator = (TFuncao& src);
};

#endif
