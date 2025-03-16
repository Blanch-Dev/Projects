#include <iostream>
#include "aes.hpp"
#include <vector>

std::vector<uint8_t> aes_encrypt(const std::string& plaintext, const uint8_t* key) {
    // Asegúrate de que el texto plano tenga un tamaño múltiplo de 16 bytes (tamaño del bloque AES)
    size_t text_len = plaintext.size();
    size_t padded_len = text_len + (AES_BLOCKLEN - (text_len % AES_BLOCKLEN));
    std::vector<uint8_t> padded_plaintext(padded_len, 0);
    std::wmemcpy(padded_plaintext.data(), plaintext.data(), text_len);

    // Buffer para el texto cifrado
    std::vector<uint8_t> ciphertext(padded_len);

    // Inicializar el contexto AES
    struct AES_ctx ctx;
    AES_init_ctx(&ctx, key);

    // Encriptar el texto
    AES_ECB_encrypt(&ctx, padded_plaintext.data(), padded_len);

    // Copiar el resultado al buffer de salida
    std::wmemcpy(ciphertext.data(), padded_plaintext.data(), padded_len);

    return ciphertext;
}

int main() {
    // Texto plano
    std::string plaintext = "Hello, AES!";

    // Clave AES-128 (16 bytes)
    uint8_t key[AES_KEYLEN] = {
        0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6,
        0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c
    };

    // Encriptar el texto
    std::vector<uint8_t> ciphertext = aes_encrypt(plaintext, key);

    // Mostrar resultados
    std::cout << "Plaintext: " << plaintext << std::endl;
    std::cout << "Ciphertext (hex): ";
    for (uint8_t byte : ciphertext) {
        printf("%02x", byte);
    }
    std::cout << std::endl;

    return 0;
}
