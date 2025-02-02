#include <iostream>
#include <SFML/Network.hpp>
#include <string>

#define localhost "127.0.0.1"

bool portIsOpen(const std::string& address, int port);
void scannig(int amountPorts, std::string IP);

int main(){

    int lastPort {100};
    std::string IP {localhost};

    std::cout << "How many ports you want to scan (1-X): ";
    std::cin >> lastPort;

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

    std::cout << "Scanning ports from 1 - " << amountPorts << std::endl;

    for (int i = 1; i < amountPorts+1; i++){
        if (portIsOpen(IP, 80))
            std::cout <<  "Port "<< i << " : OPEN" << std::endl;
            allPortsClosed = false;
    }

    if (!allPortsClosed){
        std::cout << "No ports are OPEN" << std::endl;
    }
}