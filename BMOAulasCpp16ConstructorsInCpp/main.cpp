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
        std::cout << "Entidade Construida!" << std::endl;
        X=0.0f;
        Y=0.0f;
    }
    Entidade(float x, float y) { // Esse construtor é a solucao ideal, pois da a opcao de escolher os valores.
        std::cout << "Entidade Construida!" << std::endl;
        X=x;
        Y=y;
    }
    
    //DESTRUTOR: É o contrario do construtor, e é usando para liberar espaco na memoria.
    ~Entidade() { //Este metodo é chamado sempre que o Escopo em que ele foi criado[nesse caso é o metodo main()] chega ao fim
        std::cout << "Entidade Destruida!" << std::endl;
        return;
    }
};

void Funcao() {
    Entidade e3; //Aqui a entidade foi Contruida dentro do escopo dessa funcao
    e3.Print();
} //Aqui a entidade foi Destruida, pois o escopo em que ela foi criada se encerra nessa linha por conta do digito '}'


class Log {
public:
    Log()=delete; //Isso obriga o desenvolvedor a criar um contrutor, ja que deletamos o construtor padrao dessa classe.
    
    static void Escrever(){
        std::cout << "Fazendo algo no metodo estatico." << std::endl;
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
    
    std::cout << " ----------- Usando Destrutor ----------- " << std::endl;
    e2.~Entidade(); //Isso é como se destroi uma instancia Manualmente.
    //Obs: Ao chegar no fim do escopo da funcao main(), e2 sera novamente destruida, pois a Destruicao ocorre autom no fim do escopo
    
    Funcao();
    //Ao chegar nessa linha, tudo o que foi construido dentro do escopo da funcao acima ja tera sido destruido automaticamente
    
    std::cout << "Hello, World!\n";
    return 0;
}

