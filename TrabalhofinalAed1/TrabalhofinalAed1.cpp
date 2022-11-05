#include<iostream>
#include<fstream>
#include<string>
#include<speechapi_cxx.h>
#include<locale.h>

using namespace std;
using namespace Microsoft::CognitiveServices::Speech;
using namespace Microsoft::CognitiveServices::Speech::Audio;

auto autenticacao = SpeechConfig::FromSubscription("d8c7ca801fd0428daaf8d42b9676921c", "brazilsouth");
auto requisicao_textofala = SpeechSynthesizer::FromConfig(autenticacao);
auto audio_config = AudioConfig::FromDefaultMicrophoneInput();
auto requisicao_falatexto = SpeechRecognizer::FromConfig(autenticacao, audio_config);

void texto_em_fala(string Texto)
{
	cout << Texto + "\n";
	requisicao_textofala->SpeakTextAsync(Texto).get(); // REQUISIÇÃO DA SINTETIZAÇÃO DE TEXTO EM FALA
}
string fala_em_texto() {
	auto resultado = requisicao_falatexto->RecognizeOnceAsync().get(); // REQUISIÇÃO DO RECONHEIMENTO DE FALA EM TEXTO
	cout << resultado->Text + "\n";
	return resultado->Text; //CONVERSÃO DO RESULTADO DO RECONHECIMENTO EM TEXTO
}
//procedimentos que recebem 2 strings transformam em float executam as operações e depois transformam em string para a api falar
void soma(string num1, string num2) {
    float aux1 = stof(num1);//transforma a string em float
    float aux2 = stof(num2);//transforma a string em float
    float soma = aux1 + aux2;//faz a soma
    stringstream ss;//cria uma variavel do tipo stringstream
    ss << soma;//recebe o float
    string somaf;//cria uma variavel do tipo string somaf=soma falada
    ss >> somaf;//recebe o float em formato de string
    texto_em_fala("A soma é" + somaf);

}
void subtracao(string num1, string num2) {
    float aux1 = stof(num1);//transforma a string em float
    float aux2 = stof(num2);//transforma a string em float
    float sub = aux1 - aux2;//faz a subtração
    stringstream sc;//cria uma variavel do tipo stringstream
    sc << sub;//recebe o float
    string subf;//cria uma variavel do tipo string subf=subtração falada
    sc >> subf;//recebe o float em formato de string
    texto_em_fala("A subtração é" + subf);
}
void multiplicacao(string num1, string num2) {
    float aux1 = stof(num1);//transforma a string em float
    float aux2 = stof(num2);//transforma a string em float
    float multi = aux1 * aux2;//faz a multiplicação
    stringstream sa;//cria uma variavel do tipo stringstream
    sa << multi;//recebe o float
    string multif;//cria uma variavel do tipo string multif=multiplicação falada
    sa >> multif;//recebe o float em formato de string
    texto_em_fala("O produto é" + multif);
}
void divisao(string num1, string num2) {
    float aux1 = stof(num1);//transforma a string em float
    float aux2 = stof(num2);//transforma a string em float
    float div = aux1 / aux2;//faz a divisão
    stringstream sb;//cria uma variavel do tipo stringstream
    sb << div;//recebe o float
    string divf;//cria uma variavel do tipo string divf=divisão falada
    sb >> divf;//recebe o float em formato de string
    texto_em_fala("O resultado da divisão é" + divf);
}
void modular(string num1, string num2) {
    float aux1 = stof(num1);//transforma a string em float
    float aux2 = stof(num2);//transforma a string em float
    int mod = (int)aux1 % (int)aux2;//faz a divisão inteira(módulo)
    stringstream sd;//cria uma variavel do tipo stringstream
    sd << mod;//recebe o float
    string modf;//cria uma variavel do tipo string modf=módulo falado
    sd >> modf;//recebe o float em formato de string
    texto_em_fala("O módulo entre os dois números é" + modf);
}
void achamedia(string num1, string num2) {
    float aux1 = stof(num1);//transforma a string em float
    float aux2 = stof(num2);//transforma a string em float
    float media = (aux1 + aux2) / 2;//faz a média aritmética
    stringstream sf;//cria uma variavel do tipo stringstream
    sf << media;//recebe o float
    string mediaf; // cria uma variavel do tipo string mediaf = média falada
    sf >> mediaf;//recebe o float em formato de string
    texto_em_fala("A média é" + mediaf);
}
void fazpercent(string num1, string num2) {
    float aux1 = stof(num1);//transforma a string em float
    float aux2 = stof(num2);//transforma a string em float
    float percent = 100.0 * (aux1 / aux2);//faz a porcentagem relativa entre os dois números
    stringstream se;//cria uma variavel do tipo stringstream
    se << percent;//recebe o float
    string percentf;// cria uma variavel do tipo string mediaf = média falada
    se >> percentf;//recebe o float em formato de string
    texto_em_fala("A porcentagem entre os dois números é" + percentf + "por cento.");
}


int main() {
    //configuração do comando de voz da api do azure como orientado pelo vídeo

	setlocale(LC_ALL, "pt-BR");
	autenticacao->SetSpeechRecognitionLanguage("pt-BR");
	autenticacao->SetSpeechSynthesisLanguage("pt-BR");
	autenticacao->SetSpeechSynthesisVoiceName("pt-BR-Daniel");
	requisicao_textofala = SpeechSynthesizer::FromConfig(autenticacao);
	requisicao_falatexto = SpeechRecognizer::FromConfig(autenticacao, audio_config);


    string num1, num2;//Como o software de voz só recebe strings os numeros precisam a principio serem inicializados como string

    texto_em_fala("SISTEMA LIGADO");
    texto_em_fala("Bem Vindo a calculadora interativa!");
    texto_em_fala("Qual é o seu nome?");
    string nome = fala_em_texto();//armazena o nome falado na variável
    //MENU DA CALCULADORA
    cout << "Fale (SOMAR), para executar uma soma\n" ;
    cout << "Fale (SUBTRAIR),para executar uma subtração\n" ;
    cout << "Fale (MULTIPLICAR),para executar uma multiplicação\n" ;
    cout << "Fale (DIVIDIR),para executar uma divisão\n";
    cout << "Fale (MODULO),para encontar o módulo entre os dois números\n";
    cout << "Fale (MEDIA),para encontar a média entre os dois números\n";
    cout << "Fale (PORCENTAGEM),para encontrar a porcentagem relativa entre os dois números\n";
    cout << "Fale (TUDO),para executar todas as operações\n";
    cout << "Fale (SAIR),para fechar o programa\n";



    string comando;
    
    do {//Loop do while, o programa será executado até que o usuário fale a palavra sair
        texto_em_fala("Ola " + nome + "! Fale o comando desejado ");
        comando = fala_em_texto();
        /*Todos os "IF's" seguem o mesmo princípio': 
        escutam o número em forma de string pelo comando de voz armazenam na variável
        e chamam o respectivo procedimento"*/
        if (comando == ("Somar.")) {
            texto_em_fala("Primeiro numero: ");
            num1 = fala_em_texto();
            texto_em_fala("Segundo numero: ");
            num2 = fala_em_texto();
            soma(num1, num2);
        }
        else if (comando == ("Subtrair.")) {
            texto_em_fala("Primeiro numero: ");
            num1 = fala_em_texto();
            texto_em_fala("Segundo numero: ");
            num2 = fala_em_texto();
            subtracao(num1, num2);
        }
        else if (comando == ("Multiplicar.")) {
            texto_em_fala("Primeiro numero: ");
            num1 = fala_em_texto();
            texto_em_fala("Segundo numero: ");
            num2 = fala_em_texto();
            multiplicacao(num1, num2);

        }
        else if (comando == ("Dividir.")) {
            texto_em_fala("Primeiro numero: ");
            num1 = fala_em_texto();
            texto_em_fala("Segundo numero: ");
            num2 = fala_em_texto();
            divisao(num1, num2);
        }
        else if (comando == ("Módulo.")) {
            texto_em_fala("Primeiro numero: ");
            num1 = fala_em_texto();
            texto_em_fala("Segundo numero: ");
            num2 = fala_em_texto();
            modular(num1, num2);
        }
        else if (comando == ("Media.")) {
            texto_em_fala("Primeiro numero: ");
            num1 = fala_em_texto();
            texto_em_fala("Segundo numero: ");
            num2 = fala_em_texto();
            achamedia(num1, num2);
        }
        else if (comando == ("Porcentagem.")) {
            texto_em_fala("Primeiro numero: ");
            num1 = fala_em_texto();
            texto_em_fala("Segundo numero: ");
            num2 = fala_em_texto();
            fazpercent(num1, num2);
        }
        else if (comando == ("Tudo.")) {
            texto_em_fala("Primeiro numero: ");
            num1 = fala_em_texto();
            texto_em_fala("Segundo numero: ");
            num2 = fala_em_texto();
            soma(num1, num2);
            subtracao(num1, num2);
            multiplicacao(num1, num2);
            divisao(num1, num2);
            modular(num1, num2);
            achamedia(num1, num2);
            fazpercent(num1, num2);
        }
    }while (comando != ("Sair."));
    texto_em_fala("Obrigado!, até logo!");




    


    return 0;
}