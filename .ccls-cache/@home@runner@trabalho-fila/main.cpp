
// Lucas Goulart de Farias Meres - 42127459
// Thiago Leandro Liporace - 42128481

#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include <thread>
#include <fstream>

#include "Utils.h"
#include "Canvas.h"
#include "fila.h"


using namespace std::this_thread;
using namespace std::chrono;

int GetIntFromString(const std::string& str);
void UpdateCanvas(const Canvas& canvas);

int GetIntFromString(const std::string& str)
{
    try
    {
        return std::stoi(str);
    }
    catch (...)
    {
        return -1;
    }
}


void UpdateCanvas(const Canvas& canvas)
{
    ClearScreen();
    std::cout << canvas; // PrintCanvas(canvas);
}

std::string getString(char c)
{
    std::string s = "";
    std::stringstream ss;
    ss << s << c;
    ss >> s;
    std::cout << s;
    return 0;
}


int main()
{
    Canvas canvas;
    SetupCanvas(canvas);
    ClearCanvas(canvas);
    Fila fila = Create();
    Retorno ret = { -1, '\0' },ret2 = { -1, '\0' };

    // Exemplo de como ativar/desativar um elemento da matriz.
    //ToggleCanvas(canvas, 3, 3);
    //ToggleCanvas(canvas, 3, 3);

    std::string input = "",text;
    std::ifstream LeArquivo("info.txt");
    int option = -1,row,col,entry,cont = 0;

    do
    {
        UpdateCanvas(canvas);

        std::cout << "\n\n*** OPCOES ***\n"
            << "1 - Alterar uma coordenada.\n"
            << "2 - Executar sequencia de comandos.\n"
            << "3 - Salvar comandos em um arquivo.\n"
            << "4 - Carregar comandos de um arquivo.\n"
            << "5 - Encerrar programa.\n"
            << "Opcao: ";
        
        std::getline(std::cin, input);

        option = GetIntFromString(input);
        switch (option)
        {
        case 1:
            std::cout << "Digite respectivamente a linha e a coluna desejada: ";
            std::cin >> row;
            std::cin.ignore(256,'\n');
            std::cin >> col;
            std::cin.ignore(256,'\n');
            std::cout << "Linha inserida: " << row << "\n";
            std::cout << "Coluna inserida:" << col << "\n";
            ToggleCanvas(canvas,row,col);
            Enqueue(fila,row);
            Enqueue(fila,col);
            cont++;
            break;
        
        case 2:
            if (cont == 0){
              std::cout << "Nao foi executado nenhum comando";
              break;
            }
            ClearCanvas(canvas);
            UpdateCanvas(canvas);
            sleep_for(milliseconds(500));
            for (int i = 0;i<cont;i++){
              ret = Dequeue(fila);
              ret2 = Dequeue(fila);
              row = ret.valor;
              col = ret2.valor;
              std::cout << "---- Operacao ----\n";
              std::cout << "Linha: " << row << "\n";
              std::cout << "Coluna: " << col << "\n";
              sleep_for(milliseconds(500));
              ToggleCanvas(canvas,row,col); 
              UpdateCanvas(canvas);
              Enqueue(fila,row);
              Enqueue(fila,col);        
              sleep_for(milliseconds(500));
            }
            break;
        
        case 3:
            if (cont==0){
              std::cout << "Nao foi executado nenhum comando\n";
              break;
            }
            for (int i = 0;i < cont;i++){
              std::ofstream arquivo;
              arquivo.open("info.txt", std::ios::app);
              ret = Dequeue(fila);
              ret2 = Dequeue(fila);
              row = ret.valor;
              col = ret2.valor;
              Enqueue(fila,row);
              Enqueue(fila,col);
              std::string(1, row);
              std::string(1, col);
              arquivo << row << col;
            }
            break;
        
        case 4:
            getline(LeArquivo,text);
            for (int i = 0;i < text.length();i++){
              if ((i >= 1) && (i%2 == 1)) cont++;
              Enqueue(fila,text[i]-48);
            }
            LeArquivo.close(); 
            for (int i = 0;i < cont;i++){
              ret = Dequeue(fila);
              ret2 = Dequeue(fila);
              row = ret.valor;
              col = ret2.valor;
              ToggleCanvas(canvas,row,col);
              Enqueue(fila,row);
              Enqueue(fila,col);              
            }           
            break;
        case 5:
            std::cout << "Fim.\n\n";
            break;
        
        default:
            std::cout << "*** ERRO: Opcao invalida! ***\n\n";
            Pause();
            break;
        }

    } while (option != 5);
}
