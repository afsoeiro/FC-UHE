//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("NeoSoee.res");
USEFORM("TMain.cpp", Main);
USEFORM("TSobre.cpp", Sobre);
USEUNIT("TListaDeVariaveis.cpp");
USEUNIT("TVariavel.cpp");
USEUNIT("TLista.cpp");
USEUNIT("TObjeto.cpp");
USEUNIT("TBancoDeVariaveis.cpp");
USEUNIT("TEquipamento.cpp");
USEFORM("TEdEquipamento.cpp", EdEquipamento);
USEFORM("TSolucao.cpp", Solucao);
USEFORM("TEntradaDeDados.cpp", EntradaDeDados);
USEFORM("TEdFuncao.cpp", EdFuncao);
USEUNIT("TFuncao.cpp");
USEFORM("TEntradaDePonto.cpp", EntradaDePonto);
USEFORM("TEscolhaParametro.cpp", EscolhaParametro);
USEFORM("TEscolheDiretorio.cpp", EscolheDiretorio);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
AnsiString HelpFile;
HelpFile=ExtractFilePath(Application->ExeName);
HelpFile+="FC-UHE.HLP";
        try
        {
                 Application->Initialize();
                 Application->Title = "FC-UHE";
                 Application->HelpFile = HelpFile;
                 Application->CreateForm(__classid(TMain), &Main);
                 Application->CreateForm(__classid(TSobre), &Sobre);
                 Application->CreateForm(__classid(TEdEquipamento), &EdEquipamento);
                 Application->CreateForm(__classid(TSolucao), &Solucao);
                 Application->CreateForm(__classid(TEntradaDeDados), &EntradaDeDados);
                 Application->CreateForm(__classid(TEdFuncao), &EdFuncao);
                 Application->CreateForm(__classid(TEntradaDePonto), &EntradaDePonto);
                 Application->CreateForm(__classid(TEscolhaParametro), &EscolhaParametro);
                 Application->CreateForm(__classid(TEscolheDiretorio), &EscolheDiretorio);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
