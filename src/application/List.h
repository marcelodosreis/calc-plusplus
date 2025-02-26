#ifndef LIST_H
#define LIST_H

#include <iostream>

class List
{
public:
    void teste(const std::string data)
    {
        // std::cout << "User Input: " << data << std::endl;
        std::vector<int> lista = {1, 2, 3, 4, 5}; // Lista de números

        lista.push_back(6); // Adiciona um número no final
        lista.pop_back();   // Remove o último número
    
        std::cout << "Primeiro elemento: " << lista[0] << std::endl;
        std::cout << "Último elemento: " << lista.back() << std::endl;
    }
};

#endif // LIST_H
