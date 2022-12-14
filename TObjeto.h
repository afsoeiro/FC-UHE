//---------------------------------------------------------------------------

#ifndef TObjetoH
#define TObjetoH
//---------------------------------------------------------------------------
class TObjeto
{
private:
AnsiString *FNome;
class TObjeto *FDono;
int FTipo;
AnsiString __fastcall GetNome(void);
void __fastcall SetNome(AnsiString eNome);
class TObjeto* __fastcall GetDono(void);
void __fastcall SetDono(class TObjeto* eObjeto);
int __fastcall GetTipo(void);
void __fastcall SetTipo(int eTipo);
protected:
public:
__fastcall TObjeto();
__fastcall TObjeto(class TObjeto *eDono);
__fastcall ~TObjeto(void);
__property AnsiString Nome={read=GetNome, write=SetNome};
__property TObjeto* Dono={read=GetDono, write=SetDono};
__property int Tipo={read=GetTipo, write=SetTipo};


};

#endif
