#include <iostream>
#include <SFML/Network.hpp>
#include <string>

#define localhost "127.0.0.1"

bool portIsOpen(const std::string& address, int port);
void scannig(int amountPorts, std::string IP);

int main(){

    int lastPort {0};
    std::string IP {localhost};

    do{
        std::cout << "How many ports you want to scan (1-X): ";
        std::cin >> lastPort;

        if (lastPort < 1){
            std::cout << "Port have to be bigger than 1" << std::endl;
        }
        
    } while (lastPort < 1);

    scannig(lastPort, IP);

    return 0;
}

/**
 * Call TcpSocket to see the port is OPEN
 * 
 * @param address The IP that is using, 127.0.0.1 or localhost in this case
 * @param port The port that is scanning
 * @return True if open False if close
 */
bool portIsOpen(const std::string& address, int port){
    return (sf::TcpSocket().connect(address, port) == sf::Socket::Done);
}

/**
 * Recursion to call portIsOpen with any amount of ports
 * 
 * @param amountPorts The ports that is going to scan
 * @param IP The IP that is scanning, 127.0.0.1 in this case
 */
void scannig(int amountPorts, std::string IP){

    bool allPortsClosed {true};
    int openPorts {0};

    std::cout << "Scanning ports from 1 - " << amountPorts << std::endl;

    for (int i = 1; i < amountPorts+1; i++){
        if (portIsOpen(IP, 80))
            std::cout <<  "Port "<< i << " : OPEN" << std::endl;
            openPorts++;
            allPortsClosed = false;
    }

    if (!allPortsClosed){
        std::cout << "No ports are OPEN" << std::endl;
    }else{
        std::cout << "Ports OPEN: " << openPorts << std::endl;
    }
}