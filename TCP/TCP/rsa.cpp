#include "rsa.h"



rsa::rsa()
{
}

void rsa::create_rsa(RSA * rsa, int bits)
{
	BIGNUM* big =BN_new();
	int ret = RSA_generate_key_ex(rsa, bits,big, NULL);
	this->publickey = RSAPublicKey_dup(rsa);
	this->privatekey = RSAPrivateKey_dup(rsa);
}


rsa::~rsa()
{
}
