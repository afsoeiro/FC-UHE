#ifndef DefinesH
#define DefinesH
#define SAFEDEL(X) if(X) delete X; X=NULL;
#define VALOR(N,I,T) *(T *)(N->Items[I]) //Nome, Item, Tipo
#define PTR(N,I,T) (T *)(N->Items[I]) //Nome, Item, Tipo
#define IsOperator(X) (X=='+'||X=='-'||X=='*'||X=='/'||X=='^')
#define IsBadOperator(X) (X=='*'||X=='/'||X=='^')
#define Joga AnsiString("j").ToDouble()

// Definições para os identificadores de arquivos

#define ID_VARIAVEL 0x02020402 // Arquivo contendo uma variavel;
#define ID_LISTA_DE_VARIAVEIS 0x02020400 // Arquivo contendo uma lista de variáveis;
#define ID_LISTA_DE_VARIAVEIS_PARTICULAR 0x02020500 // Arquivo contendo uma
                                 // lista de variáveis pertencentes a um objeto;
#define ID_FUNCAO 0x02020200 // Arquivo com uma equação;
#define ID_EQUACAO_STANDALONE 0x02020210 // Arquivo standalone com uma equação;
#define ID_EQUIPAMENTO 0x02020000 // Arquivo contendo descrição de um equipamento;

#define SEM_LISTAS 0x00 // SEM_LISTAS - Nenhuma lista.
#define COM_LISTA_LOCAL 0x01 // Uma lista, local.
#define COM_LISTA_GLOBAL 0x10 // Uma lista, global.
#define COM_TODAS_LISTAS 0x11 // Duas listas, uma global e uma local.


// Definições para identificadores de objetos

#define TP_OBJETO 0xAF050000 // Objeto base de todas as classes.
#define TP_VARIAVEL 0xAF050001 // Objeto do tipo variavel.
#define TP_LISTA 0xAF050002 // Objeto lista de objetos.
#define TP_FUNCAO 0xAF050003 // Objeto Funçao.
#define TP_EQUIPAMENTO 0xAF050004 // Objeto equipamento.
#define TP_USINA 0xAF050005 // Objeto usina (Conjunto de equipamentos).
#define TP_LISTADEVARIAVEIS 0xAF050006 // Lista de variaveis
#define TP_BANCODEVARIAVEIS 0xAF050007 // Lista de listas de variaveis.

// Exception... Sempre quiz fazer isso!!!
#define TMinhaException(ENome,Mensagem) \
  class ENome: public Exception \
  { \
  public: \
    ENome(TObjeto *oObjeto):Exception \
      ( \
      oObjeto->Nome + \
      AnsiString(": ") + \
      Mensagem \
      ) \
      {}; \
    ENome(TObjeto* oObjeto, AnsiString aMensagem):\
      Exception\
      (\
      oObjeto->Nome+\
      AnsiString(": ")+\
      + Mensagem \
      + AnsiString(";\n")\
      + aMensagem) \
      {}; \
  }

#endif                 //
