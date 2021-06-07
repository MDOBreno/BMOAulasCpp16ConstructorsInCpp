//
//  main.cpp
//  BMOAulasCpp16ConstructorsInCpp
//
//  Created by Breno Medeiros on 07/06/21.
//

#include <iostream>

class Entidade {
public:
    float X, Y;
    
    void Print() {
        std::cout << X << ", " << Y << std::endl;
    }
    
    void InicializacaoPorMetodoGambiarra() {
        X=0.0f;
        Y=0.0f;
    }
    
    //CONSTRUTOR: É um metodo especial(sem tipo de retorno, e com mesmo nome da classe) executado na instanciacao:
    Entidade() { //Esse construtor já resolve o problema, pois inicializa com algum valor os atributos
        X=0.0f;
        Y=0.0f;
    }
    Entidade(float x, float y) { // Esse construtor é a solucao ideal, pois da a opcao de escolher os valores.
        X=x;
        Y=y;
    }
};

class Log {
public:
    Log()=delete; //Isso obriga o desenvolvedor a criar um contrutor, ja que deletamos o construtor padrao dessa classe.
    
    static void Escrever(){
        // insert code here...
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cout << " ----------- Nosso Problema ----------- " << std::endl;
    
    Entidade e;
    e.Print();  //Fazer o Print das variaveis X e Y, sem ter inicializado o valor delas, em alguns
                // sistemas operacionais pode resultar num Print aleatorio como "-1.07e+08, -1.07e+08"
                // pois ele considera o valor atual seja lá o que havia na memoria ram naquele momento.
                // entao é boa pratica inicializar atributos antes de usar(mesmo que no meu sistema(MacOS)
                // os valores sejam automaticamente definidos para 0 enquanto não é inicializado ainda).
    
    std::cout << e.X << std::endl; //De mesma forma, em alguns sistemas isso da erro,pois n houve inicializacao
    
    std::cout << " ----------- Solucao Gambiarra ----------- " << std::endl;
    
    Entidade e1;
    e1.InicializacaoPorMetodoGambiarra();  //Uma solucao gambiarrosa seria usar uma funcao comum a mais sempre apois a instanciacao
    e.Print();
    
    std::cout << " ----------- Solucao Ideal (Construtor) ----------- " << std::endl;
    Entidade e2(10.0f, 5.0f);
    e2.Print();
    
    std::cout << " ----------- Obrigando o Desenvolvedor a escrever um construtor ----------- " << std::endl;
    Log::Escrever();
    //Log l; // Essa linha da erro, pois na classe esta escrito "Log()=delete;", que deleta o construtor padrao.
    
    
    std::cout << "Hello, World!\n";
    return 0;
}

