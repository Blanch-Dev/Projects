#include "hashpp.h"
#include "plusaes.hpp"
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

const unsigned char iv[16] = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
    0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
};

// Encriptación usando plusaes
std::vector<unsigned char> encrypt(std::string data, std::string &password) {
  std::vector<unsigned char> key(16);
  std::copy(password.begin(), password.end(), key.begin());

  const unsigned long encrypted_size =
      plusaes::get_padded_encrypted_size(data.size());
  std::vector<unsigned char> encrypted(encrypted_size);

  plusaes::encrypt_cbc((unsigned char *)data.data(), data.size(), &key[0],
                       key.size(), &iv, encrypted.data(), encrypted.size(),
                       true);
  return encrypted;
}

// Desencriptación usando plusaes
std::vector<unsigned char> decrypt(std::string encrypted,
                                   const std::string &password) {
  std::vector<unsigned char> key(16);
  std::copy(password.begin(), password.end(), key.begin());

  const unsigned long decrypted_size = encrypted.size();
  unsigned long padded_size = 0;
  std::vector<unsigned char> decrypted(decrypted_size);

  plusaes::decrypt_cbc((unsigned char *)encrypted.data(), encrypted.size(),
                       &key[0], key.size(), &iv, decrypted.data(),
                       decrypted.size(), &padded_size);
  decrypted.resize(padded_size); // Ajuste del tamaño exacto tras desencriptar
  return decrypted;
}

// Cortar una contraseña
// ! Metodo en desuso
std::string truncate(std::string str, size_t width) {
  if (str.length() > width)
    return str.substr(0, width);
  return str;
}

std::string toStringFromVector(std::vector<unsigned char> vectorToTransform) {
  std::string temp;
  for (auto p : vectorToTransform) {
    temp += (char)p;
  }
  return temp;
}

// Hashea la contraseña para que tenga un tamaño fijo
std::string hashingPass(std::string password) {
  return hashpp::get::getHash(hashpp::ALGORITHMS::MD5, password);
}

int main(int argc, char *argv[]) {

  std::string message, password;

  std::cout << "Message to encrypt: " << std::endl;
  std::cin >> message;
  std::cout << "Password to encrypt: " << std::endl;
  std::cin >> password;

  std::cout << toStringFromVector(encrypt(message, password)) << std::endl;

  std::cout << "Message to decrypt: " << std::endl;
  std::cin >> message;
  std::cout << "Password to decrypt: " << std::endl;
  std::cin >> password;

  std::cout << toStringFromVector(decrypt(message, password)) << std::endl;

  return 0;
}
