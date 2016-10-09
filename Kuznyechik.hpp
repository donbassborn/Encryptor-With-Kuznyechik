#ifndef __KUZNYECHIK__
#define __KUZNYECHIK__

#include <vector>
#include "mycrypto.hpp"

#define BLOCK_LENGTH 16

class Kuznyechik {
	std::vector<ByteBlock> keys;
	static bool is_init;
public:
	static const int block_lenght {BLOCK_LENGTH};

	Kuznyechik(const ByteBlock & key);
    Kuznyechik(const Kuznyechik & rhs) {
        is_init = rhs.is_init;
        for(auto & iter_key : rhs.keys)
            keys.push_back(iter_key.deep_copy());
    }
	~Kuznyechik();
	void encrypt(const ByteBlock & src, ByteBlock & dst) const;
	void decrypt(const ByteBlock & src, ByteBlock & dst) const;
};

#endif
