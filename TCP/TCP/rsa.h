#pragma once
#include <openssl/rsa.h>
class rsa
{
public:
	rsa();
	void create_rsa(RSA* rsa, int bits);
	~rsa();
	RSA* publickey;
	RSA* privatekey;
};

